#pragma once
#include "Table.h"

class Drinks : public Table
{
public:
    Drinks(int price = 0, bool alcohol = false);

    void setPrice(int);
    void setAlcohol(bool);

    int getPrice();
    bool getAlcohol();

    virtual string printBill() = 0;
    virtual int priceOfBill() = 0;

private:
    int price;
    bool alcohol;

};