//
//  main.cpp
//  GestureDetector
//
//  Created by Zichen Zheng on 11/27/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#include "main.h"

/**
 * Main function
 */
int main(int argc, char** argv) {
    int mode = 2;
    string imgpath;
    
    // parse command line arguments
    for (int i = 1; i < argc; i++) {
		if (argv[i][0] != '-') break;
		if (++i >= argc) {
			printHelp(argv[0]);
            exit(-1);
        }
		switch (argv[i-1][1]) {
			case 'm':
                mode = atoi(argv[i]);
                break;
            case 'i':
                imgpath = string(argv[i]);
                break;
			default:
				fprintf(stderr,"Unknown option: -%c\n", argv[i-1][1]);
				printHelp(argv[0]);
		}
	}
    
    vector<string> labels;
    labels.push_back("Negative");
    labels.push_back("A");
    labels.push_back("B");
    labels.push_back("Point");
    
#ifdef APP_CONTROLLER
    mode = 5;
#endif
    
    if (mode == 0) {
        cout << "Generating file list ...\n";
        genFileList(".png");
        return 0;
    }
    else if (mode == 1) {
        cout << "Converting images to PNG format ...\n";
        genFileList(".ppm");
        convert2pngForAll();
        return 0;
    }
    else if (mode == 2 || mode == 3) {
        if (mode == 2) {
            cout << "============= Training =============\n";
            labels.clear();
            hogTrain("../train_list.txt", labels);
            cout << endl;
        }
        
        double time0 = getSecond();
        cout << "===== Testing (Uniform Dataset) =====\n";
        hogTest("../test_uniform_list.txt", labels);
        double time1 = getSecond();
        cout << "Time elasped for testing = " << time1-time0 << " seconds\n";
        
        cout << endl;
        
        cout << "===== Testing (Complex Dataset) =====\n";
        hogTest("../test_complex_list.txt", labels);
        double time2 = getSecond();
        cout << "Time elasped for testing = " << time2-time1 << " seconds\n";
    }
    else if (mode == 4) {
        VideoCapture cap(0); // open the default camera
        if(!cap.isOpened())  // check if we succeeded
            exit(-2);
        
        // set video capture parameters
        //cap.set(CV_CAP_PROP_FRAME_HEIGHT, 120);
        //cap.set(CV_CAP_PROP_FRAME_WIDTH, 120);
        cap.set(CV_CAP_PROP_FPS, 10);  // set frame rate
        
        namedWindow("Gesture Detector", 1);
        while (true) {
            Mat frame;
            cap >> frame; // get a new frame from camera
            
            // crop the image to a square
            int dim = std::min(frame.rows, frame.cols);
            unsigned int startX = (unsigned int) (frame.cols - dim) / 2;
            unsigned int startY = (unsigned int) (frame.rows - dim) / 2;
            Rect region((int) startX, (int) startY, dim, dim);
            Mat croppedFrame;
            Mat(frame, region).copyTo(croppedFrame);
            
            int gdCode = hogPredict(croppedFrame);
            DEBUGMODE {
                cout << "---------------------\n";
                cout << "   Gesture Code: " << gdCode << endl;
                cout << "---------------------\n";
            }
            cout << "Gesture: " << gestureCode2Str(gdCode) << endl;
            imshow("Gesture Detector", croppedFrame);
        }
        
        return 0;
    }
    
    else if (mode == 5) {
        Mat img = imread(imgpath);
        if (! img.data) {  // image is empty
            cerr << "Error: cannot read image: " << imgpath << endl;
            exit(-3);
        }
        
        // crop the image to a square
        int dim = std::min(img.rows, img.cols);
        unsigned int startX = (unsigned int) (img.cols - dim) / 2;
        unsigned int startY = (unsigned int) (img.rows - dim) / 2;
        Rect region((int) startX, (int) startY, dim, dim);
        Mat croppedImg;
        Mat(img, region).copyTo(croppedImg);
        
        int gdCode = hogPredict(croppedImg);
        DEBUGMODE {
            cout << "---------------------\n";
            cout << "   Gesture Code: " << gdCode << endl;
            cout << "---------------------\n";
        }
        cout << "Gesture: " << gestureCode2Str(gdCode) << endl;
        
    }
    
    return 0;
}



/**
 * Utility functions implementation
 */

string gestureCode2Str(int gdCode) {
    string gdStr;
    switch (gdCode) {
        case 0:
            gdStr = "No Gesture";
            break;
        case 1:
            gdStr = "Fist";
            break;
        case 2:
            gdStr = "Palm";
            break;
        case 3:
            gdStr = "Pointing";
            break;
        default:
            break;
    }
    return gdStr;
}

void convert2pngForAll() {
    batch_convert2png("../train_list.txt");
    batch_convert2png("../test_complex_list.txt");
    batch_convert2png("../test_uniform_list.txt");
}

void printHelp(char* argv0) {
    cout << "Usage: " << argv0 << " [options] ...\n";
    cout << "-m mode (default 2)\n";
    cout << "   0 -- generate file list for sample images\n";
    cout << "   1 -- convert sample images to PNG\n";
    cout << "   2 -- train SVM classifier and test\n";
    cout << "   3 -- test based on existing SVM model\n";
    cout << "   4 -- predict gesture via built-in camera\n";
    cout << "   5 -- predict gesture given an image\n";
    cout << "-i input_image_path (required if -m is 5)\n";
}
