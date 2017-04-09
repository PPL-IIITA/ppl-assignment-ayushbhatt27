#ifndef Girl_Desperate_H_
#define Girl_Desperate_H_
#include "Girl.h"
#include <string>
/*
    Boy header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Girl_Desperate:public Girl{
    public:
        Girl_Desperate(std::string, int, int, int, int);
};
#endif
