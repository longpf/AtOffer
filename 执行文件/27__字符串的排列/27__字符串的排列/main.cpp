//
//  main.cpp
//  27__字符串的排列
//
//  Created by 龙鹏飞 on 2017/11/27.
//  Copyright © 2017年 longpf. All rights reserved.
//



/*
 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 输入描述:  输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    void Permutation2(string& str,int k,int n,vector<string>& res)
    {
        if (k==n) {
            res.push_back(str);
            return;
        }
        for (int i = k; i < n; i++) {
            if (str[i] == str[k] && i != k)
                continue;
            swap(str[k], str[i]);
            Permutation2(str, k+1, n, res);
            swap(str[k], str[i]);
        }
    }
    
    vector<string> Permutation(string str){
        vector<string> res;
        int n = str.length();
        if (n == 0)
            return res;
        Permutation2(str, 0, n, res);
        sort(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    
    string str = "abcde";
    
    vector<string>r = sol.Permutation(str);
    
    return 0;
}
