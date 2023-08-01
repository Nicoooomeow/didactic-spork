#include "header.h"
using namespace std;
int main()
{
	ElemType e, X, i;
	SqList LA, LB;
	int j;

	InitList(LA);
	InitList(LB);

	if (InitList(LA) && InitList(LB))
	{
		cout << "Everything is OK!" << endl;
	}

	cout << "����˳���A"<<endl;
	GetList(LA);
	cout << "�����˳���LAΪ:" << endl;
	TraverseList(LA);

	cout << "����˳���B" << endl;
	GetList(LB);
	cout << "�����˳���LBΪ" << endl;
	TraverseList(LB);

	cout << "������Ҫ����LA��Ԫ��e" << endl;
	cin >> e;
	if (!ListInsert(e, LA))
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "����ɹ�" << endl << "�µ�˳���Ϊ" << endl;
	}
	TraverseList(LA);

	cout << "����Ҫ��LB��ɾ����Ԫ��λ��" << endl;
	cin >> j;
	if (!ListDelete(LB, j, e))
	{
		cout << "���벻�Ϸ�,ɾ��ʧ��" << endl;
	}
	else
	{
		cout << "ɾ���ɹ���ɾ����Ԫ��Ϊ" << e << endl;
	}

	cout << "����Ҫ��LA�в��ҵ�Ԫ��" << endl;
	cin >> X;
	if (!LocateElem(LA, X, i))
	{
		cout << "LA�в�����" << X << endl;
	}
	else
	{
		cout <<X<< "��λ��Ϊ";
		cout << i << endl;
	}

	UnionList(LA,LB);
	if (UnionList(LA, LB))
	{
		cout << "�ϲ�A��B˳����ϲ��ɹ����µ����Ա�Ϊ��" << endl;
		TraverseList(LA);
	}
	else
	{
		cout << "�ϲ�ʧ��" << endl;
	}
	if (ClearList(LA) && ClearList(LB) && DestroyList(LA) && DestroyList(LB))
	{
		cout << "The cleanup is complete" << endl;
	}
	system("pause");

	return 0;
}
