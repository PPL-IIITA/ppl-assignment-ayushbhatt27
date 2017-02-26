//*type of boy = {1=Miser, 2=Generous, 3=Geek} type of girl = {1=Choosy, 2=Normal, 3=desperate} prefernce type of girl = {1=attraciveness, 2=rich, 3=intelligent}.

//*generates random boys and girls and their respective details.

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>

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
	// Inserting Boys data
	ofs.open("Boys.csv", std::ios::trunc);
	int i;
	for(i = 1; i < 20; i++)
	{
		std::string s = std::string("b") + to_string(i);
		int attr = rand() % 101 + 1;
		int intel = rand() % 101 + 1;
		int budget = rand() % 900 + 100;
		int attr_req = rand() % 101 + 1;
		int type = rand() % 3 + 1;
		ofs << s << " , " << attr << " , " << intel << " , " << budget << " , " << attr_req << " , " << type << "\n";
	}
	{
		std::string s = std::string("b") + to_string(i);
		int attr = rand() % 101 + 1;
		int intel = rand() % 101 + 1;
		int budget = rand() % 900 + 100;
		int attr_req = rand() % 101 + 1;
		int type = rand() % 3 + 1;
		ofs << s << " , " << attr << " , " << intel << " , " << budget << " , " << attr_req << " , " << type ;
	}
	ofs.close();
	// Inserting girl data
	ofs.open("Girls.csv", std::ios::trunc);
	for(i = 1; i < 10; i++)
	{
		std::string s = std::string("g") + to_string(i);
		int attr = rand() % 101 + 1;
		int intel = rand() % 101 + 1;
		int budget = rand() % 900 + 100;
		int type = rand() % 3 + 1;
		int preference = rand() % 3 + 1;
		ofs << s << " , " << attr << " , " << intel << " , " << budget << " , " << type << " , " << preference <<"\n";
	}
	{
		std::string s = std::string("g") + to_string(i);
		int attr = rand() % 101 + 1;
		int intel = rand() % 101 + 1;
		int budget = rand() % 900 + 100;
		int type = rand() % 3 + 1;
		int preference = rand() % 3 + 1;
		ofs << s << " , " << attr << " , " << intel << " , " << budget << " , " << type << " , " << preference ;
	}

	return 0;
}
