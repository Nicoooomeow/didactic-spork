#include <iostream>
#include"ջ.h"
#include"����.h"
using namespace std;
	  
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

//�ڽӱ�洢
typedef struct ArcNode {//����㡡
	int adjvex;//�û�ָ��Ķ����λ�á�
	struct ArcNode *nextarc; //ָ����һ������ָ�롡
	char *info;//�û��������Ϣ
}ArcNode;
typedef struct Vnode {//��ͷ��㡡
	VertexType data;//������Ϣ
	ArcNode *firstarc; //ָ���һ�������ö���Ļ�����ߣ���ָ��
}VNode, AdjList[MaxVex];
typedef struct 
{
	AdjList vertices;
	int vexnum, arcnum;//����ͻ���
	GraphKind kind;//ͼ�������־
}ALGraph;//�ڽӱ�

bool visited[100];
int(*VisitFunc)(ALGraph &G, int v);
//***++++-----�Ҿ������ø��ָ���------++++***//
//����ͼ���ڽӾ���洢
int LocateVex(MGraph &G, VertexType u)//���ض�����ͼ��λ��
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
	cout << "����ͼ�ĵ�ǰ�������ͻ�����" << endl;
	cin >> G.vexnum >> G.arcnum;
	int i, j, k;
	cout << "����ͼ�ĸ�����:" << endl;
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
	cout << "��������������Ķ��㣺" << endl;
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
	cout << "����ͼ���ڽӾ���Ϊ��" << endl;
	for (int i = 0; i<G.vexnum; ++i)
	{
		for (int j = 0; j<G.vexnum; ++j)
		{
			cout << G.arcs[i][j].adj;
		}
		cout << endl;
	}
}
void BFS(MGraph G, int v)//�����������
{
	cout<<"������ȱ���"<<endl;
	SqStack Q;//STLģ���е�queue
	InitStack(Q);
	cout<<v<<" ";
	visited[v] = true;
	Push(Q,v);
	while (Q.base!=Q.top)
	{
		int i, j;
		//i=Gettop(Q,j);//ȡ���׶���
		Pop(Q,i);
		for (j = 0; j<G.vexnum; j++)   //��ȱ���
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
//***++++-----�Ҿ������ø��ָ���------++++***//
//ͼ���ڽӱ�洢
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
	cout << "����ͼ�ĵ�ǰ�������ͻ�����" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "����ͼ�ĸ�����:" << endl;
	for (i = 0; i<G.vexnum; i++) 
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}//��ʼ���ڽӱ�
	cout << "����ͼ���������Ķ���:" << endl;
	for (k = 0; k<G.arcnum; k++)
	{
		cin >> v1 >> v2;
		i = Locatevex(G, v1);
		j = Locatevex(G, v2);
		ArcNode *p;
		p = new ArcNode;
		p->adjvex = j;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;//�������
	}
}
void DFS(ALGraph &G, int m)//�ݹ������ȱ���
{
	int v, w;
	ArcNode *p;//pΪv�ĵ�һ���ڽӶ���
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
void DFSTraverse(ALGraph &G)//������ȵݹ����
{
	cout << "������ȵݹ����:" << endl;
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
void DFStravel(ALGraph &G)//������ȷǵݹ����
{
	cout << "������ȷǵݹ����:" << endl;
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
			cout << G.vertices[i].data<<" ";//���ʳ�ʼ�ڵ�
			visited[i] = 1;
			Push(S, i);
			while (S.top != S.base)
			{
				Gettop(S, k);
				p = G.vertices[k].firstarc;//�����붥��k���ڵĶ���
				while (p)
				{
					if (!visited[p->adjvex])
					{
						cout << G.vertices[p->adjvex].data<<" ";
						visited[p->adjvex] = 1;
						Push(S, p->adjvex);  //������֮����ջ
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