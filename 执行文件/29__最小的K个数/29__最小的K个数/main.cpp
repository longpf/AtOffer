//
//  main.cpp
//  29__最小的K个数
//
//  Created by 龙鹏飞 on 2017/11/29.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <vector>
#include <set>

using namespace std;

/*
 解法1:
 运用快排的思想
 把数组的元素分成两组,右边比左边的都要大
 数据都读到内存,并且修改数组
 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int>input,int k)
    {
        vector<int> res;
        int n = input.size();
        if (n == 0 || k > n || k <= 0) {
            return res;
        }
        int start = 0,end = n-1;
        int mid = partition(input, start, end);
        while (mid != k-1)
        {
            if (mid > k-1)
            {
                end = mid - 1;
                mid = partition(input, start, end);
            }
            else
            {
                start = mid + 1;
                mid = partition(input, start, end);
            }
        }
        for (int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }
        return res;
    }
    
    int partition(vector<int>& input,int start,int end)
    {
        int key = input[start];
        while (start < end)
        {
            while (start < end && input[end] >= key)
                end --;
            input[start] = input[end];
            while (start < end && input[start] <= key)
                start++;
            input[end] = input[start];
        }
        input[start] = key;
        return start;
    }
};


/*
 解法2
 用大根堆的思想
 这里用multiset(内部红黑树,查找快(Ologn))保存k个元素,greater排序保证首个元素为最大
 k个元素之后每个与multiset首个元素比较
 适合海量数据,不修改原数组,修改都在multiset中
 */
class Solution2 {
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int n = input.size();
        if (n == 0 || n < k || k <= 0)
            return vector<int>();
        multiset<int,greater<int>> leastNumbers;
        for (int i = 0;i < n;i++)
        {
            if (i < k)
                leastNumbers.insert(input[i]);
            else
            {
                multiset<int,greater<int>> ::const_iterator iter = leastNumbers.begin();
                if (*iter > input[i]) {
                    leastNumbers.erase(iter);
                    leastNumbers.insert(input[i]);
                }
            }
        }
        vector<int> res(leastNumbers.begin(),leastNumbers.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> input = {4,5,1,6,2,7,3,8};
    
    Solution sol;
    int r = sol.partition(input, 0, input.size()-1);
    
    return 0;
}
