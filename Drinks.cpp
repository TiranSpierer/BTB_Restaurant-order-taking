#include "pch.h"
#include "Drinks.h"

Drinks::Drinks(int price, bool alcohol) : price(price), alcohol(alcohol)
{}

void Drinks::setPrice(int price)
{
    this->price = price;
}

void Drinks::setAlcohol(bool alcohol)
{
    this->alcohol = alcohol;
}

int Drinks::getPrice()
{
    return price;
}

bool Drinks::getAlcohol()
{
    return alcohol;
}
