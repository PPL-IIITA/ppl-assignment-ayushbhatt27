#include "allocategifts.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include "Gifts.h"
#include "Couples.h"
#include <vector>

void gifts_dist(std::vector<Gifts> &g, std::vector<Couples> &c)
{

    std::ifstream input;
    input.open("Gifts.csv", std::ios::in);
    while(!input.eof()) {
        std::string name;
        std::string ign;
        int price;
        int value;
        int type;
        int data1;
        int data2;
        input >> name >> ign >> price >> ign >> value >> ign >> type >> ign >> data1 >> ign >> data2;
        Gifts g1(name,price,value,type,data1,data2);
        //std::cout << g1.getname()<<"\n";
        g.push_back(g1);
    }
    //std::sort(g.begin(),g.end());
    input.close();
    input.open("Couples2.csv", std::ios::in);
    std::ofstream output;
    output.open("log.csv", std::ios::out);
    while(!input.eof()) {
        std::string name1;
        std::string ign;
        std::string name2;
        int happy;
        int ghappy = 0;
        int bhappy = 0;
        int comp = 0;
        int bud;
        int maint;
        int int1;
        int int2;
        int att1;
        int att2;
        int type;
        std::vector<Gifts>::iterator it;
        int sum = 0;
        int valuesum = 0;
        input >> name1 >> ign >> name2 >> ign >> bud >> ign >> maint >> ign >> int1 >> ign >> int2 >> ign >> att1 >> ign >> att2 >> ign >> type;
        //std::cout <<name1<<"\n";
        it = g.begin();
        int serial = 0;
        output << name1 << " , " << name2 << "\n";
        while(maint > 0) {
            sum += it->getprice();
            valuesum += (it->getvalue());
            maint = maint - it->getprice();
            output << serial<<" , "<<it->getname() <<"\n";
            it->setalloc();
            it++;
            serial++;
        }

        while(it->gettype() != 2 && it != g.end())
                it++;
        if(type == 1 && it != g.end()) {
            output << serial<<" , "<<it->getname() <<"\n";
            sum += it->getvalue() * 2;
            ghappy = log(sum);
            serial++;
        }
        if(type == 2) {
            sum = sum + valuesum;
            ghappy = sum;
        }
        if(type == 3)
            ghappy = pow(2.71,sum);

        bhappy = bud - sum;
        happy = bhappy + ghappy;
        comp = abs(bud - maint) + abs(att1 - att2) + abs(int1 - int2);
        Couples c1(name1,name2,happy,comp);
        c.push_back(c1);
        //std::cout << c[0].getnameb() <<"\n";
    }
    input.close();
    output.close();
}
