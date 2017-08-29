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
* 项目名称 :  二叉树的创建及遍历
* 版 本 号 :  v1.0.0.0
* 说    明 :
* 作    者 :  rex0yt
* 创建时间 :  2017/08/29 10:00:00
************************************************************************
* Copyright @ rex0yt . All rights reserved.
************************************************************************/

#define LOCAL
#define MaxN 10000

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

template <typename Type>
class Node
{
public:
	Type data;
	int father;
	int leftson, rightson;
	Node(Type _data = 0,int _father=-1, int _leftson=-1, int _rightson=-1)
		:data(_data),father(_father),leftson(_leftson),rightson(_rightson)
	{

	}
};

template <typename Type>
class BinaryTree
{
public:
	int len;
	vector < Node<Type> > tree;

	BinaryTree(int _len = 0) :len(_len),tree(len)
	{//默认建立一颗完全二叉树
		if (len == 0)return;

		for (int i = 0; i < len; i++)
		{
			tree[i].data = i;
			tree[i].father = i / 2;
			if (i * 2 + 1 < len)
				tree[i].leftson = i * 2 + 1;
			if (i * 2 + 2 < len)
				tree[i].rightson = i * 2 + 2;
		}
	}

	void preorder(int pntNode = 0)
	{//先序遍历
		if (tree[pntNode].leftson != -1)
			preorder(tree[pntNode].leftson);

		cout << tree[pntNode].data << " ";

		if (tree[pntNode].rightson != -1)
			preorder(tree[pntNode].rightson);
	}

	void midorder(int pntNode = 0)
	{//中序遍历
		cout << tree[pntNode].data << " ";

		if (tree[pntNode].leftson != -1)
			midorder(tree[pntNode].leftson);

		if (tree[pntNode].rightson != -1)
			midorder(tree[pntNode].rightson);
	}

	void postorder(int pntNode = 0)
	{//层次遍历
		if (tree[pntNode].leftson != -1)
			postorder(tree[pntNode].leftson);

		if (tree[pntNode].rightson != -1)
			postorder(tree[pntNode].rightson);

		cout << tree[pntNode].data << " ";
	}

	void level(int pntNode = 0)
	{//层次遍历
		queue<int> myq;
		int pnt;

		myq.push(pntNode);

		while (!myq.empty())
		{
			pnt = myq.front();
			cout << tree[pnt].data << " ";
			if (tree[pnt].leftson != -1)
				myq.push(tree[pnt].leftson);
			if (tree[pnt].rightson != -1)
				myq.push(tree[pnt].rightson);
			myq.pop();
		}
	}
};




int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif // LOCAL

	BinaryTree<int> mytree(7);//默认建立一颗完全二叉树

	cout << "前序遍历"; mytree.preorder(); cout << endl;
	cout << "中序遍历"; mytree.midorder(); cout << endl;
	cout << "后序遍历"; mytree.postorder(); cout << endl;
	cout << "层次遍历"; mytree.level(); cout << endl;

	return 0;
}
