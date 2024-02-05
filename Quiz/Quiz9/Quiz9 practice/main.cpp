#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubbleSort(int arr[], int nsize);
double median(int arr[], int nSize);
int main()
{
	int i, n, a[1000] = { 0 }, nowl;
	char y;
	do {
		printf_s("Please input array size:\n");
		scanf_s("%d", &n);
		nowl = time(NULL);
		srand(nowl);
		for (i = 0;i <= n - 1;i++)
		{
			a[i] = 1 + rand() % 100;
		}
		printf_s("Data items in original order\n");
		for (i = 0;i <= n - 1;i++)
			printf_s("%d ", a[i]);
		printf_s("\n");
		bubbleSort(a, n);
		printf_s("¤¤¦ì¼Æ=%lf\n", median(a, n));
		printf_s("Again?\n");
		scanf_s(" %c", &y);
	} while (y == 'y' || y == 'Y');
	system("pause");
}
void bubbleSort(int arr[], int nsize)
{
	int i, pass, temp;
	bool flag;
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
		if (flag == false)
			break;
	}
	printf_s("Data items in ascending order\n");
	for (i = 0;i <= nsize - 1;i++)
		printf_s("%d ", arr[i]);
	printf_s("\n");
}
double median(int arr[], int nsize)
{
	if (nsize % 2 != 0)
		return (double)arr[(nsize - 1) / 2];
	else
		return ((double)arr[nsize / 2] + arr[nsize / 2 - 1]) / 2;
}