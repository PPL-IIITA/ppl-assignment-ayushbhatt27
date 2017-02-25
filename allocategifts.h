#ifndef ALLOCATEGIFTS_H_
#define ALLOCATEGIFTS_H_
#include "Gifts.h"
#include "Couples.h"
#include <vector>

class allocategifts
{
    friend void gifts_dist(std::vector<Gifts> &mb, std::vector<Couples> &gb);

};
void gifts_dist(std::vector<Gifts> &mb, std::vector<Couples> &gb);

#endif

