//
//  main.cpp
//  48__不用加减乘除做加法
//
//  Created by 龙鹏飞 on 2017/12/15.
//  Copyright © 2017年 longpf. All rights reserved.
//


/*
 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号
 */

/*
 对于数字除了四则运算只能用位运算了
 两个整数之和可分解两个数相加(不带进位)+进位,5+17=5+7+10=2+10(进位)+10=22
 二进制不带进位的相加可看做异或
 进位可用与运算的结果左移一位表示
 */


class Solution
{
public:
    int Add(int num1,int num2)
    {
        int sum,carray;
        do
        {
            sum = num1 ^ num2;
            carray = (num1 & num2) << 1;
            
            num1 = sum;
            num2 = carray;
        }while (carray);
        return sum;
    }
};


int main(int argc, const char * argv[]) {
    
    return 0;
}
