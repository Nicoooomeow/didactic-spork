#define MaxVex 100 //最大顶点数
#define INFINTY 0
#define TURE 1
#define FALSE 0
#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10
#define MAXSIZE  50
typedef enum { DG, DN, UDG, UDN }GraphKind;
typedef char VertexType;//定点类型
typedef int  EdgeType;//权值类型

//栈相关函数
typedef struct 
{
	int * base;
	int * top;
	int stacksize;
}SqStack;
int InitStack(SqStack &S) 
{
	S.base = new int[STACK_INIT_SIZE];
	if (!S.base)exit(OVERFLOW);;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
int Push(SqStack &S, int &e) 
{
	if (S.top - S.base >= S.stacksize) 
	{
		S.base = (int *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(int));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 1;
}
int Gettop(SqStack &S, int &e)
{
	if (S.base == S.top)
	{
		return 0;
	}
	e = *(S.top - 1);
	return e;
}
int Pop(SqStack &S, int &e)//若栈不空，则删除S的栈顶元素，用e返回其值
							   //弹出栈顶元素
{
	if (S.top == S.base)
	{
		return 0;
	}
	e = *--S.top;
	return 1;
}