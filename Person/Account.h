#include <string>
#include <iostream>
using namespace std;

class Account{
public:
	void calculate()
	{
		amount += amount*interestRate;
	}
	static double rate()
	{
		return interestRate;
	}
	static void rate(double newRate)
	{
		interestRate = newRate;
	}
private:
	string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate = 42.42;
	static constexpr int period = 30;
	double daily_tbl[period];
	static double initRate(){ return todayRate; }
};

constexpr int Account::period;
double Account::interestRate = initRate();