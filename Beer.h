#pragma once
#include "Drinks.h"

class Beer : public Drinks
{
public:
    Beer(bool kind = false, bool big = false, int price = 22, int alcohol = true);

    virtual string printBill();
    virtual int priceOfBill();

    void setKind(bool isTrue);
    void setBig(bool isTrue);

    bool getKind();
    bool getBig();


private:
    bool kind;  // + $0
    bool big;  // + $2
};