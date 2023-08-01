/*
1.递归建立P129图6.9二叉树，并采用非递归的先序、中序和后序遍历该二叉树
2.给出1建造的二叉树的层次遍历序列
3.用非递归的方法建立P129图6.9二叉树，并用非递归方法求该二叉树的深度
*/
#include"树.h"
int main()
{
	BiTree T;
	cout << "先序输入二叉树的字符,以“#”代表空树" << endl;
	CreateBiTree(T);
	cout << "先序遍历二叉树:" << endl;
	PreOrderTraverse(T);
	cout << endl;
	cout << "中序遍历二叉树:" << endl;
	InOrderTraverse(T);
	cout << endl;
	cout << "后序遍历二叉树:" << endl;
	PostOrderTraverse(T);
	cout << endl;
	system("pause");
	cout << "递归求深度（忽略）" << endl;
	cout<< Deep(T) <<endl;
	cout << "层次遍历" << endl;
	LevelOrderTraverse(T);
	system("pause");
	return 0;
}
