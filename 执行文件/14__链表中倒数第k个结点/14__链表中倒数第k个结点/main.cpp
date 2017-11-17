//
//  main.cpp
//  14__链表中倒数第k个结点
//
//  Created by 龙鹏飞 on 2017/11/16.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):
    val(x),next(NULL){
    }
};

class Solution{
public:
    ListNode* FindKthToTail(ListNode* pListHead,unsigned int k){
        if (pListHead == NULL || k == 0)
        {
            return NULL;
        }
        ListNode* pFast = pListHead;
        ListNode* pSlow = pListHead;
        for (unsigned int i = 0; i < k-1; i++)
        {
            if (pFast->next==NULL)
            {
                return NULL;
            }
            pFast = pFast->next;
        }
        while (pFast->next!=NULL)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pSlow;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
