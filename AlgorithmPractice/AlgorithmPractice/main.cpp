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
#include "MergeSort.h"
#include "QuickSort.h"
#include "ReversePair.h"

int main(int argc, const char * argv[]) {

    int n = 5;
    int* array1 = Utility::GenerateRamdonArray(n, 0, 10);
    Utility::PrintArray(array1, n);
    int result = getReversePairCount(array1, n);
//    int* array2 = Utility::CopyArray(array1, n);
    
//    int* array3 = Utility::CopyArray(array1, n);
//    int* array4 = Utility::CopyArray(array1, n);
//    Utility::TestSort("QuickSort_V2", QuickSort_V2, array2, n);
//    Utility::TestSort("MergeSort 1", MergeSortV1, array2, n);
//    Utility::TestSort("InsertSort_modify", InsertSort_ModifyV2, array3, n);
//    Utility::TestSort("SelectSort", mySelectionSortV3, array4, n);
    
    delete [] array1;
//    delete [] array2;
//    delete [] array3;
//    delete [] array4;
    return 0;
}
