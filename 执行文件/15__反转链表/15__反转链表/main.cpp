//
//  main.cpp
//  15__反转链表
//
//  Created by 龙鹏飞 on 2017/11/16.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 输入一个链表，反转链表后，输出链表的所有元素
 */

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x):
    val(x),next(NULL){
    }
};

class Solution{
public:
    ListNode* ReverseList(ListNode* pHead){
        ListNode* pre = NULL;
        ListNode* p = pHead;
        ListNode* pn = NULL;
        
        while (p) {
            pn = p->next;
            p->next = pre;
            pre = p;
            p = pn;
        }
        return pre;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
