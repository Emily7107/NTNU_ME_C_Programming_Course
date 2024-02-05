#include<stdio.h>
#include<stdlib.h>
int classwork1(int select2)
{
	
	switch (select2)
	{
	case 1:
		printf_s("執行classwork1_1\n");
		int x;
		double y;
		char z;
		x = 5;
		y = 0.031415;
		z = 'a';
		printf_s("x=%d\ny=%f\ny=%e\nz=%c\n", x, y, y, z);
		system("pause");
		break;
	case 2:
		printf_s("執行classwork1_2\n");
		int xn;
		double y1;
		char z1;
		printf_s("Please input x: ");
		scanf_s("%d", &xn);
		printf_s("Please input y: ");
		scanf_s("%lf", &y1);
		printf_s("Please input z: ");
		scanf_s(" %c", &z1, sizeof(z1));
		printf_s("x=%d y=%f z=%c", xn, y1, z1);
		system("pause");
		break;
	case 3:
		printf_s("執行classwork1_3\n");
		int a, b, c;
		printf_s("Please input a: ");
		scanf_s("%d", &a);
		printf_s("Please input b: ");
		scanf_s("%d", &b);
		c = (a * a - b * b * b) / (2 * a);
		printf_s("result=%d\n", c);

		system("pause");
		break;
	case 4:
		printf_s("執行classwork1_4\n");
		double a1, b1, c1;
		printf_s("Please input a: ");
		scanf_s("%lf", &a1);
		printf_s("Please input b: ");
		scanf_s("%lf", &b1);
		c1 = (a1 * a1 - b1 * b1 * b1) / (2 * a1);
		printf_s("result=%lf\n", c1);
		system("pause");
		break;
	case 5:
		printf_s("執行classwork1_5\n");
		int a2, b2, c2, d, x1, x2, x3, x4, x5, x6, x7, x8, x9;
		printf("請輸入a+bi: ");
		scanf_s("%d%d", &a2, &b2);
		printf_s("請輸入c+di: ");
		scanf_s("%d%d", &c2, &d);
		x1 = (a2 + c2);
		x2 = (b2 + d);
		x3 = (a2 - c2);
		x4 = (b2 - d);
		x5 = (a2 * c2 - b2 * d);
		x6 = (a2 * d + b2 * c2);
		x7 = (b2 * c2 - a2 * d);
		x8 = (c2 * c2 + d * d);
		x9 = (c2 - d);
		printf_s("(a+bi)+(c+di)=%d+%di\n", x1, x2);
		printf_s("(a+bi)-(c+di)=%d+&di\n", x3, x4);
		printf_s("(a+bi)*(z+di)=%d+%di\n", x5, x6);
		printf_s("(a+bi)/(c+di)=%d*%di/%d=%d+%di/%d\n", x1, x9, x8, x5, x7, x8);
		system("pause");
		break;

	}
	if (select2 < 0 || select2 > 5)
	{
		printf_s("輸入錯誤\n");
		system("pause\n");
	}
	return(select2);
}