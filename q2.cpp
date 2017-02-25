#include "Couples.h"
#include "Gifts.h"
#include "allocategifts.h"
#include <algorithm>
#include <iostream>
#include <vector>
/*
Initial build
Cmp functions for sorting missing
*/
int main()
{
    std::vector<Gifts> g;
    std::vector<Couples> c;
    gifts_dist(g,c);
    //std::sort(c.begin(),c.end());
    int k;
    std::cout << "Enter value of k:\n";
    std::cin >> k;
    int temp = k;
    std::vector<Couples>::iterator it;
    it = c.begin();
    std::cout << "HAPPINESS:\n";
    while(temp--) {
        std::cout <<it->getnameb() << " " << it->getnameg() << "\n";
        it++;
    }
    //std::sort(c.begin(),c.end());
    it = c.begin();
    temp = k;
    std::cout << "COMPATIBLE:\n";
    while(temp--) {
        std::cout <<it->getnameb() << " " << it->getnameg() << "\n";
        it++;
    }

    return 0;
}
