
//�ةЩةУ����ܣߣ�����
//�ЩةЩب�����������������
//�ةЩأ��ܡ�����������������
//�ЩبM������������������������
//�ةШ������������������񡡡���
//�Щب���������������������������
//�ب������������������� �ܣߣߣ�
//�Ш�����������������������������������
//�ب���������������������������
//�������������������������������}�{
//�������������������������������}�{
//������������������������������������
//������������������������������������ ��
//�ب����������������������������������� ��
//�Щ���������������������������������������
//�ة���������������������������������������
//�ШM�������M�����������������ܡ������� �M
//*�M�ߣ�_�����������M���������� �ܡ�������
//�ЩةЩةЩأ� ���� ��_��������������������
//�ةЩةЩةЩ� �ܣߣߣߣܡ������� �������ܩ�������
//���������W�i�i�i�i�i�i�i�i�ܡ��� �M�� ��������������
/************************************************************************
* ��Ŀ���� :  ����ʽ�Ӽ�������
* �� �� �� :  v1.0.0.0
* ˵    �� :
* ��    �� :  rex0yt
* ����ʱ�� :  2017/08/28 17:20:00
************************************************************************
* Copyright @ re0yt . All rights reserved.
************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>

#define LOCAL

using namespace std;

template <typename Type>
class Node//����ڵ�
{
public:
	Type data;//����
	Node<Type> *succ, *pred;//ǰ�� ���

	Node<Type>() : succ(NULL), pred(NULL)
	{

	}
};

template <typename Type>
class LinkList//����
{
public:
	int len;//������
	Node<Type> head, tail;//ͷָ�� βָ��

	LinkList(int _len = 0) :len(_len)
	{
		if (len == 0)return;//NULL object

		Node<Type> *tmp;
		tmp = new(Node<Type>);
		tmp->data = 0;
		tmp->pred = &head;
		tmp->succ = &tail;
		head.succ = tmp;
		tail.pred = tmp;

		if (len == 1)return;//object with one node

		for (int i = 1; i<len; i++)
		{
			tmp = new(Node<Type>);
			tmp->data = 0;
			tmp->pred = tail.pred;
			tmp->succ = &tail;
			tail.pred->succ = tmp;
			tail.pred = tmp;
		}
	}

	void remove(int i)
	{
		//ɾ������Ԫ��
	}

	bool insert(Type _data, int pos = -1)//-1 insert in tail, other insert i pred
	{//�������iλ�ò�������_data
		Node<Type> *tmp;
		if (pos == -1)
		{
			tmp = new(Node<Type>);
			tmp->data = _data;
			if (tail.pred == NULL)
			{
				tmp->pred = &head;
				head.succ = tmp;
			}
			else
			{
				tmp->pred = tail.pred;
				tail.pred->succ = tmp;
			}
			tmp->succ = &tail;
			tail.pred = tmp;
			len++;
		}
		else if (pos < 0 || pos >= len) return false;
		else
		{
			Node<Type> *pnt;
			pnt = head.succ;

			int i = pos;//find position
			while (i--)
			{
				pnt = pnt->succ;
			}
			tmp = new(Node<Type>);
			tmp->data = _data;
			tmp->pred = pnt->pred;
			tmp->succ = pnt;
			pnt->pred->succ = tmp;
			pnt->pred = tmp;
			len++;
		}
		return true;
	}
	bool resize(int _len)
	{//�����ȵ���
		if (_len < 0)return false;

		else if (_len == len)return true;

		else if (_len > len)
		{
			int delt = _len - len;
			for (int i = 0; i<delt; i++)
			{
				insert(0);
			}
			return true;
		}
		else
		{
			//            Node<Type> *pnt;
			//            pnt = head.succ;
			//            int i = _len;
			//            while(i --)
			//            {
			//                pnt = pnt->succ;
			//            }
		}
		return true;
	}

	Type& operator[](int i)const
	{//�����±�����

		Node<Type> *pnt;
		pnt = head.succ;

		while (i--)
		{
			pnt = pnt->succ;
		}

		return pnt->data;
	}

	LinkList& operator=(const LinkList& left)
	{//���ظ�ֵ����
	 //        this->len = left.len;
		this->resize(left.len);
		Node<Type> *pnt1 = this->head.succ, *pnt2 = left.head.succ;
		for (int i = 0; i<len; i++)
		{
			pnt1->data = pnt2->data;
			pnt1 = pnt1->succ;
			pnt2 = pnt2->succ;
		}
		return *this;
	}
};

class PolyNode//����ʽ�ڵ�
{
public:
	int degree;//��ָ��
	float coef;//ϵ��

	PolyNode(int _degree = 0, float _coef = 0)
		:degree(_degree), coef(_coef) {}

	friend istream& operator>>(istream &is, PolyNode &tmp)
	{//��������
		is >> tmp.degree >> tmp.coef;
		return is;
	}
	friend ostream& operator<<(ostream &os, const PolyNode &tmp)
	{//�������
		os << tmp.coef << "X^" << tmp.degree;
		return os;
	}
};

class Polymerization//����ʽ ����
{
public:
	int len;//����ʽ���� ����
	LinkList<PolyNode> data;//����

	Polymerization(int _len = 0) :len(_len), data(_len)//,LinkList<PolyNode>()
	{

	}

	void sort()
	{
		//����ʽ�����Լ�����ָ������
	}

	float getcoef(int _degree)const
	{//ȡ����ָ��Ϊ_degree��ϵ��
		for (int i = 0; i<len; i++)
		{
			if (data[i].degree == _degree)
				return data[i].coef;
		}
		return 0;
	}

	Polymerization& operator=(const Polymerization &left)
	{//���ظ�ֵ����
		this->len = left.len;
		this->data = left.data;
		return *this;
	}

	friend Polymerization operator+(const Polymerization& left, const Polymerization& right)
	{//����ʽ�ӷ�����

		Polymerization ans;
		PolyNode tmp;

		int max_degree = max(left.data[0].degree, right.data[0].degree);
		for (int i = max_degree; i >= 0; i--)
		{
			tmp.degree = i;
			tmp.coef = 0;
			tmp.coef += left.getcoef(i) + right.getcoef(i);
			if (tmp.coef != 0)
			{
				ans.data.insert(tmp);
			}
		}
		ans.len = ans.data.len;
		return ans;
	}

	friend Polymerization operator-(const Polymerization& left, const Polymerization& right)
	{//����ʽ��������

		Polymerization tmp;
		tmp = right;
		for (int i = 0; i<int(tmp.len); i++)
		{
			tmp.data[i].coef *= -1;
		}
		Polymerization ans = left + tmp;
		return ans;
	}

	friend Polymerization operator*(const Polymerization& left, const Polymerization& right)
	{//����ʽ�˷� Ϊ=δ����

		Polymerization ans;
		PolyNode tmp;

		int max_degree = max(left.data[0].degree, right.data[0].degree);
		for (int i = 0; i <= left.data.len; i++)
		{
			for (int j = 0; j <= right.data.len; j++)
			{
				tmp.degree = left.data[i].degree + right.data[j].degree;
				tmp.coef = 0;
				tmp.coef += left.data[i].coef * right.data[j].coef;
				if (tmp.coef != 0)
				{
					ans.data.insert(tmp);
				}
			}
		}
		ans.len = ans.data.len;
		return ans;
	}

	friend istream& operator>>(istream &is, Polymerization &tmp)
	{//��������
		is >> tmp.len;
		tmp.data.resize(tmp.len);
		for (int i = 0; i<tmp.len; i++)
		{
			is >> tmp.data[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Polymerization &tmp)
	{//�������
		for (int i = 0; i<tmp.len; i++)
		{
			os << tmp.data[i];
			if (i < tmp.len - 1)
				os << "+";
			else
				os << endl;
		}
		return os;
	}
};

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);

	//FILE *fp;
	//freopen_s(&fp,"data.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(0);
#endif // LOCAL

	//��������
	//3
	//3 3
	//2 2
	//1 1
	//2
	//2 2
	//1 1
	Polymerization a, b;
	cin >> a;
	cout << "Polymerization A:" << a;
	cin >> b;
	cout << "Polymerization B:" << b;

	cout << "A+B:" << a + b << endl;
	cout << "A-B:" << a - b << endl;
	cout << "A*B:" << a * b << endl;

	//LinkList<int> a(10);
	//for (int i = 0; i<10; i++)
	//{
	//	a[i] = i;
	//	cout << a[i] << " ";
	//}

	//LinkList<int>b;
	//b = a;

	//for (int i = 0; i<10; i++)
	//	cout << b[i] << " ";
	//cout << endl;

	//a[5] = 100;
	//for (int i = 0; i<10; i++)
	//	cout << b[i] << " ";
	//cout << endl;

	return 0;
}
