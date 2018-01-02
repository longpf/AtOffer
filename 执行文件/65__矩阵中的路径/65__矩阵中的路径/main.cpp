//
//  main.cpp
//  65__矩阵中的路径
//
//  Created by 龙鹏飞 on 2018/1/2.
//  Copyright © 2018年 longpf. All rights reserved.
//

/**
 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
 例如
 a b c e
 s f c s
 a d e e
 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
 因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子
 */

/*
 这是一个回溯法的典型题.
 从一个任何一个点开始,下一个点可能位于该点的上下左右4个方位
 需要一个与输入矩阵同样大小的矩阵用来保存某个点是否被访问过
 由于回溯法的递归特性,路径可以被看成一个栈.当定位了前n个位置后,找不到第n+1个位置,
 则应该退回到第n-1个位置.
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool hasPath(char* matrix,int rows,int cols,char* str)
    {
        if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
            return false;
        vector<bool> visited(rows*cols,0);
        int pathLength = 0;
        for (int row=0;row < rows;row++)
        {
            for(int col=0;col<cols;col++)
            {
                if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
                    return true;
            }
        }
        return false;
    }
    
    bool hasPathCore(char* matrix,int rows,int cols,int row,int col,char* str,int& pathLenght,vector<bool>& visited)
    {
        //判断是否遍历寻找完毕
        if (str[pathLenght] == '\0')
            return true;
        bool res = false;
        if (row >= 0 && row < rows && col >=0 && col < cols &&
            matrix[row*cols+col]==str[pathLenght] && !visited[row*cols+col])
        {
            visited[row*cols+col] = true;
            ++pathLenght;
            //上下左右 寻找下一个位置
            res = hasPathCore(matrix, rows, cols, row, col-1, str, pathLenght, visited) ||
                  hasPathCore(matrix, rows, cols, row, col+1, str, pathLenght, visited) ||
                  hasPathCore(matrix, rows, cols, row-1, col, str, pathLenght, visited) ||
                  hasPathCore(matrix, rows, cols, row+1, col, str, pathLenght, visited) ;
            //如果找不到下一个位置,则退回
            if (!res)
            {
                visited[row*cols+col] = false;
                pathLenght--;
            }
        }
        return res;
    }
};



int main(int argc, const char * argv[]) {
    
    return 0;
}
