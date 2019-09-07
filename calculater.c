#include<stdlib.h>
#include"operation.h"
int main(void)
{

	printf("*************************************************************************************************\n");
	printf("请输入你要进行的运算的运算式（计算器1.0版本，只能算形如A + B这样的二元正整数的加减乘除以及阶乘哦）\n");
	printf("*************************************************************************************************\n");
	int x[N*N + 1] = { 0 }, y[N + 1] = { 0 }, z[2 * N + 1] = { 0 }, n = 0, precision;
	bool flag;
	char op = input(x, y, &n);
	if (op == '!')
	{
		printf("%d", n);
		putchar(op);
		putchar('=');
		factorial(x, n);
		output(x);
	}
	else
	{
		if (op == '/')
		{
			printf("请输入精度:");
			scanf("%d", &precision);
		}
		output(x);
		putchar(op);
		output(y);
		putchar('=');
		switch (op)
		{
		case '+':plus(x, y); output(x); break;
		case'-':
			if (flag = compare(x, y))
			{
				minus(x, y);
				output(x);
			}
			else
			{
				printf("-");//符号
				minus(y, x);
				output(y);
			}
			break;
		case'*':multiply(x, y, z); output(z); break;
		case'/':
			if (precision == 0)
			{
				divide(x, y, z);
				output(z);
				printf("……");
				output(x);
				break;
			}
			else
			{
				divide_decimal(x, y, z, precision);
				output(z);
				break;
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
