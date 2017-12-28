//
//  main.cpp
//  61__序列化二叉树
//
//  Created by 龙鹏飞 on 2017/12/28.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 请实现两个函数，分别用来序列化和反序列化二叉树
 */

#include <string>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){};
};

class Solution {
public:
    char* Serialize(TreeNode* root){
        if (root == NULL)
            return "$";
        string str = to_string(root->val);
        str += ",";
        str += Serialize(root->left);
        str += Serialize(root->right);
        char* s = new char[str.length()+1];
        strcpy(s, str.c_str());
        str += s;
        return s;
    }
    TreeNode* Deserialize(char*& str){
        if (str == NULL)
            return NULL;
        if (*str == '$')
        {
            str++;
            return NULL;
        }
        int val = 0;
        while (*str != ',')
        {
            val = val * 10 + (*str-'0');
            str ++;
        }
        str++;
        TreeNode* pRoot = new TreeNode(val);
        pRoot->left = Deserialize(str);
        pRoot->right = Deserialize(str);
        return pRoot;
    }
};


int main(int argc, const char * argv[]) {

    
    return 0;
}
