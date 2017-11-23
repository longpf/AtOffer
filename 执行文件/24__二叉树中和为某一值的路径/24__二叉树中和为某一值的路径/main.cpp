//
//  main.cpp
//  24__二叉树中和为某一值的路径
//
//  Created by 龙鹏飞 on 2017/11/23.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
 */

/*
 例如输入图1中二叉树和整数22，则打印出两条路径，第一条路径包含结点10、12，第二条路径包含结点10、5和7
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){
        }
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> solution;
        findPath(root, expectNumber, solution, res);
        return res;
    }
    void findPath(TreeNode* root,int expectNumber,vector<int>& solution,vector<vector<int>>&res)
    {
        int sum = expectNumber - root->val;
        solution.push_back(root->val);
        //判断是否为叶结点,并且sum是否加满了
        if (root->left == NULL && root->right==NULL && sum==0)
        {
            res.push_back(solution);
        }
        if (root->left)
            findPath(root->left, sum, solution, res);
        if (root->right)
            findPath(root->right, sum, solution, res);
        //往后推一个
        solution.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
