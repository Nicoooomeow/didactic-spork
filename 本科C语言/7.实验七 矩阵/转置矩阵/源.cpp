#include"标头.h"
int main()
{
	matrix input;
	Triple A;
	Triple B;
	initmatrix(input);
	Compressmatrix(input,A);
	Transpmatrix(A, B);
	cout << "输出三元组" ;
	Traverse(B);
	cout << "输出转置矩阵" << endl;
	Traversehahaha(B, input);
	system("pause");
}