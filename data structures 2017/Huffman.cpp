//┴┬┴┬／￣＼＿／￣＼
//┬┴┬┴▏　　▏▔▔▔▔＼
//┴┬┴／＼　／　　　　　　﹨
//┬┴∕　　　　　　　／　　　）
//┴┬▏　　　　　　　　●　　▏
//┬┴▏　　　　　　　　　　　▔█
//┴◢██◣　　　　　　 ＼＿＿／
//┬█████◣　　　　　　　／　　　　
//┴█████████████◣
//◢██████████████▆▄
//◢██████████████▆▄
//█◤◢██◣◥█████████◤＼
//◥◢████　████████◤　　 ＼
//┴█████　██████◤　　　　　 ﹨
//┬│　　　│█████◤　　　　　　　　▏
//┴│　　　│　　　　　　　　　　　　　　▏
//┬∕　　　∕　　　　／▔▔▔＼　　　　 ∕
//*∕＿＿_／﹨　　　∕　　　　　 ＼　　／＼
//┬┴┬┴┬┴＼ 　　 ＼_　　　　　﹨／　　﹨
//┴┬┴┬┴┬┴ ＼＿＿＿＼　　　　 ﹨／▔＼﹨／▔＼
//▲△▲▲╓╥╥╥╥╥╥╥╥＼　　 ∕　 ／▔﹨　／▔﹨
/************************************************************************
* 项目名称 :  Huffman树 ，编码
* 版 本 号 :  v1.0.0.0
* 说    明 :
* 作    者 :  rex0yt
* 创建时间 :  2017/08/29 11:00:00
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
	char ch;//编码字符
	int weight;//字符权重
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
	vector <Node> data;//储存带编码数据
	//vector <Node> tree;//储存哈夫曼树

	friend	istream& operator>>(istream &is, Huffman &left)
	{//重载输入 输入待编码数据
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
	{//生成Huffman树
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
	输入样例:

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
