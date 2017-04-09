#include "Gifts.h"
#include <string>
Gifts::Gifts(std::string name, int price, int value, int type, int data1, int data2)
{
    this->name = name;
    this->price = price;
    this->value = value;
    this->data1 = data1;
    this->data2 = data2;
    this->type = type;
    this->alloc = 0;
}

std::string Gifts::getname()
{
    return this->name;
}

int Gifts::getprice()
{
    return this->price;
}

int Gifts::getvalue()
{
    return this->value;
}

int Gifts::gettype()
{
    return this->type;
}

int Gifts::getdata1()
{
    return this->data1;
}

int Gifts::getdata2()
{
    return this->data2;
}

int Gifts::getalloc()
{
    return this->alloc;
}

int Gifts::setalloc()
{
    this->alloc = 1;
}
