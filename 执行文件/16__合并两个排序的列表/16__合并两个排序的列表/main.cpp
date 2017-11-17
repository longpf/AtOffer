//
//  main.cpp
//  16__合并两个排序的列表
//
//  Created by 龙鹏飞 on 2017/11/16.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 输入两个单调递增的链表，
 输出两个链表合成后的链表，
 当然我们需要合成后的链表满足单调不减规则
 */

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x),next(NULL){
    }
};

class Solution{
public:
    ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        else if (pHead2==NULL)
            return pHead1;
        ListNode* newHead = NULL;
        if (pHead1->val<pHead2->val)
        {
            newHead = pHead1;
            newHead->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            newHead = pHead2;
            newHead->next = Merge(pHead1, pHead2->next);
        }
        return newHead;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
