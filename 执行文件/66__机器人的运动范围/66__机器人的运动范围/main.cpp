//
//  main.cpp
//  66__机器人的运动范围
//
//  Created by 龙鹏飞 on 2018/1/2.
//  Copyright © 2018年 longpf. All rights reserved.
//

/**
 地上有一个m行和n列的方格。
 一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
 但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
 请问该机器人能够达到多少个格子
 */

/*
 K=4,格子数为15,如图黄色区域
 回溯法,机器人从(0,0)开始移动,当移动到下一个位置时候
 通过格子数位和判断是否可以进入
 如果可以进入则判断其上下左右4个相邻位置是否可以进入
 */

#include <vector>

using namespace std;

class Solution {
public:
    
    int movingCount(int threshold,int rows,int cols)
    {
        if (threshold <0 || rows < 1 || cols < 1)
            return 0;
        vector<bool> visited(rows*cols,0);
        int res= movingCore(threshold, rows, cols, 0, 0, visited);
        return res;
    }
    
    int movingCore(int threshold,int rows,int cols,int row,int col,vector<bool>& visited)
    {
        int res = 0;
        if (canMove(threshold, rows, cols, row, col) && !visited[row*cols+col])
        {
            visited[row*cols+col] = true;
            res = 1 + movingCore(threshold, rows, cols, row, col-1, visited) +
                    movingCore(threshold, rows, cols, row, col+1, visited) +
                    movingCore(threshold, rows, cols, row-1, col, visited) +
                    movingCore(threshold, rows, cols, row+1, col, visited);
        }
        
        return res;
    }
    
    bool canMove(int threshold,int rows,int cols,int row,int col)
    {
        int sum = 0;
        if (row >= 0 && row < rows && col >= 0 && col < cols)
        {
            while (row)
            {
                sum += row % 10;
                row /= 10;
            }
            while (col)
            {
                sum += col % 10;
                col /= 10;
            }
            if (sum <= threshold)
                return true;
            return false;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
