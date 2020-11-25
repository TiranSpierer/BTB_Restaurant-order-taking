#pragma once
#include "Drinks.h"

class Cola : public Drinks
{
public:
    Cola(bool bigSize = false, bool zero = false, int price = 10, bool alcohol = false);

    virtual string printBill();
    virtual int priceOfBill();

    void setBig(bool isTrue);
    void setZero(bool isTrue);

    bool getBig();
    bool getZero();


private:
    bool big;   // + $2
    bool zero;  // + $2
};

