#pragma once
#include "Food.h"

class Falafel : public Food
{
public:
	Falafel(bool humus = false, bool tahini = false, bool salad = false, int price = 18, int calories = 100, bool kosher = true);

	virtual string printBill();
	virtual int priceOfBill();

	void setHumus(bool isTrue);
	void setTahini(bool isTrue);
	void setSalad(bool isTrue);

	bool getHumus();
	bool getTahini();
	bool getSalad();


private:
	bool humus;   //true = with
	bool tahini;  //true = with
	bool salad;   //true = with
};