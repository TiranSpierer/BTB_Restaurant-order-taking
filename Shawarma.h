#pragma once
#include "Food.h"

class Shawarma : public Food
{
public:
	Shawarma(bool bread = false, bool mixMeat = false, bool spicy = false, int price = 40, int calories = 200, bool kosher = true);

	virtual string printBill();
	virtual int priceOfBill();

	void setLafa(bool isTrue);
	void setMix(bool isTrue);
	void setSpicy(bool isTrue);

	bool getLafa();
	bool getMix();
	bool getSpicy();


private:
	bool lafa;   //true = lafa, false = pita
	bool mix; //false = hodu or pargit, true = mix
	bool spicy;   //true = with spicy
};