//
//  ReversePair.h
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/28.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#ifndef ReversePair_h
#define ReversePair_h

#include "MergeSort.h"

/*
    利用Merge Sort的思想求解一个数组n的“逆序对”，最基本的算法穷尽所有可能的对，那么算法的复杂度是O(n^2),利用Merge Sort合并操作，可以用O(nlogn)计算出“逆序对”
 */

template <typename T>
int p_getReversePaitCount(T arr[],int l,int r){
    if (r - l < 2) {
        return 0;
    }else if( r- l == 2){
        if (arr[r] > arr[l]) {
            return 1;
        }else{
            return 0;
        }
    }else{
        int l_count = p_getReversePaitCount(arr,l, (l+r)/2);
        int r_count = p_getReversePaitCount(arr,(l+r)/2,r);
        return l_count + r_count;
    }
}

template <typename T>
int getReversePairCount(T arr[],int count) {
    return p_getReversePaitCount(arr,0,count - 1);
}


#endif /* ReversePair_h */
