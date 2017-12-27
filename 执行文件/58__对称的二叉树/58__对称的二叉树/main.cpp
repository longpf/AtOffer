//
//  main.cpp
//  58__对称的二叉树
//
//  Created by 龙鹏飞 on 2017/12/27.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 请实现一个函数，用来判断一颗二叉树是不是对称的。
 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的
 */

#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){}
};


/*
 从根结点开始遍历
 如果左右有一个为NULL,那么可定不是对称二叉树
 如果左右子结点都不为空,但不相等,那么不是堆成二叉树
 如果左右子结点都不为空,但不相等,那么
 遍历左子树,遍历顺序为: 当前结点,左子树,右子树
 遍历右子树,遍历顺序为: 当前结点,右子树,左子树
 如果遍历左子树的序列和遍历右子树的序列一样,那么该二叉树为对称的二叉树
 */

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return true;
        return isSym(pRoot, pRoot);
    }
    bool isSym(TreeNode* pLeft,TreeNode* pRight)
    {
        if (pLeft == NULL && pRight == NULL)
            return true;
        if (pLeft == NULL || pRight == NULL)
            return false;
        if (pLeft->val != pRight->val)
            return false;
        return isSym(pLeft->left, pRight->right) && isSym(pLeft->right, pRight->left);
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
