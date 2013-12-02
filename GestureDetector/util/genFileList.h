//
//  genFileList.h
//  GestureDetector
//
//  Created by Zichen Zheng on 11/29/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#ifndef __GestureDetector__genFileList__
#define __GestureDetector__genFileList__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

/**
 * Generate file lists for datasets.
 *
 * @param imgext = image extension (e.g. jpg, png, ppm ...)
 */
void genFileList(const string& imgext);

/**
 * Convert integer to string.
 *
 * @param num = integer to be converted
 * @param digit = number of digits to be retained
 */
string int2str(int num, int numDigit);

#endif /* defined(__GestureDetector__genFileList__) */
