#include<iostream>
using namespace std;
#define MaxVex 100 //最大顶点数
/*//#define INFINITY 0
#define TURE 1
#define FALSE 0
#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10
#define MAXSIZE  50




typedef struct ArcNode//弧结点 
{
	int adjvex;//该弧指向的顶点的位置　
	struct ArcNode *nextarc; //指向下一条弧的指针　
	char *info;//该弧的相关信息(权值)
}ArcNode;
typedef struct Vnode//表头结点　
{
	VertexType data;//顶点信息
	ArcNode *firstarc; //指向第一条依附该顶点的弧（或边）的指针
}VNode, AdjList[MaxVex];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;//顶点和弧数
	GraphKind kind;//图的种类标志
}ALGraph;//邻接表*/
typedef int  EdgeType;//权值类型
typedef char VertexType;//定点类型
typedef enum { DG, DN, UDG, UDN }GraphKind;



typedef int Status;


#define MAX_VERTEX_NUM 20
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
typedef struct EDGE
{
	int begin;  //起始点序号  
	int end;    //终点序号  
	int weight; //权值  
}Edge[MAX_VERTEX_NUM];//边集数组 
EDGE edges[MAX_VERTEX_NUM];
int LocateVex(MGraph &G, VertexType u)//返回顶点在图中位置
{
	for (int i = 0; i<G.vexnum; ++i)
	{
		if (u == (G.vexs[i]))
		{
			return i;
		}
	}
	return 0;
}
Status CreateUDN(MGraph &G)//创建无向网
{
	int i = 0;
	int j = 0;
	int k = 0;
	cout << "请输入顶点数和边数" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "请输入顶点" << endl;
	for (i = 0; i<G.vexnum; i++)
	{
		cin >> G.vexs[i];
	}
	for (i = 0; i<G.vexnum; i++)//初始化邻接矩阵
	{
		for (j = 0; j<G.vexnum; j++)
		{
			G.arcs[i][j].adj = 0;
		}
	}
	VertexType v1, v2;
	int w;
	cout << "请输入一条边依附的顶点及权值" << endl;
	for (k = 0; k<G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		edges[k].begin = i;
		edges[k].end = j;
		edges[k].weight=w;
	}
	return 1;
}
Status Kruskal(MGraph &G, MGraph &T)
{
	int i = 0;
	int j = 0;
	int k = 0;
	T.vexnum = G.vexnum;
	for (i = 0; i<G.vexnum; i++)
	{
		T.vexs[i] = G.vexs[i];
	}
	for (i = 0; i<G.vexnum; i++)//初始化矩阵
	{
		for (j = 0; j<G.vexnum; j++)
		{
			T.arcs[i][j].adj = 0;
		}
	}
	int u = G.vexnum ;
	for (k=0;k<G.arcnum;k++)//将数组的值升序排列
	{
		for (i = 0; i < G.arcnum; i++)
		{
			if (edges[k].weight < edges[i].weight)
			{
				edges[u] = edges[k];
				edges[k] = edges[i];
				edges[i] = edges[u];
			}
		}
	}
	for (int m = 0; m < G.arcnum; m++)
	{
		cout << edges[m].weight;
	}
	cout << endl;
	cout << "最小生成树为" << endl;
	for (k = 0; k < T.vexnum; k++)
	{
		i = edges[k].begin;
		j = edges[k].end;
		T.arcs[i][j].adj = edges[k].weight;
		cout << T.vexs[i] << "--" << T.vexs[j] << endl;
	}
	return 1;
}