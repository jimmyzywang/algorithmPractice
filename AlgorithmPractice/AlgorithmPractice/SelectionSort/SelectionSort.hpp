//
//  SelectionSort.hpp
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/17.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#ifndef SelectionSort_hpp
#define SelectionSort_hpp


#include <stdio.h>
#include <array>

/*  这样理解不对：
    选择排序是一种O(N^2)的排序算法，具体情况是这样的：
    step1: 5 21 10 4 9 (初始状态)
    step2: 从第一个元素(5)开始，跟它后面的元素依次比较，如果后面的某个元素比它小，那么他们交换位置，本次的结果是 4 21 10 5 9
    step3: 从第二个元素(21)继续，依次类推 本次的结果是 4 5 10 21 9
    ...
*/
template<typename T>
void mySelectionSortV1(T arr[],size_t count){
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[j] < arr[i]) {
                std::swap(arr[j], arr[i]);
                break;
            }
        }
    }
}

/*  正确的理解：
    选择排序是一种O(N^2)的排序算法，具体情况是这样的：
    step1: 5 21 10 4 9 (初始状态)
    step2: 从第一个元素(5)开始，跟它后面的“所有”元素依次比较，找到它们中最小的那个，然后交换位置，本次的结果是 4 21 10 5 9
    step3: 从第二个元素(21)继续，依次类推 本次的结果是 4 5 10 21 9
    ...
 
    Fix V1:这样的理解不对，比它小的元素不一定是最小的，可能还有更小的，但是这是break的话就错了
*/
template<typename T>
void mySelectionSortV2(T arr[],size_t count){
    for (int i = 0; i < count; i++) {
        int miniIndex = i + 1;
        for (int j = i + 1; j < count; j++) {
            if (arr[j] < arr[miniIndex]) {
                miniIndex = j;
            }
        }
        std::swap(arr[miniIndex], arr[i]);
    }
}

/*  正确的版本：
    选择排序是一种O(N^2)的排序算法，具体情况是这样的：
    step1: 5 21 10 4 9 (初始状态)
    step2: 从第一个元素(5)开始，跟它后面的“所有”元素依次比较，找到它们中最小的那个，然后交换位置，本次的结果是 4 21 10 5 9
    step3: 从第二个元素(21)继续，依次类推 本次的结果是 4 5 10 21 9
    ...
    
    Fix V2：临界条件有问题，当外层i = (n - 1)时，miniIndex从n开始，这时候arr[n]就越界了
    
    时间复杂度，如果n = 10000（一万），执行结果是0.11s；当n变成之前的10倍，大概是10万，时间变成11s左右，即N^2
*/
template<typename T>
void mySelectionSortV3(T arr[],size_t count){
    for (int i = 0; i < count; i++) {
        int miniIndex = i; //这里miniIndex从i开始，因为数组的坐标是从0开始的，i就是第i+1个元素
        for (int j = i; j < count; j++) {
            if (arr[j] < arr[miniIndex]) {
                miniIndex = j;
            }
        }
        std::swap(arr[miniIndex], arr[i]);
    }
}

#endif /* SelectionSort_hpp */
