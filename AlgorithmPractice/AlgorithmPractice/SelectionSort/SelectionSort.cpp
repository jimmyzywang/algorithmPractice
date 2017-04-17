//
//  SelectionSort.cpp
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/17.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#include "SelectionSort.hpp"

void selectionSort(int arr[],size_t count){
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[j], arr[i]);
            }
        }
    }
}
