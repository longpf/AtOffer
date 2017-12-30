//
//  main.cpp
//  62__二叉搜索树的第k个结点
//
//  Created by 龙鹏飞 on 2017/12/28.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 给定一颗二叉搜索树，请找出其中的第k大的结点。
 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4
 */

/*
 二叉搜索树的特点是左子结点小于根结点,根几点小于右子结点
 所以进行一次中序查找即可
 */

#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot,int k)
    {
        if (pRoot == NULL || k <= 0)
        {
            return NULL;
        }
        return KthNodeCore(pRoot, k);
    }
    TreeNode* KthNodeCore(TreeNode* pRoot,int& k)
    {
        if (pRoot == NULL || k <=0)
            return NULL;
        TreeNode* res = NULL;
        if (pRoot->left != NULL)
            res = KthNodeCore(pRoot->left, k);
        if (res == NULL)
        {
            if (k == 1)
            {
                res = pRoot;
                return res;
            }
            k --;
        }
        //res!=NULL时候则找到了结果
        if (res == NULL && pRoot->right != NULL)
            res = KthNodeCore(pRoot->right, k);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);
    
    n4->left = n2;
    n4->right = n6;
    n2->left = n1;
    n2->right = n3;
    n6->left = n5;
    n6->right = n7;
    
    Solution sol;
    TreeNode* r = sol.KthNode(n4, 5);
    
    
    return 0;
}
