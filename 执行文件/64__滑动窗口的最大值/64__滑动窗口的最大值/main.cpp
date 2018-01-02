//
//  main.cpp
//  64__滑动窗口的最大值
//
//  Created by 龙鹏飞 on 2018/1/2.
//  Copyright © 2018年 longpf. All rights reserved.
//

/*
 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
 他们的最大值分别为{4,4,6,6,6,5}；
 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}，{2,3,[4,2,6],2,5,1}，
 {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}
 */

/*
 这里用一个双向队列的方法
 最大值在队首,并保持从大到小的排列,每次新加入的从队尾到队首比较
 如果比队中已有的数大,则移除队
 每次移动要判断最大值(队首)元素是不是在有效范围内
 */

#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num,unsigned int size)
    {
        vector<int> res;
        int n = (int)num.size();
        if (n == 0 || size == 0 || n < size)
            return res;
        int i;
        deque<int> index;
        for (i = 0; i < size;i ++)
        {
            //从队尾到队首比较大小
            while (!index.empty() && num[index.back()] <= num[i])
            {
                //如果新数比对尾数大 移除对尾元素
                index.pop_back();
            }
            //添加新数
            index.push_back(i);
        }
        res.push_back(num[index.front()]);
        for (i = size; i < n; i++)
        {
            //从队尾到队首比较大小
            while (!index.empty() && num[index.back()] <= num[i])
                index.pop_back();
            //判断队首元素是否在有效范围
            if (!index.empty() && i - index.front() >= size)
                index.pop_front();
            
            index.push_back(i);
            res.push_back(num[index.front()]);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    vector<int> p = {2,3,4,2,6,2,5,1};
    vector<int> r = sol.maxInWindows(p, 3);
    return 0;
}
