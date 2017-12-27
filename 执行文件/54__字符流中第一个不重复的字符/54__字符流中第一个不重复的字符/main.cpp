//
//  main.cpp
//  54__字符流中第一个不重复的字符
//
//  Created by 龙鹏飞 on 2017/12/26.
//  Copyright © 2017年 longpf. All rights reserved.
//


/**
 请实现一个函数用来找出字符流中第一个只出现一次的字符。
 例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
 当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"
 输入描述：如果当前字符流没有存在出现一次的字符，返回#字符
 */

#include <string>
#include <vector>

using namespace std;

class Solution1
{
public:
    string str;
    //Insert one char from stringstream
    void Insert(char ch)
    {
        str += string(1,ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        vector<int> hash(256,0); //char长度为8,所以256中可能
        char res = '#';
        int n = (int)str.length();
        for (int i = 0;i < n;i++)
        {
            if (hash[str[i]] == 0)
                hash[str[i]] = 1;
            else
                hash[str[i]] = -1;
        }
        for (int i = 0; i < n;i++)
        {
            if (hash[str[i]]==1)
            {
                res = str[i];
                break;
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    
    
    return 0;
}
