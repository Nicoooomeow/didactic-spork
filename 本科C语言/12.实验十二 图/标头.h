#include <iostream>
#include"栈.h"
#include"队列.h"
using namespace std;
	  
//邻接矩阵存储
typedef struct ArcCell
{
	int adj;
	int *info;
}ArcCell, AdjMatric[MaxVex][MaxVex];
typedef struct
{
	VertexType vexs[MaxVex];  //顶点数组
	AdjMatric  arcs;//邻接矩阵
	int vexnum, arcnum;//图中节点数及边数
	GraphKind kind;
}MGraph;

//邻接表存储
typedef struct ArcNode {//弧结点　
	int adjvex;//该弧指向的顶点的位置　
	struct ArcNode *nextarc; //指向下一条弧的指针　
	char *info;//该弧的相关信息
}ArcNode;
typedef struct Vnode {//表头结点　
	VertexType data;//顶点信息
	ArcNode *firstarc; //指向第一条依附该顶点的弧（或边）的指针
}VNode, AdjList[MaxVex];
typedef struct 
{
	AdjList vertices;
	int vexnum, arcnum;//顶点和弧数
	GraphKind kind;//图的种类标志
}ALGraph;//邻接表

bool visited[100];
int(*VisitFunc)(ALGraph &G, int v);
//***++++-----我就是想用个分割线------++++***//
//建立图的邻接矩阵存储
int LocateVex(MGraph &G, VertexType u)//返回顶点在图中位置
{   
	for (int i = 0; i<G.vexnum; ++i)
	{
		if (u == (G.vexs[i]))
		{
			return i;
		}
	}
	return -1;
}
int CreateMGraph(MGraph &G)
{
	cout << "输入图的当前顶点数和弧数：" << endl;
	cin >> G.vexnum >> G.arcnum;
	int i, j, k;
	cout << "输入图的各顶点:" << endl;
	for (i = 0; i<G.vexnum; ++i)
	{
		cin >> G.vexs[i];
	}
	for (i = 0; i<G.vexnum; ++i)
	{
		for (j = 0; j<G.vexnum; ++j)
		{
			G.arcs[i][j].adj = 0;
			G.arcs[i][j].info = NULL;
		}
	}
	VertexType v1, v2;
	cout << "依次输入边依附的顶点：" << endl;
	for (k = 0; k<G.arcnum; ++k)
	{
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;
		G.arcs[i][j].info = NULL;
	}
	G.kind = DG;
	return 1;
}
void print(MGraph &G)
{
	cout << "有向图的邻接矩阵为：" << endl;
	for (int i = 0; i<G.vexnum; ++i)
	{
		for (int j = 0; j<G.vexnum; ++j)
		{
			cout << G.arcs[i][j].adj;
		}
		cout << endl;
	}
}
void BFS(MGraph G, int v)//广度优先搜索
{
	cout<<"广度优先遍历"<<endl;
	SqStack Q;//STL模板中的queue
	InitStack(Q);
	cout<<v<<" ";
	visited[v] = true;
	Push(Q,v);
	while (Q.base!=Q.top)
	{
		int i, j;
		//i=Gettop(Q,j);//取队首顶点
		Pop(Q,i);
		for (j = 0; j<G.vexnum; j++)   //广度遍历
		{
			if (G.vexs[i]!= 0 && visited[j] == false)
			{
				cout << G.vexs[i] <<" ";
				visited[j] = true;
				Push(Q,j);
			}
		}
	}
	cout << endl;
}
//***++++-----我就是想用个分割线------++++***//
//图的邻接表存储
int Locatevex(ALGraph &G, int v)
{
	int i, k = -1;
	for (i = 0; i<G.vexnum; i++)
	{
		if (G.vertices[i].data == v)
		{
			k = i;
			break;
		}
	}
	return k;
}
void CreateGraph(ALGraph &G)
{
	int i, k, j;
	char v1, v2;
	cout << "输入图的当前顶点数和弧数：" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "输入图的各顶点:" << endl;
	for (i = 0; i<G.vexnum; i++) 
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}//初始化邻接表
	cout << "输入图各边依附的顶点:" << endl;
	for (k = 0; k<G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = Locatevex(G, v1);
		j = Locatevex(G, v2);
		ArcNode *p;
		p = new ArcNode;
		p->adjvex = j;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;//逆序插入
	}
}
void DFS(ALGraph &G, int m)//递归调用深度遍历
{
	int v, w;
	ArcNode *p;//p为v的第一个邻接顶点
	v = Locatevex(G, m);
	visited[v] = TURE;
	cout << G.vertices[v].data<<" ";
	p = G.vertices[v].firstarc;
	while (p != NULL)
	{
		w = p->adjvex;
		if (!visited[w])
		{
			DFS(G, G.vertices[w].data);
		}
		p = p->nextarc;
	}
}
void DFSTraverse(ALGraph &G)//深度优先递归遍历
{
	cout << "深度优先递归遍历:" << endl;
	int v;
	for (v = 0; v<G.vexnum; v++)
		visited[v] = FALSE;
	for (v = 0; v<G.vexnum; v++)
	{
		if (visited[v] == 0)
			DFS(G, G.vertices[v].data);
	}
	cout << endl;
}
void DFStravel(ALGraph &G)//深度优先非递归遍历
{
	cout << "深度优先非递归遍历:" << endl;
	SqStack S;
	InitStack(S);
	ArcNode *p;
	int i, k;
	for (i = 0; i<G.vexnum; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i<G.vexnum; i++)
	{
		if (!visited[i])
		{
			cout << G.vertices[i].data<<" ";//访问初始节点
			visited[i] = 1;
			Push(S, i);
			while (S.top != S.base)
			{
				Gettop(S, k);
				p = G.vertices[k].firstarc;//访问与顶点k相邻的顶点
				while (p)
				{
					if (!visited[p->adjvex])
					{
						cout << G.vertices[p->adjvex].data<<" ";
						visited[p->adjvex] = 1;
						Push(S, p->adjvex);  //访问完之后入栈
						Gettop(S, k);
						p = G.vertices[k].firstarc;
					}
					else
					{
						p = p->nextarc;
					}
				}
				S.top--;
			}
		}
	}
	cout << endl;
}