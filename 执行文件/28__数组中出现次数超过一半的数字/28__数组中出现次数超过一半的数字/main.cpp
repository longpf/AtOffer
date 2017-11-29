//
//  main.cpp
//  28__数组中出现次数超过一半的数字
//
//  Created by 龙鹏飞 on 2017/11/28.
//  Copyright © 2017年 longpf. All rights reserved.
//


/*
 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
 如果不存在则输出0
 */


#include <vector>
#include <map>

using namespace std;
typedef map<int,int> MAP;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        MAP hashInt;
        for (int i = 0; i < numbers.size(); i++) {
            hashInt[numbers[i]] = hashInt.find(numbers[i])==hashInt.end()?1:hashInt[numbers[i]]+1;
        }
        MAP::iterator it = hashInt.begin();
        int max = it->second;
        int key = it->first;
        while (it != hashInt.end()) {
            if (it->second > max)
            {
                max = it->second;
                key = it->first;
            }
            it++;
        }
        if (max > numbers.size()/2)
        {
            return key;
        }
        return 0;
    }
};

class Solution2 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int res = 0;
        int count = 0;
        //找到数量最多的数字
        for (int i = 0;i < numbers.size();i++)
        {
            if (count == 0)
            {
                res = numbers[i];
                count++;
            }
            else if(numbers[i] == res)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        if (res)
        {
            count = 0;
            for (int i = 0; i < numbers.size(); i++) {
                if (numbers[i] == res)
                    count++;
            }
            if (count * 2 <= numbers.size())
                res = 0;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    
    vector<int> list = {1,2,3,2,2,2,5,4,2};
    int r = sol.MoreThanHalfNum_Solution(list);
    
    
    return 0;
}
