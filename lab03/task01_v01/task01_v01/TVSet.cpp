#include "TVSet.h"

using namespace std;

CTVSet::CTVSet() : m_isTurnedOn(false), m_currChannel(0) {}

void CTVSet::TurnOn()
{
	m_isTurnedOn = true;
	if (!m_memory.empty()) {
		m_currChannel = m_memory.top();
		m_memory.pop();
	}
}

void CTVSet::TurnOff()
{
	m_isTurnedOn = false;
	m_memory.push(m_currChannel);
	m_currChannel = 0;
}

bool CTVSet::SelectChannel(std::size_t channel)
{
	if (m_isTurnedOn && channel >= 1 && channel <= 99)
	{
		m_memory.push(m_currChannel);
		m_currChannel = channel;
		return true;
	}
	else
	{
		return false;
	}
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isTurnedOn && !m_memory.empty())
	{
		m_currChannel = m_memory.top();
		m_memory.pop();
		return true;
	}
	else
	{
		return false;
	}
}

void CTVSet::Info(ostream& output)
{
	if (m_isTurnedOn)
	{
		output << "TV is working" << endl;
	}
	else
	{
		output << "TV is not working" << endl;
	}
	output << "Current channel: " << m_currChannel << endl;
}
