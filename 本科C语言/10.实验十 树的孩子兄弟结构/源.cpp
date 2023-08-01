/*
用孩子兄弟链表存储结构构造教材P137图6.15描述的树，
并输出该树的先根和后根中序遍历序列
*/
#include"标头.h"
int main()
{
	CSTree T;
	cout << "按自上而下自左至右顺序输入双亲-孩子的有序对,建立二叉链表" << endl << "输入时,以一对'#'作为结束标志,根的双亲空,也用'#'表示" << endl;
	CreateTree(T);
	
	cout<<"先根遍历为："<<endl;
	PreOrderTraverse(T);
	cout << endl;

	cout<<"后根遍历为："<<endl;
	InOrderTraverse(T);
	cout << endl;

	/*cout << "后序遍历为：" << endl;
	PostOrderTraverse(T);
	cout << endl;*/

	system("pause");
}