#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>

/*
Gift types = {1=essential,2=luxury,3=utility}
*/

std::string to_string(int number){
    std::string number_string = "";
    char ones_char;
    int ones = 0;
    while(true){
        ones = number % 10;
        switch(ones){
            case 0: ones_char = '0'; break;
            case 1: ones_char = '1'; break;
            case 2: ones_char = '2'; break;
            case 3: ones_char = '3'; break;
            case 4: ones_char = '4'; break;
            case 5: ones_char = '5'; break;
            case 6: ones_char = '6'; break;
            case 7: ones_char = '7'; break;
            case 8: ones_char = '8'; break;
            case 9: ones_char = '9'; break;
            //default : ErrorHandling("Trouble converting number to string.");
        }
        number -= ones;
        number_string = ones_char + number_string;
        if(number == 0){
            break;
        }
        number = number/10;
    }
    return number_string;
}

int main()
{
	std::ofstream ofs;
	srand(time(NULL));
	// Inserting Gifts data
	ofs.open("Gifts.csv", std::ios::trunc);
	int i;
	for(i = 1; i < 200;i++)
	{
		std::string s = std::string("gift") + to_string(i);
		int price = rand() % 100 + 1;
		int value = rand() % 10 + 1;
		int type = rand() % 3+ 1;
		int d1, d2;
		if(type == 1)
		{
			d1 = -1;
			d2 = -1;
		}
		else
		{
			d1 = rand() % 10 + 1;
			d2 = rand() % 10 + 1;
		}
		ofs << s << " , " << price << " , " << value << " , " << type << " , " << d1 << " , " << d2 << "\n";
	}
	std::string s = std::string("gift") + to_string(i);
	int price = rand() % 101 + 1;
	int value = rand() % 10 + 1;
	int type = rand() + 1;
	int d1, d2;
	if(type == 1)
	{
		d1 = -1;
		d2 = -1;
	}
	else
	{
		d1 = rand() % 10 + 1;
		d2 = rand() % 10 + 1;
	}
	ofs << s << " , " << price << " , " << value << " , " << type << " , " << d1 << " , " << d2 << "\n";
	return 0;
}
