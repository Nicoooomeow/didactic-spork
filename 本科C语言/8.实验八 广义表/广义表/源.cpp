#include"��ͷ.h"
int main()
{
	GLNode *L = NULL;
	//string S = " '(', 'a', ',', '(', 'b', ',', 'c', ')', ',', 'd', ')' ";
	string S="(a,(b,c),d)";
	CreateGList(L, S);
	cout << "�����T" << endl;
	Traverse(L);
	cout << endl;
	//system("pause");
	cout << "�����L�����Ϊ��" << Depth(L) << endl;
	//system("pause");
	cout << "�����L�ĳ���Ϊ��" << Length(L) << endl;
	system("pause");
}