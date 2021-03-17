#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool ParseNumbersToVector(istream& input, vector<float>& inputVector)
{
	string inputStr;
	float value;

	while (input >> inputStr)
	{
		std::istringstream strm(inputStr);
		float number;
		if (strm >> number)
		{
			inputVector.push_back(number);
		}
		else
		{
			return false;
		}

	}

	if (inputVector.size() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

float MinNumberInVector(const vector<float>& v)
{
	float min = v[0];
	for (unsigned i = 0; i < v.size(); i++)
	{
		if (min < v[i])
		{
			min = v[i];
		}
	}
	return min;
}

bool MultipyByMinElement(vector<float>& v)
{
	if (v.size() == 0)
	{
		return false;
	}
	
	float minNum = MinNumberInVector(v);

	for (unsigned i = 0; i < v.size(); i++)
	{
		v[i] *= minNum;
	}

	return true;
}

void PrintFloatsVector(const vector<float>& v)
{
	for (unsigned i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}
