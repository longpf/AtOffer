//
//  main.cpp
//  42__和为S的连续正数序列
//
//  Created by 龙鹏飞 on 2017/12/12.
//  Copyright © 2017年 longpf. All rights reserved.
//

/**
 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
 输出描述:
 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 */

/*
 small=1,big=2开始.
 如果等于S.从small到big进行for加和.
 如果比S大,减去small并把small前进一位
 如果比S小,big前进一位并加big
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if (sum <= 0)
            return res;
        int start = 1,end = 2;
        int curSum = start + end;
        vector<int> solution;
        while (start <= sum/2)
        {
            if (curSum == sum)
            {
                for (int i = start;i <= end;i ++)
                    solution.push_back(i);
                res.push_back(solution);
                solution.clear();
                end++;
                curSum += end;
            }
            else if (curSum > sum)
            {
                curSum -= start;
                start++;
            }
            else
            {
                end ++;
                curSum += end;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
