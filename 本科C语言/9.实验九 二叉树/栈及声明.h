#include<iostream>
using namespace std;
//树的数据定义
typedef char TElemType;
typedef int Status;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
//栈的数据定义
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
}PostSqStack;//用于后序
Status InitStack(SqStack &S)//初始化栈
{
	S.base = new SElemType[STACK_INIT_SIZE];
	if (!S.base) return 0;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
Status StackEmpty(SqStack S)//判断栈是否为空
{
	return(S.top == S.base);
}
Status Push(SqStack &S, SElemType &e)//压入堆栈元素
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
Status Pop(SqStack &S, SElemType &e)//弹出堆栈元素
{
	if (S.top <= S.base) return 0;
	else e = *--S.top;
	return 1;
}
Status GetTop(SqStack S, SElemType &e) //取栈顶元素
{
	if (S.base == S.top) return 0;
	e = *(S.top - 1);
	return 1;
}
Status PostInitStack(PostSqStack &S) //初始化栈
{
	S.base = new PostSElemType[STACK_INIT_SIZE];
	if (!S.base) return 0;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
Status PostPush(PostSqStack &S, PostSElemType &e)//压入堆栈元素
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
Status PostStackEmpty(PostSqStack S) //判断栈是否为空
{
	return(S.top == S.base);
}
Status PostPop(PostSqStack &S, PostSElemType &e)//弹出堆栈元素
{
	if (S.top <= S.base) return 0;
	else e = *--S.top;
	return 1;
}
