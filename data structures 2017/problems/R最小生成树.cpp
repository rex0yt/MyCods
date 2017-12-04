using namespace std;

#include <iostream>
#include <vector>
#define MaxN (1000)
#define maxVal 9999
#define minVal -9999

struct Node
{
    int src;
    int des;
    int wei;
    friend bool operator<(Node a, Node b)
    {
        return a.wei < b.wei;
    }
};

int n;
int thisMap[MaxN][MaxN];
int solution[MaxN][MaxN];

void PrintSol()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Prim()
{
    bool visted[MaxN];
    //init
    for(int i=0; i<MaxN; i++)
    {
        visted[i] = false;
    }
    for(int i=0; i<MaxN; i++)
        for(int j=0; j<MaxN; j++)
            solution[i][j] = 0;
    //....................................
    visted[0] = true;
    int cntEdge=0;
    PrintSol();
    while(cntEdge < n-1)
    {
        int tmpMin = maxVal;
        int mins,mind;
        for(int i=0; i<n; i++)
        {
            if(visted[i] == true)
            {
                for(int j=0; j<n; j++)
                {
                    if(thisMap[i][j] > 0 && visted[j] == false)
                    {
                        if(thisMap[i][j] < tmpMin)
                        {
                            tmpMin = thisMap[i][j];
                            mins = i;
                            mind = j;
                        }
                    }
                }
            }
        }
        visted[mind] = true;
        cntEdge ++;
        solution[mins][mind] = solution[mind][mins] = tmpMin;
        PrintSol();
    }
}

int father[MaxN];

void setInit()
{
    for(int i=0; i<n; i++)
        father[i] = i;
    return ;
}

int getFather(int x)
{
    if(father[x] == x)
        return x;
    return getFather(father[x]);
}

void UnionSet(int left, int right)
{
    int faLeft = getFather(left);
    int faRight = getFather(right);
    if(faLeft == faRight)
        return ;
    if(faLeft < faRight)
        father[faRight] = faLeft;
    else
        father[faLeft] = faRight;
    return ;
}

vector<Node> edge;

void Kruskal()
{
    Node tmpNode;
    //...........init..........
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            solution[i][j] = 0;

    //...........init2.........
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(thisMap[i][j] > 0)
            {
                tmpNode.src = i;
                tmpNode.des = j;
                tmpNode.wei = thisMap[i][j];
                edge.push_back(tmpNode);
            }
        }
    }
    setInit();
    //..........................
    PrintSol();
    int cntEdge = 0;
    while (cntEdge < n-1)
    {
        int minEdge = maxVal;
        int mins,mind;
        for(int i=0; i<(int)edge.size(); i++)
        {
            tmpNode = edge[i];
            if(getFather(tmpNode.src) != getFather(tmpNode.des))
            {
                if(minEdge > tmpNode.wei)
                {
                    minEdge = tmpNode.wei;
                    mins = tmpNode.src;
                    mind = tmpNode.des;
                }
            }
        }
        UnionSet(mins, mind);
        cntEdge ++;
        solution[mins][mind] = solution[mind][mins] = minEdge;
        PrintSol();
    }

}
int main()
{
    //input the map
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> thisMap[i][j];
    //..................
    cout << "Prim:" << "\n";
    Prim();
    //.................
    cout << "Kruskal:\n";
    Kruskal();

    return 0;
}
