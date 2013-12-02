//
//  main.h
//  GestureDetector
//
//  Created by Zichen Zheng on 11/30/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#ifndef GestureDetector_main_h
#define GestureDetector_main_h

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "util/convert2png.h"
#include "util/genFileList.h"
#include "basic.h"
#include "hogClassifier.h"

using namespace cv;
using namespace std;

void genFileListForAll() {
    genFileList();
}

void convert2pngForAll() {
    batch_convert2png("../train_list.txt");
    batch_convert2png("../test_complex_list.txt");
    batch_convert2png("../test_complex_list.txt");
}

#endif
