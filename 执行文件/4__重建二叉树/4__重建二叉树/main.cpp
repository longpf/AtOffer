//
//  main.cpp
//  4__重建二叉树
//
//  Created by 龙鹏飞 on 2017/11/7.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>
#include <vector>

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};

class Solution {
    
public:
    TreeNode* reConstructBinaryTree(vector<int>pre,vector<int>vin)
    {
        if (pre.size()==0 || vin.size()==0) {
            return NULL;
        }
        return constructTree(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
    TreeNode* constructTree(const vector<int>& pre,long s1,long e1,const vector<int>& vin,long s2,long e2)
    {
        long i;
        for (i=s2; i<=e2; i++) {
            if (pre[s1]==vin[i])
                break;
        }
        if (i > e2)
            return NULL;
        TreeNode* head = new TreeNode(pre[s1]);
        head->left = constructTree(pre, s1+1, s1+i-s2, vin, s2, i-1); //s1+i-s2,i-s2是左子树的个数.前序是根左右,根后面是左子树的集合.
        head->right = constructTree(pre, s1+i-s2+1, e1, vin, i+1, e2);
        return head;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>pre = {1,2,4,7,3,5,6,8};
    vector<int>vin = {4,7,2,1,5,3,8,6};
    Solution sol;
    TreeNode* head = sol.reConstructBinaryTree(pre, vin);
    return 0;
}


