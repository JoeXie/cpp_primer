#include "TextQuery.h"

using namespace std;

/********************************
define TextQuery
**********************************/
TextQuery::TextQuery(std::ifstream &is) : file(new vector<string>)
{
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text); //分解文本为单词
        string word;
        while (line >> word) {
            auto &lines = wm[word]; //如果单词不在字典中，将创建一个新的key，并返回一个空指针
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n); //插入行号，set会自动排除重复和排序。
        } //while
    } //while
}

QueryResult TextQuery:: query(const std::string& sought) const
{
    static  shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

/********************************
define QueryResult
**********************************/
QueryResult::QueryResult(std::string s,
    std::shared_ptr<std::set<line_no>> p,
    std::shared_ptr<std::vector<std::string>> f)
    : sought(s), lines(p), file(f) {}


/*************************
interface functions
*****************************/
//print the result
ostream& print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << ((qr.lines->size() > 1) ? "times" : "time" )<< endl;
    for (auto num : *qr.lines)
        os << "    (line " << num + 1 << ") "
        << *(qr.file->begin() + num) << endl;
    return os;
}