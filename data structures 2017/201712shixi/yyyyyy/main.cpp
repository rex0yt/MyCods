#include <iostream>
#include <vector>
#include "PersonNo.h"
#include "PersonInfo.h"
#include "Relation.h"
#include "Map.h"
#include "IO.h"
#include "LinkedList.h"

using namespace std;

vector<Person> personArray;
vector<Relation> relationArray;
vector<PersonNo> personNoArray;

int main()
{

    //首先从文件中读取数据建立关系网络
    string path = "data.txt";

    IO dataIO(path);
    dataIO.openFile();
    dataIO.readData(personArray, relationArray);
    dataIO.closeFile();

    PersonNo tmpPersonNo;
    for (unsigned int i=0; i<personArray.size(); i++)
    {
        tmpPersonNo = personArray[i].getNo();
        personNoArray.push_back(tmpPersonNo);
    }

    Map<PersonNo, Relation> thisMap(personNoArray, relationArray);


    thisMap.Output();
    return 0;
}

