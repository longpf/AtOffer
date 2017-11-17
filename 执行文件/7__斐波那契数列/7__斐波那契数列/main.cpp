//
//  main.cpp
//  7__斐波那契数列
//
//  Created by 龙鹏飞 on 2017/11/13.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
 */

class Solution{
public:
    int Fibonacci(int n){
        if (n<2)
            return n;
        int a = 0,b = 1;
        int c = 0;
        for (int i = 2; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int reuslt = sol.Fibonacci(5);
    
    return 0;
}
