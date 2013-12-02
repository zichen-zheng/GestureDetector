//
//  genFileList.cpp
//  GestureDetector
//
//  Created by Zichen Zheng on 11/29/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#include "genFileList.h"

void genFileList(const string& imgext) {
    ofstream trainFile, testComplexFile, testUniformFile; // file lists for training and testing datasets
    trainFile.open("../train_list.txt");
    testComplexFile.open("../test_complex_list.txt");
    testUniformFile.open("../test_uniform_list.txt");
    string trainDir = "../Dataset/marcel_train/";
    string testDir = "../Dataset/marcel_test/";
    string testComplexDir = "complex/";
    string testUniformDir = "uniform/";
    
    /*
    int trainNumImgInFolder[] = {4136, 1329, 487, 572, 654, 1395, 435};
    int testComplexNumImgInFolder[] = {229, 39, 41, 47, 58, 54, 38};
    int testUniformNumImgInFolder[] = {229, 58, 61, 65, 76, 65, 57};
     */
    
    int trainNumImgInFolder[] = {4136, 1329, 487, 1395};
    int testComplexNumImgInFolder[] = {229, 39, 41, 54};
    int testUniformNumImgInFolder[] = {229, 58, 61, 65};
    
    vector<string> categories;
    categories.push_back("Negative");
    categories.push_back("A");
    categories.push_back("B");
    //categories.push_back("C");
    //categories.push_back("Five");
    categories.push_back("Point");
    //categories.push_back("V");
    
    for (int i = 0; i < categories.size(); i++) {
        string cat_folder = categories[i];
        cat_folder.push_back('/');
        
        // generate file lists for training set
        for (int j = 1; j <= trainNumImgInFolder[i]; j++) {
            string imgpath = trainDir;
            int numDigit = floor (log10 (abs (trainNumImgInFolder[i]))) + 1;
            imgpath.append(cat_folder).append(categories[i]).append("-train").append(int2str(j,numDigit)).append(imgext);
            trainFile << categories[i] << " " << imgpath << endl;
        }
        
        // generate file lists for testing sets
        for (int j = 1; j <= testComplexNumImgInFolder[i]; j++) {
            string imgpath = testDir;
            int numDigit = floor (log10 (abs (testComplexNumImgInFolder[i]))) + 1;
            imgpath.append(cat_folder).append("complex/").append(categories[i]).append("-complex").append(int2str(j,numDigit)).append(imgext);
            testComplexFile << categories[i] << " " << imgpath << endl;
        }
        for (int j = 1; j <= testUniformNumImgInFolder[i]; j++) {
            string imgpath = testDir;
            int numDigit = floor (log10 (abs (testUniformNumImgInFolder[i]))) + 1;
            imgpath.append(cat_folder).append("uniform/").append(categories[i]).append("-uniform").append(int2str(j,numDigit)).append(imgext);
            testUniformFile << categories[i] << " " << imgpath << endl;
        }
    }
    
}


string int2str(int num, int numDigit) {
    ostringstream ss;
    ss << num;
    string ss_str = ss.str();
    int strLen = (int) ss_str.length();
    
    // add "0" in the front if necessary
    for (int i = 0; i < numDigit-strLen; i++) {
        string tmp = "0";
        ss_str = tmp.append(ss_str);
    }
    return ss_str;
}