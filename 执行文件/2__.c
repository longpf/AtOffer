// 请实现一个函数，将一个字符串中的空格替换成“%20”。
// 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

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