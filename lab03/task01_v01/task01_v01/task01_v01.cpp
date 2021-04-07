#include <iostream>

using namespace std;

class CTVSet
{
private:
	bool m_isTurnedOn;
	int m_currChannel;
	int m_memoryChannel;

public:
	CTVSet()
	{
		m_isTurnedOn = false;
		m_currChannel = 0;
		m_memoryChannel = 0;
	}

	void TurnOn()
	{
		if (!m_isTurnedOn)
		{
			m_isTurnedOn = true;
			m_currChannel = m_memoryChannel != 0 ? m_memoryChannel : 1;
		}
	}

	void TurnOff()
	{
		if (m_isTurnedOn)
		{
			m_isTurnedOn = false;
			m_memoryChannel = m_currChannel;
			m_currChannel = 0;
		}
	}

	void SelectChannel(unsigned channel)
	{
		if (channel >= 1 && channel <= 99)
		{
			m_currChannel = channel;
		}
	}

	void Info()
	{
		if (m_isTurnedOn)
		{
			cout << "TV is working" << endl;
		}
		else
		{
			cout << "TV is not working" << endl;
		}
		cout << "Current channel: " << m_currChannel << endl;
	}
};

int main()
{
	CTVSet tv;
}