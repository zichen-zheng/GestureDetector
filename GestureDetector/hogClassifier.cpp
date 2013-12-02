//
//  hogClassifier.cpp
//  GestureDetector
//
//  Created by Zichen Zheng on 12/1/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#include "hogClassifier.h"

void hogTrain(char* trainFileList) {
    ifstream fs;
    fs.open(trainFileList);
    if (fs == NULL) {
        cerr << "Error: training file list \"" << trainFileList<< "\" does not exist\n";
        exit(-1);
    }
    
    HOGDescriptor hog(hogWinSize, hogBlockSize, hogBlockStride, hogCellSize, hogNBins);
    cout << "HOG descriptor length = " << hog.getDescriptorSize() << endl;
    
    vector<string> labels;
    vector<vector<vector<float> > > features;
    string label, imgpath;
    while (fs >> label) {
        int catnum = hasCategory(labels, label);
        if (catnum < 0) {
            labels.push_back(label);
            features.push_back(vector<vector<float> >());
            catnum = (int) labels.size() - 1;
        }
        
        fs >> imgpath;
        Mat img = imread(imgpath);
        assert(img.data);  // image should not be empty
        Mat resizedImg = Mat::zeros(hogWinSize.width, hogWinSize.height, CV_8UC3);
        vector<float> featVec;
        resize(img, resizedImg, hogWinSize, 0, 0, INTER_CUBIC);
        hog.compute(resizedImg, featVec, hogWinStride);  // compute HOG feature
        features[catnum].push_back(featVec);
    }
    
    fs.close();
    
    assert( labels.size() == features.size() );
    int numClasses = (int) labels.size();
    
    // Store features into files.
    // Note that SVM is a 2-class classifying mechanism; we perform the 2-class
    // classification for k times if we have k classes.
    for (int i = 0; i < numClasses; i++) {
        ofstream datafile;
        string datafile_name = FEATURES_DIR;
        datafile_name.append(trainDataFilePrefix).append(labels[i]);
        datafile.open(datafile_name.c_str());
        
        for (int j = 0; j < numClasses; j++) {
            for (int k = 0; k < features[j].size(); k++) {
                if (i == j) datafile << "1 ";  // label of positive samples
                else datafile << "-1 ";  // label of negative samples
                for (int p = 0; p < features[j][k].size(); p++) {
                    datafile << p+1 << ":" << features[j][k][p] << " ";
                }
                datafile << endl;
            }
        }
        datafile.close();
    }
    
    for (int i = 0; i < numClasses; i++) {
        string svmScaleFileName, dataFileName, scaledDataFileName, svmModelFileName;
        svmScaleFileName.append(FEATURES_DIR).append(svmScaleRangeFilePrefix).append(labels[i]);
        dataFileName.append(FEATURES_DIR).append(trainDataFilePrefix).append(labels[i]);
        scaledDataFileName.append(FEATURES_DIR).append(trainDataFilePrefix).append(labels[i]).append("_scale");
        svmModelFileName.append(FEATURES_DIR).append(svmModelFilePrefix).append(labels[i]);
        
        string command;
        
        // scale data to range [-1 1]
        command.append("../libsvm/svm-scale -l -1 -u 1 -s ").append(svmScaleFileName).append(" ").append(dataFileName).append(" > ").append(scaledDataFileName);
        cout << command << endl;
        system(command.c_str());
        
        // train SVM classifier
        command.clear();
        command.append("../libsvm/svm-train ").append(scaledDataFileName).append(" ").append(svmModelFileName);
        cout << command << endl;
        system(command.c_str());
    }
}


int hasCategory(const vector<string>& categoreis, const string &cat) {
    for (int i = 0; i < categoreis.size(); i++) {
        string str = categoreis[i];
        if (str.compare(cat) == 0) return i;
    }
    return -1;
}