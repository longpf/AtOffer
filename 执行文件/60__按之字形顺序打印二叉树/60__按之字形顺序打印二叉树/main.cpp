//
//  main.cpp
//  60__按之字形顺序打印二叉树
//
//  Created by 龙鹏飞 on 2017/12/28.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 请实现一个函数按照之字形打印二叉树，
 即第一行按照从左到右的顺序打印，
 第二层按照从右至左的顺序打印，
 第三行按照从左到右的顺序打印，
 其他行以此类推
 */

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){};
};

class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot)
    {
        vector<vector<int>> res;
        if (pRoot == NULL)
            return res;
        vector<int> numbers;
        stack<TreeNode*> odd,even; //奇偶栈
        odd.push(pRoot);
        while (!odd.empty() || !even.empty())
        {
            while (!odd.empty())
            {
                TreeNode* pNode = odd.top();
                numbers.push_back(pNode->val);
                //为下一层的偶数栈存数据
                if (pNode->left)
                    even.push(pNode->left);
                if (pNode->right)
                    even.push(pNode->right);
                odd.pop();
            }
            if (numbers.size() > 0)
            {
                res.push_back(numbers);
                numbers.clear();
            }
            while (!even.empty())
            {
                TreeNode* pNode = even.top();
                numbers.push_back(pNode->val);
                //为下一层的奇数栈存数据
                if (pNode->right)
                    odd.push(pNode->right);
                if (pNode->left)
                    odd.push(pNode->left);
                even.pop();
            }
            if (numbers.size()>0)
            {
                res.push_back(numbers);
                numbers.clear();
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
