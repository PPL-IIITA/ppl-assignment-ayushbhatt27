#ifndef GEEKY
#define GEEKY
#include <string>
/*
    GEEKY header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Geeky {
    private:
        std::string Boy_Name;
        int Boy_Atr;
        int Boy_Budget;
        int Boy_Intel;
        int Req_Attract;
        int Commit_Status;
    public:
        Geeky(std::string, int, int, int, int);
        std::string getname();
        int get_attract();
        int get_budget();
        int get_intel();
        int get_reqattract();
        int get_commitstatus();
        int set_commitstatus();
};

#endif
