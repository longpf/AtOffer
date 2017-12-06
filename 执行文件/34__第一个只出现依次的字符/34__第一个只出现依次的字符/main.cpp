//
//  main.cpp
//  34__第一个只出现依次的字符
//
//  Created by 龙鹏飞 on 2017/12/6.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中
 找到第一个只出现一次的字符,
 并返回它的位置
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //由于字符(char)是一个长度为8的数据类型,因此总共有可能256种可能.
        vector<int> num(256,0);
        int n = (int)str.length();
        if (n == 0)
            return -1;
        for (int i = 0; i < n; i++)
        {
            int c = str[i];
            num[c] ++;
        }
        int res = -1;
        for (int i = 0 ; i < n; i++)
        {
            if (num[str[i]] == 1)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}















