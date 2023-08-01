#include"栈及声明.h"
#include"队列.h"
Status CreateBiTree(BiTree &T)
{//按先序次序输入二叉树中结点的值(一个字符),#字符表示空树,递归构造二叉链表表示的二叉树T.
 //输入一个根结点，
 //如果输入的是一个‘#’（空格）字符，则表明二叉树为空树，即T＝NULL
 //如果输入的不是‘#’（空格）字符，则将该字符赋给T->data
 //之后依次递归建立它的左子树T->lchild和右子树T->rchild 。
	TElemType e;
	cin >> e;
	if (e == '#')
	{
		T = NULL;
	}
	else
	{
		T = new BiTNode;
		if (!T)
		{
			return 0;
		}
		T->data = e;//生成根结点
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
	return 1;
}
Status PreOrderTraverse(BiTree T)//先序遍历二叉树
{
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			cout << p->data << " ";
			Push(S, p);
			p = p->lchild;//根指针进栈,访问根结点,遍历左子树
		}
		else//根指针退栈,遍历右子树
		{
			Pop(S, p);
			p = p->rchild;
		}
	}
	return 1;
}
Status InOrderTraverse(BiTree T) //中序遍历二叉树
{
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			Push(S, p);
			p = p->lchild;//根指针进栈,遍历左子树
		}
		else////根指针退栈,访问根结点,遍历右子树
		{
			Pop(S, p);
			cout << p->data << " ";
			p = p->rchild;
		}
	}
	return 1;
}
Status PostOrderTraverse(BiTree T)//后序遍历二叉树
{
	PostSqStack S;
	PostInitStack(S);
	PostSElemType e;
	e.ptr = T;
	e.task = Travel;
	if (T) PostPush(S, e);
	while (!PostStackEmpty(S))
	{
		PostPop(S, e);
		if (e.task == Visit)
		{
			cout << e.ptr->data << " ";
		}
		else
		{
			BiTree p = e.ptr;
			e.task = Visit;
			PostPush(S, e);
			if (p->rchild)
			{
				e.ptr = p->rchild;
				e.task = Travel;
				PostPush(S, e);
			}
			if (p->lchild)
			{
				e.ptr = p->lchild;
				e.task = Travel;
				PostPush(S, e);
			}
		}
	}
	return  1;
}
Status LevelOrderTraverse(BiTree T)//层次遍历二叉树
{
	SqQueue Q;
	BiTNode *s;
	InitQueue(Q);
	if (!T)
	{
		return 0;
	}
	s = T;
	EnQueue(Q, s);
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, s);
		cout << s->data << " ";
		if (s->lchild)
		{
			EnQueue(Q, s->lchild);
		}
		if (s->rchild)
		{
			EnQueue(Q, s->rchild);
		}
	}
	cout << endl;
	return 1;
}
int Deep(BiTree T)//递归求深度
{
	int deep = 0;
	if (T)
	{
		int lchilddeep = Deep(T->lchild);
		int rchilddeep = Deep(T->rchild); 
		deep = lchilddeep >= rchilddeep ? lchilddeep + 1 : rchilddeep + 1;
	}
	return deep;
}