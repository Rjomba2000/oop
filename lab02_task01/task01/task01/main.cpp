#include "VectorFunctions.h"

int main()
{
	vector<float> inputVector;

	if (!ParseNumbersToVector(cin, inputVector))
	{
		cout << "Incorrect input data";
		return 1;
	}

	if (!MultipyByMinElement(inputVector))
	{
		cout << "Vector must contain elements";
		return 1;
	}

	PrintFloatsVector(inputVector);
}