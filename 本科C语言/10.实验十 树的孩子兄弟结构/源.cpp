/*
�ú����ֵ�����洢�ṹ����̲�P137ͼ6.15����������
������������ȸ��ͺ�������������
*/
#include"��ͷ.h"
int main()
{
	CSTree T;
	cout << "�����϶�����������˳������˫��-���ӵ������,������������" << endl << "����ʱ,��һ��'#'��Ϊ������־,����˫�׿�,Ҳ��'#'��ʾ" << endl;
	CreateTree(T);
	
	cout<<"�ȸ�����Ϊ��"<<endl;
	PreOrderTraverse(T);
	cout << endl;

	cout<<"�������Ϊ��"<<endl;
	InOrderTraverse(T);
	cout << endl;

	/*cout << "�������Ϊ��" << endl;
	PostOrderTraverse(T);
	cout << endl;*/

	system("pause");
}