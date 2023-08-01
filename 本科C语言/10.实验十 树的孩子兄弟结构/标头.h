#include<iostream>
#include"����.h"
void CreateTree(CSTree &T) //�����϶�����������˳������˫��-���ӵ������,������������
{//����ʱ,��һ��'#'��Ϊ������־,����˫�׿�,Ҳ��'#'��ʾ
	ElemType fa, ch;
	CSNode *p, *s, *r;
	SqQueue Q;
	InitQueue(Q);
	T = NULL;
	for (cin >> fa >> ch; ch != '#'; cin >> fa >> ch) 
	{
		p = new CSNode;
		p->data = ch;
		p->firstchild = p->nextsibling = NULL;
		EnQueue(Q, p);
		if (fa == '#')
		{
			T = p;//�������Ϊ��
		}
		else
		{
			GetHead(Q, s);
			while (s->data != fa) 
			{//��ѯ˫�׽��
				DeQueue(Q, s);
				GetHead(Q, s);
			}
			if (!(s->firstchild)) 
			{//rָ��ǰ���׵����һ������
				s->firstchild = p;
				r = p;
			}
			else 
			{
				r->nextsibling = p;
				r = p;
			}
		}
	}
}
void PreOrderTraverse(CSTree T)//ǰ��ݹ����
{
	if (T)
	{
		cout << T->data << " ";
		PreOrderTraverse(T->firstchild);
		PreOrderTraverse(T->nextsibling);
	}
}
void InOrderTraverse(CSTree T)//����ݹ����
{
	if (T) 
	{
		InOrderTraverse(T->firstchild);
		cout << T->data<<" ";
		InOrderTraverse(T->nextsibling);
	}
}
void PostOrderTraverse(CSTree T)//����ݹ����
{
	if (T)
	{
		PostOrderTraverse(T->firstchild);
		PostOrderTraverse(T->nextsibling);
		cout << T->data << " ";
	}
}