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
#include "InsertSort.h"

int main(int argc, const char * argv[]) {

    size_t n = 5;
    int* array1 = Utility::GenerateRamdonArray(n, 0, n);

    Utility::PrintArray(array1, n);
    Utility::TestSort("InsertSort", InsertSortV4, array1, n);
    Utility::PrintArray(array1, n);
    delete [] array1;
    return 0;
}
