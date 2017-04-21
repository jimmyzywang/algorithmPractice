//
//  InsertSort.h
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/18.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#ifndef InsertSort_h
#define InsertSort_h

#include "Utility.hpp"

/*
 插入排序是一种O(n^2)的排序算法，过程是这样的：数组 6 1 9 10 5
 step1:从第一个元素6开始，跟它前面的元素依次比较，如果它把前面的元素大，那么就交换位置，因为第一个元素6前面没有元素，所以不动。结果是：6 1 9 10 5
 step2:从第二个元素1开始，它跟前面的6对比，1大于6，所以它们交换位置。结果是：1 6 9 10 5
 step2:从第三个元素9开始，它跟前面的1，6对比。结果是：1 6 9 10 5
 ....
 */

template <typename T>
void InsertSortV1(T arr[],size_t count) {
    for (int i = 0; i < count; i++) {
        for (int j = i ; j >= 0; j--) {
            if (arr[j] > arr[i]) {
                std::swap(arr[j],arr[i]);
            }
        }
        Utility::PrintArray(arr, count);
    }
}

/*
 Fix BUG:
 插入排序是一种O(n^2)的排序算法，过程是这样的：数组 6 1 9 10 5
 step1:第一个元素6，认为它已经有序了
 step2:从第二个元素1开始，跟它前面的元素们（已经排序）依次比较，直到找到第一个比元素1大的位置，然后插入在它前面。结果是：1 6 9 10 5
 step3:从第三个元素9开始，它跟前面的1，6对比。结果是：1 6 9 10 5
 ....
 数组的插入是挺麻烦的事情，V2版本就放弃了，
 */

template <typename T>
void InsertSortV2(T arr[],size_t count) {
    for (int i = 1; i < count; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                //在位置j插入arr[i]
            }
        }
    }
}

/*
 Fix BUG:
 插入排序是一种O(n^2)的排序算法，过程是这样的：数组 6 1 9 10 5
 step1:第一个元素6，认为它已经有序了
 step2:从第二个元素1开始，跟它前面的元素们（已经排序）依次比较，如果前一个元素比自己大，就两者就交换位置，直到前一个元素比自己小。结果是：1 6 9 10 5
 step3:从第三个元素9开始，它跟前面的1，6对比。结果是：1 6 9 10 5
 ....
 这里用交换代替了插入
 */

template <typename T>
void InsertSortV3(T arr[],size_t count) {
    for (int i = 1; i < count; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) {
                std::swap(arr[i], arr[j]);
            }else{
                break;
            }
        }
        Utility::PrintArray(arr, count);
    }
}

/*
 正确的版本
 Fix BUG:
 step2:从第二个元素1开始，跟它前面的元素们（已经排序）依次比较，如果前一个元素比自己大，就*相邻*就交换位置，直到前一个元素比自己小。结果是：1 6 9 10 5
 ....
 */

template <typename T>
void InsertSortV4(T arr[],size_t count) {
    for (int i = 1; i < count; i++) { //从第二个元素开始计算插入位置，第一个元素被认为有序
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[j + 1]) { //第二层循环是对j的操作，i没有变化
                std::swap(arr[j], arr[j + 1]); //相邻位置交互位置，用“交换位置”代替“插入“
            }else{
                break;
            }
        }
    }
}


#endif /* InsertSort_h */
