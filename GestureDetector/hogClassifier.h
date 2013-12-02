//
//  hogClassifier.h
//  GestureDetector
//
//  Created by Zichen Zheng on 12/1/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#ifndef __GestureDetector__hogClassifier__
#define __GestureDetector__hogClassifier__

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv/ml.h>
#include "basic.h"

using namespace std;
using namespace cv;

const Size hogWinSize = Size(32,32);
const Size hogBlockSize = Size(16,16);
const Size hogBlockStride = Size(8,8);
const Size hogCellSize = Size(8,8);
const int hogNBins = 9;
const Size hogWinStride = Size(8,8);
const string trainDataFilePrefix = "train_data_";
const string svmScaleRangeFilePrefix = "range_";
const string svmModelFilePrefix = "model_";

/*
//calculate the length of HOG descriptor
const int numBlock = ((hogWinSize.height - hogBlockSize.height) / hogBlockStride.height + 1) *
((hogWinSize.width - hogBlockSize.width) / hogBlockStride.width + 1);
const int numCell = (hogBlockSize.height / hogCellSize.height) * (hogBlockSize.width / hogCellSize.width);
const int descriptorLen = numBlock * numCell * hogNBins;
 */

void hogTrain(char* trainFileList);
int hasCategory(const vector<string>& categoreis, const string &cat);

#endif /* defined(__GestureDetector__hogClassifier__) */
