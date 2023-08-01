#include"header.h"
using namespace std;
LinkList LA;
LinkList LB;
void main()
{
	cout << "请倒序输入LA：25，12，78，34，100，88" << endl;
	InitList(LA,6);
	//cout << "确认LA：" << endl;
	//Traverse(LA, 6);

	cout << "请倒序输入LB：88，10，15，25，32" << endl;
	InitList(LB,5);
	//cout << "确认LB：" << endl;
	//Traverse(LB, 5);

	cout << "先将38插入LA第三个结点之后" << endl;
	system("Pause");
	ListInsert(LA,3);
	cout << "插入后的La为：" << endl;
	//Traverse(LA, 7);
	LNode *a;
	a = LA->next;
	for (int i = 0; i <7; i++)
	{
		cout << a->data<<" ";
		a = a->next;
	}
	cout << endl;

	cout << "现删除LB中的第四个元素" << endl;
	ListDelete(LB, 4);
	cout << "删除后LB为" << endl;
	//Traverse(LB, 4);
	LNode *b;
	b = LB->next;
	for (int i = 0; i < 4; i++)
	{
		cout << b->data << " ";
		b = b->next;
	}
	cout << endl;

	cout << "请输入在LA中要查找的元素：";
	int e;
	cin >> e;
	cout <<"返回的指向元素的指针为：";
	LNode *q;
	q=ListReserch(LA, 7, e);
	if (q != NULL)
	{
		cout << q->data << endl;
	}
	system("Pause");

	cout << "现将LA与LB合并，合并后为：" << endl;
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