//
//  main.cpp
//  25__复杂链表的复制
//
//  Created by 龙鹏飞 on 2017/11/24.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>

/*
 输入一个复杂链表
 （每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
 返回结果为复制后复杂链表的head。
 （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 */

#include <map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode* next,* random;
    RandomListNode(int x):
        label(x),next(NULL),random(NULL){
    }
};

/*
 方法1:
 复制原始链表上的每个节点N创建N',然后把这些创建出来的结点用next连接起来,
 A-->B-->C-->D
 A'->B'->C'->D'.
 同时把<N,N'>的配对信息放一个哈希表中.
 然后设置复制链表中的每个结点的random指针,如果原始列表中的N的random指向的结点为S,
 那么在赋值链表中,对应的N'应该指向S'.
 时间复杂度: O(N)
 */

typedef map<RandomListNode*,RandomListNode*> MAP;

class Solution1 {
public:
    
    RandomListNode* CloneNodes(RandomListNode* pHead,MAP &hashNode)
    {
        RandomListNode* pNode = new RandomListNode(0);
        RandomListNode* p = pNode;
        RandomListNode* tmp;
        while (pHead != NULL) {
            tmp = new RandomListNode(0);
            tmp->label = pHead->label;
            p->next = tmp;
            hashNode[pHead] = tmp;
            pHead = pHead->next;
            p=p->next; //就是当前的tmp
        }
        return pNode->next;
    }
    
    void setRandomNodes(RandomListNode* pHead,RandomListNode* pCopy,MAP &hashNode)
    {
        while (pCopy!=NULL) {
            pCopy->random = hashNode[pHead->random];
            pCopy = pCopy->next;
            pHead = pHead->next;
        }
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* pCopy;
        MAP hashNode;
        pCopy = CloneNodes(pHead, hashNode);
        setRandomNodes(pHead, pCopy, hashNode);
        return pCopy;
    }
};

/*
 方法2
 在不使用辅助空间的情况下实现O(N)的时间效率
 第一步：根据原始链表的每个结点N创建对应的N',然后将N‘通过pNext接到N的后面
 第二步：设置复制出来的结点的random,假设原始链表上的N的random指向结点S,那么其对应复制出来的N'是N->pNext指向的结点,同样S'也是结点S->pNext指向的结点
 第三步：把长链表拆分成两个链表,把奇数位置的结点用pNext连接起来的就是原始链表,把偶数位置的结点通过pNext连接起来的就是复制链表
 */

class Solution2{
    
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloned;
        while (pNode!=NULL) {
            pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }
    
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloned;
        while (pNode!=NULL) {
            pCloned = pNode->next;
            if (pNode->random!=NULL) {
                pCloned->random = pNode->random->next;
            }
            pNode=pCloned->next;
        }
    }
    
    RandomListNode* ReconnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = NULL;
        RandomListNode* pClonedNode = NULL;
        if (pNode!=NULL) {
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        while (pNode!=NULL) {
            pClonedNode->next=pNode->next;
            pClonedNode=pClonedNode->next;
            pNode->next=pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReconnectNodes(pHead);
    }
};


int main(int argc, const char * argv[]) {
    return 0;
}












