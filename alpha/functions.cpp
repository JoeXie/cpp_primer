#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <utility>

using namespace std;

istream& testIostream(istream & istrm)
{
	string str;
	while (istrm) {
		getline(istrm, str);
		cout << str << endl;
	}

	cout << "eof: " << istrm.eof() << endl;
	cout << "bad: " << istrm.bad() << endl;
	cout << "fail: " << istrm.fail() << endl;
	cout << "good: " << istrm.good() << endl;
	istrm.clear(istrm.failbit);
	cout << "eof: " << istrm.eof() << endl;
	cout << "bad: " << istrm.bad() << endl;
	cout << "fail: " << istrm.fail() << endl;
	cout << "good: " << istrm.good() << endl;

	return istrm;
}

void replace(string &s, string &oldVal, string &newVal)
{
	for (size_t i = 0; i != s.size() - oldVal.size() + 1; ++i) {
		//string sub = s.substr(i, oldVal.size());
		string sub(s, i, oldVal.size());
		if (sub == oldVal) {
			s.replace(i, oldVal.size(), newVal);
		}
	}

}

void fixName(string &name, const string fore, const string back)
{
	name.insert(0, fore, 0, fore.size());
	name.insert(name.size(), back, 0, back.size());
}

void elimDups(vector<string> & words)
{
	for (auto str : words) {
		cout << str << " ";
	}
	cout << endl;

	sort(words.begin(), words.end());
	for (auto str : words) {
		cout << str << " ";
	}
	cout << endl;

	auto end_unique = unique(words.begin(), words.end());
	for (auto str : words) {
		cout << str << " ";
	}
	cout << endl;

	words.erase(end_unique, words.end());
	for (auto str : words) {
		cout << str << " ";
	}
	cout << endl;

}

bool longerThan(string& str)
{
	return str.size() > 3;
}

bool isShorter(const string & s1, const string & s2)
{
	return s1.size() < s2.size();
}

bool check_size(const string& s, string::size_type sz)
{
	return s.size() > sz;
}

void printVec(vector<int> &ivec)
{
	for (const auto & i : ivec)
		cout << i << " ";
	cout << endl;
}

void printVec(vector<string> &vec)
{
	for (const auto & s : vec)
		cout << s << " ";
	cout << endl;
}

void printList(list<int> &iLst)
{
	for (const auto & i : iLst)
		cout << i << " ";
	cout << endl;
}

void printList(list<string> &lst)
{
	for (const auto & s : lst)
		cout << s << " ";
	cout << endl;
}

void printMap(map<string, int> mp)
{
	for (auto &pa : mp) {
		cout << "first: " << pa.first << " \t"
			<< "second: " << pa.second << endl;
		pa.second = 100;
	}
}

//10.33
void selectNum(const string &in_path, const string &odd_path, const string &even_path)
{
	// open file
	ifstream file_in(in_path);
	ofstream out1(odd_path), out2(even_path);

	// creat iostream iteratror.
	istream_iterator<int> in(file_in), eof;
	ostream_iterator<int> odd_out(out1, " "), even_out(out2, "\n");

	while (in != eof) {
		int ival = *in++;
		if (ival % 2) //odd
			*odd_out++ = ival;
		else //even
			*even_out++ = ival;
	}
}

//11.3
map<string, string> buildMap(ifstream &map_file){
	map<string, string> trans_map; //保存转换规则  
	string key; // 要替换的单词  
	string value; // 替换后的内容  
	// 读取第一个单词存入key中，行中剩余内容存入value  
	while (map_file >> key && getline(map_file, value)){
		if (value.size() > 1){ // 检查是否有转换规则  
			trans_map[key] = value.substr(1); //跳过前导空格  
		}
		else{
			throw runtime_error("no rule for " + key);
		}
	}
	return trans_map;
}

const string& transform(const string &s, const map<string, string> &m){
	// 实际的转换工作；此部分是程序的核心  
	auto map_it = m.find(s);
	// 如果单词在转换规则map中  
	if (map_it != m.cend()){
		return map_it->second;  // 使用替换短语  
	}
	else{
		return s;  // 否则返回原string  
	}
}

void word_transform(ifstream &map_file, ifstream &input){
	auto trans_map = buildMap(map_file); // 保存转换规则  
	string text;      // 保存输入中的每一行  
	while (getline(input, text)){ // 读取一行输入  
		istringstream stream(text); // 读取每个单词  
		string word;
		bool firstword = true;   // 控制是否打印空格  
		while (stream >> word){
			if (firstword){
				firstword = false;
			}
			else{
				cout << " ";
			}
			// transform返回它的第一个参数或其转换之后的形式  
			cout << transform(word, trans_map); // 打印输出  
		}
		cout << endl;
	}
}
