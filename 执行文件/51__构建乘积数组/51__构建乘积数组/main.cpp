//
//  main.cpp
//  51__构建乘积数组
//
//  Created by 龙鹏飞 on 2017/12/20.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A)
    {
        int n = (int)A.size();
        if (n == 0)
            return vector<int> ();
        vector<int> B(n,1);
        //存储i之前的数的乘积
        for (int i = 1;i < n ; i++)
            B[i] = B[i-1] * A[i-1];
        
        int tmp = 1;
        for (int i = n-2;i >=0; i--)
        {
            //tmp存储i之后的乘积
            tmp *= A[i+1];
            B[i] *= tmp;
        }
        return B;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
