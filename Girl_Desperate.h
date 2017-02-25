#ifndef Girl_Desperate_H_
#define Girl_Desperate_H_
#include <string>
/*
    Boy header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Girl_Desperate {
    private:
        std::string Girl_Name;
        int Girl_Atr;
        int Girl_Budget;
        int Girl_Intel;
        int Commit_Status;
        int pre;
    public:
        Girl_Desperate(std::string, int, int, int, int);
        std::string getname();
        int get_attract();
        int get_budget();
        int get_intel();
        int get_commitstatus();
        int get_pre();
};
#endif
