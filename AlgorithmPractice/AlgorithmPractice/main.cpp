//
//  main.cpp
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/17.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#include <iostream>
#include "Utility.hpp"
#include "SelectionSort.hpp"

int main(int argc, const char * argv[]) {

    size_t n = 100000;
    int* array = Utility::GenerateRamdonArray(n, 0, n);
    Utility::TestSort("SelectionSort", mySelectionSortV3, array, n);
    delete [] array;
    return 0;
}
