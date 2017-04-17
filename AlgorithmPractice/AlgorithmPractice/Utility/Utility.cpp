//
//  Utility.hpp
//  AlgorithmPractice
//
//  Created by 王泽一 on 2017/4/17.
//  Copyright © 2017年 jimmyzywang. All rights reserved.
//

#include "Utility.hpp"
#include <random>
#include <cassert>
#include <iostream>

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
    
    void PrintArray(int array[],size_t count){
        std::cout << "PrintArray: " << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << array[i] << " ";
        }
    }
}
