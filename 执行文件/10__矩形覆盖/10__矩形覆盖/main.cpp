//
//  main.cpp
//  10__矩形覆盖
//
//  Created by 龙鹏飞 on 2017/11/13.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int rectCover(int number) {
        if(number <= 2)
            return number;
        int a = 1, b = 2;
        int c = 3;
        for(int i=3; i<=number; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int result = sol.rectCover(10);
    return 0;
}
