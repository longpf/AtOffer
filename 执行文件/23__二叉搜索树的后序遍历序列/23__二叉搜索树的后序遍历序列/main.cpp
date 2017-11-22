//
//  main.cpp
//  23__二叉搜索树的后序遍历序列
//
//  Created by 龙鹏飞 on 2017/11/22.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 如果是则输出Yes,否则输出No。
 假设输入的数组的任意两个数字都互不相同。
 例如在下面的一颗二叉搜索树中，输入数组{5,7,6,9,11,10,8}，则返回true，
 因为这个整数序列是下图二叉搜索树的后序遍历结果。
 如果输入的数组是{7,4,6,5}，
 由于没有哪棵二叉搜索树的后序遍历的结果是这个序列，因此返回false。
 */


#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)
            return false;
        return VerifyBST(sequence, 0, (int)sequence.size()-1);
    }
    
    bool VerifyBST(vector<int> sequence,int start,int end)
    {
        int i,j;
        for (i=start;i<end;i++)
        {
            if (sequence[i] > sequence[end])
                break;
        }
        j = i - 1;
        while (i < end)
        {
            if (sequence[i] < sequence[end])
                return false;
            i++;
        }
        bool left = true;
        if (j > start)
            left = VerifyBST(sequence, start, j);
        bool right = true;
        if (j+1 < end-1)
            right = VerifyBST(sequence, j+1, end-1);
        return left && right;
    }
};


int main(int argc, const char * argv[]) {
    
    
    
    
    return 0;
}
