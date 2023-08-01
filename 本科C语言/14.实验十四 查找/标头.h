#include<iostream>
using namespace std;
//typedef float KeyType;
typedef int KeyType;
//typedef char *KeyType;
typedef int Status;
typedef int ElemType;
//typedef ElemType KeyType;
#define ksize 30
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)< (b))
#define LQ(a,b) ((a)<=(b))
typedef struct
{
	KeyType key;
}SElemType;
typedef struct 
{
	ElemType *elem;
	int length;
	KeyType key;//结点数据元素
}SSTable;
//////////////////////////
typedef struct
{
	KeyType key;
	int stadr;
}indexItem;
typedef struct
{
	indexItem *elem;
	int length;
}indexTable;
/////////////////////////////

Status InitTable(SSTable &ST)//创建顺序表
{
	ST.elem = new ElemType[ksize];
	if (!ST.elem)
	{
		return 0;
	}
	ST.length = 0;
	return 1;
}
Status InitIndex(SSTable ST, indexTable &ID)//给索引表赋值
{
	int i, j;
	ID.length = ST.length/4;
	ID.elem= new indexItem[ksize];
	for (i = 0; i < ID.length; i++)
	{
		j = 4*(i+1);
		ID.elem[i].key = ST.elem[j];
		ID.elem[i].stadr = j;
	}
	return 1;
}

Status GetTable(SSTable &ST, int a[])//给ST赋值
{
	int i = 0;
	int j = 0;
	for (i = 0; a[i]; i++)
	{
		ST.elem[i + 1] = a[i];
		ST.length++;
	}
	ST.length++;
	return 1;
}
int Search_Seq(SSTable ST, KeyType key)//顺序查找
{
	int i = 0;
	ST.elem[0] = key;
	for (i = ST.length; !EQ(ST.elem[i], key); i--);
	return i;
}
int order(SSTable &ST)
{
	int i;
	int k;
	for (k = 1; k<ST.length; k++)
	{
		for (i = 1; i < ST.length; i++)
		{
			if (ST.elem[k] < ST.elem[i])
			{
				ST.elem[0] = ST.elem[k];
				ST.elem[k] = ST.elem[i];
				ST.elem[i] = ST.elem[0];
			}
		}
	}
	cout << "升序排序后表中元素为" << endl;
	for (i = 1; i < ST.length; i++)
	{
		cout << ST.elem[i] << " ";
	}
	cout << endl;
	return 1;
}
int Search_Bin(SSTable ST, KeyType key)//折半查找
{
	
	int low = 1;
	int high = ST.length;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(key, ST.elem[mid]))
		{
			return mid;
		}
		else if (LT(key, ST.elem[mid]))
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return 0;
}
int Search_Idx(SSTable ST, indexTable ID, KeyType kval)
{
	int low = 0; 
	int high = ID.length - 1; 
	int found = 0;
	if (kval > ID.elem[high].key)
	{
		return 0;         //kval大于表中所有关键字
	}
	while (low <= high && !found)// 折半查找索引表，确定记录查找区间
	{                   
		int mid = (low + high) / 2;
		if (kval < ID.elem[mid].key)
		{
			high = mid - 1;
		}
		else if (kval > ID.elem[mid].key)
		{
			low = mid + 1;
		}
		else 
		{
			found = 1;
			low = mid;
		}
	}//while
	int s = ID.elem[low].stadr;// 下一步的查找范围定位在第low块
	int k,t;
	if (low < ID.length - 1)
	{
		t = ID.elem[low + 1].stadr - 1; // s和t为ST表查找的下界和上界
	}
	else
	{
		t = ST.length;    //最后一块
	}
	if (ST.elem[s] == kval)
	{
		return s;
	}
	else 
	{                              // 在ST.elem[s] 至ST.elem[t-1]的区间内进行顺序查找
		ST.elem[0] = ST.elem[s];            // 暂存ST.elem[s]
		ST.elem[s] = kval;            // 设置监视哨
		for ( k = t; ST.elem[k] != kval; k--);
		ST.elem[s] = ST.elem[0];          // 恢复暂存值
		if (k != s)
		{
			return k;
		}
		else
		{
			return 0;
		}
	} // else
} // Search_Idx
