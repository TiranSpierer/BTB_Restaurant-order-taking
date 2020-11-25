#pragma once
#include "Drinks.h"

class Water : public Drinks
{
public:
    Water(bool bigSize = false, bool spark = false, int price = 7, int alcohol = false);

    virtual string printBill();
    virtual int priceOfBill();

    void setBig(bool isTrue);
    void setSpark(bool isTrue);

    bool getBig();
    bool getSpark();


private:
    bool big;   // + $2
    bool spark;  // + $2
};

