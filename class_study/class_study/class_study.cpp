// class_study.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Sales_data.h"
using namespace std;

int main(int argc,char **argv)
{
	ifstream input(argv[1]);
	ofstream out(argv[2],ostream::app);
	Sales_data total(input);
	if (!total.isbn().empty())
	{
		Sales_data trans;
		while (read(input,trans))
		{
			
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(out, total) << endl;;
				total = trans;
			}
		}
		print(out, total) << endl;
	}
	system("pause");
	return 0;
}
