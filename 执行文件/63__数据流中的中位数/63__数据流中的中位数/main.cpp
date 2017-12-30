//
//  main.cpp
//  63__数据流中的中位数
//
//  Created by 龙鹏飞 on 2017/12/30.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 如何得到一个数据流中的中位数？
 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
 */

/*
 头文件 #include <algorithm>
       #include <functional>
 make_heap()建立堆,默认建立的是最大堆,建最小堆的话第三个参数传greater<int>()
 push_heap()在堆中添加数据
 pop_heap()在堆中删除数据
 sort_heap()堆排序
 */

/*
 可以使用一个大根堆,一个小根堆配合
 为了实现平均分配,当前总数是偶数的时候插入小跟堆,奇数的时候插入大根堆.
 那么中位数就是最小堆的堆顶(插入前是偶数,插入后为奇数),或是两堆顶的平均值.
 */

#include <vector>
#include <algorithm> // sort
#include <functional> //greater
using namespace std;

class Solution {
public:
    void Insert(int num)
    {
        //偶
        if (((min.size()+max.size()) & 0x1)==0)
        {
            //为了保证新进入的流元素在插入最小堆的时候为最大堆的最大值,所以先插入最大堆并筛选下
            if (max.size() > 0 && max[0] > num)
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            //插入到最小堆
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        //奇
        else
        {
            if (min.size() > 0 && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }
    
    double GetMedian()
    {
        if (((min.size()+max.size()) & 0x1)==1)
        {
            return min[0];
        }
        else
            return (max[0]+min[0]) / 2.0;
    }
    
private:
    vector<int> min; //小根堆
    vector<int> max; //大根堆
};

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
