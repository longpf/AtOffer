//
//  main.cpp
//  12__数值的整数次方
//
//  Created by 龙鹏飞 on 2017/11/14.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 给定一个double类型的浮点数base和int类型的整数exponent。
 求base的exponent次方。
 */

class Solution{
public:
    double Power(double base,int exponent)
    {
        if (equal(base, 0.0) && exponent < 0) {
            return 0.0;
        }
        unsigned int absExponent = abs(exponent);
        double result = PowerWithUnsignedExponent(base, absExponent);
        if (exponent<0) {
            result = 1.0/result;
        }
        return result;
    }
    
    bool equal(double num1,double num2)
    {
        if (num1-num2 < 0.0000001 && num1-num2 > -0.0000001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    double PowerWithUnsignedExponent(double base,unsigned int exponent)
    {
        if (exponent==0) {
            return 1;
        }
        else if (exponent==1)
        {
            return base;
        }
        double result = PowerWithUnsignedExponent(base,exponent>>1);
        result *= result;
        //判断奇偶 位运算判断奇偶比取余效率高
        if((exponent & 0x1) == 1)
        {
            result *= base;
        }
        return result;
    }
};



int main(int argc, const char * argv[]) {
    Solution sol;
    int b = sol.Power(2, 6);
    return 0;
}
