#include"��ͷ.h"
int main()
{
	matrix input;
	Triple A;
	Triple B;
	initmatrix(input);
	Compressmatrix(input,A);
	Transpmatrix(A, B);
	cout << "�����Ԫ��" ;
	Traverse(B);
	cout << "���ת�þ���" << endl;
	Traversehahaha(B, input);
	system("pause");
}