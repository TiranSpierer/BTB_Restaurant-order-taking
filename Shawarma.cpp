#include "pch.h"
#include "Shawarma.h"
Shawarma::Shawarma(bool lafa, bool mix, bool spicy, int price, int calories, bool kosher) : Food(price, calories, true)
{
	this->lafa = lafa;
	this->mix = mix;
	this->spicy = spicy;

	if (lafa == true) {
		setPrice(getPrice() + 13);
		setCalories(getCalories() + 50);
	}

	if (mix == true)
		this->setPrice(getPrice() + 5);

	if (spicy == true)
		this->setPrice(getPrice() + 1);

	setBill(getBill() + getPrice());
}

string Shawarma::printBill()
{
	string str;
	str += "Shawarma: $" + to_string(getPrice()) + "\r\n";
	return str;
}

int Shawarma::priceOfBill()
{
	return getPrice();
}

void Shawarma::setLafa(bool isTrue)
{
	lafa = isTrue;
	if (lafa == true) {
		setPrice(getPrice() + 13);
		setCalories(getCalories() + 50);
	}
	else {
		setPrice(getPrice() - 13);
		setCalories(getCalories() -50);
	}
		
}

void Shawarma::setMix(bool isTrue)
{
	mix = isTrue;

	if (mix == true)
		setPrice(getPrice() + 5);
	else
		setPrice(getPrice() - 5);
}

void Shawarma::setSpicy(bool isTrue)
{
	spicy = isTrue;

	if (spicy == true) {
		setPrice(getPrice() + 1);
	}
	else
		setPrice(getPrice() - 1);

}

bool Shawarma::getLafa()
{
	return lafa;
}

bool Shawarma::getMix()
{
	return mix;
}

bool Shawarma::getSpicy()
{
	return spicy;
}
