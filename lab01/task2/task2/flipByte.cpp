#include <iostream>
#include <optional>
#include <string>

using namespace std;

struct Args
{
	string byte;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		return nullopt;
	}

	Args args;
	args.byte = argv[1];

	return args;
}

int charToInt(char ch)
{
	switch (ch)
	{
		case '0':
			return 0;
			break;
		case '1': 
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '8':
			return 8;
			break;
		case '9':
			return 9;
			break;
		default:
			return -1;
			break;
	}
}

int stringToInt(string str)
{
	int addDig, result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		result *= 10;
		addDig = charToInt(str[i]);
		if (addDig == -1)
			return -1;
		result += addDig;
	}
	return result;
}

int flipByte(int n)
{
	int result = 0;
	for (int i = 7; i >= 0; i--)
	{
		result |= (n & 1) << i;
		n >>= 1;
	}
	return result;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);

	if (!args)
	{
		return 1;
	}

	int byte = stringToInt(argv[1]);

	if (byte == -1 )
	{
		cout << "Incorrect input data type";
		return 1;
	}

	if (byte > 255)
	{
		cout << "Number must be less than 256";
		return 1;
	}

	int result = flipByte(byte);
	cout << result << '\n';

	return 0;
}