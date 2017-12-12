//
//  main.cpp
//  41__和为S的两个数字
//
//  Created by 龙鹏飞 on 2017/12/12.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
 如果有多对数字的和等于S，输出两个数的乘积最小的。
 输出描述：对应每个测试案例，输出两个数，小的先输出
 */

/*
 两个指针从数组两侧遍历相加比较
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum)
    {
        int n = (int)array.size();
        if (n == 0 || n < 2)
            return vector<int>();
        vector<int> res;
        int small = 0,big = n - 1;
        while (small < big)
        {
            int curSum = array[small] + array[big];
            if (curSum == sum)
            {
                res.push_back(array[small]);
                res.push_back(array[big]);
                break;
            }
            else if (curSum > sum)
                big --;
            else
                small ++;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
