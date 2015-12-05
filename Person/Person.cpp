// Person.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include<vector>
#include "Person.h"
using namespace std;

int gets(const vector<int>& a)
{
	//cout << a.size() << endl;
	return a.size();
}

int main()
{
	cout << boolalpha << is_literal_type<Person>::value << endl;
	//cout << gets(vector<int>(34)) << endl;
	system("pause");
	return 0;
}

