//
//  basic.h
//  GestureDetector
//
//  Basic definitions.
//
//  Created by Zichen Zheng on 11/29/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#ifndef GestureDetector_basic_h
#define GestureDetector_basic_h

#include <sys/time.h>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

//#define APP_CONTROLLER
#ifdef APP_CONTROLLER
#define ROOT_DIR "AppController.app/Contents/Resources/GestureDetector/"
#define FEATURES_DIR ""
#define LIBSVM_DIR ""
#else
#define ROOT_DIR "../"
#define FEATURES_DIR "DerivedData/"
#define LIBSVM_DIR "libsvm/"
#endif


#ifdef DEBUG
#define DEBUGMODE if (true)
#else
#define DEBUGMODE if (false)
#endif


// get system time in second
static double getSecond() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ( (double)tv.tv_sec ) + ( (double)tv.tv_usec ) * 1.0e-6;
}

// put command line output to a string
static string exec(char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}

#endif
