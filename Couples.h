#ifndef COUPLES_H_
#define COUPLES_H_
#include <string>

class Couples{
    private:
        std::string nameb;
        std::string nameg;
        int happy;
        int comp;
    public:
        Couples(std::string, std::string, int, int);
        std::string getnameb();
        std::string getnameg();
        int gethappy();
        int getcomp();
};

#endif
