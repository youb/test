#include <memory>
#include <iostream>
using namespace std;

class String
{
	friend ostream& operator<<(ostream&, const String &);
	friend istream& operator>>(istream&, String &);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
public:
	String() :String(""){}
	String(const char *s);
	String(const String&);
	String& operator=(const String&);
	String(String&&);
	String& operator=(String&&);
	~String();
	const char* c_str() const { return elements; }
	size_t size() const{ return end - elements; }
	size_t length() const { return end - elements - 1; }
	
	
private:
	allocator<char> alloc;
	char* elements;
	char* end;

	pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();
};

String::String(const char *s)
{
	char* s1 = const_cast<char*>(s);
	while (*s1)
		s1++;
	range_initializer(s, ++s1);
}

void String::range_initializer(const char* b, const char* e)
{
	auto iter = alloc_n_copy(b, e);
	elements = iter.first;
	end = iter.second;

}

pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
	auto count = e - b;
	auto news = alloc.allocate(count);
	return{ news, uninitialized_copy(b, e, news) };
}

String& String::operator=(const String& s)
{
	auto news = alloc_n_copy(s.elements, s.end);
	free();
	elements = news.first;
	end = news.second;
	cout << "copy assignment" << endl;
	return *this;

}

String::String(const String& s)
{
	range_initializer(s.elements, s.end);
	cout << "copy constructor" << endl;
}

void String::free()
{
	if (elements)
	{
		for (auto p = end; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, end - elements);
	}
}

String::~String()
{
	free();
}


String::String(String&& s) :elements(s.elements), end(s.end)
{
	cout << "move constructor" << endl;
	s.elements = s.end = nullptr;
}
String& String::operator=(String&& s)
{
	cout << "move assignment" << endl;
	if (this != &s)
	{
		free();
		elements = s.elements;
		end = s.end;
		s.elements = s.end = nullptr;
	}
	return *this;
}

ostream& operator<<(ostream& os, const String & s)
{
	for (auto p = s.elements; p != s.end;)
	{
		os << *p++;
	}
	return os;
}

istream& operator>>(istream& is, String& s)
{
	for (auto p = s.elements; p != s.end;)
	{
		is >> *p++;
	}
	return is;
}

bool operator==(const String& a, const String& b)
{
	if (a.length() != b.length())
		return false;
	auto q = b.elements;
	for (auto p = a.elements; p != a.end;)
	{
		if (*p++ != *q++)
			return false;
	}
	return true;
}
bool operator!=(const String& a, const String& b)
{
	return !(a == b);
}