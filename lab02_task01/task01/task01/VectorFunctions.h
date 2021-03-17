#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool ParseNumbersToVector(istream& input, vector<float>& inputVector);
bool MultipyByMinElement(vector<float>& v);
void PrintFloatsVector(const vector<float>& v);