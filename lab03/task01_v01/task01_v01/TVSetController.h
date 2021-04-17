#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <sstream>
#include "TVSet.h"

class CTVSetController
{
public:
	CTVSetController(CTVSet& tv, std::istream& input, std::ostream& output);
	bool HandleCommand();

private:
	bool TurnOn(std::istream& args);
	bool TurnOff(std::istream& args);
	bool SelectChannel(std::istream& args);
	bool SelectPreviousChannel(std::istream& args);
	bool Info(std::istream& args);

	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	CTVSet& m_tv;
	std::istream & m_input;
	std::ostream & m_output;

	ActionMap m_actionMap;
};