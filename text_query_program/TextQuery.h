#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <set>
#include <map>

// foreward declaration
class QueryResult;

/**********************************
define TextQuery
*******************************/
class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &is);
    QueryResult query(const std::string&) const;

private:
    // point to vector save text in line.
    std::shared_ptr<std::vector<std::string>> file; 
    // save line number for the key string.
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

/**********************************
define TextResult
*******************************/
class QueryResult
{
    friend std::ostream & print(std::ostream& os, const QueryResult & qr);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s, 
        std::shared_ptr<std::set<line_no>> p, 
        std::shared_ptr<std::vector<std::string>> f);

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

/*************************
interface functions
*****************************/
//print the result
std::ostream& print(std:: ostream &os, const QueryResult &qr);