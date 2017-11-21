# AtOffer

简记剑指offer

## 目录

* [1. 二维数组中的查找](#二维数组中的查找)
* [2. 字符串中的空格替换](#字符串中的空格替换)
* [3. 从尾到头打印链表](#从尾到头打印链表)
* [4. 重建二叉树](#重建二叉树)
* [5. 两个栈实现队列](#两个栈实现队列)
* [6. 旋转数组的最小数字](#旋转数组的最小数字)
* [7. 斐波那契数列](#斐波那契数列)
* [8. 跳台阶](#跳台阶)
* [9. 变态跳台阶](#变态跳台阶)
* [10. 矩形覆盖](#矩形覆盖)
* [位运算tip](#位运算tip)
* [11. 二进制中1的个数](#二进制中1的个数)
* [12. 数值的整数次方](#数值的整数次方)
* [13. 调整数组顺序使奇数位于偶数前面](#调整数组顺序使奇数位于偶数前面)
* [14. 链表中倒数第k个结点](#链表中倒数第k个结点)
* [15. 反转链表](#反转链表)
* [16. 合并两个排序的列表](#合并两个排序的列表)
* [17. 树的子结构](#树的子结构)
* [18. 二叉树的镜像](#二叉树的镜像)
* [19. 顺时针打印矩阵](#顺时针打印矩阵)
* [20. 包含min函数的栈](#包含min函数的栈)
* [21. 栈的压入、弹出序列](#栈的压入、弹出序列)





* [学习地址1:牛客网](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
* [学习地址2:鼠标CS的博客](http://blog.csdn.net/hubeidaxuesanqi3012/article/details/74090645?locationNum=3&fps=1)
* [学习地址3:周旭龙的博客](http://www.cnblogs.com/edisonchou/p/3843287.html)








<span id="二维数组中的查找"></span>

### 1. 二维数组中的查找
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

```c
#include <stdio.h>
#include <stdbool.h>

bool find(int target, int arr[3][3])
{
	int rows = 3;
	int cols = 3;
	int i = 0,j = cols-1;
	while(i < rows && j >= 0)
	{
		if (arr[i][i] == target)
			return true;
		else if (arr[i][j] > target)
			j --;
		else
			i ++;
	}
	return false;
}

int main()
{
	int arr[3][3] = {1,2,3,4,5,6,7,8,9};
	bool result = find(10,arr);
	if (result)
		printf("Existent\n");
	else
		printf("Non-existent\n");

	return 0;
}

```

<span id="字符串中的空格替换"></span>

### 2. 字符串中的空格替换

请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void replaceSpace(char *str, int length)
{
	if (str == NULL || length <= 0)
		return;
	int count = 0;
	for(int i = 0;i<strlen(str);i++)
	{
		if (str[i] == ' ')
			count++;
	}
	int newLength = strlen(str)+count*2+1;
	if (newLength>length)
		return;

	int i = strlen(str) + 1;
	int j = newLength;

	// 直接用str 会报错 /bin/sh: line : Bus error: 10
	char *tmpStr = str;
	str = malloc(strlen(tmpStr)+1);

	while(i >= 0 && j >= i)
	{
		if (tmpStr[i] == ' ')
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else
		{
			str[j--] = tmpStr[i];
		}
		i--;
	}

	printf("%s\n", tmpStr);
	printf("%s\n", str);
}


int main()
{
	char *str = "We Are Happy.";
	replaceSpace(str,13+6);
	return 0;
}
```

<span id="从尾到头打印链表"></span>

### 3. 从尾到头打印链表

输入一个链表，从尾到头打印链表每个节点的值

```cpp
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    vector<int>printListFromTail(struct ListNode* head){
        vector<int> result;
        stack<struct ListNode*>nodes;
        struct ListNode *pNode = head;
        while (pNode != NULL) {
            nodes.push(pNode);
            pNode = pNode->next;
        }
        while (!nodes.empty()) {
            pNode = nodes.top();
            if (pNode->val != -1)
            {
                result.push_back(pNode->val);
            }
            nodes.pop();
        }
        //        reverse(result.begin(), result.end());  //如果允许使用就不用上面的stack了
        return result;
    }

    ListNode *createList(){
        
        int i;
        int len;
        int val;
        
        ListNode * phead = (ListNode *)malloc(sizeof(ListNode*));
        phead->val = -1;
        ListNode *ptail = phead;
        ptail->next = NULL;
        
        len = 3;
        
        for(i = 0; i < len; i++)
        {
            printf("第 %d 个节点的数值: ",i+1);
            // scanf("%d",&val);
            val = 5;
            ListNode *pnew = (ListNode *)malloc(sizeof(ListNode*));
            pnew->val = val;
            ptail->next = pnew;
            pnew->next = NULL;
            ptail = pnew;
        }
        return phead;
    }
};

int main() {
    
    cout << "Hello, World!\n";
    
    Solution sol;
    
    ListNode *head = sol.createList();
    sol.printListFromTail(head);
    
    return 0;
}
```

<span id="重建二叉树"></span>

### 4. 重建二叉树

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回

```cpp
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};

class Solution {
    
public:
    TreeNode* reConstructBinaryTree(vector<int>pre,vector<int>vin)
    {
        if (pre.size()==0 || vin.size()==0) {
            return NULL;
        }
        return constructTree(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
    TreeNode* constructTree(const vector<int>& pre,long s1,long e1,const vector<int>& vin,long s2,long e2)
    {
        long i;
        for (i=s2; i<=e2; i++) {
            if (pre[s1]==vin[i])
                break;
        }
        if (i > e2)
            return NULL;
        TreeNode* head = new TreeNode(pre[s1]);
        head->left = constructTree(pre, s1+1, s1+i-s2, vin, s2, i-1); //s1+i-s2减s2是因为i是从s2开始for循环
        head->right = constructTree(pre, s1+i-s2+1, e1, vin, i+1, e2);
        return head;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>pre = {1,2,4,7,3,5,6,8};
    vector<int>vin = {4,7,2,1,5,3,8,6};
    Solution sol;
    TreeNode* head = sol.reConstructBinaryTree(pre, vin);
    return 0;
}
```

<span id="两个栈实现队列"></span>

### 5. 两个栈实现队列

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

```cpp
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node){
        stack1.push(node);
    }
    int pop(){
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = -1;
        if (!stack2.empty()) {
            res = stack2.top();
            stack2.pop();
        }
        return res;
    }
    
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    sol.push(1);
    sol.push(2);
    
    int a = sol.pop();
    
    return 0;
}
```

<span id="旋转数组的最小数字"></span>

### 6. 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

```cpp
#include <iostream>
#include <vector>

using namespace std;

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
```

<span id="斐波那契数列"></span>

### 7. 斐波那契数列

现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39

```cpp
class Solution{
public:
    int Fibonacci(int n){
        if (n<2)
            return n;
        int a = 0,b = 1;
        int c = 0;
        for (int i = 2; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int reuslt = sol.Fibonacci(39);
    
    return 0;
}
```

<span id="跳台阶"></span>

### 8. 跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法

```cpp
/*
 如果n级为f(n)
 当n>2时,如果第一次跳一级,则剩下的n-1为f(n-1)
 如果第一次跳两级,则剩下的为f(n-2)
 则f(n)=f(n-1)+f(n-2)
 */

class Solution{
public:
    int jumpFloor(int number){
        if (number==1)
            return 1;
        else if (number==2)
            return 2;
        int a = 1,b = 2,c = 3;
        for (int i = 3; i <=number; i++) {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    int result = sol.jumpFloor(10);
    return 0;
}
```

<span id="变态跳台阶"></span>

### 9. 变态跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法

```cpp
#include <iostream>

class Solution {
public:
    int jumpFloorII(int number) {
        // f(n) = 2^(n-1)
        // 1左移(number-1)相当2^(n-1)
        return 1 << (number -1);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int result = sol.jumpFloorII(10);
    
    return 0;
}

```

<span id="矩形覆盖"></span>

### 10. 矩形覆盖

我们可以用`2*1`的小矩形横着或者竖着去覆盖更大的矩形。请问用n个`2*1`的小矩形无重叠地覆盖一个`2*n`的大矩形，总共有多少种方法

解析：用第一个1×2小矩形去覆盖大矩形的最左边时有两个选择，竖着放和横着放，当竖着放时右边还剩下2×(n-1)的区域，这种情况下的覆盖方法记为f(n-1)
当横着放在左上角的时候，左下角必须横着放一个1×2的小矩形，而右边还剩下2×6的区域，这种情况下的覆盖方法记为f(n-2)

```cpp
#include <iostream>

class Solution {
public:
    int rectCover(int number) {
        if(number <= 2)
            return number;
        int a = 1, b = 2;
        int c = 3;
        for(int i=3; i<=number; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution sol;
    int result = sol.rectCover(10);
    return 0;
}
```

<span id="位运算tip"></span>


### 位运算tip

* 原码:最高位表示符号位,1位负,0为正.其他为存二进制的绝对值.`1010位-2`
* 反码:证书的反码还是等于原码.负数的反码就是他的原码除符号位外,安位取反.例:3当反码与原码相同,则可以表示为0011.-3的原码是1011,反码为1100
* 补码:证书的补码等于他的原码.负数的补码等于反码+1.
* 负数的补码=模-负数的绝对值.例:10000(模为2^4=16)-0100=1100(-4的补码)
* 左移:左边移出的部分丢弃,右边补0. `00001010<<2=00101000`,`10001010<<3=01010000`
* 正数右移:左边补0.`00001010>>2=00000010`
* 负数右移:左边补1.`10001010>>3=11110001`
* 把整数右移以为和把证书初一2在数学上都是等价的,但是位运算比乘除法效率高很多



<span id="二进制中1的个数"></span>

### 11. 二进制中1的个数

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示

```cpp
//解法1
class Solution1{
public:
    int NumberOf1(int n){
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            //将类似0001,0010,0100,...(应该为32位)和n做位与运算,如果不为0,则n的该位为1
            if (n & flag) {
                count ++;
            }
            //32位的整数要循环32次,
            //当左移后超出32位则1存在寄存器进位器中,剩下部分为0,跳出循环
            flag = flag << 1;
        }
        return count;
    }
};

//解法2: 1100,减1后为1011,1100和1011做与运算为1000,相当将最右边的1取反为0.
class Solution2{
public:
    int NumberOf1(int n){
        int count = 0;
        while (n) {
            count++;
            n = (n-1) & n;
        }
        return count;
    }
};
```

<span id="数值的整数次方"></span>

### 12. 数值的整数次方

```cpp
class Solution{
public:
    double Power(double base,int exponent)
    {
        if (equal(base, 0.0) && exponent < 0) {
            return 0.0;
        }
        unsigned int absExponent = abs(exponent);
        double result = PowerWithUnsignedExponent(base, absExponent);
        if (exponent<0) {
            result = 1.0/result;
        }
        return result;
    }
    
    bool equal(double num1,double num2)
    {
        if (num1-num2 < 0.0000001 && num1-num2 > -0.0000001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    double PowerWithUnsignedExponent(double base,unsigned int exponent)
    {
        if (exponent==0) {
            return 1;
        }
        else if (exponent==1)
        {
            return base;
        }
        double result = PowerWithUnsignedExponent(base,exponent>>1);
        result *= result;
        //判断奇偶 位运算判断奇偶比取余效率高,奇数左移1位后相当除2,所以还有余数1
        if((exponent & 0x1) == 1)
        {
            result *= base;
        }
        return result;
    }
};
```

<span id="调整数组顺序使奇数位于偶数前面"></span>

### 13. 调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变

```cpp
class Solution{
public:
    void reOrderArray(vector<int>array){
        int n = (int)array.size();
        if(n <= 1)
            return;
        vector<int>tmp;
        for (int i = 0; i<n; i++) {
            //奇数
            if (array[i] & 0x1) {
                tmp.push_back(array[i]);
            }
        }
        for (int i = 0; i<n; i++) {
            //偶数
            if ((array[i] & 0x1)==0) {
                tmp.push_back(array[i]);
            }
        }
        array = tmp;
    }
};
```

<span id="链表中倒数第k个结点"></span>

### 14. 链表中倒数第k个结点

输入一个链表，输出该链表中倒数第k个结点

```cpp
struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):
    val(x),next(NULL){
    }
};

class Solution{
public:
    ListNode* FindKthToTail(ListNode* pListHead,unsigned int k){
        if (pListHead == NULL || k == 0)
        {
            return NULL;
        }
        ListNode* pFast = pListHead;
        ListNode* pSlow = pListHead;
        for (unsigned int i = 0; i < k-1; i++)
        {
            if (pFast->next==NULL)
            {
                return NULL;
            }
            pFast = pFast->next;
        }
        while (pFast->next!=NULL)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
        }
        return pSlow;
    }
};
```

<span id="反转链表"></span>

### 15. 反转链表

输入一个链表，反转链表后，输出链表的所有元素

```cpp
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x):
    val(x),next(NULL){
    }
};

class Solution{
public:
    ListNode* ReverseList(ListNode* pHead){
        ListNode* pre = NULL;
        ListNode* p = pHead;
        ListNode* pn = NULL;
        
        while (p) {
            pn = p->next;
            p->next = pre;
            pre = p;
            p = pn;
        }
        return pre;
    }
};

```

<span id="合并两个排序的列表"></span>

### 16. 合并两个排序的列表

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则

~~~cpp
struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x),next(NULL){
    }
};

class Solution{
public:
    ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
    {
        if (pHead1 == NULL)
            return pHead2;
        else if (pHead2==NULL)
            return pHead1;
        ListNode* newHead = NULL;
        if (pHead1->val<pHead2->val)
        {
            newHead = pHead1;
            newHead->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            newHead = pHead2;
            newHead->next = Merge(pHead1, pHead2->next);
        }
        return newHead;
    }
};
~~~

<span id="树的子结构"></span>

### 17. 树的子结构

```cpp
/*
 step1: 在树A中找到和B的根结点一样的结点R
 step2: 判断树A中以R为根结点的子树是不是包含和树B一样的结构
 这是一个递归的过程
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;
        bool res = false;
        if (pRoot1->val == pRoot2->val)
            return IsSubtree(pRoot1, pRoot2);
        if (!res)
            res = HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        return res;
    }
    
    bool IsSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if (pRoot2 == NULL)
            return true;
        if (pRoot1 == NULL)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right);
    }
};
```

<span id="二叉树的镜像"></span>

### 18. 二叉树的镜像

```cpp
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){};
};

class Solution {
public:
    void Mirror(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return;
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        if (pRoot->left)
            Mirror(pRoot->left);
        if (pRoot->right)
            Mirror(pRoot->right);
    }
};
```

<span id="顺时针打印矩阵"></span>

### 19. 顺时针打印矩阵

解法1:

```cpp
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        vector<vector<int> >  tmp = matrix;
        while(tmp.size() >= 1)
        {
            vector<int> r = tmp[0];
            for(int i = 0;i<r.size();i++){
                result.push_back(r[i]);
            }
            tmp.erase(tmp.begin());
            if (tmp.size()>0) {
                tmp = reverseMatrix(tmp);
            }
            else{
                break;
            }
        }
        return result;
    }
    
    vector<vector<int>> reverseMatrix(vector<vector<int>> matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> result;
        for (int i = cols-1;i >= 0;i--)
        {
            vector<int> r;
            for (int j = 0;j<rows;j++)
            {
                r.push_back(matrix[j][i]);
            }
            result.push_back(r);
        }
        return result;
    }
};
```

解法2:

```cpp
class Solution2 {
public:
    vector<int> printMatrix(vector<vector<int>> matrix){
        vector<int> res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows==0||cols==0) {
            return res;
        }
        int left = 0,top = 0;
        int right = cols-1,bottom = rows-1;
        while (top<=bottom && left <= right)
        {
            int i,j;
            for (j=left;j<=right;j++)
                res.push_back(matrix[top][j]);
            for (i = top+1;i<=bottom;i++)
                res.push_back(matrix[i][right]);
            if (top < bottom) {
                for(j=right-1;j>left;j--)
                    res.push_back(matrix[bottom][j]);
            }
            if (left<right) {
                for (i=bottom;i>top;i--)
                    res.push_back(matrix[i][left]);
            }
            top++;
            left++;
            right--;
            bottom--;
            
        }
        return res;
    }
};
```

<span id="包含min函数的栈"></span>

### 20. 包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数

```cpp
#include <stack>
using namespace std;

class Solution {
private:
    stack<int> s1,s2;
public:
    void push(int value) {
        if (s1.size()>0 && s1.top()<value)
        {
            s2.push(s1.top());
        }
        else
        {
            s2.push(value);
        }
        s1.push(value);
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
```

<span id="栈的压入、弹出序列"><span>

### 21. 栈的压入、弹出序列

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列  4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

```cpp
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        
        stack<int> st;
        
        for (int i = 0,j=0; i < pushV.size(); )
        {
            st.push(pushV[i++]);
            while (j<popV.size() && st.top()==popV[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};
```