#include "Couples.h"

Couples::Couples(std::string nameb,std::string nameg, int happy, int comp)
{
    this->nameb = nameb;
    this->nameg = nameg;
    this->happy = happy;
    this->comp = comp;
}

std::string Couples::getnameb()
{
    return this->nameb;
}
std::string Couples::getnameg()
{
    return this->nameg;
}
double Couples::gethappy()
{
    return this->happy;
}
int Couples::getcomp()
{
    return this->comp;
}
