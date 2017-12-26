//
//  main.cpp
//  53__表示数值的字符串
//
//  Created by 龙鹏飞 on 2017/12/20.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == NULL || *string == '\0')
            return false;
        if (*string == '+' || *string == '-')
            string ++;
        if (*string == '\0')
            return false;
        scanDigit(string);
        if (*string != '\0')
        {
            if (*string == '.')
            {
                string++;
                scanDigit(string);
                if (*string == 'e' || *string == 'E')
                    return isExponent(string);
            }
            else if (*string == 'e' || *string == 'E')
                return isExponent(string);
            else
                return false;
        }
        return *string == '\0' ? true : false;
    }
    
    void scanDigit(char*& str)
    {
        while (*str != '\0' && *str >= '0' && *str <= '9')
            str++;
    }
    
    bool isExponent(char*& str)
    {
        if (*str != 'e' && *str != 'E')
            return false;
        str++;
        if (*str=='+' || *str=='-')
            str++;
        if (*str == '\0')
            return false;
        scanDigit(str);
        return *str == '\0' ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    
    char str[] = "5e2";
    Solution sol;
    bool b = sol.isNumeric(str);
    
    return 0;
}
