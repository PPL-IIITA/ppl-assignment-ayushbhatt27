#ifndef Girl_Normal_H_
#define Girl_Normal_H_
#include "Girl.h"
#include <string>
/*
    Boy header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Girl_Normal: public Girl {
    public:
        Girl_Normal(std::string, int, int, int, int);
};
#endif
