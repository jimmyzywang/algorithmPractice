//
//  Utility.hpp
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/17.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#ifndef UTILITY_hpp
#define UTILITY_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <random>
#include <cassert>

namespace Utility{
    int* GenerateRamdonArray(int count,int rangeL,int rangeR){
        assert(rangeL < rangeR);
        int* arr = new int[count];
        srand(time(NULL));
        for (int i = 0; i < count; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    
    int* GenerateNearlyOrderArray(int count,int changeCount){
        int* arr = new int[count];
        for (int index = 0; index < count; index++) {
            arr[index] = index;
        }
        srand(time(NULL));
        for (int index = 0; index < changeCount; index++) {
            int index1 = rand() % count;
            int index2 = rand() % count;
            std::swap(arr[index1], arr[index2]);
        }
        return arr;
    }
    
    template<typename T>
    int* CopyArray(T array[],int count){
        int* arr = new int[count];
        std::copy(array, array + count, arr);
        return arr;
    }
    
    
    //打印arr的每一个元素
    template<typename T>
    void PrintArray(T array[],int count){
        std::cout << "PrintArray: start:";
        for (int i = 0; i < count; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
    
    //测试arr是否被正确排序
    template<typename T>
    bool isSorted(T arr[],int count){
        for (int i = 0; i < count - 1; i++) { //这里循环到count - 1 而不是count，是因为i+1会越界
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    //测试排序的时间
    template<typename T>
    void TestSort(const std::string& sortName,void(*sort)(T[],int),T arr[],int count,bool printResultIfSuceess = false){
        clock_t start_time = clock();
        sort(arr,count);
        clock_t end_time = clock();
        if (!isSorted(arr, count)) {
            std::cout << "TestSort not pass" << std::endl;
            PrintArray(arr, count);
        }
        assert(isSorted(arr, count));
        std::cout << std::endl << sortName <<" Time:" << double(end_time - start_time) / CLOCKS_PER_SEC << "s" << std::endl;
    }
    

}


#endif /* Utility.hpp */
