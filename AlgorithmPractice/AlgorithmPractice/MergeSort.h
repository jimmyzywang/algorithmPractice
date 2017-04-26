
//  MergeSort.h
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/24.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h
#include "InsertSort_Modify.h"
/*
    这个版本的归并排序可以工作，但是有不少的copy，效率不如V2
 */
template <typename T>
T* mergeV1(T arr1[],int count_1,T arr2[],int count_2) {
    int total_length = count_1 + count_2;
    T* result = new T[total_length];
    int j = 0; //j是结果数组中，下一个空的位置，从0开始，到(count_1 + count_2 - 1)
    int i1 = 0; //i1和i2是子数组arr1和arr2最新的指针位置
    int i2 = 0;
    for (; j < total_length; j++) {
        if (i1 < count_1 && i2 < count_2) { //arr1和arr2均有剩余元素
            if (arr1[i1] < arr2[i2]) {
                result[j] = arr1[i1];
                i1++;
            }else{
                result[j] = arr2[i2];
                i2++;
            }
        }else if (i1 >= count_1 && i2 < count_2){ //arr2均有剩余元素,arr1已经空了
            result[j] = arr2[i2];
            i2++;
        }else if (i1 < count_1 && i2 >= count_2 ){ //arr1均有剩余元素,arr2已经空了
            result[j] = arr1[i1];
            i1++;
        }else if(i1 >= count_1 && i2 >= count_2){
            assert(j == total_length - 1);
        }
    }
    return result;
}

template <typename T>
void MergeSortV1(T arr[],int count) {
    if (count > 1) {
        int sub_count1 = count / 2;
        int sub_count2 = count - sub_count1;
        T* arr1 = new T[sub_count1];
        T* arr2 = new T[sub_count2];
        std::copy(arr, arr + sub_count1, arr1);
        std::copy(arr + sub_count1, arr + count, arr2);
        T* result = new T[count];
        MergeSortV1(arr1, sub_count1);
        MergeSortV1(arr2, sub_count2);
        result = mergeV1(arr1, sub_count1, arr2, sub_count2);
        std::copy(result, result + count, arr);
        delete [] arr1;
        delete [] arr2;
    }
}

//对[r,middle]和(middle,l]这个两个区间的元素执行合并操作
#pragma mark MergeSortV2
template <typename T>
void mergeV2(T arr[],int r,int middle,int l) {
    T* aux = new T[l - r + 1];
    int i1 = r;
    int i2 = middle + 1;
    int j = 0;
    for (; j < l - r + 1; j++) { //这里j的index是aux的，所以不是从r开始的，从0开始
        if (i1 <= middle && i2 <= l) { //[r,middle]和(middle,l]都有剩余的元素
            if (arr[i1] < arr[i2]) {
                aux[j] = arr[i1];
                i1++;
            }else{
                aux[j] = arr[i2];
                i2++;
            }
        }else if (i1 > middle && i2 <= l){ //[r,middle]没有剩余元算了，(middle,l]还有剩余的元素
            aux[j] = arr[i2];
            i2++;
        }else if (i1 <= middle && i2 > l){
            aux[j] = arr[i1];
            i1++;
        }else{
            assert(j == l + 1);
        }
    }
    std::copy(aux, aux + l - r + 1, arr + r);
    delete [] aux;
}

template <typename T>
//排序的区间是[l,r]
void p_mergeSortV2(T arr[],int l,int r){
    if (l >= r) {
        return;
    }
    p_mergeSortV2(arr, l, (l + r) / 2);
    p_mergeSortV2(arr, (l + r) / 2 + 1, r);
    mergeV2(arr, l, (l + r) / 2, r);
}

template <typename T>
void MergeSortV2(T arr[],int count){
    p_mergeSortV2(arr,0,count - 1);
}

#pragma mark MergeSortV3
/*
 不使用递归调用，任何递归调用都可以修改为非递归模式，非递归方式是一种自下而上的方式，从相邻元素两两merge，四四merge
 不可用,没有理解到
 */
template <typename T>
void MergeSortBU_V1(T arr[],int count){
    int level = int(std::pow(2.0, ceil(log2(count))));
    for (int merge_size = 2; merge_size <= std::max(count,level);) {
        for (int i = 0; i <= count / merge_size; i++) {
            int end = std::min(count - 1, (i+1)*merge_size - 1);
            int start = i * merge_size;
            mergeV2(arr, start,(start + end) / 2, end);
        }
        merge_size *= 2;
    }
}

#pragma mark MergeSortV3
/*
 
 */
template <typename T>
void MergeSortBU_V2(T arr[],int count){
    /*
     each_merge_size表示：当要操作merge是，两段等长的数据，每一个的长度，如果从低至上的merge的话，长度是1。
     没经过一次merge以后（即外层循环一次），each_merge_size需要变成之前的两倍，因为两段数据被merge到了一起，所以就乘以2
     
     i表示：在以each_merge_size为merge长度的情况下，从数组坐标0开始，依次分段进行merge操作
     这个算法没有考虑count不是2的整数指数的情况，V2的代码只能操作2，4，8，16，32，64这样的数据
     */
    int each_merge_size = 1; //
    for (; each_merge_size <= count; each_merge_size *= 2) { //merge_size是
        for (int i = 0; i < count; i += each_merge_size) {
            int start = i;
            int end = i + 2 * each_merge_size - 1;
            mergeV2(arr, i,(start + end) / 2, end);
        }
    }
}

template <typename T>
void MergeSortBU_V3(T arr[],int count){
    /*
      V3考虑了临界情况，可以工作了
     */
    int each_merge_size = 1; //
    for (; each_merge_size <= count; each_merge_size *= 2) { //merge_size是
        for (int i = 0; i < count; i += 2 * each_merge_size) { //内部循环，每次跨过的区间长度应该是2*each_merge_size，因为这里涉及到两段数据
            int start = i;
            int end = std::min(i + 2 * each_merge_size - 1,count - 1); //结束坐标end有边界问题，可能会越界
            int split = std::min(count - 1, start + each_merge_size - 1); //分割坐标split有边界问题，可能会越界
            mergeV2(arr, start,split, end); //这里的middle不再是(start + end)/2，以5个元素为例，有一次merge是需要前4个一组，后一个为1组，不是完全平分的，而且应该按照each_merge_size来算
        }
    }
}

template <typename T>
void MergeSortBU_V4(T arr[],int count){
    /*
     V4有改进，1.对于merge_size较小的情况下，采用InsertSort，比Merge效率高
     */
    int each_merge_size = 1; //
    for (; each_merge_size <= count; each_merge_size *= 2) {
        for (int i = 0; i < count; i += 2 * each_merge_size) {
            int start = i;
            int end = std::min(i + 2 * each_merge_size - 1,count - 1);
            int split = std::min(count - 1, start + each_merge_size - 1);
            if (2 * each_merge_size <= 16) { //对于merge_size较小的情况下，采用InsertSort，比Merge效率高
                InsertSort_ModifyV3(arr, start, end);
            }else{
                mergeV2(arr, start,split, end);
            }
        }
    }
}

template <typename T>
void MergeSortBU_V5(T arr[],int count){
    /*
     V4有改进 2.在操作merge之前，可以看下第一段数据的最后一个元素是否已经大于了第二段的第一个元素
     */
    int each_merge_size = 1;
    for (; each_merge_size <= count; each_merge_size *= 2) {
        for (int i = 0; i < count; i += 2 * each_merge_size) {
            int start = i;
            int end = std::min(i + 2 * each_merge_size - 1,count - 1);
            int split = std::min(count - 1, start + each_merge_size - 1);
            if (2 * each_merge_size <= 16) {
                InsertSort_ModifyV3(arr, start, end);
            }else if(arr[split] < arr[split + 1]){ //在操作merge之前，可以看下第一段数据的最后一个元素是否已经大于了第二段的第一个元素
            }else{
                mergeV2(arr, start,split, end);
            }
        }
    }
}



#endif /* MergeSort_h */
