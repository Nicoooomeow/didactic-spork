#include"ջ������.h"
#include"����.h"
Status CreateBiTree(BiTree &T)
{//�������������������н���ֵ(һ���ַ�),#�ַ���ʾ����,�ݹ鹹����������ʾ�Ķ�����T.
 //����һ������㣬
 //����������һ����#�����ո��ַ��������������Ϊ��������T��NULL
 //�������Ĳ��ǡ�#�����ո��ַ����򽫸��ַ�����T->data
 //֮�����εݹ齨������������T->lchild��������T->rchild ��
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
		T->data = e;//���ɸ����
		CreateBiTree(T->lchild);//����������
		CreateBiTree(T->rchild);//����������
	}
	return 1;
}
Status PreOrderTraverse(BiTree T)//�������������
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
			p = p->lchild;//��ָ���ջ,���ʸ����,����������
		}
		else//��ָ����ջ,����������
		{
			Pop(S, p);
			p = p->rchild;
		}
	}
	return 1;
}
Status InOrderTraverse(BiTree T) //�������������
{
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			Push(S, p);
			p = p->lchild;//��ָ���ջ,����������
		}
		else////��ָ����ջ,���ʸ����,����������
		{
			Pop(S, p);
			cout << p->data << " ";
			p = p->rchild;
		}
	}
	return 1;
}
Status PostOrderTraverse(BiTree T)//�������������
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
Status LevelOrderTraverse(BiTree T)//��α���������
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
int Deep(BiTree T)//�ݹ������
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