//
//  main.cpp
//  46__圆圈中最后剩下的数字
//
//  Created by 龙鹏飞 on 2017/12/13.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 0,1,...,n-1这n个数字排成一个圆圈,从数字0开始每次从这个圆圈里删除第m个数字.
 求出这个圆圈里剩下的最后一个数字
 */

#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;
        list<int> numbers;
        int i = 0;
        for (;i < n;i++)
            numbers.push_back(i);
        list<int>::iterator iter = numbers.begin();
        while (numbers.size() > 1)
        {
            for (i = 1; i < m ;i++)
            {
                iter++;
                if (iter == numbers.end())
                    iter = numbers.begin();
            }
            
            list<int>::iterator next = ++iter;
            --iter;
            numbers.erase(iter);
            iter = next;
            if (iter == numbers.end())
                iter = numbers.begin();
        }
        return *iter;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    
    int r = sol.LastRemaining_Solution(5, 3);
    
    return 0;
}
