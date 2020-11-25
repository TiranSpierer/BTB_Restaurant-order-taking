#include "pch.h"
#include "Table.h"

int Table::bill = 0;

Table::~Table()
{

}

void Table::setBill(int bill)
{
	this->bill = bill;
}

int Table::getBill()
{
	return bill;
}
