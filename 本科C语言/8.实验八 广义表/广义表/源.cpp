#include"标头.h"
int main()
{
	GLNode *L = NULL;
	//string S = " '(', 'a', ',', '(', 'b', ',', 'c', ')', ',', 'd', ')' ";
	string S="(a,(b,c),d)";
	CreateGList(L, S);
	cout << "广义表T" << endl;
	Traverse(L);
	cout << endl;
	//system("pause");
	cout << "广义表L的深度为：" << Depth(L) << endl;
	//system("pause");
	cout << "广义表L的长度为：" << Length(L) << endl;
	system("pause");
}