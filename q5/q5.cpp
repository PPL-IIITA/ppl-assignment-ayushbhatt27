#include <iostream>
#include "lib/Miser.h"
#include "lib/Geeky.h"
#include "lib/Generous.h"
#include "lib/Girl_Desperate.h"
#include "lib/Girl_Normal.h"
#include "lib/Girl_Choosy.h"
#include <vector>
#include "lib/extract_data.h"

//*prints Couples formed using boys and girls csv files.

int main()
{
    //std::cout <<"hello";
    std::vector<Miser> mb;
    std::vector<Geeky> gb;
    std::vector<Generous> genb;
    std::vector<Girl_Choosy> gc;
    std::vector<Girl_Normal> gn;
    std::vector<Girl_Desperate> gd;
    extract(mb, gb, genb, gc, gn, gd);
    return 0;
}
