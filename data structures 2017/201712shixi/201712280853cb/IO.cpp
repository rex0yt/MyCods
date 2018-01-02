using namespace std;
#include <fstream>
#include <io.h>
#include <vector>
#include "Person.h"
#include "IO.h"
#include "Relation.h"

bool IO::openFile() throw(IOException)
{
    if(access(path.data(), 0) == -1)
    {
        throw IOException(0);
        return false;
    }
    thisFile.open(path.data(),ios::in|ios::out);
    return true;
}

bool IO::closeFile()
{
    thisFile.close();
    return true;
}

bool IO::readData(vector<Person>& personArray, vector<Relation>& relationArray)
{
    int lenPer,lenRela;
    personArray.clear();
    thisFile >> lenPer;
    Person onePerson;
    for(int i=0; i<lenPer; i++)
    {
        thisFile >> onePerson;
        personArray.push_back(onePerson);
    }
    relationArray.clear();
    thisFile >> lenRela;
    Relation oneRelation;
    for(int i=0; i<lenRela; i++)
    {
        thisFile >> oneRelation;
        relationArray.push_back(oneRelation);
    }
    return true;
}

bool IO::writeData(vector<Person>& personArray, vector<Relation>& realtionArray)
{
    thisFile << personArray.size() << endl;
    for(int i=0; i<(int)personArray.size(); i++)
    {
        thisFile << personArray[i];
    }
    thisFile << realtionArray.size() << endl;
    for(int i=0; i<(int)realtionArray.size(); i++)
    {
        thisFile << realtionArray[i];
    }
    return true;
}
