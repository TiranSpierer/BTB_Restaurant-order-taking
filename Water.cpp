#include "pch.h"
#include "Water.h"

Water::Water(bool big, bool spark, int price, int alcohol) : Drinks(price, false)
{
    this->big = big;
    this->spark = spark;

    if (big == true)
        setPrice(getPrice() + 2);

    if (spark == true)
        setPrice(getPrice() + 2);

    setBill(getBill() + getPrice());
}

string Water::printBill()
{
    string str;
    str += "Water: $" + to_string(getPrice()) + "\r\n";
    return str;
}

int Water::priceOfBill()
{
    return getPrice();
}

void Water::setBig(bool isTrue)
{
    this->big = isTrue;

    if (big == true)
        setPrice(getPrice() + 2);
    else
        setPrice(getPrice() - 2);
}

void Water::setSpark(bool isTrue)
{
    this->spark = isTrue;

    if (spark == true)
        setPrice(getPrice() + 2);
    else
        setPrice(getPrice() - 2);
}

bool Water::getBig()
{
    return big;
}

bool Water::getSpark()
{
    return spark;
}

