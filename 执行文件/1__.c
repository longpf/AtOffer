
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




