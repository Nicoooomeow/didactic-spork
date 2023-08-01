#include<iostream>
using namespace std;
typedef int QElemType;
typedef int Status;
#define MAXSIZE 100
typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
Status InitQueue(SqQueue &Q)//构造一个空队列Q
{
	Q.base = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	if (!Q.front)

	{
		cout<<"创建失败";
		return 0;
	}
	Q.front = Q.rear = 0;
	return 1;
}
int QueueLength(SqQueue Q)//返回Q的元素个数，及队列的长度
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status EnQueue(SqQueue &Q, QElemType e)//插入元素e为Q的新的队尾元素
{
	if ((Q.rear+1)%MAXSIZE==Q.front)
	{
		return 0;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 1;
}
Status DeQueue(SqQueue &Q, QElemType &e)//若队列不空，删除Q的队头元素，用e返回其值
{
	if (Q.front == Q.rear)
	{
		return 0;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return 1;
}
Status QueueEmpty(SqQueue &Q)//判断是否为空
{
	if (Q.rear == Q.front&&QueueLength(Q) == 0)
	{
		return 1;
	}
	return 0;
}
void Ynaghui(int n)//输出杨辉三角的前n行（n>0）
{
	SqQueue Q;
	QElemType e;
	for (int i = 1; i <= n - 1; i++)
	{
		cout << " ";
	}
	cout <<" "<< '1' << endl;//输出顶端的1
	InitQueue(Q);//n+1个元素有效
	EnQueue(Q, 1); 
	EnQueue(Q, 1);//第一行入队列
	int k = 1;
	int s = 0;
	while (k < n)//输出前n-1行
	{
		EnQueue(Q, 0);//行界标识‘0’入队列
		for (int i = 1; i <= n - k; i++)
		{
			cout << " ";
		}
		do 
		{
			DeQueue(Q, e);
			EnQueue(Q, s + e);
			if (e)cout << e << " "; 
			else 
			{
				cout << endl;
			}
			s = e;
		} while (e != 0);  //输出一行
		k++;
	}
	while(!QueueEmpty(Q))//单独输出第n行
	{
		DeQueue(Q, e);
		cout<< e << " ";
	}
}