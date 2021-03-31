#pragma once
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

std::set<int> CrossSet(std::set<int> const& set1, std::set<int> const& set2);
std::set<int> DigitsSumDivisibleSet(int n);
std::set<int> DigitsSumEvenSet(int n);
void PrintIntSet(const std::set<int>& outputSet);