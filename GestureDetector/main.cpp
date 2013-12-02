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
    
    if (mode == 0) {
        genFileList(".png");
        return 0;
    }
    else if (mode == 1) {
        genFileList(".ppm");
        convert2pngForAll();
        return 0;
    }
    else if (mode == 2 || mode == 3) {
        if (mode == 2) {
            labels.clear();
            hogTrain("../train_list.txt", labels);
        }
        hogTest("../test_uniform_list.txt", labels);
        hogTest("../test_complex_list.txt", labels);
    }
    else if (mode == 4) {
        VideoCapture cap(0); // open the default camera
        if(!cap.isOpened())  // check if we succeeded
            exit(-2);
        
        // set video capture parameters
        //cap.set(CV_CAP_PROP_FRAME_HEIGHT, 120);
        //cap.set(CV_CAP_PROP_FRAME_WIDTH, 120);
        cap.set(CV_CAP_PROP_FPS, 3);  // set frame rate
        
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
            
            int l = hogPredict(croppedFrame);
            cout << "-----------------\n";
            cout << l << endl;
            cout << "-----------------\n";
            //imshow("Frame", croppedFrame);
        }
        
        return 0;
    }
    
    return 0;
}



/**
 * Utility functions implementation
 */

void convert2pngForAll() {
    batch_convert2png("../train_list.txt");
    batch_convert2png("../test_complex_list.txt");
    batch_convert2png("../test_uniform_list.txt");
}

void printHelp(char* argv0) {
    cout << "Usage: " << argv0 << " [options] ...\n";
    cout << "-m mode : (default 2)\n";
    cout << "   0 -- generate file list for sample images\n";
    cout << "   1 -- convert sample images to PNG\n";
    cout << "   2 -- train SVM classifier and test\n";
    cout << "   3 -- test based on existing SVM model\n";
    cout << "   4 -- predict a single image based on existing SVM model\n";
}
