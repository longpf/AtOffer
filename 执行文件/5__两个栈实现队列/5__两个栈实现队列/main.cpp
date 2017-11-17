//
//  main.cpp
//  5__两个栈实现队列
//
//  Created by 龙鹏飞 on 2017/11/8.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;


/*
 用两个栈来实现一个队列，完成队列的Push和Pop操作。
 队列中的元素为int类型。
 */

class Solution
{
public:
    void push(int node){
        stack1.push(node);
    }
    int pop(){
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = -1;
        if (!stack2.empty()) {
            res = stack2.top();
            stack2.pop();
        }
        return res;
    }
    
private:
    stack<int> stack1;
    stack<int> stack2;
};



int main(int argc, const char * argv[]) {
    
    Solution sol;
    sol.push(1);
    sol.push(2);
    
    int a = sol.pop();
    
    return 0;
}
