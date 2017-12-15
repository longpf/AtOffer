//
//  main.cpp
//  47__求1+2+3+...+n
//
//  Created by 龙鹏飞 on 2017/12/14.
//  Copyright © 2017年 longpf. All rights reserved.
//

/*
 求1+2+3+...+n，
 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
 */
/*
 // 方法一: 利用构造函数
class A
{
public:
    A()
    {
        ++i;
        sum += i;
    }
    static int getsum()
    {
        return sum;
    }
    static void reset()
    {
        i = 0;
        sum = 0;
    }
    
private:
    static int i ;
    static int sum;
};

int A::i = 0;
int A::sum = 0;

class Solution{
public:
    int Sum_Solution(int n)
    {
        A::reset();
        A* a = new A[n];
        int res = A::getsum();
        delete[] a;
        return res;
    }
};
*/

//方法二: 利用虚函数
class A;
A* array[2];

class A
{
public:
    virtual int sum(int n)
    {
        return 0;
    }
};
class B: public A
{
public:
    virtual int sum(int n)
    {
        return ::array[!!n]->sum(n-1)+n;
    }
};

class Solution
{
public:
    int Sum_Solution(int n)
    {
        A a;
        B b;
        ::array[0] = &a;
        ::array[1] = &b;
        
        return ::array[1]->sum(n);
    }
};


int main(int argc, const char * argv[]) {
    
    Solution sol;
    int r = sol.Sum_Solution(100);
    
    
    return 0;
}
