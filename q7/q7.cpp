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
#include <bits/stdc++.h>

bool cmp(std::pair<std::string, std::string>  &c1, std::pair<std::string, std::string>  &c2) {return c1.first < c2.first;}

std::string binary_search(std::vector<std::pair<std::string, std::string> > vec, std::string x)
{
  int l = 0; 
  int h = vec.size();
  while(l <= h) {
    int mid = (l+h)/2;
    if((vec[mid]).first == x) {
      return vec[mid].second;
    }
    else if((vec[mid]).first < x) {
      l = mid +1;
    }
    else h = mid -1;
  }
  return "x";
}


void f1(std::vector<Couples> c, std::string x) 
{
    std::cout <<"Implementation: 1 (simple array)" <<"\n";
    std::vector<Couples>::iterator it;
    int flag = 0;
    for(it = c.begin(); it != c.end(); it++) {
        //std::cout << it -> getnameg() << it -> getnameg() << "\n";
      if(it -> getnameg() == x) {
        std::cout << x <<" -> "<< it -> getnameb() << "\n";
        flag =1;
        break;
      }
    }
    if(flag == 0)
      std::cout <<"No Girlfriend of " << x << "\n";
}

void f2(std::vector<std::pair<std::string, std::string> > vec, std::string x)
{ 
    std::cout <<"Implementation: 2 (Binary Search)" <<"\n";
    std::sort(vec.begin(), vec.end(),cmp);
    std::string ans = binary_search(vec, x);
    if(ans == "x")
        std::cout <<"No Girlfriend of " << x << "\n";
    else 
        std::cout << x <<" -> "<< ans << "\n";
}

void f3(std::vector<std::pair<std::string, std::string> > vec, std::string x)
{ 
    std::cout <<"Implementation: 3 (Hashing)" <<"\n";
    std::map<std::string,std::string> hash;
    std::vector<std::pair<std::string, std::string> >::iterator it2;
    for(it2 = vec.begin(); it2 != vec.end(); it2++ ) {
        hash[it2->first] = it2->second;
    }
    if(hash.find(x) != hash.end()) 
        std::cout << x <<" -> "<< hash[x] << "\n";
    else
        std::cout <<"No Girlfriend of " << x << "\n";
} 

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
    std::vector<Couples>::iterator it;
    //std::cout <<"enter name of boy (example b4)";
   	std::string x = "b4";
    std::string y = "b100";
    std::string z = "b14";
   	//std::cin >> x;
    f1(c, x);
    f1(c, y);
    f1(c, z);
    std::vector<std::pair<std::string, std::string> > vec;
    for(it = c.begin(); it != c.end(); it++) {
      vec.push_back(make_pair(it->getnameg(),it->getnameb()));
    }
    f2(vec, x);
    f3(vec, x);
    f2(vec, y);
    f3(vec, y);
    f2(vec, z);
    f3(vec, z);
    return 0;
}
