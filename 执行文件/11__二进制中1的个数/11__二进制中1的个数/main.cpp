//
//  main.cpp
//  11__二进制中1的个数
//
//  Created by 龙鹏飞 on 2017/11/14.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
 */


//解法1
class Solution1{
public:
    int NumberOf1(int n){
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            //将类似0001,0010,0100,...(应该为32位)和n做位与运算,如果不为0,则n的该位为1
            if (n & flag) {
                count ++;
            }
            //32位的整数要循环32次,
            //当左移后超出32位则1存在寄存器进位器中,剩下部分为0,跳出循环
            flag = flag << 1;
        }
        return count;
    }
};

//解法2: 1100,减1后为1011,1100和1011做与运算为1000,相当将最右边的1取反为0.
class Solution2{
public:
    int NumberOf1(int n){
        int count = 0;
        while (n) {
            count++;
            n = (n-1) & n;
        }
        return count;
    }
};



int main(int argc, const char * argv[]) {
    
//    Solution1 sol1;
//    int result = sol1.NumberOf1(1);
    
    return 0;
}
