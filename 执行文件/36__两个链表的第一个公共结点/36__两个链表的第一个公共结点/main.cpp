//
//  main.cpp
//  36__两个链表的第一个公共结点
//
//  Created by 龙鹏飞 on 2017/12/11.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 输入两个链表，找出它们的第一个公共结点
 */

/*
 因为每个节点只有一个next结点,所以如果有公共结点,那从改结点后都为相同结点
 呈现为Y形状
 */

#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
    val(x),next(NULL) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2)
    {
        if (pHead1 == NULL || pHead2 == NULL) {
            return NULL;
        }
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);
        int dist = 0;
        ListNode* pLong = NULL;
        ListNode* pShort = NULL;
        if (len1 > len2) {
            pLong = pHead1;
            pShort = pHead2;
            dist = len1 - len2;
        }
        else
        {
            pLong = pHead2;
            pShort = pHead1;
            dist = len2 - len1;
        }
        for (int i = 0; i<dist;i++)
        {
            pLong = pLong->next;
        }
        while (pLong)
        {
            if (pLong->val==pShort->val) {
                return pLong;
            }
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return NULL;
    }
    
    int getLength(ListNode* head)
    {
        ListNode* p = head;
        int count = 0;
        while (p) {
            count ++;
            p = p->next;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
