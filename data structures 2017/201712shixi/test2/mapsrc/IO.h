#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#include "Person.h"
#include "Relation.h"
#include <fstream>

class IOException: public exception
{
private:
    int code;
//-1 ERROR
//00 Existence only
//02 Write permission
//04 Read permission
//06 Read and write permission
public:
    IOException():code(-1) {}
    IOException(int _code):code(_code) {}

    string throwError() const throw()
    {
        switch(code)
        {
        case -1:
            return "ERROR";break;
        case 0:
            return "NOT EXISTED";break;
        case 2:
            return "WRITE PERMISSION DENIED";break;
        case 4:
            return "READ PERMISSION DENIED";break;
        case 6:
            return "READ AND WRITE PERMINSSION DENIED";break;
        }
    }
};

class IO
{
private:
    string path;
    fstream thisFile;
public:
    IO():thisFile(NULL) {}
    IO(string _path):path(_path),thisFile(NULL) {}
    bool openFile() throw(IOException);
    bool closeFile();
    bool readData(vector<Person>& personArray, vector<Relation>& relationArray);
    bool writeData(vector<Person>& personArray, vector<Relation>& realtionArray);
};


#endif // IO_H_INCLUDED
