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
Status InitQueue(SqQueue &Q)//����һ���ն���Q
{
	Q.base = (QElemType*)malloc(MAXSIZE * sizeof(QElemType));
	if (!Q.front)

	{
		cout<<"����ʧ��";
		return 0;
	}
	Q.front = Q.rear = 0;
	return 1;
}
int QueueLength(SqQueue Q)//����Q��Ԫ�ظ����������еĳ���
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status EnQueue(SqQueue &Q, QElemType e)//����Ԫ��eΪQ���µĶ�βԪ��
{
	if ((Q.rear+1)%MAXSIZE==Q.front)
	{
		return 0;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 1;
}
Status DeQueue(SqQueue &Q, QElemType &e)//�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
{
	if (Q.front == Q.rear)
	{
		return 0;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return 1;
}
Status QueueEmpty(SqQueue &Q)//�ж��Ƿ�Ϊ��
{
	if (Q.rear == Q.front&&QueueLength(Q) == 0)
	{
		return 1;
	}
	return 0;
}
void Ynaghui(int n)//���������ǵ�ǰn�У�n>0��
{
	SqQueue Q;
	QElemType e;
	for (int i = 1; i <= n - 1; i++)
	{
		cout << " ";
	}
	cout <<" "<< '1' << endl;//������˵�1
	InitQueue(Q);//n+1��Ԫ����Ч
	EnQueue(Q, 1); 
	EnQueue(Q, 1);//��һ�������
	int k = 1;
	int s = 0;
	while (k < n)//���ǰn-1��
	{
		EnQueue(Q, 0);//�н��ʶ��0�������
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
		} while (e != 0);  //���һ��
		k++;
	}
	while(!QueueEmpty(Q))//���������n��
	{
		DeQueue(Q, e);
		cout<< e << " ";
	}
}