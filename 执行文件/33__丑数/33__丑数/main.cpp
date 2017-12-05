//
//  main.cpp
//  33__丑数
//
//  Created by 龙鹏飞 on 2017/12/5.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 把只包含因子2、3和5的数称作丑数（Ugly Number）
 例如6、8都是丑数，但14不是，因为它包含因子7
 习惯上我们把1当做是第一个丑数。
 求按从小到大的顺序的第N个丑数
 */

#include <vector>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        int i = 1;
        int two = 0;
        int three = 0;
        int five = 0;
        vector<int> ugly(index,0);
        ugly[0] = 1;
        while (i < index)
        {
            ugly[i] = min(min(ugly[two]*2, ugly[three]*3), ugly[five]*5);
            while (ugly[two]*2 <= ugly[i])
                two++;
            while (ugly[three]*3 <= ugly[i])
                three++;
            while (ugly[five]*5 <= ugly[i])
                five++;
            i++;
        }
        return ugly[index-1];
    }
};


int main(int argc, const char * argv[]) {
    
    Solution sol;
    sol.GetUglyNumber_Solution(10);
    
    return 0;
}
