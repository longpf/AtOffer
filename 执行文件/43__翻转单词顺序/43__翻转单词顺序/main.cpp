//
//  main.cpp
//  43__翻转单词顺序
//
//  Created by 龙鹏飞 on 2017/12/12.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
 Cat对一一的翻转这些单词顺序可不在行，你能帮助他么
 */

#include <string>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int length = (int)str.length();
        if (length == 0)
            return str;
        Reverse(str, 0, length-1);
        int start = 0;
        int end = 0;
        for (int i = 0;i < length;i++)
        {
            if (str[i] == ' ')
            {
                end = i - 1;
                Reverse(str, start, end);
                start = i + 1;
            }
            if (i == length -1)
            {
                end = i;
                Reverse(str, start, end);
            }
        }
        return str;
    }
    
    void Reverse(string& str,int start,int end)
    {
        while (start < end)
        {
            char tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
            start++;
            end --;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    string s = "student. a am I";
    Solution sol;
    sol.ReverseSentence(s);
    
    return 0;
}
