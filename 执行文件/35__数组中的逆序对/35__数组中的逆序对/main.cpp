//
//  main.cpp
//  35__数组中的逆序对
//
//  Created by 龙鹏飞 on 2017/12/6.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 输入一个数组,求出这个数组中的逆序对的总数P。
 并将P对1000000007取模的结果输出。 即输出P%1000000007
 
 输入描述:题目保证输入的数组中没有的相同的数字
 
 数据范围：
 
 对于%50的数据,size<=10^4
 
 对于%75的数据,size<=10^5
 
 对于%100的数据,size<=2*10^5
 */

/*
 归并排序
 1. 先按顺序拆成一个个
 2. 相邻的比较并计数,比较后排序成小->大(正序)
 3. 相邻的两两比较并排序,比较后排序(4个数正序)
 3. 相邻两组比较(每组4个)...
 */


#include <vector>
using namespace std;
class Solution {
public:
    int InversePairs(vector<int> data) {
        int n = (int)data.size();
        if (n==0)
            return 0;
        int count = 0;
        MergeSort(data, 0, n-1, count);
        return count % 1000000007;
    }
    void MergeSort(vector<int>& data,int start,int end,int& count)
    {
        if (start < end)
        {
            int mid = (start + end)/2;
            MergeSort(data, start, mid, count);
            MergeSort(data, mid+1, end, count);
            Merge(data, start, mid, mid+1, end, count);
        }
    }
    void Merge(vector<int>& data,int lbegin,int lend,int rbegin,int rend,int& count)
    {
        int i = lend,j = rend;
        int n = rend - lbegin + 1;
        int k = n - 1 ;
        vector<int> tmp(n,0);
        while (i >= lbegin && j >= rbegin)
        {
            if (data[i] > data[j])
            {
                count += j - rbegin + 1;
                count %= 1000000007;
                tmp[k] = data[i];
                k--;
                i--;
            }
            else
            {
                tmp[k] = data[j];
                k--;
                j--;
            }
        }
        while (i >= lbegin)
        {
            tmp[k] = data[i];
            k--;
            i--;
        }
        while (j >= rbegin)
        {
            tmp[k] = data[j];
            k--;
            j--;
        }
        for (i = lbegin,k = 0; i <= rend; i++,k++)
        {
            data[i] = tmp[k];
        }
    }
};



int main(int argc, const char * argv[]) {
    
    Solution sol;
    
    vector<int> t = {7,5,6,4};
    
    int r = sol.InversePairs(t);
    
    
    return 0;
}
