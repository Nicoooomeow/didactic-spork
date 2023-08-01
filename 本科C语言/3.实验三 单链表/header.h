#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;                //数据域
	struct LNode *next;      //指针域
}LNode, *LinkList;
void InitList(LNode *&p, int n)           //创建单链表
{
	LinkList L, k;
	p = L = k = new LNode;
	cin >> p->data;
	for (int a = 0; a<n - 1; a++)
	{
		k = new LNode;
		cin >> k->data;
		k->next = L;
		L->next = k;
		L = k;
	}
}
/*void InitList(LinkList &L,int n)
{
	int i = 0;
	L = new LNode;
	L->next = NULL;
	LNode *p;
	for (int i = 0; i <n; i++)
	{
		p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}*/
void Traverse(LinkList &L,int n)
{
	int i = 0;
	for (int i = 0; i <n; i++)
	{
		L = L->next;
		cout << L->data << " ";
	}
	cout << endl;
}

void ListInsert(LNode *L, int n)
{
	LNode *p;
	int e = 38;
	p = new LNode;
	p->data = e;
	for (int i = 0; i<n; i++)
		if (i == n - 1)
		{
			p->next = L->next;
			L->next = p;
		}
		else
			L = L->next;
}

int ListDelete(LNode *L, int i)
{
	int a = 0;
	for (int x = 0; x<i ; x++)
		if (x == i-1)
		{
			a = L->next->data;
			L->next = L->next->next;
			return a;
		}
		else
			L = L->next;
	return 0;
}
LNode * ListReserch(LNode *L, int n, int e)//查找元素
//指针函数，指针函数是指带指针的函数，即本质是一个函数。
//函数都有返回类型（如果不返回值，则为无值型）
//只不过指针函数返回类型是某一类型的指针。
{                                                  
	for (int a = 0; a < n; a++)
	{
		if (L->data == e)
		{
			return L;
		}
		else
		{
			L = L->next;
		}
	}
	cout << "没有相等的数" << endl;
	return NULL;
}
/*LNode * Seek(LNode *p, int n, int e)
{
	for (int i = 0; i < n; i++)
	{
		if (p->data == e)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	return NULL;
}

void  Combine(LNode *La, int a, LNode *Lb, int b)            //合并单链表
{
	LNode *p;
	for (int z = 0; z < a ; z++)
	{
		La = La->next;
	}
	for (int x = 0; x<b; x++)
	{
		p = Seek(La, a, Lb->data);
		if (p== NULL)
		{
			La->next = Lb;
			La = La->next;
		}
		if (x != b - 1)
		{
			Lb = Lb->next;
		}
	}
}*/
void Combine(LinkList La,int a, LinkList Lb,int b)
{
	LNode *p, *k,*q;
	p = k = La;
	q = Lb;
	for (int i = 0; i < a; i++)
	{
		La = La->next;
	}
	La->next = q;
	delete Lb;
	for (int i = 0; i < a + b; i++)
	{
		for (int i = 0; i < a + b; i++)
		{
			k = k->next;
			if (k->data = p->data)
			{
				p->next = p->next->next;
			}
		}
		p = p->next;
	}
}