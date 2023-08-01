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
Status InitQueue(SqQueue &Q)//����һ���ն���Q
{
	Q.base = new BiTree[MAXSIZE];
	if (!Q.front)
	{
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;
	return 1;
}
int QueueLength(SqQueue Q)//����Q��Ԫ�ظ����������еĳ���
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue &Q, BiTree &e)//����Ԫ��eΪQ���µĶ�βԪ��
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
	{
		return 0;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 1;
}

Status DeQueue(SqQueue &Q, BiTree &e)//�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
{
	if (Q.front == Q.rear)
	{
		return 0;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front+1) % MAXSIZE;
	return 1;
}

Status QueueEmpty(SqQueue &Q)//�ж��Ƿ�Ϊ��
{
	if (Q.rear == Q.front && QueueLength(Q) == 0)
	{
		return 1;
	}
	return 0;
}
