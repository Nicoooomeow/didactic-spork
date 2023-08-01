#include<iostream>
using namespace std;
typedef char QElemType;
typedef int Status;
#define MAXSIZE 100
typedef struct
{
	BiTree *base;
	int front;
	int rear;
}SqQueue;
//typedef BiTree QElemType;
Status InitQueue(SqQueue &Q)//构造一个空队列Q
{
	Q.base = new BiTree[MAXSIZE];
	if (!Q.front)
	{
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;
	return 1;
}
int QueueLength(SqQueue Q)//返回Q的元素个数，及队列的长度
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue &Q, BiTree &e)//插入元素e为Q的新的队尾元素
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		return 0;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 1;
}

Status DeQueue(SqQueue &Q, BiTree &e)//若队列不空，删除Q的队头元素，用e返回其值
{
	if (Q.front == Q.rear)
	{
		return 0;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front+1) % MAXSIZE;
	return 1;
}

Status QueueEmpty(SqQueue &Q)//判断是否为空
{
	if (Q.rear == Q.front && QueueLength(Q) == 0)
	{
		return 1;
	}
	return 0;
}
