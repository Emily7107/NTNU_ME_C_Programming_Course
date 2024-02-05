﻿#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, x1, x2, t;
	printf("**********************************************\n");
	printf("*   臺灣師範大學機電工程系109程式設計Quiz1   *\n");
	printf("*   求解一元二次方程式ax^2+bx+c=0 的根       *\n");
	printf("**********************************************\n");
	printf("請依序輸入a, b, c 之值:\f");
	scanf_s("%f %f %f", &a, &b, &c);
	printf("a=%f\f b=%f\f c=%f\n", a, b, c);
	t = sqrt((b * b) - (4 * a * c));
	x1 = (-b + t) / (2 * a);
	x2 = (-b - t) / (2 * a);
	printf("x1=%f\nx2=%f\n", x1, x2);
}


// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
