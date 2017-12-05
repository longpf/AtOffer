//
//  main.cpp
//  32__把数组排成最小的数
//
//  Created by 龙鹏飞 on 2017/12/5.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 打印能拼接出的所有数字中最小的一个。
 例如输入数组{3，32，321}，
 则打印出这三个数字能排成的最小数字为321323
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers)
    {
        vector<string> strNum;
        for (int i = 0; i < numbers.size(); i++)
        {
            string s = to_string(numbers[i]);
            strNum.push_back(s);
        }
        sort(strNum.begin(), strNum.end(), cmp);
        string res = "";
        for (int i = 0;i < strNum.size();i++)
            res += strNum[i];
        return res;;
    }
    
    static bool cmp(const string s1,const string s2)
    {
        string num1 = s1 + s2;
        string num2 = s2 + s1;
        return num1 < num2;
    }
};

int main(int argc, const char * argv[]) {

    return 0;
}
