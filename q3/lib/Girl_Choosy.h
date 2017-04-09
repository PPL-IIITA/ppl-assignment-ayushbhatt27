#ifndef GIRL_CHOOSY_H_
#define GIRL_CHOOSY_H_
#include "Girl.h"
#include <string>
/*
    Boy header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Girl_Choosy : public Girl{
    public:
        Girl_Choosy(std::string, int, int, int, int);
       
};
#endif
