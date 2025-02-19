#include <iostream>

extern "C" bool IsValidAssembly(int a, int b, int c);

//ID: 300028

int main()
{

	return 0;
}

void ControlInAsm() {
	using std::cout, std::cin;

	int a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;

	if (IsValidAssembly(a, b, c) == 0) {
		cout << "Algo salió mal" << std::endl;
		exit();
	}
}
