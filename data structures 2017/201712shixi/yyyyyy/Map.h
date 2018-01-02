#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

using namespace std;
#include <vector>
#include <iostream>
#include <queue>
#define MAXVERTICES (10000)

//邻接链表的边类型
template <class T, class E>
struct Edge
{
    int dest;
    E cost;
    Edge<T, E> *link;
    Edge() {}
    Edge(int num, E weight):dest(num), cost(weight), link(NULL) {}
    bool operator!=(Edge<T,E>& R) const;//判断两条边不相等
};

//邻接链表的顶点类型
template <class T, class E>
struct Vertex
{
    T data;
    Edge<T, E> *adj;
};

//定义邻接链表
template <class V, class E>
class Map
{
public:
    Vertex<V, E> *NodeTable;//顶点链表
    int numVertices;//当前顶点数量
    int numEdges;//边的数量
    int maxVertices;//最多顶点数量
public:
    int getVertexPos(const V vertex);//取某个顶点的编号
    Map();//默认构造函数
    Map(vector<V> &vArray, vector<E> &eArray);//根据顶点和边生成图
    ~Map();//析构函数：删除一个链接表
    V getValue(int i);//根据顶点的编号返回顶点信息
    E getWeight(int v1,int v2);//函数返回边(v1,v2)上的权值，若该边不在图中，则函数返回权值0
    bool insertVertex(const V&vertex);//在图的顶点表中插入一个新顶点vertex。若插入成功，函数返回true，否则false
    bool insertEdge(int v1, int v2, E cost);//在带权图中插入一条边（v1，v2），若此边存在或参数不合理，函数返回flase，否则true
    bool insertEdge(E cost);//插入一条边
    bool removeVertex(int v);//在图中删除一个顶点v,v是顶点号。若删除成功，函数返回true，否则false
    bool removeEdge(int v1,int v2);//在图中删除一条边（v1,v2）
    int getFirstNeighbor(int v);//给出顶点位置为v的第一个邻接顶点的位置，如果找不到，则函数返回-1
    int getNextNeighbor(int v,int w);//给出顶点v的邻接顶点w的下一个邻接顶点的位置，若没有下一个邻接顶点，则函数返回-1
    void Output();//向屏幕输出图的信息
    void Output(vector<V> &vArray, vector<E> &eArray);//向数组输出图的信息 保存
    int getNumVertices() {return numVertices;}
    int getNumEdges() {return numEdges;}
    friend istream& operator>>(istream& in, Map<V,E>&G)
    {
        return in;
    };
    friend ostream& operator<<(ostream& out, Map<V,E>&G)
    {
        return out;
    };
};

template <class T, class E>
bool Edge<T, E>::operator!=(Edge<T,E>& R) const
{
    return (dest != R.dest)?true:false;
}

template <class V, class E>
int Map<V, E>::getVertexPos(const V vertex){
    for(int i=0; i<numVertices; i++)
        if(NodeTable[i].data == vertex) return i;
    return -1;
}

template <class V, class E>
Map<V, E>::Map()
{
    maxVertices = MAXVERTICES; numVertices = 0; numEdges = 0;
    NodeTable = new Vertex<V, E>[maxVertices];//创建顶点数组
    if (NodeTable == NULL) {cerr << "存储分配出错！" << endl; return ;}
    for (int i=0; i<maxVertices; i++)NodeTable[i].adj = NULL;
};

template <class V, class E>
Map<V, E>::Map(vector<V> &vArray, vector<E> &eArray)
{
    maxVertices = MAXVERTICES; numVertices = 0; numEdges = 0;
    NodeTable = new Vertex<V, E>[maxVertices];//创建顶点数组

    for(int i=0; i<(int)vArray.size(); i++) //生成表头结点
    {
        NodeTable[i].data = vArray[i];
        NodeTable[i].adj = NULL;
        numVertices ++;
    }
    E tmpEdge;
    for(unsigned int i=0; i<eArray.size(); i++)
    {
        tmpEdge = eArray[i];
        this->insertEdge(tmpEdge);
    }
}

template <class V, class E>
Map<V, E>::~Map()
{
    for(int i=0;i<numVertices;i++)
    {
        Edge<V,E> *p = NodeTable[i].adj;
        while(p!=NULL)
        {
            NodeTable[i].adj = p->link;
            delete p;
            p = NodeTable[i].adj;
        }
    }
    delete[] NodeTable;
}

template <class V, class E>
V Map<V, E>::getValue(int i)
{
    return (i>=0 && i<numVertices) ? NodeTable[i].data : 0;
}

template <class V, class E>
int Map<V, E>::getFirstNeighbor(int v)
{
    if(v != -1)
    {
        Edge<V,E> *p = NodeTable[v].adj;
        if(p != NULL) return p->dest;
    }
    return -1;
}

template <class V, class E>
int Map<V, E>::getNextNeighbor(int v, int w)
{
    if(v!=-1)
    {
        Edge<V, E> *p = NodeTable[v].adj;
        while (p != NULL && p->dest != w)
            p = p->link;
        if (p != NULL && p->link != NULL)
            return p->link->dest;
    }
    return -1;
}

template <class V, class E>
E Map<V,E>::getWeight(int v1, int v2)
{
    if(v1!=-1&&v2!=-1)
    {
        Edge<V,E> *p = NodeTable[v1].adj;
        while(p!=NULL&&p->dest!=v2)
            p = p->link;
        if(p!= NULL) return p->cost;
    }
    return 0;
}

template <class V, class E>
bool Map<V,E>::insertVertex(const V& vertex)
{
    if(numVertices == maxVertices)
        return false;
    NodeTable[numVertices].data = vertex;
    numVertices++;
    return true;
}

template <class V, class E>
bool Map<V,E>::removeVertex(int v)
{
    if(numVertices==1||v<0||v>=numVertices)
        return false;
    Edge<V,E> *p,*s,*t;
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

template <class V, class E>
bool Map<V,E>::insertEdge(int v1,int v2, E weight)
{
    if(v1>=0 && v1<numVertices && v2>=0 && v2<numVertices)
    {
        Edge<V,E> *q, *p=NodeTable[v1].adj;
        while(p!=NULL&&p->dest!=v2)
            p = p ->link;
        if(p!=NULL) return false;
        p = new Edge<V,E>; q = new Edge<V,E>;
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

template <class V, class E>
bool Map<V,E>::insertEdge(E weight)
{
    int src = this->getVertexPos(weight.per1);
    int dst = this->getVertexPos(weight.per2);
    if(this->insertEdge(src, dst, weight))
        return true;
    return false;
}

template <class V, class E>
bool Map<V,E>::removeEdge(int v1, int v2) {
    if (v1 != -1 && v2 != -1)
    {
        Edge<V, E> *p = NodeTable[v1].adj, *q = NULL, *s = p;
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

template <class V, class E>
void Map<V, E>::Output()
{
    Edge<PersonNo, Relation> *tmp;
    int len = this->getNumVertices();
    for(int i=0; i<len; i++)
    {
        cout << this->NodeTable[i].data << endl;
        tmp = this->NodeTable[i].adj;
        while(tmp != NULL)
        {
            cout << tmp->cost << " " << tmp->dest << endl;
            tmp = tmp->link;
        }
    }
}

template <class V, class E>
void Map<V, E>::Output(vector<V> &vArray, vector<E> &eArray)
{

}
#endif // MAP_H_INCLUDED
