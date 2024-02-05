#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void longestPlateau(int nArr[], int size, int ans[]);
void bubbleSort(int arr[], int nsize);
int main()
{
	int arr[1000] = { 0 }, nowl, i, n, ans[2];
	printf("How many data do you want?\n");
	scanf_s("%d", &n);
	printf_s("The data is:\n");
	nowl = time(NULL);
	srand(nowl);
	for (i = 0;i <= n - 1;i++)
	{
		arr[i] = 1 + rand() % 10;
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
	bubbleSort(arr, n);
	longestPlateau(arr, n, ans);
	system("pause");
}
void bubbleSort(int arr[], int nsize)
{
	int pass, i, temp;
	bool flag;
	printf_s("Data items in ascending order\n");
	for (pass = 1;pass < nsize;pass++)
	{
		flag = false;
		for (i = 0;i < nsize - pass;i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = true;
			}
		}
		if (false == flag)
			break;
	}
	for (i = 0;i <= nsize - 1;i++)
		printf_s("%d ", arr[i]);
	printf_s("\n");
}
void longestPlateau(int nArr[], int size, int ans[])
{
	int i, d,max,freq[1000] = { 0 },data=0;
	for (i = 0;i <= size-1;i++)
	{
		d = nArr[i];
		freq[d - 1]++;
	}
	max = freq[0];
	for (i = 0;i <= size - 1;i++)
	{
		if (max < freq[i + 1])
		{
			max = freq[i + 1];
			data = i + 1;
		}

	}
	ans[0] = max;
	ans[1] = data+1;
	printf_s("出現頻率最高的數字為%d,次數為%d\n",ans[1], ans[0]);
}