//
//  main.cpp
//  17__树的子结构
//
//  Created by 龙鹏飞 on 2017/11/17.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 输入两棵二叉树A，B，判断B是不是A的子结构。
 （ps：我们约定空树不是任意一个树的子结构）
 */

/*
 step1: 在树A中找到和B的根结点一样的结点R
 step2: 判断树A中以R为根结点的子树是不是包含和树B一样的结构
 这是一个递归的过程
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;
        bool res = false;
        if (pRoot1->val == pRoot2->val)
            return IsSubtree(pRoot1, pRoot2);
        if (!res)
            res = HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        return res;
    }
    
    bool IsSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if (pRoot2 == NULL)
            return true;
        if (pRoot1 == NULL)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
