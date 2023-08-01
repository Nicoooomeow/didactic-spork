#include <iostream>
#define ksize 20
#define increment 10
using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct        //�����ṹ�幹��˳���
{
	ElemType * elem;
	int length;
	int listsize;
}SqList;


Status InitList(SqList & L)    //����˳���
{
	L.elem = new ElemType[ksize];
	if (!L.elem)
	{
		return 0;
	}
	L.length = 0;
	L.listsize = ksize;
	return 1;
};


void GetList(SqList & L)    //ѭ������˳�����ȡ���ȣ����룩
{
	int i=0;
	cout << "����˳���ĳ���(�������ǳ��ȣ�����������Ԫ�أ�)" << endl;
	cin >> L.length;
	cout << "��������˳��������(��С����)" << endl;
	for (i = 0; i < L.length; i++)
	{
		cin >> L.elem[i];
	}
}


void TraverseList(SqList L)      //���һ������Ԫ��
{
	int i=0;
	for (i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl;
}


/*Status ListInsert(ElemType e, SqList &L)     //����Ԫ��e
{
	int i = 0;
	ElemType *newbase;      //int *newbase=(int *)realloc(n*sizeof(int));
	if (i<1 && i>L.length + 1) 
	{
		return 0;
	}
	if (L.length >= L.listsize) 
	{
		newbase = new ElemType[L.listsize + increment];
		if (!newbase)
		{
			return 0;
		}
		L.elem = newbase;
		L.listsize =L.listsize+ increment;
	}
	for (i = L.length - 1; i >= 0 && L.elem[i]>e; i--) 
	{
		L.elem[i + 1] = L.elem[i];
	}
	L.elem[i + 1] = e;
	++L.length;
	return 1;
}*/
Status ListInsert(ElemType e, SqList &L)     //����Ԫ��e
{
	int i = 0;
	ElemType *newbase;      //int *newbase=(int *)realloc(n*sizeof(int));
	if (L.length >= L.listsize)
	{
		newbase = new ElemType[L.listsize + increment];
		if (!newbase)
		{
			return 0;
		}
		L.elem = newbase;
		L.listsize = L.listsize + increment;
	}
	for (i = L.length - 1; i >= 0 && L.elem[i]>e; i--)
	{
		L.elem[i + 1] = L.elem[i];
	}
	L.elem[i + 1] = e;
	L.length++;
	return 1;
}



Status ListDelete(SqList & L, int i, ElemType & e)    //ɾ��Ԫ��
{
	if (i > L.length || i < 1)
	{
		return 0;
	}
	int *p;
	int *q;
	p = &L.elem[i - 1];
	e = *p;
	q = L.elem + L.length - 1;
	for (p++; p <= q; p++)
	{
		*(p - 1) = *p;
	}
	L.length--;
	return 1;
}

Status LocateElem(SqList L, ElemType e, int & j)    //ȷ��λ��
{
	int i;
	int flag = 1;
	for (i = 0; i < L.length && flag; i++)
	{
		if (e == L.elem[i])
		{
			flag = 0;
			j = i + 1;
		}
	}
	if (!flag)
	{
		return j-1;
	}
	return 0;

}


Status UnionList(SqList & L1, SqList L2)     //�ϲ�����˳���
{
	ElemType *p2 = L2.elem;
	int tap;
	while (p2 <= (L2.elem + L2.length - 1))
	{
		if (!LocateElem(L1, *p2, tap))
		{
			ListInsert(*p2, L1);
		}
		p2++;
	}
	return 1;
}
Status ClearList(SqList & L)    //���˳���
{
	L.length = 0;
	return 1;
}
Status DestroyList(SqList & L)//����˳���
{
	delete L.elem;
	return 1;
}
