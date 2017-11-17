//
//  main.cpp
//  13__调整数组顺序使奇数位于偶数前面
//
//  Created by 龙鹏飞 on 2017/11/15.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
 并保证奇数和奇数，偶数和偶数之间的相对位置不变
 */

class Solution{
public:
    void reOrderArray(vector<int>array){
        int n = (int)array.size();
        if(n <= 1)
            return;
        vector<int>tmp;
        for (int i = 0; i<n; i++) {
            //奇数
            if (array[i] & 0x1) {
                tmp.push_back(array[i]);
            }
        }
        for (int i = 0; i<n; i++) {
            //偶数
            if ((array[i] & 0x1)==0) {
                tmp.push_back(array[i]);
            }
        }
        array = tmp;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution sol;
    
    vector<int>array = {1,2,3,4,5,6,7,8,9};
    sol.reOrderArray(array);
    
    return 0;
}
