//
//  main.cpp
//  20__包含min函数的栈
//
//  Created by 龙鹏飞 on 2017/11/21.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <stack>
using namespace std;

class Solution {
private:
    stack<int> s1,s2;
public:
    void push(int value) {
        if (s1.size()>0 && s1.top()<value)
        {
            s2.push(s1.top());
        }
        else
        {
            s2.push(value);
        }
        s1.push(value);
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
