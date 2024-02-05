#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int binarySearch(const int data[], int search, int n);
void bubbleSort(int arr[], int nsize);
void longestPlateau(int nArr[], int size, int ans[]);
double median(int arr[], int nSize);
void p1();
void p2();
void p3();
int classwork8(int select2)
{
	switch (select2)
	{
	case 1:
		p1();
		break;
	case 2:
		p2();
		break;
	case 3:
		p3();
		break;
	}
	if (select2 < 0 || select2 > 3)
	{
		printf_s("輸入錯誤\n");
		system("pause\n");
	}
	return(select2);
}
void p1()
{
	int a[1000] = { 0 }, i, n, search;
	int nowl;
	printf_s("How many data do you want?\n");
	scanf_s("%d", &n);
	nowl = time(NULL);
	srand(nowl);
	printf_s("The data is:\n");
	for (i = 0;i <= n - 1;i++)
	{
		a[i] = 1 + rand() % 100;
		printf_s("%d ", a[i]);
	}
	printf_s("\n");
	bubbleSort(a, n);
	printf_s("What number do you want to search?\n");
	scanf_s("%d", &search);
	if (binarySearch(a, search, n) == -1)
		printf_s("%d can't be found!\n", search);
	else
	{
		printf_s("the %d data is %d", binarySearch(a, search, n) + 1, search);
		printf_s("\n");
	}
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
int binarySearch(const int data[], int search, int n)
{
	int low = 0, high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (data[mid] == search)
			return mid;
		else if (search < data[mid])
			return binarySearch(data, search, mid);
		else if (search > data[mid])
			low = mid + 1;
	}
	return -1;
}
void p2()
{
	int a[1000] = { 0 },i,n,nowl;
	int b[100] = { 0 };
	int c[100] = { 0 };
	printf_s("How many number do you want?\n");
	scanf_s("%d", &n);
	nowl = time(NULL);
	srand(nowl);
	for (i = 0;i <= n - 1;i++)
	{
		a[i] = 1 + rand() % 100;
		printf_s("%d ", a[i]);
	}
	printf_s("\n");
	bubbleSort(a, n);
	if (n % 2 != 0)
	{
		for (i = 0;i < (n - 1) / 2;i++)
		{
			b[i] = a[i];
		}
		for (i = (n + 1) / 2;i <= n - 1;i++)
		{
			c[i- (n + 1) / 2] = a[i];
		}
		printf_s("Q1=%lf\n", median(b, (n - 1) / 2));
		printf_s("Q2=%lf\n", median(a, n));
		printf_s("Q3=%lf\n", median(c, (n - 1) / 2));
	}
	else
	{
		for (i = 0;i < n / 2-2;i++)
		{
			b[i] = a[i];
		}
		for (i = n / 2+1;i <= n - 1;i++)
		{
			c[i- (n / 2 + 1)] = a[i];
		}
		printf_s("Q1=%lf\n", median(b, n / 2-1));
		printf_s("Q2=%lf\n", median(a, n));
		printf_s("Q3=%lf\n", median(c, n / 2 - 1));
	}
	system("pause");
}
double median(int arr[], int nsize)
{
	if (nsize % 2 != 0)
		return (double)arr[(nsize - 1) / 2];
	else
		return ((double)arr[nsize / 2] + arr[nsize / 2 - 1]) / 2;
}
void p3()
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
	longestPlateau(arr,n,ans);
	system("pause");
}
void longestPlateau(int nArr[], int size, int ans[])
{
	int i, d, max, freq[1000] = { 0 },data=0;
	for (i = 0;i <= size - 1;i++)
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
	ans[0] = data+1;
	ans[1] = max;
		printf_s("出現頻率最高的數字為%d,次數為%d\n", ans[0], ans[1]);
}
