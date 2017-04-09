#ifndef GIRL_H_
#define GIRL_H_
#include <string>

class Girl{
    protected:
        std::string Girl_Name;
        int Girl_Atr;
        int Girl_Budget;
        int Girl_Intel;
        int Commit_Status;
        int pre;
        double happiness;
    public:
        Girl(std::string, int, int, int, int);
        std::string getname();
        int get_attract();
        int get_budget();
        int get_intel();
        int get_commitstatus();
        int get_pre();
        int set_commitstatus();
        double get_happiness();
};
#endif
