#include "extract_data.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
void extract(std::vector<Miser> &mb, std::vector<Geeky> &gb, std::vector<Generous> &genb, std::vector<Girl_Choosy> &gc,
                             std::vector<Girl_Normal> &gn, std::vector<Girl_Desperate> &gd)
{
    //std::cout << "hello\n";
    std::ifstream input;
    input.open("Boys.csv", std::ios::in);
    //std::cout<<"hello\n";
    if(!input)
    {
        std::cout << "Not file";
        exit(0);
    }
    while(!input.eof()) {
        std::string name;
        std::string ign;
        int attract;
        int intelli;
        int budget;
        int min_req;
        int type;
        input >> name >> ign >> attract >> ign >> intelli >> ign >> budget >> ign >> min_req >> ign >> type;
        //std::cout<<name<<std::endl;
        if(type == 1) {
            Miser m (name, attract, budget, intelli, min_req);
            mb.push_back(m);
        }
        else if (type == 3) {
            Geeky g (name, attract,budget,intelli, min_req);
            gb.push_back(g);
        }
        else {
            Generous gen (name, attract, budget, intelli, min_req);
            genb.push_back(gen);
        }
    }
    //std::cout<<"hello\n";
    input.close();
    input.open("Girls.csv", std::ios::in);
    //std::cout<<"hello\n";
    while(!input.eof()) {
        std::string name;
        std::string ign;
        int attract;
        int intelli;
        int budget;
        int type;
        int pre;
        input >> name >> ign >> attract >> ign >> intelli >> ign >> budget >> ign >> type >> ign >> pre;
        if(type == 1) {
            Girl_Choosy m (name, attract, budget, intelli, pre);
            gc.push_back(m);
        }
        else if (type == 2) {
            Girl_Normal g (name, attract,budget,intelli, pre);
            gn.push_back(g);
        }
        else {
            Girl_Desperate gen (name, attract,budget, intelli, pre);
            gd.push_back(gen);
        }
    }
    input.close();
   input.open("Girls.csv", std::ios::in);

//std::cout<<"hello\n";
    std::ofstream output;
    output.open("Couples.csv", std::ios::trunc);
    while(!input.eof()) {
        std::string name;
        std::string ign;
        int attract;
        int intelli;
        int budget;
        int type;
        int pre;
        input >> name >> ign >> attract >> ign >> intelli >> ign >> budget >> ign >> type >> ign >> pre;

        std::vector<Miser>::iterator it1;
        std::vector<Geeky>::iterator it2;
        std::vector<Generous>::iterator it3;
        std::vector<Miser>::iterator temp1;
        std::vector<Geeky>::iterator temp2;
        std::vector<Generous>::iterator temp3;
        int ma = 0;
        int mbud = 0;
        int mint = 0;
        int t = 0;
        //std::cout<<"hello\n";
        for(it1 = mb.begin(); it1 != mb.end(); it1++) {
            if(it1->get_budget() > budget && it1->get_commitstatus() == 0) {
                if(pre == 2 && it1->get_budget() > mbud) {
                        mbud = it1->get_budget();
                        temp1 = it1;
                        t = 1;
                }
                else if(pre == 1 && it1->get_attract() > ma) {
                    ma = it1->get_attract();
                    temp1 = it1;
                    t = 1;
                }
                else if(pre == 3 && it1->get_intel() > mint) {
                    mint = it1->get_intel();
                    temp1 = it1;
                    t = 1;
                }
            }
        }
        //std::cout<<"hello\n";
        for(it2 = gb.begin(); it2 != gb.end(); it2++) {
             if(it2->get_budget() > budget && it2->get_commitstatus() == 0) {
                if(pre == 2 && it2->get_budget() > mbud) {
                        mbud = it2->get_budget();
                        temp2 = it2;
                        t = 3;
                }
                else if(pre == 1 && it2->get_attract() > ma) {
                    ma = it2->get_attract();
                    temp2 = it2;
                    t = 3;
                }
                else if(pre == 3 && it2->get_intel() > mint) {
                    mint = it2->get_intel();
                    temp2 = it2;
                    t = 3;
                }
            }
        }
        //std::cout<<t <<std::endl;
        for(it3 = genb.begin(); it3 != genb.end(); it3++) {
             if(it3->get_budget() > budget && it3->get_commitstatus() == 0) {
                if(pre == 2 && it3->get_budget() > mbud) {
                        mbud = it3->get_budget();
                        temp3 = it3;
                        t = 2;
                }
                else if(pre == 1 && it3->get_attract() > ma) {
                    ma = it3->get_attract();
                    temp3 = it3;
                    t = 2;
                }
                else if(pre == 3 && it3->get_intel() > mint) {
                    mint = it3->get_intel();
                    temp3 = it3;
                    t = 2;
                }
            }
        }
            if(t == 1) {
                temp1->set_commitstatus();
                std::cout << name <<" " << temp1->getname() << std::endl;
                output << name << "," <<temp1->getname()<<"\n";
            }
            else if(t == 2) {
                temp3->set_commitstatus();
                std::cout << name <<" " << temp3->getname() << std::endl;
                output << name << "," <<temp3->getname()<<"\n";
            }
            else if(t == 3) {
                temp2->set_commitstatus();
                std::cout << name <<" " << temp2->getname() << std::endl;
                output << name << "," <<temp2->getname()<<"\n";
            }
    }
    output.close();
}
