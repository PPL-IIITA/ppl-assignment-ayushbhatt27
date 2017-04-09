#ifndef BOY_H_
#define BOY_H_
#include <string>
/*
    Generous header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Boy {
    private:
        std::string Boy_Name;
        int Boy_Atr;
        int Boy_Budget;
        int Boy_Intel;
        int Req_Attract;
        int Commit_Status;
        double happiness;

    public:
        Boy(std::string, int, int, int, int);
        std::string getname();
        int get_attract();
        int get_budget();
        int get_intel();
        int get_reqattract();
        int get_commitstatus();
        int set_commitstatus();
        double get_happiness();
};

#endif
