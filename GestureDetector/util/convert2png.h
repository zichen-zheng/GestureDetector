//
//  convert2png.h
//  GestureDetector
//
//  Convert images to PNG format.
//
//  Created by Zichen Zheng on 11/29/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#ifndef __GestureDetector__convert2png__
#define __GestureDetector__convert2png__

#include <iostream>
#include <string>
#include <fstream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

/**
 * Convert all images listed in a file list to PNG format.
 * 
 * @param file_list_path = location of file list
 */
void batch_convert2png(char* file_list_path);


/**
 * Convert a given image to PNG format.
 *
 * @param imgpath = location of the image to be converted
 */
void convert2png(string imgpath);

#endif /* defined(__GestureDetector__convert2png__) */
