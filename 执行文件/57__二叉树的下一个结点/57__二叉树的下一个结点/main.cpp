//
//  main.cpp
//  57__二叉树的下一个结点
//
//  Created by 龙鹏飞 on 2017/12/27.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针
 */

/*
 分三种情况:
 1. 如果一个结点有右子树,那么它的下一个结点就是它的右子树的最左结点 b->h
 2. 如果一个结点没有右子树,如果它是其父亲的左子结点,那么它下一个结点为它的父亲结点 d->b,f->c
 3. 如果一个结点既没有右子树,也不是父亲的左子树.那么沿着指向父亲结点的指针一直向上遍历.
    直到找到一个结点,它的其父亲结点的左子结点,那么它的父亲结点就是下一个结点.
    i->e->b->a
    g->c->a a为根节点,所以g的下一个结点不存在
 */

#include <iostream>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x):
        val(x),left(NULL),right(NULL),next(NULL){}
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
            return NULL;
        if (pNode->right)
        {
            pNode = pNode->right;
            while (pNode->left)
            {
                pNode = pNode->left;
            }
            return pNode;
        }
        TreeLinkNode* pParent = pNode->next;
        while (pParent != NULL && pParent->right == pNode)
        {
            pNode = pParent;
            pParent = pParent->next;
        }
        return pParent;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
