#include"header.h"
using namespace std;
LinkList LA;
LinkList LB;
void main()
{
	cout << "�뵹������LA��25��12��78��34��100��88" << endl;
	InitList(LA,6);
	//cout << "ȷ��LA��" << endl;
	//Traverse(LA, 6);

	cout << "�뵹������LB��88��10��15��25��32" << endl;
	InitList(LB,5);
	//cout << "ȷ��LB��" << endl;
	//Traverse(LB, 5);

	cout << "�Ƚ�38����LA���������֮��" << endl;
	system("Pause");
	ListInsert(LA,3);
	cout << "������LaΪ��" << endl;
	//Traverse(LA, 7);
	LNode *a;
	a = LA->next;
	for (int i = 0; i <7; i++)
	{
		cout << a->data<<" ";
		a = a->next;
	}
	cout << endl;

	cout << "��ɾ��LB�еĵ��ĸ�Ԫ��" << endl;
	ListDelete(LB, 4);
	cout << "ɾ����LBΪ" << endl;
	//Traverse(LB, 4);
	LNode *b;
	b = LB->next;
	for (int i = 0; i < 4; i++)
	{
		cout << b->data << " ";
		b = b->next;
	}
	cout << endl;

	cout << "��������LA��Ҫ���ҵ�Ԫ�أ�";
	int e;
	cin >> e;
	cout <<"���ص�ָ��Ԫ�ص�ָ��Ϊ��";
	LNode *q;
	q=ListReserch(LA, 7, e);
	if (q != NULL)
	{
		cout << q->data << endl;
	}
	system("Pause");

	cout << "�ֽ�LA��LB�ϲ����ϲ���Ϊ��" << endl;
	Combine(LA, 7, LB, 5);
	LNode *z;
	z = LA->next;
	for (int i = 0; i < 11; i++)
	{
		cout << z->data << " ";
		z = z->next;
	}

	system("Pause");
}