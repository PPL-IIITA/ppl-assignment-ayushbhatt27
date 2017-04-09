#include "Girl_Desperate.h"
#include <string>

Girl_Desperate::Girl_Desperate(std::string Girl_Name, int Girl_Atr, int Girl_Budget, int Girl_Intel, int pre)
{
    this->Girl_Name = Girl_Name;
    this->Girl_Atr = Girl_Atr;
    this->Girl_Budget = Girl_Budget;
    this->Girl_Intel = Girl_Intel;
    this->Commit_Status = 0;
    this->pre = pre;
}

std::string Girl_Desperate::getname()
{
    return this->Girl_Name;
}

int Girl_Desperate::get_attract()
{
    return this->Girl_Atr;
}

int Girl_Desperate::get_budget()
{
    return this->Girl_Budget;
}

int Girl_Desperate::get_intel()
{
    return this->Girl_Intel;
}

int Girl_Desperate::get_commitstatus()
{
    return this->Commit_Status;
}

int Girl_Desperate::get_pre()
{
    return this->pre;
}

void Girl_Desperate::set_commitstatus()
{
    this->Commit_Status = 1;
}