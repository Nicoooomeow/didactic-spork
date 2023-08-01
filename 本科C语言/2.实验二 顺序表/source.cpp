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

	cout << "对于顺序表A"<<endl;
	GetList(LA);
	cout << "输入的顺序表LA为:" << endl;
	TraverseList(LA);

	cout << "对于顺序表B" << endl;
	GetList(LB);
	cout << "输入的顺序表LB为" << endl;
	TraverseList(LB);

	cout << "输入你要插入LA的元素e" << endl;
	cin >> e;
	if (!ListInsert(e, LA))
	{
		cout << "插入失败" << endl;
	}
	else
	{
		cout << "插入成功" << endl << "新的顺序表为" << endl;
	}
	TraverseList(LA);

	cout << "输入要在LB中删除的元素位序" << endl;
	cin >> j;
	if (!ListDelete(LB, j, e))
	{
		cout << "输入不合法,删除失败" << endl;
	}
	else
	{
		cout << "删除成功，删除的元素为" << e << endl;
	}

	cout << "输入要在LA中查找的元素" << endl;
	cin >> X;
	if (!LocateElem(LA, X, i))
	{
		cout << "LA中不存在" << X << endl;
	}
	else
	{
		cout <<X<< "的位序为";
		cout << i << endl;
	}

	UnionList(LA,LB);
	if (UnionList(LA, LB))
	{
		cout << "合并A，B顺序表并合并成功，新的线性表为：" << endl;
		TraverseList(LA);
	}
	else
	{
		cout << "合并失败" << endl;
	}
	if (ClearList(LA) && ClearList(LB) && DestroyList(LA) && DestroyList(LB))
	{
		cout << "The cleanup is complete" << endl;
	}
	system("pause");

	return 0;
}
