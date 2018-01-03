#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

using namespace std;
#include <vector>
#include <iostream>

#include "mapsrc/Person.h"
#include "mapsrc/Relation.h"
#include "mapsrc/IO.h"

#define MAXVERTICES (10000)

//邻接链表的边类型
template <class T>
struct Edge
{
  int dest;
  int cost;
  Edge<T> *link;
  Edge() {}
  Edge(int num, int weight):dest(num), cost(weight), link(NULL) {}
  bool operator!=(Edge<T>& R) const;//判断两条边不相等
};

//邻接链表的顶点类型
template <class T>
struct Vertex
{
  T data;
  Edge<T> *adj;

  Vertex():adj(NULL) {}
  Vertex(T t):data(t),adj(NULL) {}
};

//定义邻接链表
template <class V>
class Map
{
public:
  Vertex<V> *NodeTable;//顶点链表
  int numVertices;//当前顶点数量
  int numEdges;//边的数量
  int maxVertices;//最多顶点数量
public:
  int getVertexPos(const V vertex);//取某个顶点的编号
  Map();//默认构造函数
  Map(vector<V> &vArray, vector<Relation> &eArray);//根据顶点和边生成图
  ~Map();//析构函数：删除一个链接表
  V getValue(int i);//根据顶点的编号返回顶点信息
  int getWeight(int v1,int v2);//函数返回边(v1,v2)上的权值，若该边不在图中，则函数返回权值0
  vector<int> getAllRelation(int v1);//返回所有相邻边的
  bool insertVertex(const V&vertex);//在图的顶点表中插入一个新顶点vertex。若插入成功，函数返回true，否则false
  bool insertEdge(int v1, int v2, int cost);//在带权图中插入一条边（v1，v2），若此边存在或参数不合理，函数返回flase，否则true
  bool insertEdge(Relation oneRela);//插入一条边
  bool removeVertex(int v);//在图中删除一个顶点v,v是顶点号。若删除成功，函数返回true，否则false
  bool removeEdge(int v1,int v2);//在图中删除一条边（v1,v2）
  int getFirstNeighbor(int v);//给出顶点位置为v的第一个邻接顶点的位置，如果找不到，则函数返回-1
  int getNextNeighbor(int v,int w);//给出顶点v的邻接顶点w的下一个邻接顶点的位置，若没有下一个邻接顶点，则函数返回-1
  void Output();//向屏幕输出图的信息
  void Output(vector<V> &vArray, vector<Relation> &eArray);//向数组输出图的信息 保存
  int getNumVertices() {return numVertices;}
  int getNumEdges() {return numEdges;}
};

template <class T>
bool Edge<T>::operator!=(Edge<T>& R) const
{
  return (dest != R.dest)?true:false;
}

template <class V>
int Map<V>::getVertexPos(const V vertex){
  for(int i=0; i<numVertices; i++)
    if(NodeTable[i].data == vertex) return i;
  return -1;
}

template <class V>
Map<V>::Map()
{
  maxVertices = MAXVERTICES; numVertices = 0; numEdges = 0;
  NodeTable = new Vertex<V>[maxVertices];//创建顶点数组
  if (NodeTable == NULL) {cerr << "存储分配出错！" << endl; return ;}
  for (int i=0; i<maxVertices; i++)NodeTable[i].adj = NULL;
};

template <class V>
Map<V>::Map(vector<V> &vArray, vector<Relation> &eArray)
{
  maxVertices = MAXVERTICES; numVertices = 0; numEdges = 0;
  NodeTable = new Vertex<V>[maxVertices];//创建顶点数组

  for(int i=0; i<(int)vArray.size(); i++) //生成表头结点
    {
      NodeTable[i].data = vArray[i];
      NodeTable[i].adj = NULL;
      numVertices ++;
    }
  Relation tmpEdge;
  for(unsigned int i=0; i<eArray.size(); i++)
    {
      tmpEdge = eArray[i];
      this->insertEdge(tmpEdge);
    }
}

template <class V>
Map<V>::~Map()
{
  for(int i=0;i<numVertices;i++)
    {
      Edge<V> *p = NodeTable[i].adj;
      while(p!=NULL)
        {
          NodeTable[i].adj = p->link;
          delete p;
          p = NodeTable[i].adj;
        }
    }
  delete[] NodeTable;
}

template <class V>
V Map<V>::getValue(int i)
{
  return (i>=0 && i<numVertices) ? NodeTable[i].data : 0;
}

template <class V>
int Map<V>::getFirstNeighbor(int v)
{
  if(v != -1)
    {
      Edge<V> *p = NodeTable[v].adj;
      if(p != NULL) return p->dest;
    }
  return -1;
}

template <class V>
int Map<V>::getNextNeighbor(int v, int w)
{
  if(v!=-1)
    {
      Edge<V> *p = NodeTable[v].adj;
      while (p != NULL && p->dest != w)
        p = p->link;
      if (p != NULL && p->link != NULL)
        return p->link->dest;
    }
  return -1;
}

template <class V>
int Map<V>::getWeight(int v1, int v2)
{
  if(v1!=-1&&v2!=-1)
    {
      Edge<V> *p = NodeTable[v1].adj;
      while(p!=NULL&&p->dest!=v2)
        p = p->link;
      if(p!= NULL) return p->cost;
    }
  return 0;
}

template<class V>
vector<int> Map<V>::getAllRelation(int v1)
{
  vector<int> ans;
  Edge<V> *pnt = NodeTable[v1].adj;
  while(pnt != NULL)
    {
      int vertex = this->getValue(pnt->dest);
      ans.push_back(vertex);
      pnt = pnt->link;
    }
  return ans;
}

template <class V>
bool Map<V>::insertVertex(const V& vertex)
{
  if(numVertices == maxVertices)
    return false;
  NodeTable[numVertices].data = vertex;
  numVertices++;
  return true;
}

template <class V>
bool Map<V>::removeVertex(int v)
{
  if(numVertices==1||v<0||v>=numVertices)
    return false;
  Edge<V> *p,*s,*t;
  int i,k;
  while(NodeTable[v].adj!= NULL)
    {
      p = NodeTable[v].adj;
      k = p->dest;
      s = NodeTable[k].adj;
      t = NULL;
      while(s!= NULL&&s->dest!=v)
        {
          t = s;
          s = s->link;
        }
      if(s!= NULL)
        {
          if(t==NULL)
            NodeTable[k].adj = s->link;
          else t->link = s->link;
          delete s;
        }
      NodeTable[v].adj = p->link;
      delete p;
      numEdges--;
    }
  numVertices--;
  NodeTable[v].data = NodeTable[numVertices].data;
  p = NodeTable[v].adj = NodeTable[numVertices].adj;
  while(p != NULL)
    {
      s =NodeTable[p->dest].adj;
      while(s!=NULL)
        if(s->dest == numVertices)
          {
            s->dest = v;
            break;
          }
        else s = s->link;
    }
  return true;
}

template <class V>
bool Map<V>::insertEdge(int v1,int v2, int weight)
{
  if(v1>=0 && v1<numVertices && v2>=0 && v2<numVertices)
    {
      Edge<V> *q, *p=NodeTable[v1].adj;
      while(p!=NULL&&p->dest!=v2)
        p = p ->link;
      if(p!=NULL) return false;
      p = new Edge<V>; q = new Edge<V>;
      p->dest = v2; p->cost = weight;
      p -> link = NodeTable[v1].adj;
      NodeTable[v1].adj = p;
      q -> dest = v1; q -> cost = weight;
      q -> link = NodeTable[v2].adj;
      NodeTable[v2].adj=q;
      numEdges ++; return true;
    }
  return false;
}

template <class V>
bool Map<V>::insertEdge(Relation oneRela)
{
  if(this->insertEdge(this->getVertexPos(oneRela.getPer1()),
         this->getVertexPos(oneRela.getPer2()),oneRela.getWeight()))
    return true;
  return false;
}

template <class V>
bool Map<V>::removeEdge(int v1, int v2) {
  if (v1 != -1 && v2 != -1)
    {
      Edge<V> *p = NodeTable[v1].adj, *q = NULL, *s = p;
      while (p != NULL && p->dest != v2)
        {
          q = p;p = p->link;
        }
      if (p != NULL)
        {
          if(p == s) NodeTable[v1].adj = p->link;
          else q->link = p->link;
          delete p;
        }
      else return false;
      p = NodeTable[v2].adj;
      q = NULL, s = p;
      while (p->dest != v1)
        {
          q = p; p = p->link;
        }
      if (p == s) NodeTable[v2].adj = p->link;
      else q->link = p->link;
      delete p;
      return true;
    }
  return false;
}

template <class V>
void Map<V>::Output()
{
  Edge<V> *tmp;
  int len = this->getNumVertices();
  for(int i=0; i<len; i++)
    {
      cout << this->NodeTable[i].data << endl;
      tmp = this->NodeTable[i].adj;
      while(tmp != NULL)
        {
          cout << this->getValue(tmp->dest) << " " << tmp->cost << endl;
          tmp = tmp->link;
        }
    }
}

template <class V>
void Map<V>::Output(vector<V> &vArray, vector<Relation> &eArray)
{

}
#endif // MAP_H_INCLUDED
