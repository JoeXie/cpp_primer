#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "MyTextQuery.h"

using namespace std;

void myRunQueries(ifstream &infile)
{
    MyTextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        // print result.
        print(cout, tq.query(s)) << endl;
    }
}