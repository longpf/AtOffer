//
//  main.cpp
//  38__二叉树的深度
//
//  Created by 龙鹏飞 on 2017/12/11.
//  Copyright © 2017年 longpf. All rights reserved.
//


/**
 输入一棵二叉树，求该树的深度。
 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
 最长路径的长度为树的深度
 */

#include <algorithm>
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
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;
        int left = 0;
        int right = 0;
        if (pRoot->left)
            left = TreeDepth(pRoot->left);
        if (pRoot->right)
            right = TreeDepth(pRoot->right);
        return 1 + max(left, right);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
