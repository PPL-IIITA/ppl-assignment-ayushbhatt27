#include "allocategifts.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include "Gifts.h"
#include "Couples.h"
#include <vector>

bool cmp1(Gifts &g1, Gifts &g2)
{
    return g1.getprice() < g2.getprice();
}

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
        g.push_back(g1);
    }
    std::sort(g.begin(),g.end(),cmp1);
    input.close();
    input.open("Couples2.csv", std::ios::in);
    std::ofstream output;
    output.open("log.csv", std::ios::out);
    std::string name1;
    while(input >> name1) {
        std::string ign;
        std::string name2;
        double happy;
        double ghappy = 0;
        double bhappy = 0;
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
        int boytype;
        int valuesum = 0;
        input >> ign >> name2 >> ign >> bud >> ign >> maint >> ign >> int1 >> ign >> int2 >> ign >> att1 >> ign >> att2 >> ign >> type >> ign >> boytype;
        //std::cout <<name1<<"\n";
        it = g.begin();
        int serial = 1;
        int lux = 0;
        int gmain = maint;
        while(maint > 0) {
            sum += it->getprice();
            if(it->gettype() == 2)
                lux = lux + it->getprice();
            valuesum += (it->getvalue());
            maint = maint - it->getprice();
            output << serial <<" , "<< name1 << " , " << name2 <<" , "<<it->getname() <<"\n";
            it->setalloc();
            it++;
            serial++;
        }
        if(type == 1) {
            sum = sum + lux - gmain;
            ghappy = log(sum);
            serial++;
        }
        if(type == 2) {
            sum = sum + valuesum - gmain;
            ghappy = sum;
        }
        if(type == 3)
            ghappy = pow(2.71828,(sum - gmain));

        if(boytype == 1)
            bhappy = abs(bud - sum);
        if(boytype == 2)
            bhappy = ghappy;
        if(boytype == 3)
            bhappy = int2;

        happy = bhappy + ghappy;
        comp = abs(bud - maint) + abs(att1 - att2) + abs(int1 - int2);
        Couples c1(name1,name2,happy,comp);
        c.push_back(c1);
    }
    input.close();
    output.close();
}
