//
//  main.cpp
//  56__删除链表中重复的结点
//
//  Created by 龙鹏飞 on 2017/12/27.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x),next(NULL){}
};

class Solution
{
public:
    ListNode* deleteDuplication(ListNode*& pHead)
    {
        if (pHead == NULL)
            return NULL;
        ListNode* pre = NULL;
        ListNode* p = pHead;
        while (p != NULL && p->next != NULL)
        {
            if (p->val == p->next->val)
            {
                int key = p->val;
                while (p != NULL && p->val == key)
                {
                    ListNode* pToDelete = p;
                    p = p->next;
                    delete pToDelete;
                    pToDelete = NULL;
                }
                
                if (pre == NULL)
                    pHead = p;
                else
                    pre->next = p;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        return pHead;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
