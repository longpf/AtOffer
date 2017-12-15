//
//  main.cpp
//  50__数组中重复的数字
//
//  Created by 龙鹏飞 on 2017/12/15.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 在一个长度为n的数组里的所有数字都在0到n-1的范围内。
 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2
 */

/**
 方法1: 先排序(快,堆),后遍历一遍  时间复杂度O(nlogn)  空间复杂度O(1)
 方法2: 用哈希表存,取 比较  时间O(n) 空间O(n)
 方法3: 遍历数组,假设第i个位置的数字为j,比较下标j的位置数字相同则直接返回,否则交换j到下标为j的位置.下标i之前的数为0到i-1.
        如果第i个位置小于i则直接返回结果
        时间O(n),空间O(1)
 */

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    //        Return value: true if the input is valid, and there are some duplications in the array number
    //         otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == NULL ||length == 0)
            return false;
        int i = 0;
        for (i = 0;i < length;i++)
        {
            if (numbers[i] < 0 || numbers[i] > length - 1)
                return false;
        }
        while (i < length)
        {
            if (numbers[i] == i)
                i++;
            else if (numbers[i] > i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
            else
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int a ;
    int b[] = {2,3,1,0,2,5,3};
    sol.duplicate(b, 7, &a);
    
    return 0;
}
