#include "extract_data.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
//*extract function scans boys csv file and fills boy objects similarly it scans girls csv files and fills girl objects then it scans girl files and try to find a boyfriend according to constraints.
bool cmp1(Miser &c1 , Miser &c2){
    return c1.get_attract() < c2.get_attract();
}
bool cmp2(Generous &c1 , Generous &c2){
    return c1.get_attract() < c2.get_attract();
}
bool cmp3(Geeky &c1 , Geeky &c2){
    return c1.get_attract() < c2.get_attract();
}
bool cmp4(Girl_Choosy &c1 , Girl_Choosy &c2){
    return c1.get_budget() < c2.get_budget();
}
bool cmp5(Girl_Normal &c1 , Girl_Normal &c2){
    return c1.get_budget() < c2.get_budget();
}
bool cmp6(Girl_Desperate &c1 ,Girl_Desperate  &c2){
    return c1.get_budget() < c2.get_budget();
}

void extract(std::vector<Miser> &mb, std::vector<Geeky> &gb, std::vector<Generous> &genb, std::vector<Girl_Choosy> &gc,
                             std::vector<Girl_Normal> &gn, std::vector<Girl_Desperate> &gd)
{
    //std::cout << "hello\n";
    std::ifstream input;
    input.open("./files/Boys.csv", std::ios::in);
    //std::cout<<"hello\n";
    if(!input)
    {
        std::cout << "Not file";
        exit(0);
    }
    std::ofstream out;
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
    std::sort(mb.begin(),mb.end(),cmp1);
    std::sort(genb.begin(),genb.end(),cmp2);
    std::sort(gb.begin(),gb.end(),cmp3);
    //std::cout<<"hello\n";
    input.close();
    input.open("./files/Girls.csv", std::ios::in);
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
    std::sort(gc.begin(),gc.end(),cmp4);
    std::sort(gn.begin(),gn.end(),cmp5);
    std::sort(gd.begin(),gd.end(),cmp6);
    
    input.close();
   	input.open("./files/Girls.csv", std::ios::in);
	//std::cout<<"hello\n";
    std::ofstream output;
    output.open("./files/Couples.csv", std::ios::trunc);
    //* couples2 store extra details about couples.
    out.open("./files/Couples2.csv", std::ios::trunc);
   	std::ifstream input2;
    input2.open("./files/Boys.csv", std::ios::in);
    int b_size = mb.size() + gb.size() + genb.size();
    for(int i = 0; i <b_size;i++)	{
     	if(i%2 == 0){   
    //* scans girls csv file and make couples.
    		if(input.eof())
    			break; 
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
	            if(it1->get_budget() > budget && it1->get_commitstatus() == 0 && it1->get_reqattract() < attract) {
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
	             if(it2->get_budget() > budget && it2->get_commitstatus() == 0 && it2->get_reqattract() < attract) {
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
	             if(it3->get_budget() > budget && it3->get_commitstatus() == 0 && it3->get_reqattract() < attract) {
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
	                output << name << " , " <<temp1->getname()<<"\n";
	                out << name << " , " << temp1->getname()<<" , "<<temp1->get_budget()<<" , "<<budget<<" , "<<temp1->get_intel()<<" , "<<intelli<<" , "<<temp1->get_attract()<<" , "<<attract<<" , "<<type<<" , "<<t<<"\n";
	            }
	            else if(t == 2) {
	                temp3->set_commitstatus();
	                std::cout << name <<" " << temp3->getname() << std::endl;
	                output << name << " , " <<temp3->getname()<<"\n";
	                out << name << " , " << temp3->getname()<<" , "<<temp3->get_budget()<<" , "<<budget<<" , "<<temp3->get_intel()<<" , "<<intelli<<" , "<<temp3->get_attract()<<" , "<<attract<<" , "<<type<<" , "<<t<<"\n";;
	            }
	            else if(t == 3) {
	                temp2->set_commitstatus();
	                std::cout << name <<" " << temp2->getname() << std::endl;
	                output << name << " , " <<temp2->getname()<<"\n";
	                out << name << " , " << temp2->getname()<<" , "<<temp2->get_budget()<<" , "<<budget<<" , "<<temp2->get_intel()<<" , "<<intelli<<" , "<<temp2->get_attract()<<" , "<<attract<<" , "<<type<<" , "<<t<<"\n";;
	            }
	    }
	    else {
	    	std::string name;
        	std::string ign;
        	int attract;
        	int intelli;
        	int budget;
        	int min_req;
        	int type;
        	input2 >> name >> ign >> attract >> ign >> intelli >> ign >> budget >> ign >> min_req >> ign >> type;
        //std::cout<<name<<std::endl;

        	std::vector<Girl_Choosy>::iterator it1,temp1;
        	std::vector<Girl_Normal>::iterator it2,temp2;
        	std::vector<Girl_Desperate>::iterator it3,temp3;
        //cout<<"AA\n";
       	 	int max_att = INT_MIN;
        	int t = 0;
        	for(it1 = gc.begin();it1!=gc.end();it1++){
           		 if(it1->get_commitstatus() == 0 && it1->get_budget() > budget){
               		 temp1 = it1;
                	if(temp1->get_attract() > max_att){
                    	max_att = temp1->get_attract();
                    	t = 1;
                	}
                	break;
            	}

       		 }
        //cout<<"bb\n";
        	for(it2 = gn.begin();it2!=gn.end();it2++){
            	if(it2->get_commitstatus() == 0 && it2->get_budget() > budget){
                	temp2 = it2;
                	if(temp2->get_attract() > max_att){
                    	max_att = temp2->get_attract();
                    	t = 2;
               		 }
				 break;
            	}
			 }
        //cout<<"cc\n";
        	for(it3 = gd.begin();it3!=gd.end();it3++){
            	if(it3->get_commitstatus() == 0 && it3->get_budget() > budget){
                	temp3 = it3;
                	if(temp3->get_attract() > max_att){
                   		 max_att = temp3->get_attract();
                    	t = 3;
               		 }
				break;
            	}
			}

        //std::cout<<"dd\n";
 
        //std::cout <<t<<"1\n";
        //cout <<temp1->get_attractiveness()<<endl;
            if(t == 1){
                std::cout <<name<<" "<< temp1->getname()<<std::endl;
                temp1->set_commitstatus();
			}
        
        
                //std::cout <<t<<"2\n" ;
            if(t == 2){
                std::cout << name<<" "<<temp2->getname()<<std::endl;
                temp2->set_commitstatus();
			}
        
        
                //std::cout <<t<<"3\n";
            if(t == 3){
                std::cout <<name <<" "<<temp3->getname()<<std::endl;
                temp3->set_commitstatus();
			}
        
	    }
	}
    output.close();
}
