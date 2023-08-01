#include<iostream>
using namespace std;
typedef int Status;
typedef struct
{
	char *base;  //ջ��ָ��
	char *top;   //ջ��ָ��
	int stacksize;    //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;
Status InitStack(SqStack &S)   //����һ����ջ
{
	S.base = new char;
	if (!S.base)
	{
		cout << "�洢����ʧ��" << endl;
		return -1;
	}
	S.top = S.base;
	S.stacksize = 20;
	return 1;
}
Status DestroyStsck(SqStack &S) //����ջ
{
	delete S.base;
	S.base = 0;
	S.top = 0;
	S.stacksize = 0;
	if (!S.base)
		return 1;
	else return 0;
}
Status ClearStack(SqStack &S) //���ջ
{
	S.top = S.base;
	return 1;
}
Status Push(SqStack &S, char e)//����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = new char;
		if (!S.base)
		{
			cout << "�洢����ʧ��" << endl;
			return -1;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += 10;
	}
	*S.top++ = e;
	return 1;
}
Status Pop(SqStack &S, char &e)//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ
							   //����ջ��Ԫ��
{
	if (S.top == S.base)
	{
		return 0;
	}
	e = *--S.top;
	return 1;
}
Status GetTop(SqStack &S, char &e)//��ջ���գ���e����S��ջ��Ԫ��
{
	if (S.top == S.base)
	{
		return 0;
	}
	e = *(S.top - 1);
	return 1;
}
Status distinguish(char e)//�Ƚ���������ȼ�
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
	int j = 0;//����������
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