// string_by_myself.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include  <vector>
#include "string.h"
using namespace std;

String baz()
{
	String ret("world");
	return ret; // first avoided
}



int _tmain(int argc, _TCHAR* argv[])
{
	String s5 = baz(); // second avoided
	cout << s5 << endl;

	String tmp;
	cin >> tmp;
	cout << tmp << endl;

	/*vector<String>a;
	a.push_back("aaa");
	
	cout << "--1--" << endl;
	a.push_back("bbb");
	cout << "--1--" << endl;
	a.push_back("ccc");
	cout << "--1--" << endl;
	a.push_back("aaa");
	cout << "--1--" << endl;
	a.push_back("bbb");
	cout << "--1--" << endl;
	a.push_back("ccc");
	cout << "--1--" << endl;
	a.push_back("aaa");
	cout << "--1--" << endl;
	a.push_back("aaa");
	cout << "--1--" << endl;*/
	system("pause");
	return 0;
}

