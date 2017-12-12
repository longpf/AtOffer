//
//  main.cpp
//  44__左旋转字符串
//
//  Created by 龙鹏飞 on 2017/12/12.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 汇编语言中有一种移位指令叫做循环左移（ROL），
 现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
 是不是很简单？OK，搞定它！
 */

/*
 例:'helloworld' => 'worldhello'
 可以先翻转前一部分,再翻转后一部分,最后在翻转整个字符串即可
 1. 'ollehworld'
 2. 'ollehdlrow'
 3. 'worldhello'
 */

#include <string>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n)
    {
        int length = (int)str.length();
        if (length == 0 || n < 0)
            return str;
        n %= length;
        
        Reverse(str, 0, n-1);
        Reverse(str, n, length-1);
        Reverse(str, 0, length-1);
        return str;
    }
    
    void Reverse(string& str,int start,int end)
    {
        while (start < end)
        {
            char tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
            start ++;
            end --;
        }
    }
};


#include <iostream>

int main(int argc, const char * argv[]) {
    
    return 0;
}
