//
//  main.cpp
//  39__平衡二叉树
//
//  Created by 龙鹏飞 on 2017/12/11.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 输入一棵二叉树，判断该二叉树是否是平衡二叉树
 */

#include <iostream>

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
    bool IsBalanced_Solution(TreeNode* pRoot){
        if (pRoot == NULL)
            return true;
        int depth = 0;
        return Balance(pRoot, depth);
    }
    
    //后序遍历保证每个结点只被遍历一次
    bool Balance(TreeNode* pRoot,int& depth)
    {
        if (pRoot == NULL)
            return true;
        int left = 0,right = 0;
        if (Balance(pRoot->left, left) && Balance(pRoot->right, right))
        {
            int dif = left - right;
            if (dif >= -1 && dif <= 1)
            {
                depth = left > right ? left + 1 : right + 1;
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
