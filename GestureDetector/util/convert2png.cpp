//
//  convert2png.cpp
//  GestureDetector
//
//  Created by Zichen Zheng on 11/29/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#include "convert2png.h"

void batch_convert2png(char* file_list_path) {
    ifstream fs;
    fs.open(file_list_path);
    if (fs == NULL) {
        cerr << "Error: file list \"" << file_list_path << "\" does not exist\n";
        exit(-1);
    }
    
    string imgpath, cat;
    while (fs >> cat) {
        fs >>  imgpath;
        cout << "Converting " << imgpath << " ..." << endl;
        convert2png(imgpath);
    }
    
    fs.close();
}

void convert2png(string imgpath) {
    Mat img = imread(imgpath);
    int extpos =  (int) imgpath.find_last_of(".");  // find extension position of the file name
    string new_imgpath = imgpath.substr(0, extpos).append(".png");
    vector<int> comp_params;  // image compression parameters
    comp_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    comp_params.push_back(0);
    
    try {
        imwrite(new_imgpath, img, comp_params);
    }
    catch (runtime_error& ex) {
        fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());
    }
}

