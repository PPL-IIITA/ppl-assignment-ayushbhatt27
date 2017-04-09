#ifndef MISER_H_
#define MISER_H_
#include "Boy.h"
#include <string>
/*
    Boy header file contains Boy class declaration which include :
    name,attractiveness,Budget,Intelligence,Minimum attractiveness required in a girl.

*/
class Miser:public Boy{
	public:
        Miser(std::string, int, int, int, int);

};
#endif
