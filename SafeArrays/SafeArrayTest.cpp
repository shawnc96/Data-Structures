#include <iostream>
#include<list>
#include<string>
#include"SafeArrays.h"


int main()
{

	std::cout << "This is SafeArrays Project!\n";

	
	//Initialization using default contructor
	SafeArray<int>  Array(5);
	SafeArray<int> yourArray(-1, 13);

	Array[3] = 3;

	std::cout << "myArray has length: " << Array.length() << "\n";
	std::cout << "yourArray has length: " << yourArray.length() <<"\n";

	//Initialization by copy ctr
	SafeArray<int> Array2(Array);
	SafeArray<int> Array3 = Array;
	
	//assignment by assignemnt operator
	Array2 = Array;
	

	std::cout << "myArray2 has length: " << Array2.length() <<"\n";
	std::cout << "myArray 2 is: " << Array2[3];
	
	

	std::cin.get();
	return 0;
}
