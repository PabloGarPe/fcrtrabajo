#include <iostream>

#include "stages.h"


using std::cout;
using std::cin;
using std::endl;

int main()
{
	Stage1();

	cout << "Stage 1 disabled" << endl;

	Stage2();

	cout << "Stage 2 disabled" << endl;

	Stage3();

	cout << "Stage 3 disabled" << endl;

	Stage4();

	cout << "Stage 4 disabled" << endl;

	cout << "Wow, you've just saved the Earth!" << endl;

	cout << "Press Enter to exit..." << endl;
	cin.get();

	return 1;
}