#include "TVSetController.h"
#include "TVSet.h"

using namespace std;
using namespace std::placeholders;

CTVSetController::CTVSetController(CTVSet& tv, std::istream& input, std::ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
{
	m_actionMap.insert(make_pair("TurnOn", bind(&CTVSetController::TurnOn, this, _1)));
	m_actionMap.insert(make_pair("TurnOff", bind(&CTVSetController::TurnOff, this, _1)));
	m_actionMap.insert(make_pair("SelectChannel", bind(&CTVSetController::SelectChannel, this, _1)));
	m_actionMap.insert(make_pair("SelectPreviousChannel", bind(&CTVSetController::SelectPreviousChannel, this, _1)));
	m_actionMap.insert(make_pair("Info", bind(&CTVSetController::Info, this, _1)));
}

bool CTVSetController::HandleCommand()
{
	string commandLine;

	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);

	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CTVSetController::TurnOn(std::istream& args)
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << endl;
	return true;
}

bool CTVSetController::TurnOff(std::istream& args)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
	return true;
}

bool CTVSetController::SelectChannel(std::istream& args)
{
	int channel;
	string arg;
	args >> arg;

	if (atoi(arg.c_str()) || arg == "0")
	{
		channel = atoi(arg.c_str());
		if (m_tv.SelectChannel(channel))
		{
			m_output << "Channel successfully selected" << endl;
		}
		else
		{
			m_output << "No such channel exists" << endl;
		}
	}
	else
	{
		m_output << "Unable to select channel" << endl;
	}

	return true;
}

bool CTVSetController::SelectPreviousChannel(std::istream& args)
{
	if (m_tv.SelectPreviousChannel())
	{
		m_output << "Previous channel successfully selected" << endl;
	}
	else
	{
		m_output << "Previous channel does not exist" << endl;
	}
	return true;
}

bool CTVSetController::Info(std::istream& args)
{
	m_tv.Info(m_output);
	return true;
}