#include<iostream>
using namespace std;
typedef int Status;
typedef struct
{
	char *base;  //栈底指针
	char *top;   //栈顶指针
	int stacksize;    //当前已分配的存储空间，以元素为单位
}SqStack;
Status InitStack(SqStack &S)   //构造一个空栈
{
	S.base = new char;
	if (!S.base)
	{
		cout << "存储分配失败" << endl;
		return -1;
	}
	S.top = S.base;
	S.stacksize = 20;
	return 1;
}
Status DestroyStsck(SqStack &S) //销毁栈
{
	delete S.base;
	S.base = 0;
	S.top = 0;
	S.stacksize = 0;
	if (!S.base)
		return 1;
	else return 0;
}
Status ClearStack(SqStack &S) //清空栈
{
	S.top = S.base;
	return 1;
}
Status Push(SqStack &S, char e)//插入元素e为新的栈顶元素
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = new char;
		if (!S.base)
		{
			cout << "存储分配失败" << endl;
			return -1;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += 10;
	}
	*S.top++ = e;
	return 1;
}
Status Pop(SqStack &S, char &e)//若栈不空，则删除S的栈顶元素，用e返回其值
							   //弹出栈顶元素
{
	if (S.top == S.base)
	{
		return 0;
	}
	e = *--S.top;
	return 1;
}
Status GetTop(SqStack &S, char &e)//若栈不空，用e返回S的栈顶元素
{
	if (S.top == S.base)
	{
		return 0;
	}
	e = *(S.top - 1);
	return 1;
}
Status distinguish(char e)//比较运算符优先级
{
	int i;
	switch (e)
	{
	case '+':i = 1; break;
	case '-':i = 1; break;
	case '*':i = 2; break;
	case '/':i = 2; break;
	case '#':i = 0; break;
	case '(':i = 3; break;
	case ')':i = 1; break;
	}
	return i;
}
Status change(char string[], int n)
{
	int j = 0;//输出数组计数
	char a;
	char k;
	char e = '#';
	SqStack OP;
	InitStack(OP);
	Push(OP, e);
	char output[20];
	for (int z = n; z >= 0; z--)
	{
		a = string[z];
		if (a >= 'a'&& a <= 'z')
		{
			output[j] = a;
			j++;
		}
		else if (a == '(')
		{
			if (Pop(OP, k) != ')')
			{
				output[j] = k;
				j++;
			}
			Pop(OP, k);
		}
		else
		{
			GetTop(OP, k);
			if (distinguish(a) < distinguish(k))
			{
				Pop(OP, k);
				output[j] = k;
				Push(OP, a);
				j++;
			}
			else
			{
				Push(OP, a);
			}
		}
	}
	for (int i = 0; Pop(OP,k); i++)
	{
		output[j] = k;
		j++;
		
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (output[i] == '#')
		{
			continue;
		}
		cout << output[i];
	}
	return 1;
}