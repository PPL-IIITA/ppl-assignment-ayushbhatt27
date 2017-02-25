#include "Generous.h"
#include <string>

Generous::Generous(std::string Boy_Name, int Boy_Atr, int Boy_Budget, int Boy_Intel, int Req_Attract)
{
    this->Boy_Name = Boy_Name;
    this->Boy_Atr = Boy_Atr;
    this->Boy_Budget = Boy_Budget;
    this->Boy_Intel = Boy_Intel;
    this->Req_Attract = Req_Attract;
    this->Commit_Status = 0;
}

std::string Generous::getname()
{
    return this->Boy_Name;
}

int Generous::get_attract()
{
    return this->Boy_Atr;
}

int Generous::get_budget()
{
    return this->Boy_Budget;
}

int Generous::get_intel()
{
    return this->Boy_Intel;
}

int Generous::get_reqattract()
{
    return this->Req_Attract;
}

int Generous::get_commitstatus()
{
    return this->Commit_Status;
}
int Generous:: set_commitstatus()
{
    this->Commit_Status = 1;
}
