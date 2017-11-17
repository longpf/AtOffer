//
//  main.cpp
//  6__旋转数组的最小数字
//
//  Created by 龙鹏飞 on 2017/11/9.
//  Copyright © 2017年 longpf. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */
class Solution{
public:
    int Min(vector<int>rotateArray)
    {
        if (rotateArray.size()==0) {
            return 0;
        }
        int i = 0,j=(int)rotateArray.size()-1;
        int mid = i;
        while (rotateArray[i] >= rotateArray[j]) {
            if (j-i==1) {
                mid = j;
                break;
            }
            mid = (i+j)/2;
            //如果i,j,mid指向的数相等,则只能顺序查找
            if (rotateArray[i]==rotateArray[mid]&&rotateArray[mid]==rotateArray[j]) {
                return MinInOrder(rotateArray, i, j);
            }
            if (rotateArray[mid]>=rotateArray[i]) {
                i = mid;
            }
            else if (rotateArray[mid]<rotateArray[j])
            {
                j = mid;
            }
        }
        return rotateArray[mid];
    }
    
    int MinInOrder(const vector<int>rotateArray,int start,int end)
    {
        int min = rotateArray[start];
        for (int i=start+1; i<=end; i++)
        {
            if (rotateArray[i]<min) {
                min = rotateArray[i];
            }
        }
        return min;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    vector<int> rotateArray = {3,4,5,1,2};
    int result = sol.Min(rotateArray);
    return 0;
}
