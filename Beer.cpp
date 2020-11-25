#include "pch.h"
#include "Beer.h"



Beer::Beer(bool kind, bool big, int price, int alcohol) : Drinks(price, true)
{
    this->big = big;
    this->kind = kind;

    if (big == true)
        setPrice(getPrice() + 2);

    if (kind == true)
        setPrice(getPrice() + 0);

    setBill(getBill() + getPrice());
}

string Beer::printBill()
{
    string str;
    str += "Beer: $" + to_string(getPrice()) + "\r\n";
    return str;
}

int Beer::priceOfBill()
{
    return getPrice();
}


void Beer::setBig(bool isTrue)
{
    big = isTrue;

    if (big == true) {
        setPrice(getPrice() + 2);
    }
    else
        setPrice(getPrice() - 2);
}

void Beer::setKind(bool isTrue)
{
    kind = isTrue;
}


bool Beer::getBig()
{
    return big;
}

bool Beer::getKind()
{
    return kind;
}