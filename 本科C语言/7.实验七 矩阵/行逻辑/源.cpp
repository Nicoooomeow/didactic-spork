#include"标头.h"
int main() 
{
	RLSMatrix M, T, Q;
	//cout << "矩阵A为：" << endl;
	//cout << "12 0 0 -1" << endl << "0 3 0 0" << endl << "0 0 2 0" << endl << "0 0 10 0" << endl;
	Init(M);
	//cout << "矩阵B为：" << endl;
	//cout << "0 7 0 0" << endl << "0 3 0 0" << endl << "0 0 -2 0" << endl << "9 0 0 8" << endl;
	Init(T);
	system("pause");
	cout << "矩阵A:" << endl;
	Traverse(M);
	cout << "矩阵B:" << endl;
	Traverse(T);
	system("pause");
	Add(M, T, Q);
	cout << "相加之后的矩阵C:" << endl;
	Traverse(Q);
	system("pause");
	return 0;
}