#include "pch.h"
#include "Falafel.h"

Falafel::Falafel(bool humus, bool tahini, bool salad, int price, int calories, bool kosher) : Food(price, calories, true)
{
	this->humus = humus;
	this->tahini = tahini;
	this->salad = salad;

	if (humus == true)
		setPrice(getPrice() + 1);

	if (tahini == true)
		setPrice(getPrice() + 1);

	if (salad == true)
		setPrice(getPrice() + 3);

	setBill(getBill() + getPrice());

}

string Falafel::printBill()
{
	string str;
	str += "Falafel: $" + to_string(getPrice()) + "\r\n";
	return str;
}

int Falafel::priceOfBill()
{
	return getPrice();
}

void Falafel::setHumus(bool isTrue)
{
	this->humus = isTrue;
	if (humus == true)
		setPrice(getPrice() + 1);
	else
		setPrice(getPrice() - 1);
}

void Falafel::setTahini(bool isTrue)
{
	this->tahini = isTrue;
	if (tahini == true)
		setPrice(getPrice() + 1);
	else
		setPrice(getPrice() - 1);
}

void Falafel::setSalad(bool isTrue)
{
	this->salad = isTrue;
	if (salad == true)
		setPrice(getPrice() + 3);
	else
		setPrice(getPrice() - 3);
}

bool Falafel::getHumus()
{
	return humus;
}

bool Falafel::getTahini()
{
	return tahini;
}

bool Falafel::getSalad()
{
	return salad;
}

