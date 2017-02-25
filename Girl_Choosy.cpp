#include "Girl_Choosy.h"
#include <string>

Girl_Choosy::Girl_Choosy(std::string Girl_Name, int Girl_Atr, int Girl_Budget, int Girl_Intel, int pre)
{
    this->Girl_Name = Girl_Name;
    this->Girl_Atr = Girl_Atr;
    this->Girl_Budget = Girl_Budget;
    this->Girl_Intel = Girl_Intel;
    this->Commit_Status = 0;
    this->pre = pre;
}

std::string Girl_Choosy::getname()
{
    return this->Girl_Name;
}

int Girl_Choosy::get_attract()
{
    return this->Girl_Atr;
}

int Girl_Choosy::get_budget()
{
    return this->Girl_Budget;
}

int Girl_Choosy::get_intel()
{
    return this->Girl_Intel;
}

int Girl_Choosy::get_commitstatus()
{
    return this->Commit_Status;
}

int Girl_Choosy::get_pre()
{
    return this->pre;
}

