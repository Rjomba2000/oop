#include "StringFunctions.h"

using namespace std;

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return 1;
	}

	string inputStr;

	while (!cin.eof())
	{
		getline(cin, inputStr);
		cout << FindAndReplace(inputStr, args->search, args->replace) << endl;
	}

	return 0;
}