#include "Couples.h"
#include "Gifts.h"
#include "allocategifts.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
//*cmp1 to sort couple vectors in decreasing order of happiness.
bool cmp1(Couples &c1, Couples &c2)
{
    return c1.gethappy() > c2.gethappy();
}
//*cmp2 to sort couple vectors in increasing order of compatibility.
bool cmp2(Couples &c1, Couples &c2)
{
    return c1.getcomp() < c2.getcomp();
}
int main()
{
    std::vector<Gifts> g;
    std::vector<Couples> c;
    //*gifts_dist called to allocate gifts.
    gifts_dist(g,c);
    std::sort(c.begin(),c.end(),cmp1);
    int k;
    std::cout << "Enter value of k:\n";
    std::cin >> k;
    int temp = k;
    std::vector<Couples>::iterator it;
    it = c.begin();
    int vsize = c.size();
    if(vsize < k)
        k = vsize;
    std::cout <<k<<" MOST HAPPIEST COUPLES:\n";
    while(temp-- && it != c.end()) {
        std::cout <<it->getnameb() << " " << it->getnameg()<<"\n";
        it++;
    }
    std::sort(c.begin(),c.end(),cmp2);
    it = c.begin();
    temp = k;
    std::cout <<"\n";
    std::cout <<k<<" MOST COMPATIBLE COUPLES:\n";
    while(temp-- && it != c.end()) {
        std::cout <<it->getnameb() << " " << it->getnameg() <<"\n";
        it++;
    }
    std::cout << "\n\nGIFTS EXCHANGED BETWEEN COUPLES:\n\n";
    //*to print gift log file.
    std::ifstream input2;
    input2.open("log.csv", std::ios::in);
    int timestamp;
    while(input2 >> timestamp) {
        std::string name1;
        std::string name2;
        std::string gift;
        std::string ign;
        input2 >> ign >> name1 >> ign >> name2 >> ign >> gift;
        std::cout << timestamp <<" " << name1 << " " << name2 << " " << gift << "\n";
    }
    return 0;
}
