//
//  main.cpp
//  18__二叉树的镜像
//
//  Created by 龙鹏飞 on 2017/11/17.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 操作给定的二叉树，将其变换为源二叉树的镜像
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){};
};

class Solution {
public:
    void Mirror(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return;
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        if (pRoot->left)
            Mirror(pRoot->left);
        if (pRoot->right)
            Mirror(pRoot->right);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
