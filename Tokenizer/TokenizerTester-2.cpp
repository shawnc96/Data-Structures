#include <iostream>
#include <string>
#include <list>
#include "tokenizer.h"

int main()
{
	std::cout << "This is tokenizer projext\n"  ;

	std::string in;
	std::string delim;
	std::list<string> tList;
	std::list<string>::iterator iter;
	std::cout << "Enter an input string: ";
	std::getline(std::cin, in);
	//std::cout << "\n" << input;

	std::cout << "\nEnter the delimiter string:";
	std::getline(std::cin, delim);

	tokenizer(in, delim, tList);


	for (iter = tList.begin(); iter != tList.end(); ++iter)
	{
		cout << ">> ";
		cout << *iter << "\n";
		
	}
	
	
	/*while (!tList.empty())
	{
		
		cout <<"\n" <<tList.front();
		tList.pop_front();
		

	}*/


	cin.get();
	return 0;
}
