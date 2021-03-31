#include "SetFunctions.h"
#include <optional>
#include <string>

using namespace std;

struct Args
{
	int number;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		return nullopt;
	}

	Args args;

	string str = argv[1];

	if (str.find_first_not_of("0123456789") != string::npos)
	{
		cout << "Argument must be integer number\n";
		return nullopt;
	}

	args.number = stoi(str);

	if (args.number < 1)
	{
		cout << "Argument must be greater than 0\n";
		return nullopt;
	}

	return args;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	
	if (!args)
	{
		return 1;
	}

	PrintIntSet(CrossSet(DigitsSumDivisibleSet(args->number), DigitsSumEvenSet(args->number)));

	return 0;
}