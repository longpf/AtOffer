//
//  main.cpp
//  26__二叉搜索树与双向链表
//
//  Created by 龙鹏飞 on 2017/11/27.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x),left(NULL),right(NULL){}
};

#pragma mark - 二叉树 前,中,后序排序

//前序递归遍历
vector<int> preVector;
void PreOrder(TreeNode* root)
{
    if (root != NULL)
    {
        preVector.push_back(root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

//前序非递归遍历
void PreOrder2(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* p = root;
    vector<int> result;
    while (p || !s.empty())
    {
        if (p)
        {
            result.push_back(p->val);
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            p = p->right;
            s.pop();
        }
    }
}

//中序递归遍历
vector<int> inResult;
void InOrder(TreeNode* root)
{
    if (root != NULL) {
        InOrder(root->left);
        inResult.push_back(root->val);
        InOrder(root->right);
    }
}

//中序非递归遍历
void InOrder2(TreeNode* root)
{
    stack<TreeNode*> s;
    vector<int> result;
    TreeNode* p = root;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            result.push_back(p->val);
            s.pop();
            p = p->right;
        }
    }
}

//后序递归遍历
vector<int> postResult;
void PostOrder(TreeNode* root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        postResult.push_back(root->val);
    }
}

//后序非递归遍历
void PostOrder2(TreeNode* root)
{
    stack<TreeNode*> s;
    vector<int> result;
    TreeNode* p = root;
    TreeNode* r =new TreeNode(0);
    while (p || !s.empty())
    {
        //走到最左边
        if (p)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            //取栈顶结点
            p  = s.top();
            //如果右子树存在,且未被输出
            if (p->right&&p->right!=r)
            {
                p = p->right;
                s.push(p);
                //在走到最左
                p = p->left;
            }
            //否则,访问栈顶结点并弹出
            else
            {
                result.push_back(p->val);
                //记录该结点
                r = p;
                s.pop();
                //结点访问完后,重置p指针
                p = NULL;
            }
        }
    }
}

#pragma mark - 26

/*
 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 要求不能创建任何新的结点，只能调整树中结点指针的指向
 */

class Solution {
public:
    
    //中序遍历后为排序结果
    void Order(TreeNode* root,vector<TreeNode*>& result)
    {
        if (root != NULL) {
            Order(root->left,result);
            result.push_back(root);
            Order(root->right,result);
        }
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL) {
            return NULL;
        }
        vector<TreeNode*> result;
        Order(pRootOfTree, result);
        TreeNode* tmp;
        for (int i = 0;i < result.size();i++)
        {
            if (i != 0)
            {
                TreeNode* p = result[i];
                tmp->right = p;
                p->left = tmp;
            }
            tmp = result[i];
        }
        return result[0];
    }
    
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    
    TreeNode* node10 = new TreeNode(10);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node14 = new TreeNode(14);
    TreeNode* node12 = new TreeNode(12);
    TreeNode* node16 = new TreeNode(16);
    
    node10->left = node6;
    node10->right = node14;
    node6->left = node4;
    node6->right = node8;
    node14->left = node12;
    node14->right = node16;
    
    TreeNode* result = sol.Convert(node10);
    
    return 0;
}
