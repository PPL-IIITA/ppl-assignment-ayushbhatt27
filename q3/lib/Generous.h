#ifndef GENEROUS_H_ 
#define GENEROUS_H_
#include <string>
#include "Boy.h"
/*
    Generous header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Generous:public Boy{
    public:
        Generous(std::string, int, int, int, int);
};

#endif
