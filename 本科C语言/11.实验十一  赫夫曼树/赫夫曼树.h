#include<iostream>
using namespace std;
#define M 10
typedef struct 
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
	char ch;
}HTNode, *HuffmanTree;//��̬��������洢�շ�����
typedef char **HuffmanCode;//��̬��������洢�շ��������
typedef struct
{
	char elem[M];         //Ҷ��
	int wei[M];          //Ȩֵ 
}ElemWeight;
void CreateElemWeight(ElemWeight &T, int n)//����Ҷ�Ӽ�Ȩֵ
{
	int i;
	cout << "�������������Ԫ�غ�Ȩֵ" << endl;
	for (i = 1; i <= n; i++)
	{
		cin >> T.elem[i] >> T.wei[i];
	}
}
void Select(HuffmanTree HT, int n, int &s1, int &s2) //Select����
{
	int m1 = 0 ;
	int m2 = 0;
	int i;
	for (i = 1; i <= n; i++) 
	{
		if (HT[i].parent == 0)
		{
			if (m1 == 0 || HT[i].weight < HT[m1].weight)
			{
				m2 = m1; 
				m1 = i;
			}
			else if (m2 == 0 || HT[i].weight < HT[m2].weight)
			{
				m2 = i;
			}
		}
	}
	s1 = m1;
	s2 = m2;
}
void CreateHuffmanTree(HuffmanTree &HT, ElemWeight T, int n) //�����շ�����
{
	int m, i, s1, s2;
	if (n <= 1)
	{
		return;
	}
	m = 2 * n - 1;
	HT = new HTNode[m + 1]; //Ϊ�շ���������һ��˳��ռ�
	for (i = 1; i <= n; i++)//��ʼ��
	{ //*p = {*w,0,0,0};				 
		HT[i].ch = T.elem[i];
		HT[i].weight = T.wei[i];
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= m; i++) //����δʹ�õĽ�㸳��ֵ
	{//*p = {0,0,0,0};  
		HT[i].ch = '*';
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= m; ++i) //�����շ�����
	{ //��HT[0..i-1] ��ѡ��Ȩֵ��С���������,����ŷֱ�Ϊs1��s2.
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int n) //���ɺշ�������
{//w���n���ַ���Ȩֵ(��>0)������շ�����HT�������n���ַ��ĺշ�������HC
	int i, c, start, f = 0;
	HC = new char*[n + 1];
	char *cd = new char[n];               //�洢�������ʱ����
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i) //0�ŵ�Ԫδ��
	{
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if (HT[f].lchild == c)
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}
/*#include<iostream>
using namespace std;
typedef struct
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode,*HuffmanTree;
typedef char * * HuffmanCode;
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
	if (n <= 1)
	{
		return;
	}
	int m = 0;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0�ŵ�Ԫδ��
	HuffmanTree p;
	int i;
	for (p = HT, i = 1; i <= n; ++i, ++p, ++w)
	{
		*p = { 0,0,0,0 };
	}
	for (; i <= m; ++i, ++p)
	{
		*p = { 0,0,0,0 };
	}
	for (i = n + 1; i <= m; ++i)//���շ�����
	{
		Select(HT, i - 1, s1, s2);// ��HT.Htree[0..i-1] ��ѡ��Ȩֵ��С��������㣬����ŷֱ�Ϊs1��s2��
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
/*typedef struct
{
	int weight;
	int lchild, rchild;
}HTNode;
typedef struct
{
	HTNode *HTree;
	int root;
}HuffmanTree;

void CreateHuffmanTree(HuffmanTree &HT, int *w, int n)// w���n��Ȩֵ(��>0)������շ�����HT
{ 
	if (n <= 1)
	{
		return;
	}
	int m = 2 * n - 1;
	int i = 0;
	HTNode *p;
	HT.HTree = new HTNode[m + 1];  // Ϊ�շ���������һ��˳��ռ�
	for (p = HT.HTree, i = 1; i <= n; ++i, ++p, ++w)
	{
		*p = { *w,0,0 };
	}
	for (; i <= m; ++i, ++p)     // ����δʹ�õĽ�㸳��ֵ
	{
		*p = { 0,0,0 };
	}
	for (i = n + 1; i <= m; ++i) 
	{        // ���շ�����
		Select(HT.Htree, i - 1, s1, s2); // ��HT.Htree[0..i-1] ��ѡ��Ȩֵ��С��������
										 // �㣬����ŷֱ�Ϊs1��s2��
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}//for
} // CreatHuffmanTree
*/