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
#include "InsertSort_Modify.h"

int main(int argc, const char * argv[]) {

    size_t n = 10000;
    int* array1 = Utility::GenerateRamdonArray(n, 0, n);
    int* array2 = Utility::CopyArray(array1, n);
    int* array3 = Utility::CopyArray(array1, n);
    
    Utility::TestSort("InsertSort", InsertSortV4, array1, n);
    Utility::TestSort("InsertSort_modify", InsertSort_ModifyV2, array2, n);
    Utility::TestSort("SelectSort", mySelectionSortV3, array3, n);
    delete [] array1;
    delete [] array2;
    delete [] array3;
    return 0;
}
