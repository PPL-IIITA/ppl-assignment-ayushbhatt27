#ifndef GIFTS_H_
#define GIFTS_H_
#include <string>

class Gifts
{
    private:
        std::string name;
        int price;
        int value;
        int data1;
        int data2;
        int type;
        int alloc;
    public:
        Gifts(std::string, int, int, int,int,int);
        std::string getname();
        int getprice();
        int getvalue();
        int gettype();
        int getdata1();
        int getdata2();
        int getalloc();
        int setalloc();
};
#endif
