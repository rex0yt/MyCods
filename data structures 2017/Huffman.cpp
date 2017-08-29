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
* ��Ŀ���� :  Huffman�� ������
* �� �� �� :  v1.0.0.0
* ˵    �� :
* ��    �� :  rex0yt
* ����ʱ�� :  2017/08/29 11:00:00
************************************************************************
* Copyright @ rex0yt . All rights reserved.
************************************************************************/

//#define LOCAL

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Node
{
public:
	char ch;//�����ַ�
	int weight;//�ַ�Ȩ��
	int father;
	int left, right;
	Node(char _ch = 0, int _weight = 0, int _father = -1, int _left = -1, int _right = -1)
		:ch(_ch), weight(_weight),father(_father),left(_left),right(_right)
	{

	}

	friend bool operator<(const Node &left,const Node &right)
	{
		return left.weight < right.weight;
	}
};

class Huffman
{
public:
	int len;
	int root;
	vector <Node> data;//�������������
	//vector <Node> tree;//�����������

	friend	istream& operator>>(istream &is, Huffman &left)
	{//�������� �������������
		is >> left.len;
		left.data.resize(2*left.len);
		//left.tree.resize(2 * left.len);

		for (int i = 0; i < left.len; i++)
		{
			is >> left.data[i].ch >> left.data[i].weight;
		}

		return is;
	}
	void create()
	{//����Huffman��
		set <int> iset;
		int pnt = len;
		int minval, posmin;

		for (int i = 0; i < len; i++)
		{
			//pq.push(data[i]);
			iset.insert(i);
		}
		while (iset.size()>=2)
		{
			minval = 9999;
			posmin = -1;
			for (int i = 0; i < pnt; i++)
			{
				if (iset.find(i)!=iset.end() && minval >= data[i].weight)
				{
						minval = data[i].weight;
						posmin = i;
				}
			}
			data[pnt].left = posmin;
			data[posmin].father = pnt;
			iset.erase(posmin);
			minval = 9999;
			posmin = -1;
			for (int i = 0; i < pnt; i++)
			{
				if (iset.find(i) != iset.end() && minval >= data[i].weight)
				{
						minval = data[i].weight;
						posmin = i;
				}
			}
			data[pnt].right = posmin;
			data[posmin].father = pnt;
			iset.erase(posmin);
			iset.insert(pnt);
			pnt++;
		}
		int i;
		for (i = 0; i < pnt; i++)
			if (iset.find(i) != iset.end())
				break;
		root = i;
	}
	void printcode()
	{
		for (int i = 0; i < len; i++)
		{
			cout << data[i].ch << ":";
			print(i);
			cout << endl;
		}
	}
	void print(int i)
	{
		if (i == root)return;
		int fa = data[i].father;
		if (data[fa].left == i)
		{
			print(fa);
			cout << 1 << " ";
		}
		if (data[fa].right == i)
		{
			print(fa);
			cout << 0 << " ";
		}
	}
};
int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif // LOCAL

/*
	��������:

		5
		a 3
		b 20
		d 15
		f 6
		h 1

*/
	Huffman huff;
	cin >> huff;
	huff.create();
	huff.printcode();
	//for (int i = 0; i < huff.len; i++)
	//	cout << huff.data[i].ch << " " << huff.data[i].weight << endl;

	return 0;
}
