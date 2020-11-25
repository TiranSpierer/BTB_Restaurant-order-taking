#include "pch.h"
#include "Table.h"
#include "Food.h"


Food::Food(int price, int calories, bool kosher) : price(price), calories(calories), kosher(kosher)
{
}

void Food::setPrice(int price)
{
	this->price = price;
}

void Food::setCalories(int calories)
{
	this->calories = calories;
}

void Food::setKosher(bool kosher)
{
	this->kosher = kosher;
}

int Food::getPrice()
{
	return price;
}

int Food::getCalories()
{
	return calories;
}

bool Food::getKosher()
{
	return kosher;
}
