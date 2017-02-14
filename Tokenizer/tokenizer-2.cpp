#include "tokenizer.h"
#include <iostream>
#include <string>
#include <list>


 void tokenizer(string input, string delimiter, list<string> &tokenList)
{
	std::list<string>::iterator iter1;


	int len = input.length();
	int len2 = delimiter.length();
	string temp1;


	int hold = 0;
	int pos = 0;
	pos = input.find(delimiter, pos);

	for (int j = 0; j < pos; j++)
	{
		temp1 += input[j];
	}
	tokenList.push_back(temp1);
	
	while (pos < len)
	{
		hold = pos + len2;
		pos = input.find(delimiter, pos + len2);
		if (pos != string::npos)
		{
			string temp;
			for (int i = hold; i < pos; i++)
			{
				temp += input[i];
			}
			//hold = pos + len2 ;
			tokenList.push_back(temp);
		}


		if (pos == string::npos)
		{
			string temp2;
			if (hold != len)
			{
				for (int i = hold; i < len; i++)
				{
					temp2 += input[i];
				}
			}
			tokenList.push_back(temp2);
		}


		if (pos == string::npos)
			break;
	}
		
		
	//}

	//cout << tokenList.back();
	return;
}



/*tokenizer::~tokenizer()
{
}*/



