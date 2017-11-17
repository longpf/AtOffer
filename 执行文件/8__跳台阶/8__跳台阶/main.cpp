//
//  main.cpp
//  8__跳台阶
//
//  Created by 龙鹏飞 on 2017/11/13.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 求该青蛙跳上一个n级的台阶总共有多少种跳法
 */

/*
 如果n级为f(n)
 当n>2时,如果第一次跳一级,则剩下的n-1为f(n-1)
 如果第一次跳两级,则剩下的为f(n-2)
 则f(n)=f(n-1)+f(n-2)
 */

class Solution{
public:
    int jumpFloor(int number){
        if (number==1)
            return 1;
        else if (number==2)
            return 2;
        int a = 1,b = 2,c = 3;
        for (int i = 3; i <=number; i++) {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    int result = sol.jumpFloor(10);
    return 0;
}
