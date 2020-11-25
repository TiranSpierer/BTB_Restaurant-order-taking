#pragma once
#include <iostream>
#include <string>
using namespace std;

class Table
{
public:
	virtual ~Table();
	virtual string printBill() = 0;
	virtual int priceOfBill() = 0;

	void setBill(int);
	static int getBill();

private:
	static int bill;
};

