#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int CountDigitsSum(int num)
{
	int res = 0;
	while (num != 0)
	{
		res += num % 10;
		num = num / 10;
	}
	return res;
}

set<int> DigitsSumDivisibleSet(int n)
{
	set<int> resSet;
	for (size_t i = 1; i <= n; ++i)
	{
		if (i % CountDigitsSum(i) == 0)
		{
			resSet.insert(i);
		}
	}
	return resSet;
}

set<int> DigitsSumEvenSet(int n)
{
	set<int> resSet;
	for (size_t i = 1; i <= n; ++i)
	{
		if (CountDigitsSum(i) % 2 == 0)
		{
			resSet.insert(i);
		}
	}
	return resSet;
}

void PrintIntSet(const set<int>& outputSet)
{
	for (set<int>::iterator it = outputSet.begin(); it != outputSet.end(); ++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

set<int> CrossSet(set<int> const& set1, set<int> const& set2)
{
	set<int> resSet;
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(resSet, resSet.begin()));
	return resSet;
}