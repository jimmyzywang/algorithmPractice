
//  MergeSort.h
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/24.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h
/*
 
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
template <typename T>
void merge(T arr[],int r,int middle,int l) {
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
    merge(arr, l, (l + r) / 2, r);
}

template <typename T>
void MergeSortV2(T arr[],int count){
    p_mergeSortV2(arr,0,count - 1);
}

//自下而上的归并排序
template <typename T>
void MergeSortBU(T arr[],size_t count){
    int level = ceil(log2(count));
    p_mergeSortV2(arr,0,count - 1);
}

#endif /* MergeSort_h */
