//
//  main.cpp
//  GestureDetector
//
//  Created by Zichen Zheng on 11/27/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

int main(int, char**) {
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    
    Mat edges;
    namedWindow("edges",1);
    while(true) {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}