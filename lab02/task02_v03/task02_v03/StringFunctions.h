#pragma once
#include "Structs.h"
#include <iostream>
#include <string>
#include <optional>

std::string FindAndReplace(std::string const& subject, std::string const& search, std::string const& replace);
std::optional<Args> ParseArgs(int argc, char* argv[]);