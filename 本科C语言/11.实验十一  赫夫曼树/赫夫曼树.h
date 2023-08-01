#include<iostream>
using namespace std;
#define M 10
typedef struct 
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
	char ch;
}HTNode, *HuffmanTree;//动态分配数组存储赫夫曼树
typedef char **HuffmanCode;//动态分配数组存储赫夫曼编码表
typedef struct
{
	char elem[M];         //叶子
	int wei[M];          //权值 
}ElemWeight;
void CreateElemWeight(ElemWeight &T, int n)//构建叶子及权值
{
	int i;
	cout << "输入各结点的数据元素和权值" << endl;
	for (i = 1; i <= n; i++)
	{
		cin >> T.elem[i] >> T.wei[i];
	}
}
void Select(HuffmanTree HT, int n, int &s1, int &s2) //Select函数
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
void CreateHuffmanTree(HuffmanTree &HT, ElemWeight T, int n) //建立赫夫曼树
{
	int m, i, s1, s2;
	if (n <= 1)
	{
		return;
	}
	m = 2 * n - 1;
	HT = new HTNode[m + 1]; //为赫夫曼树分配一组顺序空间
	for (i = 1; i <= n; i++)//初始化
	{ //*p = {*w,0,0,0};				 
		HT[i].ch = T.elem[i];
		HT[i].weight = T.wei[i];
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= m; i++) //对尚未使用的结点赋初值
	{//*p = {0,0,0,0};  
		HT[i].ch = '*';
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (i = n + 1; i <= m; ++i) //建立赫夫曼树
	{ //在HT[0..i-1] 中选择权值最小的两个结点,其序号分别为s1和s2.
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int n) //生成赫夫曼编码
{//w存放n个字符的权值(均>0)，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
	int i, c, start, f = 0;
	HC = new char*[n + 1];
	char *cd = new char[n];               //存储编码的临时数组
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i) //0号单元未用
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
	HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0号单元未用
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
	for (i = n + 1; i <= m; ++i)//建赫夫曼树
	{
		Select(HT, i - 1, s1, s2);// 在HT.Htree[0..i-1] 中选择权值最小的两个结点，其序号分别为s1和s2。
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

void CreateHuffmanTree(HuffmanTree &HT, int *w, int n)// w存放n个权值(均>0)，构造赫夫曼树HT
{ 
	if (n <= 1)
	{
		return;
	}
	int m = 2 * n - 1;
	int i = 0;
	HTNode *p;
	HT.HTree = new HTNode[m + 1];  // 为赫夫曼树分配一组顺序空间
	for (p = HT.HTree, i = 1; i <= n; ++i, ++p, ++w)
	{
		*p = { *w,0,0 };
	}
	for (; i <= m; ++i, ++p)     // 对尚未使用的结点赋初值
	{
		*p = { 0,0,0 };
	}
	for (i = n + 1; i <= m; ++i) 
	{        // 建赫夫曼树
		Select(HT.Htree, i - 1, s1, s2); // 在HT.Htree[0..i-1] 中选择权值最小的两个结
										 // 点，其序号分别为s1和s2。
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}//for
} // CreatHuffmanTree
*/