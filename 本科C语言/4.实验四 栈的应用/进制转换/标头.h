#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int SElemType;
typedef int Status;
typedef struct 
{
	SElemType *base;  //栈底指针
	SElemType *top;   //栈顶指针
	int stacksize;    //当前已分配的存储空间，以元素为单位
}SqStack;
#define ksize 100
#define increment 10
Status InitStack(SqStack &S)   //构造一个空栈
{
	S.base = (SElemType*)malloc(ksize * sizeof(SElemType));
	if (!S.base)
	{
		cout << "存储分配失败" << endl;
		return -1;
	}
	S.top = S.base;
	S.stacksize = ksize;
	return 1;
}
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
	{
		return 1;
	}
	return 0;
}
Status Push(SqStack &S, SElemType e)//插入元素e为新的栈顶元素
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + increment) * sizeof(SElemType));
		if (!S.base)
		{
			cout << "存储分配失败" << endl;
			return -1;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += increment;
	}
	*S.top++ = e;
	return 1;
}
Status Pop(SqStack &S, SElemType &e)//若栈不空，则删除S的栈顶元素，用e返回其值
{
	if (S.top == S.base)
	{
		return 0;
	}
	e = *--S.top;
	return 1;
}
Status traverse(int N)
{
	SqStack S;
	SElemType e;
	InitStack(S);
	while (N)
	{
		Push(S, N % 6);
		N = N / 6;
	}
	cout << "转换成的六进制数为：" << endl;
	while (!StackEmpty(S))
	{
		Pop(S, e);
		cout << e;
	}
	return 1;
}