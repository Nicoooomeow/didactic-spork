#include<iostream>
#include"队列.h"
void CreateTree(CSTree &T) //按自上而下自左至右顺序输入双亲-孩子的有序对,建立二叉链表
{//输入时,以一对'#'作为结束标志,根的双亲空,也用'#'表示
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
			T = p;//所建结点为根
		}
		else
		{
			GetHead(Q, s);
			while (s->data != fa) 
			{//查询双亲结点
				DeQueue(Q, s);
				GetHead(Q, s);
			}
			if (!(s->firstchild)) 
			{//r指向当前父亲的最后一个孩子
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
void PreOrderTraverse(CSTree T)//前序递归遍历
{
	if (T)
	{
		cout << T->data << " ";
		PreOrderTraverse(T->firstchild);
		PreOrderTraverse(T->nextsibling);
	}
}
void InOrderTraverse(CSTree T)//中序递归遍历
{
	if (T) 
	{
		InOrderTraverse(T->firstchild);
		cout << T->data<<" ";
		InOrderTraverse(T->nextsibling);
	}
}
void PostOrderTraverse(CSTree T)//后序递归遍历
{
	if (T)
	{
		PostOrderTraverse(T->firstchild);
		PostOrderTraverse(T->nextsibling);
		cout << T->data << " ";
	}
}