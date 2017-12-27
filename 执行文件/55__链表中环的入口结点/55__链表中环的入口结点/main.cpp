//
//  main.cpp
//  55__链表中环的入口结点
//
//  Created by 龙鹏飞 on 2017/12/27.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 一个链表中包含环，请找出该链表的环的入口结点
 */

#include <iostream>

/*
 快慢指针,快指针每次走2个节点,慢指针每次走1个节点
 如图 相遇时候 fast走 a+b+c+b
 slow 走 a+b
 那么 2*(a+b) = a+b+c+b ==> a = c
 然后让fast指向head,fast和slow都每次走1个节点
 相遇点就是环的起始点
 */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x),next(NULL){}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;
        ListNode* pSlow = pHead->next;
        ListNode* pFast = pHead->next;
        if (pFast)
            pFast = pFast->next;
        else
            return NULL;
        while (pFast->next && pSlow != pFast)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast)
                pFast = pFast->next;
            else
                break;
        }
        if (pSlow != pFast)
            return NULL;
        pFast = pHead;
        while (pFast != pSlow)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pFast;
    }
};

int main(int argc, const char * argv[]) {
    
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;
    
    Solution sol;
    ListNode* r = sol.EntryNodeOfLoop(n1);
    
    return 0;
}
