#include "TVSetController.h"
#include "TVSet.h"

using namespace std;

int main()
{
	CTVSet tv;
	CTVSetController controller(tv, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!controller.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}