//
//  main.cpp
//  52_正则表达式匹配
//
//  Created by 龙鹏飞 on 2017/12/20.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 请实现一个函数用来匹配包括'.'和'*'的正则表达式。
 模式中的字符'.'表示任意一个字符，
 而'*'表示它前面的字符可以出现任意次（包含0次）。
 在本题中，匹配是指字符串的所有字符匹配整个模式。
 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 */

/*
 如果模式串此时是'.',那么只需要模式串匹配串都往后移动一个位置
 如果现在这位的字符能匹配且模式串的下一位是'*',我们则需要分情况讨论
 1. 匹配串往后移动1位,模式串跳过'*'
 2. 匹配串往后移动1位,模式串不动
 3. 匹配串不动,模式串跳过'*'
 */

#include <iostream>

class Solution {
public:
    bool match(char* str,char* pattern)
    {
        if (str == NULL || pattern == NULL)
            return false;
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        
        if (*(pattern+1)=='*')
        {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                return match(str+1, pattern+2)||match(str+1, pattern)||match(str, pattern+2);
            return match(str, pattern+2);
        }
        if (*str==*pattern || (*pattern=='.' && *str!='\0'))
            return match(str+1, pattern+1);
        return false;
    }
};





int main(int argc, const char * argv[]) {
    
    Solution sol;
    sol.match("", ".*");
    
    return 0;
}
