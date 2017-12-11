# AtOffer

简记剑指offer

## 目录

* <a href="#二维数组中的查找">1. 二维数组中的查找</a>
* <a href="#字符串中的空格替换">2. 字符串中的空格替换</a>
* <a href="#从尾到头打印链表">3. 从尾到头打印链表</a>
* <a href="#重建二叉树">4. 重建二叉树</a>
* <a href="#两个栈实现队列">5. 两个栈实现队列</a>
* <a href="#旋转数组的最小数字">6. 旋转数组的最小数字</a>
* <a href="#斐波那契数列">7. 斐波那契数列</a>
* <a href="#跳台阶">8. 跳台阶</a>
* <a href="#变态跳台阶">9. 变态跳台阶</a>
* <a href="#矩形覆盖">10. 矩形覆盖</a>
* <a href="#位运算tip">位运算tip</a>
* <a href="#二进制中1的个数">11. 二进制中1的个数</a>
* <a href="#数值的整数次方">12. 数值的整数次方</a>
* <a href="#调整数组顺序使奇数位于偶数前面">13. 调整数组顺序使奇数位于偶数前面</a>
* <a href="#链表中倒数第k个结点">14. 链表中倒数第k个结点</a>
* <a href="#反转链表">15. 反转链表</a>
* <a href="#合并两个排序的列表">16. 合并两个排序的列表</a>
* <a href="#树的子结构">17. 树的子结构</a>
* <a href="#二叉树的镜像">18. 二叉树的镜像</a>
* <a href="#顺时针打印矩阵">19. 顺时针打印矩阵</a>
* <a href="#包含min函数的栈">20. 包含min函数的栈</a>
* <a href="#栈的压入、弹出序列">21. 栈的压入、弹出序列</a>
* <a href="#从上到下打印二叉树">22. 从上到下打印二叉树</a>
* <a href="#二叉搜索树的后序遍历序列">23. 二叉搜索树的后序遍历序列</a>
* <a href="#二叉树中和为某一值的路径">24. 二叉树中和为某一值的路径</a>
* <a href="#复杂链表的复制">25. 复杂链表的复制</a>
* <a href="#二叉树的前中后序遍历">二叉树的前中后序遍历</a>
* <a href="#二叉搜索树与双向链表">26. 二叉搜索树与双向链表</a>
* <a href="#字符串的排列">27. 字符串的排列</a>
* <a href="#数组中出现次数超过一半的数字">28. 数组中出现次数超过一半的数字</a>
* <a href="#红黑树,快排,堆排">红黑树,快排,堆排</a>
* <a href="#最小的K个数">29. 最小的K个数</a>
* <a href="#连续子数组的最大和">30. 连续子数组的最大和</a>
* <a href="#整数中1出现的次数(从1到n整数中1出现的次数)">31. 整数中1出现的次数(从1到n整数中1出现的次数)</a>
* <a href="#把数组排成最小的数">32. 把数组排成最小的数</a>
* <a href="#丑数">33. 丑数</a>
* <a href="#第一个只出现依次的字符">34. 第一个只出现依次的字符</a>
* <a href="#数组中的逆序对">35. 数组中的逆序对</a>
* <a href="#两个链表的第一个公共结点">36. 两个链表的第一个公共结点</a>
* <a href="#数字在排序数组中出现的次数">37. 数字在排序数组中出现的次数</a>
* <a href="#二叉树的深度">38. 二叉树的深度</a>
* <a href="#平衡二叉树">39. 平衡二叉树</a>




* [学习地址1:牛客网](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
* [学习地址2:鼠标CS的博客](http://blog.csdn.net/hubeidaxuesanqi3012/article/details/74090645?locationNum=3&fps=1)
* [学习地址3:周旭龙的博客](http://www.cnblogs.com/edisonchou/p/3843287.html)








<a id="二维数组中的查找"></a>

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

<a id="字符串中的空格替换"></a>

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

<a id="从尾到头打印链表"></a>

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

<a id="重建二叉树"></a>

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

<a id="两个栈实现队列"></a>

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

<a id="旋转数组的最小数字"></a>

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

<a id="斐波那契数列"></a>

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

<a id="跳台阶"></a>

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

<a id="变态跳台阶"></a>

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

<a id="矩形覆盖"></a>

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

<a id="位运算tip"></a>


### 位运算tip

* 原码:最高位表示符号位,1位负,0为正.其他为存二进制的绝对值.`1010为-2`
* 反码:正数的反码还是等于原码.负数的反码就是他的原码除符号位外,安位取反.例:3当反码与原码相同,则可以表示为0011.-3的原码是1011,反码为1100
* 补码:正数的补码等于他的原码.负数的补码等于反码+1.
* 负数的补码=模-负数的绝对值.例:10000(模为2^4=16)-0100=1100(-4的补码)
* 左移:左边移出的部分丢弃,右边补0. `00001010<<2=00101000`,`10001010<<3=01010000`
* 正数右移:左边补0.`00001010>>2=00000010`
* 负数右移:左边补1.`10001010>>3=11110001`
* 把正数右移一位和把正数除以2在数学上都是等价的,但是位运算比乘除法效率高很多



<a id="二进制中1的个数"></a>

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

<a id="数值的整数次方"></a>

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

<a id="调整数组顺序使奇数位于偶数前面"></a>

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

<a id="链表中倒数第k个结点"></a>

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

<a id="反转链表"></a>

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

<a id="合并两个排序的列表"></a>

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

<a id="树的子结构"></a>

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

<a id="二叉树的镜像"></a>

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

<a id="顺时针打印矩阵"></a>

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

<a id="包含min函数的栈"></a>

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

<a id="栈的压入、弹出序列"><a>

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

<a id="从上到下打印二叉树"></a>

### 22. 从上到下打印二叉树

从上往下打印出二叉树的每个节点，同层节点从左至右打印

```cpp
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){
            
        }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root)
    {
        vector<int> result;
        if (root==NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode* node = q.front();
            result.push_back(node->val);
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        return result;
    }
};
```

<a id="二叉搜索树的后序遍历序列"></a>

### 23. 二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)
            return false;
        return VerifyBST(sequence, 0, (int)sequence.size()-1);
    }
    
    bool VerifyBST(vector<int> sequence,int start,int end)
    {
        int i,j;
        for (i=start;i<end;i++)
        {
            if (sequence[i] > sequence[end])
                break;
        }
        j = i - 1;
        while (i < end)
        {
            if (sequence[i] < sequence[end])
                return false;
            i++;
        }
        bool left = true;
        if (j > start)
            left = VerifyBST(sequence, start, j);
        bool right = true;
        if (j+1 < end-1)
            right = VerifyBST(sequence, j+1, end-1);
        return left && right;
    }
};
```

<a id="二叉树中和为某一值的路径"></a>

### 24. 二叉树中和为某一值的路径

输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径

```cpp
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){
        }
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        vector<int> solution;
        findPath(root, expectNumber, solution, res);
        return res;
    }
    void findPath(TreeNode* root,int expectNumber,vector<int>& solution,vector<vector<int>>&res)
    {
        int sum = expectNumber - root->val;
        solution.push_back(root->val);
        //判断是否为叶结点,并且sum是否加满了
        if (root->left == NULL && root->right==NULL && sum==0)
        {
            res.push_back(solution);
        }
        if (root->left)
            findPath(root->left, sum, solution, res);
        if (root->right)
            findPath(root->right, sum, solution, res);
        //往后推一个
        solution.pop_back();
    }
};
```

<a id="复杂链表的复制"></a>

### 25. 复杂链表的复制

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

```cpp
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode* next,* random;
    RandomListNode(int x):
        label(x),next(NULL),random(NULL){
    }
};

/*
 方法1:
 复制原始链表上的每个节点N创建N',然后把这些创建出来的结点用next连接起来,
 A-->B-->C-->D
 A'->B'->C'->D'.
 同时把<N,N'>的配对信息放一个哈希表中.
 然后设置复制链表中的每个结点的random指针,如果原始列表中的N的random指向的结点为S,
 那么在赋值链表中,对应的N'应该指向S'.
 时间复杂度: O(N)
 */

typedef map<RandomListNode*,RandomListNode*> MAP;

class Solution1 {
public:
    
    RandomListNode* CloneNodes(RandomListNode* pHead,MAP &hashNode)
    {
        RandomListNode* pNode = new RandomListNode(0);
        RandomListNode* p = pNode;
        RandomListNode* tmp;
        while (pHead != NULL) {
            tmp = new RandomListNode(0);
            tmp->label = pHead->label;
            p->next = tmp;
            hashNode[pHead] = tmp;
            pHead = pHead->next;
            p=p->next; //就是当前的tmp
        }
        return pNode->next;
    }
    
    void setRandomNodes(RandomListNode* pHead,RandomListNode* pCopy,MAP &hashNode)
    {
        while (pCopy!=NULL) {
            pCopy->random = hashNode[pHead->random];
            pCopy = pCopy->next;
            pHead = pHead->next;
        }
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* pCopy;
        MAP hashNode;
        pCopy = CloneNodes(pHead, hashNode);
        setRandomNodes(pHead, pCopy, hashNode);
        return pCopy;
    }
};

/*
 方法2
 在不使用辅助空间的情况下实现O(N)的时间效率
 第一步：根据原始链表的每个结点N创建对应的N',然后将N‘通过pNext接到N的后面
 第二步：设置复制出来的结点的random,假设原始链表上的N的random指向结点S,那么其对应复制出来的N'是N->pNext指向的结点,同样S'也是结点S->pNext指向的结点
 第三步：把长链表拆分成两个链表,把奇数位置的结点用pNext连接起来的就是原始链表,把偶数位置的结点通过pNext连接起来的就是复制链表
 */

class Solution2{
    
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloned;
        while (pNode!=NULL) {
            pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }
    
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloned;
        while (pNode!=NULL) {
            pCloned = pNode->next;
            if (pNode->random!=NULL) {
                pCloned->random = pNode->random->next;
            }
            pNode=pCloned->next;
        }
    }
    
    RandomListNode* ReconnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = NULL;
        RandomListNode* pClonedNode = NULL;
        if (pNode!=NULL) {
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        while (pNode!=NULL) {
            pClonedNode->next=pNode->next;
            pClonedNode=pClonedNode->next;
            pNode->next=pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReconnectNodes(pHead);
    }
};
```

<a id="二叉树的前中后序遍历"></a>


### 二叉树的前中后序遍历

* 前序遍历：根节点->左子树->右子树
* 中序遍历：左子树->根节点->右子树
* 后序遍历：左子树->右子树->根节点

```cpp
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x),left(NULL),right(NULL){}
};


//前序递归遍历
vector<int> preVector;
void PreOrder(TreeNode* root)
{
    if (root != NULL)
    {
        preVector.push_back(root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

//前序非递归遍历
void PreOrder2(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* p = root;
    vector<int> result;
    while (p || !s.empty())
    {
        if (p)
        {
            result.push_back(p->val);
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            p = p->right;
            s.pop();
        }
    }
}

//中序递归遍历
vector<int> inResult;
void InOrder(TreeNode* root)
{
    if (root != NULL) {
        InOrder(root->left);
        inResult.push_back(root->val);
        InOrder(root->right);
    }
}

//中序非递归遍历
void InOrder2(TreeNode* root)
{
    stack<TreeNode*> s;
    vector<int> result;
    TreeNode* p = root;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            result.push_back(p->val);
            s.pop();
            p = p->right;
        }
    }
}

//后序递归遍历
vector<int> postResult;
void PostOrder(TreeNode* root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        postResult.push_back(root->val);
    }
}

//后序非递归遍历
void PostOrder2(TreeNode* root)
{
    stack<TreeNode*> s;
    vector<int> result;
    TreeNode* p = root;
    TreeNode* r =new TreeNode(0);
    while (p || !s.empty())
    {
        //走到最左边
        if (p)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            //取栈顶结点
            p  = s.top();
            //如果右子树存在,且未被输出
            if (p->right&&p->right!=r)
            {
                p = p->right;
                s.push(p);
                //在走到最左
                p = p->left;
            }
            //否则,访问栈顶结点并弹出
            else
            {
                result.push_back(p->val);
                //记录该结点
                r = p;
                s.pop();
                //结点访问完后,重置p指针
                p = NULL;
            }
        }
    }
}
```



<a id="二叉搜索树与双向链表"></a>

### 26. 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向

```cpp

#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    
    //中序遍历后为排序结果
    void Order(TreeNode* root,vector<TreeNode*>& result)
    {
        if (root != NULL) {
            Order(root->left,result);
            result.push_back(root);
            Order(root->right,result);
        }
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL) {
            return NULL;
        }
        vector<TreeNode*> result;
        Order(pRootOfTree, result);
        TreeNode* tmp;
        for (int i = 0;i < result.size();i++)
        {
            if (i != 0)
            {
                TreeNode* p = result[i];
                tmp->right = p;
                p->left = tmp;
            }
            tmp = result[i];
        }
        return result[0];
    }
};
```

<a id="字符串的排列"></a>

### 27. 字符串的排列

输入一个字符串,按字典序打印出该字符串中字符的所有排列。

例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 

输入描述:  输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母

```cpp
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    void Permutation2(string& str,int k,int n,vector<string>& res)
    {
        if (k==n) {
            res.push_back(str);
            return;
        }
        for (int i = k; i < n; i++) {
            if (str[i] == str[k] && i != k)
                continue;
            swap(str[k], str[i]);
            Permutation2(str, k+1, n, res);
            swap(str[k], str[i]);
        }
    }
    
    vector<string> Permutation(string str){
        vector<string> res;
        int n = str.length();
        if (n == 0)
            return res;
        Permutation2(str, 0, n, res);
        sort(res.begin(), res.end());
        return res;
    }
};
```

<a id="数组中出现次数超过一半的数字"></a>

### 28. 数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字.

例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。

由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

如果不存在则输出0

```cpp
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
```

<a id="红黑树,快排,堆排"></a>

### 红黑树,快排,堆排

[红黑树](https://www.cnblogs.com/skywang12345/p/3245399.html)

[快排](https://baike.baidu.com/item/快速排序算法/369842?fr=aladdin)

[堆排](https://www.cnblogs.com/jingmoxukong/p/4303826.html)

<a id="最小的K个数"></a>

### 29. 最小的K个数

输入n个整数，找出其中最小的K个数。

例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4

```cpp
#include <vector>
#include <set>
using namespace std;
/*
 解法1:
 运用快排的思想
 把数组的元素分成两组,右边比左边的都要大
 数据都读到内存,并且修改数组
 */
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int>input,int k)
    {
        vector<int> res;
        int n = input.size();
        if (n == 0 || k > n || k <= 0) {
            return res;
        }
        int start = 0,end = n-1;
        int mid = partition(input, start, end);
        while (mid != k-1)
        {
            if (mid > k-1)
            {
                end = mid - 1;
                mid = partition(input, start, end);
            }
            else
            {
                start = mid + 1;
                mid = partition(input, start, end);
            }
        }
        for (int i = 0; i < k; i++) {
            res.push_back(input[i]);
        }
        return res;
    }
    
    int partition(vector<int>& input,int start,int end)
    {
        int key = input[start];
        while (start < end)
        {
            while (start < end && input[end] >= key)
                end --;
            input[start] = input[end];
            while (start < end && input[start] <= key)
                start++;
            input[end] = input[start];
        }
        input[start] = key;
        return start;
    }
};
/*
 解法2
 用大根堆的思想
 这里用multiset(内部红黑树,查找快(Ologn))保存k个元素,greater排序保证首个元素为最大
 k个元素之后每个与multiset首个元素比较
 适合海量数据,不修改原数组,修改都在multiset中
 */
class Solution2 {
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int n = input.size();
        if (n == 0 || n < k || k <= 0)
            return vector<int>();
        multiset<int,greater<int>> leastNumbers;
        for (int i = 0;i < n;i++)
        {
            if (i < k)
                leastNumbers.insert(input[i]);
            else
            {
                multiset<int,greater<int>> ::const_iterator iter = leastNumbers.begin();
                if (*iter > input[i]) {
                    leastNumbers.erase(iter);
                    leastNumbers.insert(input[i]);
                }
            }
        }
        vector<int> res(leastNumbers.begin(),leastNumbers.end());
        return res;
    }
};
```

<a id="连续子数组的最大和"></a>

### 30. 连续子数组的最大和

HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8 ( 从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int>array)
    {
        int n = (int)array.size();
        if (n == 0)
            return 0;
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum <= 0)
                sum = array[i];
            else
                sum += array[i];
            if (sum > maxSum)
                maxSum = sum;
        }
        return maxSum;
    }
};
```

<a id="整数中1出现的次数(从1到n整数中1出现的次数)"></a>

### 31. 整数中1出现的次数(从1到n整数中1出现的次数)

求出`1~13`的整数中1出现的次数,并算出`100~1300`的整数中1出现的次数？为此他特别数了一下`1~13`中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数

```cpp
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
```

<a id="把数组排成最小的数"></a>

### 32. 把数组排成最小的数

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323

```cpp
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers)
    {
        vector<string> strNum;
        for (int i = 0; i < numbers.size(); i++)
        {
            string s = to_string(numbers[i]);
            strNum.push_back(s);
        }
        sort(strNum.begin(), strNum.end(), cmp);
        string res = "";
        for (int i = 0;i < strNum.size();i++)
            res += strNum[i];
        return res;;
    }
    
    static bool cmp(const string s1,const string s2)
    {
        string num1 = s1 + s2;
        string num2 = s2 + s1;
        return num1 < num2;
    }
};
```

<a id="丑数"></a>

### 33. 丑数

把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数

```cpp
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
```

<a id="第一个只出现依次的字符"></a>

### 34. 第一个只出现依次的字符

在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置

```cpp
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        //由于字符(char)是一个长度为8的数据类型,因此总共有可能256种可能.
        vector<int> num(256,0);
        int n = (int)str.length();
        if (n == 0)
            return -1;
        for (int i = 0; i < n; i++)
        {
            int c = str[i];
            num[c] ++;
        }
        int res = -1;
        for (int i = 0 ; i < n; i++)
        {
            if (num[str[i]] == 1)
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
```

<a id="数组中的逆序对"></a>

### 35. 数组中的逆序对

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007 

**输入描述**:题目保证输入的数组中没有的相同的数字
 
**数据范围：**

对于%50的数据,size<=10^4
        
对于%75的数据,size<=10^5
        
对于%100的数据,size<=2*10^5
    
```cpp
/*
 归并排序
 1. 先按顺序拆成一个个
 2. 相邻的比较并计数,比较后排序成小->大(正序)
 3. 相邻的两两比较并排序,比较后排序(4个数正序)
 3. 相邻两组比较(每组4个)...
 */
#include <vector>
using namespace std;
class Solution {
public:
    int InversePairs(vector<int> data) {
        int n = (int)data.size();
        if (n==0)
            return 0;
        int count = 0;
        MergeSort(data, 0, n-1, count);
        return count % 1000000007;
    }
    void MergeSort(vector<int>& data,int start,int end,int& count)
    {
        if (start < end)
        {
            int mid = (start + end)/2;
            MergeSort(data, start, mid, count);
            MergeSort(data, mid+1, end, count);
            Merge(data, start, mid, mid+1, end, count);
        }
    }
    void Merge(vector<int>& data,int lbegin,int lend,int rbegin,int rend,int& count)
    {
        int i = lend,j = rend;
        int n = rend - lbegin + 1;
        int k = n - 1 ;
        vector<int> tmp(n,0);
        while (i >= lbegin && j >= rbegin)
        {
            if (data[i] > data[j])
            {
                count += j - rbegin + 1;
                count %= 1000000007;
                tmp[k] = data[i];
                k--;
                i--;
            }
            else
            {
                tmp[k] = data[j];
                k--;
                j--;
            }
        }
        while (i >= lbegin)
        {
            tmp[k] = data[i];
            k--;
            i--;
        }
        while (j >= rbegin)
        {
            tmp[k] = data[j];
            k--;
            j--;
        }
        for (i = lbegin,k = 0; i <= rend; i++,k++)
        {
            data[i] = tmp[k];
        }
    }
};
```        

<a id="两个链表的第一个公共结点"></a>

### 36. 两个链表的第一个公共结点

输入两个链表，找出它们的第一个公共结点

```cpp
/*
 因为每个节点只有一个next结点,所以如果有公共结点,那从改结点后都为相同结点
 呈现为Y形状
 */

#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
    val(x),next(NULL) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2)
    {
        if (pHead1 == NULL || pHead2 == NULL) {
            return NULL;
        }
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);
        int dist = 0;
        ListNode* pLong = NULL;
        ListNode* pShort = NULL;
        if (len1 > len2) {
            pLong = pHead1;
            pShort = pHead2;
            dist = len1 - len2;
        }
        else
        {
            pLong = pHead2;
            pShort = pHead1;
            dist = len2 - len1;
        }
        for (int i = 0; i<dist;i++)
        {
            pLong = pLong->next;
        }
        while (pLong)
        {
            if (pLong->val==pShort->val) {
                return pLong;
            }
            pLong = pLong->next;
            pShort = pShort->next;
        }
        return NULL;
    }
    
    int getLength(ListNode* head)
    {
        ListNode* p = head;
        int count = 0;
        while (p) {
            count ++;
            p = p->next;
        }
        return count;
    }
};
```

<a id="数字在排序数组中出现的次数"></a>

### 37. 数字在排序数组中出现的次数

统计一个数字在排序数组中出现的次数

```cpp
/*
 因为有序数组,想到二分查找
 修改二分查找
 因为可能有重复出现
 找到左边的第一个索引和右边的最后一个索引即可
 */

#include <vector>
using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int>data, int k)
    {
        int n = (int)data.size();
        if (n == 0)
            return 0;
        int left = leftEqual(data, k);
        int right = rightEqual(data, k);
        if (left!=-1&&right!=-1)
            return right-left+1;
        return 0;
    }
    
    int leftEqual(vector<int>& data,int k)
    {
        int left = 0,right = (int)data.size()-1;
        int mid;
        while (left <= right)
        {
            mid = (left+right) / 2;
            if (data[mid]==k)
            {
                if (mid==left || (mid-1>=left && data[mid-1] != k))
                    return mid;
                right = mid - 1;
            }
            else if (data[mid]>k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return  -1;
    }
    
    int rightEqual(vector<int>& data,int k)
    {
        int left = 0,right=(int)data.size()-1;
        int mid;
        while (left <= right) {
            mid = (left+right)/2;
            if (data[mid]==k) {
                if (mid == right || (mid+1 <= right && data[mid+1] != k))
                    return mid;
                left = mid + 1;
            }
            else if(data[mid] > k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};
```

<a id="二叉树的深度"></a>


### 38. 二叉树的深度

输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度

```cpp
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){
            
        }
};

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;
        int left = 0;
        int right = 0;
        if (pRoot->left)
            left = TreeDepth(pRoot->left);
        if (pRoot->right)
            right = TreeDepth(pRoot->right);
        return 1 + max(left, right);
    }
};
```

<a id="平衡二叉树"></a>

### 39. 平衡二叉树

输入一棵二叉树，判断该二叉树是否是平衡二叉树

```cpp
#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x),left(NULL),right(NULL){
            
        }
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot){
        if (pRoot == NULL)
            return true;
        int depth = 0;
        return Balance(pRoot, depth);
    }
    
    //后序遍历保证每个结点只被遍历一次
    bool Balance(TreeNode* pRoot,int& depth)
    {
        if (pRoot == NULL)
            return true;
        int left = 0,right = 0;
        if (Balance(pRoot->left, left) && Balance(pRoot->right, right))
        {
            int dif = left - right;
            if (dif >= -1 && dif <= 1)
            {
                depth = left > right ? left + 1 : right + 1;
                return true;
            }
        }
        return false;
    }
};
```