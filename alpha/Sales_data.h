#include <iostream>
#include <string>

class Sales_data
{
	friend Sales_data add(const Sales_data&, const Sales_data &);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);

public:
	//constructor
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p) {}
	Sales_data(std::istream &is);



	//members
	std::string isbn() const { return bookNo; }
	Sales_data & combine(const Sales_data&);
	double avg_price() const;

private:
	//members
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

//interface functions for Sales_data, but not it's member.
Sales_data add(const Sales_data&, const Sales_data &);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
