#include <iostream>
#include <string>
#include <optional>
#include "Structs.h"

using namespace std;

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		return nullopt;
	}

	Args args;
	args.search = argv[1];
	args.replace = argv[2];

	return args;
}

string FindAndReplace(string const& subject, string const& search, string const& replace)
{
	if (search == "")
	{
		return subject;
	}

	size_t pos;
	size_t start = 0;
	string resStr = "";

	pos = subject.find(search, start);

	while (pos != -1)
	{
		resStr += subject.substr(start, pos - start) + replace;
		start = pos + search.length();
		pos = subject.find(search, start);
	}

	resStr += subject.substr(start, subject.length() - start);

	return resStr;
}

