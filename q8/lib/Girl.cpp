#include "Girl.h"
#include <string>

Girl::Girl(std::string Girl_Name, int Girl_Atr, int Girl_Budget, int Girl_Intel, int pre)
{
    this->Girl_Name = Girl_Name;
    this->Girl_Atr = Girl_Atr;
    this->Girl_Budget = Girl_Budget;
    this->Girl_Intel = Girl_Intel;
    this->Commit_Status = 0;
    this->pre = pre;
}

std::string Girl::getname()
{
    return this->Girl_Name;
}

int Girl::get_attract()
{
    return this->Girl_Atr;
}

int Girl::get_budget()
{
    return this->Girl_Budget;
}

int Girl::get_intel()
{
    return this->Girl_Intel;
}

int Girl::get_commitstatus()
{
    return this->Commit_Status;
}

int Girl::get_pre()
{
    return this->pre;
}

double Girl::get_happiness()
{
    return this->happiness;
}

int Girl::set_commitstatus()
{
    this->Commit_Status = 1;
}