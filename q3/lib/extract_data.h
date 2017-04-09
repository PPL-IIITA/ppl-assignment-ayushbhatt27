#ifndef EXTRACT_DATA_H_
#define EXTRACT_DATA_H_

#include <iostream>
#include "Miser.h"
#include "Geeky.h"
#include "Generous.h"
#include "Girl_Desperate.h"
#include "Girl_Normal.h"
#include "Girl_Choosy.h"
#include <vector>

class extract_data
{
        friend void extract(std::vector<Miser> &mb, std::vector<Geeky> &gb, std::vector<Generous> &genb, std::vector<Girl_Choosy> &gc,
                             std::vector<Girl_Normal> &gn, std::vector<Girl_Desperate> &gd);

};
void extract(std::vector<Miser> &mb, std::vector<Geeky> &gb, std::vector<Generous> &genb, std::vector<Girl_Choosy> &gc,
                             std::vector<Girl_Normal> &gn, std::vector<Girl_Desperate> &gd);

#endif
