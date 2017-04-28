//
//  QuickSort.h
//  AlgorithmPractice
//
//  Created by jimmyzywang-nb on 2017/4/27.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h


/*
    BUG:pivot_i等于l的时候，可以工作，其他值不行
*/
template <typename T>
int partition_V1(T arr[],int l, int r,int pivot_i) {
    assert(pivot_i <= r);
    assert(pivot_i >= l);
    T pivot = arr[pivot_i];
    int i = l; //[l,i]都是小于基准值pivot，叫做“小于部分”
    int j = l; //排序完成以后(j,r]都是大于基准值pivot，叫做“大于部分”
    int e = l + 1; //e是下一个待考察的点，如果e == l + 1，那么partition结束
    for (; e <= r; e++) {
        //如果待考察的值，比基准值大，那么arr[e]算作“大于部分”，arr[e]直接加在“大于部分”，j++
        if (arr[e] >= pivot) {
            j++;
        }else{
        //如果待考察的值，比基准值小，那么arr[e]算作“小于部分”，arr[e]与i++位置的元素（“大于部分的第一个元素”）交换位置，j++
            i++;
            std::swap(arr[i], arr[e]);
        }
    }
    //pivot与i位置交互位置,这样pivot_i就放在了合适的位置上
    std::swap(arr[pivot_i], arr[i]);
    return i;
}

template <typename T>
void p_QuickSort_V1(T arr[],int l,int r) {
  if (l >= r) {
    return;
  }
  int pivot = partition_V1(arr, l, r, l);
  p_QuickSort_V1(arr, l, pivot);
  p_QuickSort_V1(arr, pivot + 1, r);
}

template <typename T>
void QuickSort_V1(T arr[],int count) {
  p_QuickSort_V1(arr,0,count - 1);
}

/*
 */
template <typename T>
int partition_V2(T arr[],int l, int r) {
    std::swap(arr[l], arr[rand() % (r - l + 1) + l]); //随机化基准值
    T pivot = arr[l];
    int i = l;
    int j = l;
    int e = l + 1;
    for (; e <= r; e++) {
        if (arr[e] >= pivot) {
            j++;
        }else{
            i++;
            std::swap(arr[i], arr[e]);
        }
    }
    //pivot与i位置交互位置,这样pivot_i就放在了合适的位置上
    std::swap(arr[l], arr[i]);
    return i;
}

template <typename T>
void p_QuickSort_V2(T arr[],int l,int r) {
  if (l >= r) {
    return;
  }
  /*每次选择基准点都是第一个元素，这样不合理，如果是一个近似有序的数组，快速排序会退化成O(N^2)
    所以基准点需要随机选择,如何实现随机选择呢，其实只需要让第一个元素跟任一一个元素交换就可以了
    */
  int pivot = partition_V2(arr, l, r);
  p_QuickSort_V2(arr, l, pivot);
  p_QuickSort_V2(arr, pivot + 1, r);
}

template <typename T>
void QuickSort_V2(T arr[],int count) {
  srand(time(NULL));
  p_QuickSort_V2(arr,0,count - 1);
}


#endif /* QuickSort_h */
