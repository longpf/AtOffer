//
//  main.cpp
//  59__把二叉树打印成多行
//
//  Created by 龙鹏飞 on 2017/12/27.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行
 */

#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot){
        vector<vector<int>> res;
        if (pRoot == NULL)
            return res;
        queue<TreeNode*>q;
        q.push(pRoot);
        int toBePrint = 1; //记录当前层还有几个未被打印
        int nextLevel = 0; //记录下一层有多少个需要被打印
        vector<int> numbers;
        while (!q.empty())
        {
            TreeNode* pNode = q.front();
            numbers.push_back(pNode->val);
            if (pNode->left)
            {
                q.push(pNode->left);
                ++nextLevel;
            }
            if (pNode->right)
            {
                q.push(pNode->right);
                ++nextLevel;
            }
            q.pop();
            toBePrint--;
            
            //当前层打印完成
            if (toBePrint == 0)
            {
                toBePrint = nextLevel;
                nextLevel = 0;
                res.push_back(numbers);
                numbers.clear();
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
