/*
�����ڽӱ���ڽӾ���洢�ṹ
���÷ǵݹ���й�ȱ�������һ�Ŷ��㿪ʼ��
���Ⱥ�˳�����������ȱ��������ߡ�
*/
/*
������ͼ���ڽӾ�����ڽӱ�洢�ṹ
���õݹ�ͷǵݹ������ȱ�������1�Ŷ��㿪ʼ��
���Ⱥ�˳�����������ȱ����ĸ�����.
*/
#include"��ͷ.h"
int main()
{
	MGraph G;
	CreateMGraph(G);
	print(G);
	//BFS(G, 1);
	ALGraph M;
	CreateGraph(M);
	DFSTraverse(M);
	DFStravel(M);
	system("pause");
	return 0;
}