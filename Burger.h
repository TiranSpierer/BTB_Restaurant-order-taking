#pragma once
#include "Food.h"

class Burger : public Food
{
public:
	Burger(bool salad = false, bool cheese = false, bool intBurger = false, int price = 56, int calories = 300, bool kosher = true);

	virtual string printBill();
	virtual int priceOfBill();

	void setCheese(bool isTrue);
	void setSalad(bool isTrue);
	void setDoubleBurger(bool isTrue);

	bool getCheese();
	bool getSalad();
	bool getDoubleBurger();


private:
	bool salad;        // + $3
	bool cheese;       // + $5
	bool doubleBurger; // + $15
};