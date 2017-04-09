#include "Boy.h"
#include <string>



Boy::Boy(std::string Boy_Name, int Boy_Atr, int Boy_Budget, int Boy_Intel, int Req_Attract)
{
    this->Boy_Name = Boy_Name;
    this->Boy_Atr = Boy_Atr;
    this->Boy_Budget = Boy_Budget;
    this->Boy_Intel = Boy_Intel;
    this->Req_Attract = Req_Attract;
    this->Commit_Status = 0;
    this->happiness = 0.0;
}

std::string Boy::getname()
{
    return this->Boy_Name;
}

int Boy::get_attract()
{
    return this->Boy_Atr;
}

int Boy::get_budget()
{
    return this->Boy_Budget;
}

int Boy::get_intel()
{
    return this->Boy_Intel;
}

int Boy::get_reqattract()
{
    return this->Req_Attract;
}

int Boy::get_commitstatus()
{
    return this->Commit_Status;
}
int Boy::set_commitstatus()
{
    this->Commit_Status = 1;
}
double Boy::get_happiness()
{
    return this -> happiness;
}
