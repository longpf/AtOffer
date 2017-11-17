#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    vector<int>printListFromTail(struct ListNode* head){
        vector<int> result;
        stack<struct ListNode*>nodes;
        struct ListNode *pNode = head;
        while (pNode != NULL) {
            nodes.push(pNode);
            pNode = pNode->next;
        }
        while (!nodes.empty()) {
            pNode = nodes.top();
            if (pNode->val != -1)
            {
                result.push_back(pNode->val);
            }
            nodes.pop();
        }
        return result;
    }

    ListNode *createList(){
        
        int i;
        int len;
        int val;
        
        ListNode * phead = (ListNode *)malloc(sizeof(ListNode*));
        phead->val = -1;
        ListNode *ptail = phead;
        ptail->next = NULL;
        
        len = 3;
        
        for(i = 0; i < len; i++)
        {
            printf("第 %d 个节点的数值: ",i+1);
            // scanf("%d",&val);
            val = 5;
            ListNode *pnew = (ListNode *)malloc(sizeof(ListNode*));
            pnew->val = val;
            ptail->next = pnew;
            pnew->next = NULL;
            ptail = pnew;
        }
        return phead;
    }
};

int main() {
    
    cout << "Hello, World!\n";
    
    Solution sol;
    
    ListNode *head = sol.createList();
    sol.printListFromTail(head);
    
    return 0;
}