#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

// foreward declaration
class MyQueryResult;

/*************************
define MyTextQuery
***************************/
class MyTextQuery 
{
public:
    MyTextQuery(std::ifstream &infile_path);
    MyQueryResult query(const std::string &infile);


};

/*************************
define MyQueryResult
***************************/
class MyQueryResult
{
public:
    MyQueryResult();
};


// function interfaces.
ostream & print(std::ostream &os, MyQueryResult qresult);