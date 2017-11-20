//
//  main.cpp
//  19__顺时针打印矩阵
//
//  Created by 龙鹏飞 on 2017/11/20.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 例如，
 如果输入如下矩阵：
 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 则依次打印出数字
 1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 */

class Solution1 {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        vector<vector<int> >  tmp = matrix;
        while(tmp.size() >= 1)
        {
            vector<int> r = tmp[0];
            for(int i = 0;i<r.size();i++){
                result.push_back(r[i]);
            }
            tmp.erase(tmp.begin());
            if (tmp.size()>0) {
                tmp = reverseMatrix(tmp);
            }
            else{
                break;
            }
        }
        return result;
    }
    
    vector<vector<int>> reverseMatrix(vector<vector<int>> matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> result;
        for (int i = cols-1;i >= 0;i--)
        {
            vector<int> r;
            for (int j = 0;j<rows;j++)
            {
                r.push_back(matrix[j][i]);
            }
            result.push_back(r);
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> printMatrix(vector<vector<int>> matrix){
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows==0||cols==0) {
            return res;
        }
        int left = 0,top = 0;
        int right = cols-1,bottom = rows-1;
        while (top<=bottom && left <= right)
        {
            int i,j;
            for (j=left;j<=right;j++)
                res.push_back(matrix[top][j]);
            for (i = top+1;i<=bottom;i++)
                res.push_back(matrix[i][right]);
            if (top < bottom) {
                for(j=right-1;j>left;j--)
                    res.push_back(matrix[bottom][j]);
            }
            if (left<right) {
                for (i=bottom;i>top;i--)
                    res.push_back(matrix[i][left]);
            }
            top++;
            left++;
            right--;
            bottom--;
            
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> r0 = {1,2,3,4};
    vector<int> r1 = {5,6,7,8};
    vector<int> r2 = {9,10,11,12};
    vector<int> r3 = {13,14,15,16};
    vector<vector<int>> m ={r0,r1,r2,r3};
    
    Solution2 sol2;
    vector<int>r = sol2.printMatrix(m);
    
    return 0;
}
