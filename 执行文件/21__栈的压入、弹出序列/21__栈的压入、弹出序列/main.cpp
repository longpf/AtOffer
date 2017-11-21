//
//  main.cpp
//  21__栈的压入、弹出序列
//
//  Created by 龙鹏飞 on 2017/11/21.
//  Copyright © 2017年 longpf. All rights reserved.
//


/*
 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 假设压入栈的所有数字均不相等。
 例如序列 1,2,3,4,5 是某栈的压入顺序，
 序列 4，5,3,2,1 是该压栈序列对应的一个弹出序列，
 但 4,3,5,1,2 就不可能是该压栈序列的弹出序列。
 （注意：这两个序列的长度是相等的）
 */


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        stack<int> st;
        
        for (int i = 0,j=0; i < pushV.size(); )
        {
            st.push(pushV[i++]);
            while (j<popV.size() && st.top()==popV[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,3,5,1,2};
    
    Solution sol;
    bool r = sol.IsPopOrder(pushV, popV);
    
    return 0;
}
