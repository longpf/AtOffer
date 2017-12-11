//
//  main.cpp
//  37__数字在排序数组中出现的次数
//
//  Created by 龙鹏飞 on 2017/12/11.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 统计一个数字在排序数组中出现的次数
 */

/*
 因为有序数组,想到二分查找
 修改二分查找
 因为可能有重复出现
 找到左边的第一个索引和右边的最后一个索引即可
 */

#include <vector>
using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int>data, int k)
    {
        int n = (int)data.size();
        if (n == 0)
            return 0;
        int left = leftEqual(data, k);
        int right = rightEqual(data, k);
        if (left!=-1&&right!=-1)
            return right-left+1;
        return 0;
    }
    
    int leftEqual(vector<int>& data,int k)
    {
        int left = 0,right = (int)data.size()-1;
        int mid;
        while (left <= right)
        {
            mid = (left+right) / 2;
            if (data[mid]==k)
            {
                if (mid==left || (mid-1>=left && data[mid-1] != k))
                    return mid;
                right = mid - 1;
            }
            else if (data[mid]>k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return  -1;
    }
    
    int rightEqual(vector<int>& data,int k)
    {
        int left = 0,right=(int)data.size()-1;
        int mid;
        while (left <= right) {
            mid = (left+right)/2;
            if (data[mid]==k) {
                if (mid == right || (mid+1 <= right && data[mid+1] != k))
                    return mid;
                left = mid + 1;
            }
            else if(data[mid] > k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> v = {1,2,3,4,5,5,5,5,5,6,7};
    
    Solution sol;
    int r = sol.GetNumberOfK(v, 5);
    
    return 0;
}
