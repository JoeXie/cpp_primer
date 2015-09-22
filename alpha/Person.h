#include <iostream>
#include <string>

// class person
class Person
{
	friend std::istream &read(std::istream &is, Person &psn);
	friend std::ostream &print(std::ostream &os, const Person &psn);
public:
	//constructors
	Person() = default;
	Person(const std::string & name, const std::string &address) :
		name(name), address(address) {}

private:
	//members
	std::string name;
	std::string address;
};

//interface of Person
std::istream &read(std::istream &is, Person &psn);
std::ostream &print(std::ostream &os, const Person &psn);