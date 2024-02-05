#include<stdio.h>
#include<stdlib.h>
struct studentData
{
	int id;
	char name[20];
	double height;
	double weight;
	char sex;
};
typedef struct studentData sst;
void print(sst a[], int n);
void swap(sst&, sst&);
void sortheight(sst a[], int n);
void sortweight(sst a[], int n);
int main()
{
	int n = 3;
	sst a[3] = { {9301,"Peter",173.2,65.2,'M'},{9302,"Mary",168.3,47.3,'F'},{9310,"John",170.5,70.5,'M'} };
	printf_s("==============before sorting==============\n");
	print(a, n);
	printf_s("==============sort by Height==============\n");
	sortheight(a, n);
	print(a, n);
	printf_s("==============sort by Weight==============\n");
	sortweight(a, n);
	print(a, n);
	system("pause");
}
void print(sst a[], int n)
{
	int i;
	printf_s("%8s %8s %20s %8s %8s %8s\n", "No.", "ID", "Name", "Height", "Weight", "Sex");
	for (i = 0;i < n;i++)
		printf_s("%8d %8d %20s %8.2lf %8.2lf %8c\n", i, a[i].id, a[i].name, a[i].height, a[i].weight, a[i].sex);
}
void sortheight(sst a[], int n)
{
	int pass, i;
	for (pass = 1;pass < n;pass++)
	{
		for (i = 0;i < n - pass;i++)
		{
			if (a[i].height > a[i+1].height)
				swap(a[i], a[i + 1]);
		}
	}
}
void sortweight(sst a[], int n)
{
	int pass, i;
	for (pass = 1;pass < n;pass++)
	{
		for (i = 0;i < n - pass;i++)
		{
			if (a[i].weight > a[i+1].weight)
				swap(a[i], a[i + 1]);
		}
	}
}
void swap(sst& a, sst& b)
{
	sst temp;
	temp = a;
	a = b;
	b = temp;
}