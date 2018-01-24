//
//  main.cpp
//  49__把字符串转换成整数
//
//  Created by 龙鹏飞 on 2017/12/15.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
 数值为0或者字符串不是一个合法的数值则返回0
 输入描述：输入一个字符串,包括数字字母符号,可以为空
 输出描述：如果是合法的数值表达则返回该数字，否则返回0
 */

#include <string>

using namespace std;

class Solution
{
public:
    int StrToInt(string str)
    {
        int length = (int)str.length();
        if (length == 0)
            return 0;
        int res = 0;
        bool flag = false;
        for (int i = 0; i < length; i++)
        {
            if (i == 0 && str[i] == '-')
                flag = true;
            else if (i == 0 && str[i]== '+')
                continue;
            else if (str[i] >= '0' && str[i] <= '9')
            {
                res = res*10+str[i]-'0';
                if ((!flag && res > 0x7FFFFFFF)||(flag && -res < 0x80000000))
                    return 0;
            }
            else
                return 0;
        }
        if (flag)
            res *= -1;
        return res;
    }
    
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int r = sol.StrToInt("-123");
    
    return 0;
}
