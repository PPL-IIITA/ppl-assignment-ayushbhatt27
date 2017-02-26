#ifndef COUPLES_H_
#define COUPLES_H_
#include <string>

class Couples{
    private:
        std::string nameb;
        std::string nameg;
        double happy;
        int comp;
    public:
        Couples(std::string, std::string, int, int);
        std::string getnameb();
        std::string getnameg();
        double gethappy();
        int getcomp();
};

#endif
