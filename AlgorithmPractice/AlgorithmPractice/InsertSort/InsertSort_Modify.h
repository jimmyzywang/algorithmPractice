//
//  InsertSort_Modify.h
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/21.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#ifndef InsertSort_Modify_h
#define InsertSort_Modify_h
#include "Utility.hpp"

/*
 普通的InsertSort，由于是在已排好序的数组中寻找插入位置，所以理论上，可以提前完成小循环，理论上应该比SelectSort速度快。
 但是，因为数组没有高效的插入方法，在实现上，用逐个元素“交换”替代“插入”，一个“交换”有三次赋值，而SelectSort中，每次小循环都是多次比较大小，一次赋值，速度比较快
 实际测试，普通的InsertSort效率不如SelectSort

 */
template <typename T>
//坏的
void InsertSort_ModifyV1(T arr[],size_t count) {
    for (int i = 1; i < count; i++) {
        T temp = arr[i];
        for (int j = i - 1 ; j >= 0; j--) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            }else{
                arr[j + 1] = temp;
                break;
            }
            Utility::PrintArray(arr, count);
        }
    }
}

/*
InsertSort_Modify是一种改进的InsertSort：
还是从第2个元素开始比较作为待排序元素，如果前面一个元素比它大，说明这个已排序元素需要向后移动，所以这里就直接把
 */

template <typename T>
void InsertSort_ModifyV2(T arr[],size_t count) {
    for (int i = 1; i < count; i++) { //还是从i = 1 开始
        T temp = arr[i]; //首先先把arr[i]的值赋给一个临时变量
        int j = i; //j表示元素arr[j]最终位置的index,从i的当前位置开始
        for (; j >= 0; j--) { //如果j前一个元素（已排序的元素）比i大，那么j - 1赋值给j（这里j的值会被覆盖，但是没关系，我们有保存temp）
            if (arr[j - 1] > temp) { //如果j前面的元素比temp大，那么
                arr[j] = arr[j - 1];
            }else{
                break;
            }
        }
        arr[j] = temp;
    }
}

#endif /* InsertSort_Modify_h */
