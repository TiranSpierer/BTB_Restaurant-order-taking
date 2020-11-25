#include "pch.h"
#include "Cola.h"


Cola::Cola(bool big, bool zero, int price, bool alcohol) : Drinks(price, false)
{
    this->big = big;
    this->zero = zero;

    if (big == true)
        setPrice(getPrice() + 2);

    if (zero == true)
        setPrice(getPrice() + 2);

    setBill(getBill() + getPrice());
}

string Cola::printBill()
{
    string str;
    str += "Cola: $" + to_string(getPrice()) + "\r\n";
    return str;
}

int Cola::priceOfBill()
{
    return getPrice();
}


void Cola::setBig(bool isTrue)
{
    big = isTrue;

    if (big == true) {
        setPrice(getPrice() + 2);
    }
    else
        setPrice(getPrice() - 2);
}

void Cola::setZero(bool isTrue)
{
    zero = isTrue;

    if (zero == true) {
        setPrice(getPrice() + 2);
    }
    else
        setPrice(getPrice() - 2);
}


bool Cola::getBig()
{
    return big;
}

bool Cola::getZero()
{
    return zero;
}
