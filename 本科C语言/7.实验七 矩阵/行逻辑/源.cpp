#include"��ͷ.h"
int main() 
{
	RLSMatrix M, T, Q;
	//cout << "����AΪ��" << endl;
	//cout << "12 0 0 -1" << endl << "0 3 0 0" << endl << "0 0 2 0" << endl << "0 0 10 0" << endl;
	Init(M);
	//cout << "����BΪ��" << endl;
	//cout << "0 7 0 0" << endl << "0 3 0 0" << endl << "0 0 -2 0" << endl << "9 0 0 8" << endl;
	Init(T);
	system("pause");
	cout << "����A:" << endl;
	Traverse(M);
	cout << "����B:" << endl;
	Traverse(T);
	system("pause");
	Add(M, T, Q);
	cout << "���֮��ľ���C:" << endl;
	Traverse(Q);
	system("pause");
	return 0;
}