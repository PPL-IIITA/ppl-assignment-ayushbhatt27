#include "Girl_Normal.h"
#include <string>
//*Constructor function Normal Girl.
Girl_Normal::Girl_Normal(std::string Girl_Name, int Girl_Atr, int Girl_Budget, int Girl_Intel, int pre)
{
    this->Girl_Name = Girl_Name;
    this->Girl_Atr = Girl_Atr;
    this->Girl_Budget = Girl_Budget;
    this->Girl_Intel = Girl_Intel;
    this->Commit_Status = 0;
    this->pre = pre;
}
//*returns Girl name.
std::string Girl_Normal::getname()
{
    return this->Girl_Name;
}
//*returns attractiveness.
int Girl_Normal::get_attract()
{
    return this->Girl_Atr;
}

int Girl_Normal::get_budget()
{
    return this->Girl_Budget;
}

int Girl_Normal::get_intel()
{
    return this->Girl_Intel;
}

int Girl_Normal::get_commitstatus()
{
    return this->Commit_Status;
}
int Girl_Normal::get_pre()
{
    return this->pre;
}

