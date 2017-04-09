#ifndef GEEKY_H_
#define GEEKY_H_
#include <string>
#include "Boy.h"
/*
    GEEKY header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Geeky:public Boy{
    public:
        Geeky(std::string, int, int, int, int);
};

#endif
