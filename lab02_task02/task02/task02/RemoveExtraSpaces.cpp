#include <iostream>
#include <string>

using namespace std;

string RemoveExtraSpaces(string const& str)
{
	bool firstSpacesDeleted = false;
	bool spaceWas = false;
	string resultStr = "";

	for (unsigned i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			if (firstSpacesDeleted && !spaceWas) 
			{
				spaceWas = true;
			}
		}
		else
		{
			firstSpacesDeleted = true;
			if (spaceWas)
			{
				resultStr += ' ';
				spaceWas = false;
			}
			resultStr += str[i];
		}
	}
	
	return resultStr;
}

int main()
{
	string str;
	getline(cin, str);
	cout << RemoveExtraSpaces(str);
}