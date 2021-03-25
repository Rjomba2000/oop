#include <catch2/catch.hpp>
#include "task02_v03/task02_v03/StringFunctions.h"

using namespace std;

TEST_CASE("FindAndReplace: Empty search str")
{
	string inputStr = "test";
	string search = "";
	string replace = "a";
	REQUIRE(FindAndReplace(inputStr, search, replace) == inputStr);
}

TEST_CASE("FindAndReplace: Normal String")
{
	string inputStr = "test00te0st";
	string search = "0";
	string replace = "1";
	string lookingResult = "test11te1st";
	REQUIRE(FindAndReplace(inputStr, search, replace) == lookingResult);
}

TEST_CASE("FindAndReplace: String with search string on first position")
{
	string inputStr = "0test";
	string search = "0";
	string replace = "1";
	string lookingResult = "1test";
	REQUIRE(FindAndReplace(inputStr, search, replace) == lookingResult);
}

TEST_CASE("FindAndReplace: String with search string on last position")
{
	string inputStr = "test0";
	string search = "0";
	string replace = "1";
	string lookingResult = "test1";
	REQUIRE(FindAndReplace(inputStr, search, replace) == lookingResult);
}