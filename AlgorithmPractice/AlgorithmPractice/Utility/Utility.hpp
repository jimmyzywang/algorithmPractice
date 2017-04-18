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
    int* GenerateRamdonArray(size_t count,size_t rangeL,size_t rangeR){
        assert(rangeL < rangeR);
        int* arr = new int[count];
        srand(time(NULL));
        for (int i = 0; i < count; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    
    //打印arr的每一个元素
    template<typename T>
    void PrintArray(T array[],size_t count){
        std::cout << "PrintArray: start" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl << "PrintArray end " << std::endl;
    }
    
    //测试arr是否被正确排序
    template<typename T>
    bool isSorted(T arr[],size_t count){
        for (int i = 0; i < count - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    //测试排序的时间
    template<typename T>
    void TestSortTime(const std::string& sortName,void(*sort)(T[],size_t),T arr[],size_t count){
        clock_t start_time = clock();
        sort(arr,count);
        clock_t end_time = clock();
        assert(isSorted(arr, count));
        std::cout << "Time:" << sortName << (end_time - start_time) / CLOCKS_PER_SEC << "s";
    }
    

}


#endif /* Utility.hpp */
