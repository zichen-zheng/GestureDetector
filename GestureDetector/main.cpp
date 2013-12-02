//
//  main.cpp
//  GestureDetector
//
//  Created by Zichen Zheng on 11/27/13.
//  Copyright (c) 2013 Zichen Zheng. All rights reserved.
//

#include "main.h"

int main(int, char**) {
    genFileListForAll();
    //convert2pngForAll();
    
    vector<string> labels;
    hogTrain("../train_list.txt", labels);
    /*
    labels.push_back("Negative");
    labels.push_back("A");
    labels.push_back("B");
    labels.push_back("Point");
     */
    hogTest("../test_uniform_list.txt", labels);
    
    return 0;
}
