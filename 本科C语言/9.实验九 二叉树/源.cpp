/*
1.�ݹ齨��P129ͼ6.9�������������÷ǵݹ����������ͺ�������ö�����
2.����1����Ķ������Ĳ�α�������
3.�÷ǵݹ�ķ�������P129ͼ6.9�����������÷ǵݹ鷽����ö����������
*/
#include"��.h"
int main()
{
	BiTree T;
	cout << "����������������ַ�,�ԡ�#���������" << endl;
	CreateBiTree(T);
	cout << "�������������:" << endl;
	PreOrderTraverse(T);
	cout << endl;
	cout << "�������������:" << endl;
	InOrderTraverse(T);
	cout << endl;
	cout << "�������������:" << endl;
	PostOrderTraverse(T);
	cout << endl;
	system("pause");
	cout << "�ݹ�����ȣ����ԣ�" << endl;
	cout<< Deep(T) <<endl;
	cout << "��α���" << endl;
	LevelOrderTraverse(T);
	system("pause");
	return 0;
}
