//
//  main.cpp
//  9__变态跳台阶
//
//  Created by 龙鹏飞 on 2017/11/13.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int jumpFloorII(int number) {
        // f(n) = 2^(n-1)
        // 1左移(number-1)相当2^(n-1)
        return 1 << (number -1);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int result = sol.jumpFloorII(10);
    
    return 0;
}
