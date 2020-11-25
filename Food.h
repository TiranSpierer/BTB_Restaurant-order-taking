#pragma once
#include "Table.h"

class Food : public Table
{
public:
	Food(int price = 0, int calories = 0, bool kosher = true);

	void setPrice(int);
	void setCalories(int);
	void setKosher(bool);

	int getPrice();
	int getCalories();
	bool getKosher();

	virtual string printBill() = 0;
	virtual int priceOfBill() = 0;

private:
	int price;
	int calories;
	bool kosher;
};