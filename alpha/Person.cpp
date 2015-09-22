#include "Person.h"

using namespace std;

//Person define.
//interface of Person.
std::istream &read(std::istream &is, Person &psn)
{
	is >> psn.name >> psn.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &psn)
{
	os << psn.name << " "
		<< psn.address;
	return os;
}