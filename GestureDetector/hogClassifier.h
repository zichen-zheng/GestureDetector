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

const Size hogWinSize = Size(64,64);
const Size hogBlockSize = Size(16,16);
const Size hogBlockStride = Size(8,8);
const Size hogCellSize = Size(8,8);
const int hogNBins = 9;
const Size hogWinStride = Size(8,8);
const string trainDataFileName = "train.data";
const string scaledTrainDataFileName = "train_scaled.data";
const string svmScaleRangeFileName= "gesture.range";
const string svmModelFileName = "gesture.model";
const string testDataFileName = "test.data";
const string scaledTestDataFileName = "test_scaled.data";
const string testResultFileName = "test.result";
const string predictDataFileName = "predict.data";
const string scaledPredictDataFileName = "predict_scaled.data";
const string predictResultFileName = "predict.result";

/*
//calculate the length of HOG descriptor
const int numBlock = ((hogWinSize.height - hogBlockSize.height) / hogBlockStride.height + 1) *
((hogWinSize.width - hogBlockSize.width) / hogBlockStride.width + 1);
const int numCell = (hogBlockSize.height / hogCellSize.height) * (hogBlockSize.width / hogCellSize.width);
const int descriptorLen = numBlock * numCell * hogNBins;
 */


/**
 * Train a SVM classifier for HOG descriptors.
 *
 * @param trainFileList = a text file listing file paths for training samples
 * @param labels = a label list containing all labels in the training dataset
 */
void hogTrain(char* trainFileList, vector<string>& labels);


/**
 * Test the accuracy of the SVM classifier trained by hogTrain.
 *
 * @param testFileList = a text file listing file paths for testing samples
 * @param labels = a label list containing labels supported by the SVM classifier
 */
void hogTest(char* testFileList, const vector<string>& labels);


int hogPredict(const Mat& img);


/**
 * Help function to determine the location of a label in the label list.
 *
 * @param labels = a label list
 * @param label = a label
 * @return the location/index of the label in the label list; -1 if not exist
 */

int hasCategory(const vector<string>& labels, const string& label);

#endif /* defined(__GestureDetector__hogClassifier__) */
