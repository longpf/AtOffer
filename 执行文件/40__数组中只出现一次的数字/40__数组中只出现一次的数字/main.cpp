//
//  main.cpp
//  40__数组中只出现一次的数字
//
//  Created by 龙鹏飞 on 2017/12/11.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
 请写程序找出这两个只出现一次的数字
 */

/**
 两个相同的数异或为0,0异或5等于5
 先对数组中每个数进行异或,将得到的数的第一个为1的位作为分割位n,
 再对原数组分组,以分割位n的0,1分为两个子数组
 例:{2,4,3,6,3,2,5,5}
 1. 0^=2^=4^=3^=6^=3^=2^=5^=5 = 010
 2. 再以分割位的0或者1进行分组,得到{2,3,6,3,2},{4,5,5}
 因为4和6的倒数第二位不一样,所以以倒数第二位分组
 所以在对两个子数组分别从头到尾异或运算分别得到6和4
 */

#include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int>data,int* num1,int* num2)
    {
        int n = (int)data.size();
        if(n==0||n<2)
            return;
        int res = 0;
        *num1 = 0;
        *num2 = 0;
        for (int i = 0;i < n;i++)
            res ^= data[i];
        int k = firstBit(res);
        for (int i = 0; i < n; i ++)
        {
            if (IsEqualOne(data[i], k))
            {
                *num1 ^= data[i];
            }
            else
            {
                *num2 ^= data[i];
            }
        }
    }
    
    int firstBit(int res)
    {
        int count = 0;
        while ((res & 0x1)==0 && (count < 8 * sizeof(int)))
        {
            res >>= 1;
            count ++;
        }
        return count;
    }
    bool IsEqualOne(int num,int k)
    {
        return (num >> k) & 0x1;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> v = {2,4,3,6,3,2,5,5};
    Solution sol;
    int *a=new int,*b=new int;
    *a = 0;
    *b = 0;
    sol.FindNumsAppearOnce(v, a, b);
    
    return 0;
}
