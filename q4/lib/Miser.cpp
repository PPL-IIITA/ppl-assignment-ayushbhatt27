#include "Miser.h"
#include <string>
//*Constructor function Miser.
Miser::Miser(std::string Boy_Name, int Boy_Atr, int Boy_Budget, int Boy_Intel, int Req_Attract)
{
    this->Boy_Name = Boy_Name;
    this->Boy_Atr = Boy_Atr;
    this->Boy_Budget = Boy_Budget;
    this->Boy_Intel = Boy_Intel;
    this->Req_Attract = Req_Attract;
    this->Commit_Status = 0;
}
//*return name.
std::string Miser::getname()
{
    return this->Boy_Name;
}
//*return attractiveness.
int Miser::get_attract()
{
    return this->Boy_Atr;
}
//*return budget.
int Miser::get_budget()
{
    return this->Boy_Budget;
}
//*returns intelligence.
int Miser::get_intel()
{
    return this->Boy_Intel;
}
//*returns required attractiveness.
int Miser::get_reqattract()
{
    return this->Req_Attract;
}
//*returns Commitment status.
int Miser::get_commitstatus()
{
    return this->Commit_Status;
}
//*Set Commitment status to 1.
int Miser:: set_commitstatus()
{
    this->Commit_Status = 1;
}

