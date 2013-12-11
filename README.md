GestureDetector
===============

GestureDetector trains a gesture SVM classifier by extracting HOG descriptors from input images. Given a model, it can also determine which gesture it is in a given image.

Minimum System Requirements
---------------------------

To build and run this project, you should prepare:

* OS X 10.9 or above
* Xcode 5.0 or above
* OpenCV 2.4.2 or above
* At least 1GB memory

Dataset
-------
This project uses [Sebastien Marcel - Hand Posture and Gesture Datasets][http://www.idiap.ch/resource/gestures/] for gesture samples, and background images from [INRIA Person Dataset][http://pascal.inrialpes.fr/data/human/] for negative samples. You can download the dataset [here][http://zichenzheng.com/documents/AppController/dataset.zip].

LIBSVM
------
The classifier used in this project is SVM; particularly, [LIBSVM][http://www.csie.ntu.edu.tw/~cjlin/libsvm/]. The three binary files in "libsvm" directory were compiled using LIBSVM source code under OS X.


Configure OpenCV for Your Xcode
-------------------------------

1. Start a new XCode Command Line Tool project.
2. Rght click on the project, and click "Add files to...".
3. When Finder pops up, hit "/" to bring up the navigation panel.
4. Type in "/usr/local/lib".
5. Add in all the .dylib files that you need. To prevent linker errors, I recommend you initially add ALL the files ending in "...2.4.0.dylib". Now, you should have a bunch of .dylib files in your project. Feel free to move them to a separate group within your project.
6. Click on the project file and go to "Build Settings".
7. Search for "Header Search Paths", and change the path to "/usr/local/include".
8. Search for "Library Search Paths", and change the path to "/usr/local/lib".
9. [For Xcode 5] Search for "C++ Standard Library", and change to "libstdc++ (GNU C++
   standard library".
