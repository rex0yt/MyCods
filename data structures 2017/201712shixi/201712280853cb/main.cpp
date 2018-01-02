#include <iostream>
#include <vector>
#include "PersonNo.h"
#include "PersonInfo.h"
#include "Relation.h"
#include "Map.h"
#include "IO.h"
#include "LinkedList.h"

using namespace std;

int main()
{
    vector<Person> personArray;
    vector<Relation> relationArray;
    vector<PersonNo> personNoArray;

    //首先从文件中读取数据建立关系网络
    string path = "data.txt";


    IO dataIO(path);
    dataIO.openFile();
    dataIO.readData(personArray, relationArray);
    dataIO.closeFile();

    PersonNo tttt;
    for (int i=0; i<(int)personArray.size(); i++)
    {
        tttt = personArray[i].getNo();
        personNoArray.push_back(tttt);
    }
    Map<PersonNo, Relation> thisMap(personNoArray, relationArray);

    Edge<PersonNo, Relation> *tmp;
    for(int i=0; i<thisMap.getNumVertices(); i++)
    {
        cout << thisMap.NodeTable[i].data << endl;
        tmp = thisMap.NodeTable[i].adj;
        while(tmp != NULL)
        {
            cout << tmp->cost << " " << tmp->dest << endl;
            tmp = tmp->link;
        }
    }
    return 0;
}

