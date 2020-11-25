#include "pch.h"
#include "Burger.h"

Burger::Burger(bool salad, bool cheese, bool doubleBurger, int price, int calories, bool kosher) : Food(price, calories, kosher)
{
	this->salad = salad;
	this->cheese = cheese;
	this->doubleBurger = doubleBurger;

	if (salad == true)
		setPrice(getPrice() + 3);
	if (cheese == true) {
		setPrice(getPrice() + 5);
		setCalories(calories + 50);
		setKosher(false);
	}

	if (doubleBurger == true) {
		setPrice(getPrice() + 15);
		setCalories(calories + 150);
	}

	setBill(getBill() + getPrice());
}

string Burger::printBill()
{
	string str;
	str += "Burger: $" + to_string(getPrice()) + "\r\n";
	return str;
}

int Burger::priceOfBill()
{
	return getPrice();
}

void Burger::setCheese(bool isTrue)
{
	cheese = isTrue;
	if (cheese == true) {
		setKosher(false);
		setCalories(getCalories() + 50);
		setPrice(getPrice() + 5);
	}
	else {
		setKosher(true);
		setCalories(getCalories() - 50);
		setPrice(getPrice() - 5);
	}
}

void Burger::setSalad(bool isTrue)
{
	salad = isTrue;

	if (salad == true)
		setPrice(getPrice() + 3);
	else
		setPrice(getPrice() - 3);
}

void Burger::setDoubleBurger(bool isTrue)
{
	doubleBurger = isTrue;

	if (doubleBurger == true) {
		setCalories(getCalories() + 150);
		setPrice(getPrice() + 15);
	}
	else {
		setCalories(getCalories() - 150);
		setPrice(getPrice() - 15);
	}
}

bool Burger::getCheese()
{
	return cheese;
}

bool Burger::getSalad()
{
	return salad;
}

bool Burger::getDoubleBurger()
{
	return doubleBurger;
}
