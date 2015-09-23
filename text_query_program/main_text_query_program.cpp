#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "TextQuery.h"

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        // print result.
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char* argv[])
{
    ifstream inf("../../infile.txt");
    if (inf)
        runQueries(inf);
    else
        cout << "file open failed." << endl;

    system("pause");
    return 0;
}