//
//  main.cpp
//  22__从上到下打印二叉树
//
//  Created by 龙鹏飞 on 2017/11/22.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印
 */

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){
            
        }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        vector<int> result;
        if (root==NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode* node = q.front();
            result.push_back(node->val);
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
