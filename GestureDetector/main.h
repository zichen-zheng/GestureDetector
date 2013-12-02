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

/**
 * Utility functions
 *
 * convert2pngForAll: convert images listed in the above file list to PNG format.
 *
 * printHelp: print the usage of this program in the command line.
 */
void convert2pngForAll();
void printHelp(char* argv0);

#endif
