#include <string>
#include <iostream>
using namespace std;

class Person
{
	friend istream &read(istream&, Person &);
	friend ostream &print(ostream&, Person &);
public:
	Person() = default;
	Person(const string a,const string b) :name(a), address(b){}
	explicit Person(istream& is){ read(is, *this); }
	
	string getName() const{ return name; }
	string getAddress() const{ return address; }
private:
	string name;
	string address;
};

istream &read(istream& is, Person & p)
{
	is >> p.name >> p.address;
	return is;
}

ostream &print(ostream& os, Person &p)
{
	os << p.name << " " << p.address;
	return os;
}