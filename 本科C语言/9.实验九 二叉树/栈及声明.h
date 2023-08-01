#include<iostream>
using namespace std;
//�������ݶ���
typedef char TElemType;
typedef int Status;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
//ջ�����ݶ���
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef BiTree SElemType;
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
typedef enum
{
	Travel, Visit
}Tag;
typedef struct
{
	BiTree ptr;
	Tag task;
}PostSElemType;
typedef struct
{
	PostSElemType * base;
	PostSElemType * top;
	int stacksize;
}PostSqStack;//���ں���
Status InitStack(SqStack &S)//��ʼ��ջ
{
	S.base = new SElemType[STACK_INIT_SIZE];
	if (!S.base) return 0;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
Status StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ��
{
	return(S.top == S.base);
}
Status Push(SqStack &S, SElemType &e)//ѹ���ջԪ��
{
	if (S.top - S.base >= S.stacksize)
	{
		SqStack p;
		p.base = new SElemType[S.stacksize + STACKINCREMENT];
		if (!p.base) return 0;
		S.base = p.base;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 1;
}
Status Pop(SqStack &S, SElemType &e)//������ջԪ��
{
	if (S.top <= S.base) return 0;
	else e = *--S.top;
	return 1;
}
Status GetTop(SqStack S, SElemType &e) //ȡջ��Ԫ��
{
	if (S.base == S.top) return 0;
	e = *(S.top - 1);
	return 1;
}
Status PostInitStack(PostSqStack &S) //��ʼ��ջ
{
	S.base = new PostSElemType[STACK_INIT_SIZE];
	if (!S.base) return 0;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
Status PostPush(PostSqStack &S, PostSElemType &e)//ѹ���ջԪ��
{
	if (S.top - S.base >= S.stacksize) 
	{
		PostSqStack p;
		p.base = new PostSElemType[S.stacksize + STACKINCREMENT];
		if (!p.base) return 0;
		S.base = p.base;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 1;
}
Status PostStackEmpty(PostSqStack S) //�ж�ջ�Ƿ�Ϊ��
{
	return(S.top == S.base);
}
Status PostPop(PostSqStack &S, PostSElemType &e)//������ջԪ��
{
	if (S.top <= S.base) return 0;
	else e = *--S.top;
	return 1;
}
