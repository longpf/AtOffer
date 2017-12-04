//
//  main.cpp
//  31__整数中1出现的次数(从1到n整数中1出现的次数)
//
//  Created by 龙鹏飞 on 2017/12/4.
//  Copyright © 2017年 longpf. All rights reserved.
//


/*
 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
 ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数
 */

/*
 以534为例:
 个位中1出现的次数为53*1+1
 十位中1出现的次数为5*10+10
 百位中1出现的次数为0*100+100
 
 以514为例:
 个位中1出现的次数为53*1+1
 十位中1出现的次数为5*10+4+1 (5*10位0~500,4+1为501~514中十位为1)
 百位中1出现的次数为0*100+100
 */

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n < 1)
            return 0;
        int count = 0;
        int base = 1;
        int round = n;
        while (round > 0) {
            int weight = round%10;
            round /= 10;
            count += base*round;
            if (weight==1)
                count += (n%base)+1;
            else if(weight>1)
                count += base;
            base *= 10;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int r = sol.NumberOf1Between1AndN_Solution(123);
    
    return 0;
}
