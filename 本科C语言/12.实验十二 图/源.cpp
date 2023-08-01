/*
建立邻接表和邻接矩阵存储结构
采用非递归进行广度遍历（从一号顶点开始）
按先后顺序输出广度优先遍历各条边。
*/
/*
建立下图的邻接矩阵和邻接表存储结构
采用递归和非递归进行深度遍历（从1号顶点开始）
按先后顺序输出深度优先遍历的各条边.
*/
#include"标头.h"
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