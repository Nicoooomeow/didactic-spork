#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int SElemType;
typedef int Status;
typedef struct 
{
	SElemType *base;  //ջ��ָ��
	SElemType *top;   //ջ��ָ��
	int stacksize;    //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;
#define ksize 100
#define increment 10
Status InitStack(SqStack &S)   //����һ����ջ
{
	S.base = (SElemType*)malloc(ksize * sizeof(SElemType));
	if (!S.base)
	{
		cout << "�洢����ʧ��" << endl;
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
Status Push(SqStack &S, SElemType e)//����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + increment) * sizeof(SElemType));
		if (!S.base)
		{
			cout << "�洢����ʧ��" << endl;
			return -1;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += increment;
	}
	*S.top++ = e;
	return 1;
}
Status Pop(SqStack &S, SElemType &e)//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ
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
	cout << "ת���ɵ���������Ϊ��" << endl;
	while (!StackEmpty(S))
	{
		Pop(S, e);
		cout << e;
	}
	return 1;
}