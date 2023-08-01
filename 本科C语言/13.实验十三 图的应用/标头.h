#include<iostream>
using namespace std;
#define MaxVex 100 //��󶥵���
/*//#define INFINITY 0
#define TURE 1
#define FALSE 0
#define STACK_INIT_SIZE  100
#define STACKINCREMENT   10
#define MAXSIZE  50




typedef struct ArcNode//����� 
{
	int adjvex;//�û�ָ��Ķ����λ�á�
	struct ArcNode *nextarc; //ָ����һ������ָ�롡
	char *info;//�û��������Ϣ(Ȩֵ)
}ArcNode;
typedef struct Vnode//��ͷ��㡡
{
	VertexType data;//������Ϣ
	ArcNode *firstarc; //ָ���һ�������ö���Ļ�����ߣ���ָ��
}VNode, AdjList[MaxVex];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;//����ͻ���
	GraphKind kind;//ͼ�������־
}ALGraph;//�ڽӱ�*/
typedef int  EdgeType;//Ȩֵ����
typedef char VertexType;//��������
typedef enum { DG, DN, UDG, UDN }GraphKind;



typedef int Status;


#define MAX_VERTEX_NUM 20
		 //�ڽӾ���洢
typedef struct ArcCell
{
	int adj;
	int *info;
}ArcCell, AdjMatric[MaxVex][MaxVex];
typedef struct
{
	VertexType vexs[MaxVex];  //��������
	AdjMatric  arcs;//�ڽӾ���
	int vexnum, arcnum;//ͼ�нڵ���������
	GraphKind kind;
}MGraph;
typedef struct EDGE
{
	int begin;  //��ʼ�����  
	int end;    //�յ����  
	int weight; //Ȩֵ  
}Edge[MAX_VERTEX_NUM];//�߼����� 
EDGE edges[MAX_VERTEX_NUM];
int LocateVex(MGraph &G, VertexType u)//���ض�����ͼ��λ��
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
Status CreateUDN(MGraph &G)//����������
{
	int i = 0;
	int j = 0;
	int k = 0;
	cout << "�����붥�����ͱ���" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "�����붥��" << endl;
	for (i = 0; i<G.vexnum; i++)
	{
		cin >> G.vexs[i];
	}
	for (i = 0; i<G.vexnum; i++)//��ʼ���ڽӾ���
	{
		for (j = 0; j<G.vexnum; j++)
		{
			G.arcs[i][j].adj = 0;
		}
	}
	VertexType v1, v2;
	int w;
	cout << "������һ���������Ķ��㼰Ȩֵ" << endl;
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
	for (i = 0; i<G.vexnum; i++)//��ʼ������
	{
		for (j = 0; j<G.vexnum; j++)
		{
			T.arcs[i][j].adj = 0;
		}
	}
	int u = G.vexnum ;
	for (k=0;k<G.arcnum;k++)//�������ֵ��������
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
	cout << "��С������Ϊ" << endl;
	for (k = 0; k < T.vexnum; k++)
	{
		i = edges[k].begin;
		j = edges[k].end;
		T.arcs[i][j].adj = edges[k].weight;
		cout << T.vexs[i] << "--" << T.vexs[j] << endl;
	}
	return 1;
}