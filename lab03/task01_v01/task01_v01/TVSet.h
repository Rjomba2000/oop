#pragma once
#include <iostream>
#include <stack>

class CTVSet
{
public:
	CTVSet();

	void TurnOn();
	void TurnOff();
	bool SelectChannel(std::size_t channel);
	bool SelectPreviousChannel();
	void Info(std::ostream& output);
private:
	bool m_isTurnedOn;
	std::size_t m_currChannel;
	std::stack<std::size_t> m_memory;
};