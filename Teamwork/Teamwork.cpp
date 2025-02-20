#include <iostream>

extern "C" bool IsValidAssembly(int a, int b, int c);

//300028
void MaskControl() {
	using std::cout;
	using std::cin;
	using std::endl;

	unsigned int a;
	unsigned int b;

	unsigned int firstMask = 0x1; // 00000000 00000000 00000000 00000001
	unsigned int secondMask = 0x100; // 00000000 00000000 00000001 00000000
	unsigned int thirdMask = 0x8; // 00000000 00000000 00000000 00001000
	unsigned int highMask = 0x0; // 00000000 00000000 00000000 00000000
	unsigned int lowMask = 0xFFFFFFFF;


	cout << "Ingresa el primer numero: ";
	cin >> a;
	cout << endl << "Ingresa el segundo numero: ";
	cin >> b;
	cout << endl;

	if ((a & firstMask) != 0) {
		cout << "Acceso erróneo";
		//exit()
	}

	if ((a & secondMask) != (b & thirdMask)) {
		cout << "Intruso detectado";
		//exit()
	}

	unsigned int highBits = a & highMask;
	unsigned int lowBits = b & lowMask;
	unsigned int number = highBits | lowBits;

	if (number <= 0) {
		cout << "Hubo algun fallo";
		//exit
	}
}
//ID: 300028

void ControlInAsm() {
	using std::cout;
	using std::cin;

	int unsigned a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;

	if (IsValidAssembly(a, b, c) == 0) {
		cout << "Algo salió mal" << std::endl;
		//exit();
	}
}

int main()
{
	MaskControl();
	ControlInAsm();
	return 0;
}