#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>

#include "StrBlob.h"

using namespace std;

//remember to release memory
shared_ptr<vector<string>> read(istream &is)
{
    //auto pvec = new vector<string>();
    //auto pvec = make_shared<vector<string>>();
    shared_ptr<vector<string>> pvec(new vector<string>());

    string str;
    while (is >> str) {
        pvec->push_back(str);
    }

    return pvec;
}

ostream& print(ostream &os, const vector<string> *pvec)
{
    for (const auto &s : *pvec) {
        os << s << "  ";
    }
    return os;
}

ostream& print(ostream &os, const shared_ptr<vector<string>> &pvec)
{
    for (const auto &s : *pvec) {
        os << s << "  ";
    }
    return os;
}

struct destination
{
    destination()
    {
        cout << "destination" << "  ";
    }

};

struct connection
{
    connection()
    {
        cout << "connection" << "  ";
    }

};

connection connect(destination* dst)
{
    connection c;
    return c;
};

void disconect(connection cnct)
{
    cout << "disconnect" << "  ";
};

void end_connection(connection *p)
{
    disconect(*p);
}

void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p){ disconect(*p); });
}

//read and save data to StrBlob
istream & readline(istream &is, StrBlob & strb)
{
    string str;
    getline(is, str);
    strb.push_back(str);

    return is;
}

//print
ostream & print(ostream &os, StrBlob & strb)
{
    StrBlobPtr strbPtr = strb.begin();
    for (int i = 0; i < strb.size(); strbPtr.incr(), ++i) {
        os << strbPtr.deref() << "\n";
    }
    return os;
}

int main(int argc, char *argv[])
{



    system("pause");
    return 0;
}
