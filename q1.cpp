#include <iostream>
#include "Miser.h"
#include "Geeky.h"
#include "Generous.h"
#include "Girl_Desperate.h"
#include "Girl_Normal.h"
#include "Girl_Choosy.h"
#include <vector>
#include "extract_data.h"

int main()
{

    std::vector<Miser> mb;
    std::vector<Geeky> gb;
    std::vector<Generous> genb;
    std::vector<Girl_Choosy> gc;
    std::vector<Girl_Normal> gn;
    std::vector<Girl_Desperate> gd;
    extract(mb, gb, genb, gc, gn, gd);
    return 0;
}
