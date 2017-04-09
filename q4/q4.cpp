#include "lib/Couples.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "lib/extract_data.h"
#include "lib/allocategifts.h"
#include "lib/Miser.h"
#include "lib/Geeky.h"
#include "lib/Generous.h"
#include "lib/Girl_Desperate.h"
#include "lib/Girl_Normal.h"
#include "lib/Girl_Choosy.h"

int main()
{
    std::vector<Gifts> g;
    std::vector<Couples> c;
    std::vector<Miser> mb;
    std::vector<Geeky> gb;
    std::vector<Generous> genb;
    std::vector<Girl_Choosy> gc;
    std::vector<Girl_Normal> gn;
    std::vector<Girl_Desperate> gd;
    gifts_dist(g,c);
    int k = 5;
    //std::cin >> k;
    extract(mb, gb, genb, gc, gn, gd, c, k);
    return 0;
}
