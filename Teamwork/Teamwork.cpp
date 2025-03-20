#include <iostream>

extern "C" bool IsValidAssembly(int a, int b, int c);

using namespace std;

//299928
void MaskControl() {
	unsigned int a;
	unsigned int b;

	unsigned int firstMask = 0x200; // 00000000 00000000 00000010 00000000
	unsigned int secondMask = 0x100; // 00000000 00000000 00000001 00000000
	unsigned int thirdMask = 0x4; // 00000000 00000000 00000000 00000100
	unsigned int highMask = 0x0; // 00000000 00000000 00000000 00000000
	unsigned int lowMask = 0xFFFFFFFF;


	cout << "Ingresa el primer numero: ";
	cin >> a;
	cout << endl << "Ingresa el segundo numero: ";
	cin >> b;
	cout << endl;

	if ((a & firstMask) != 0) {
		cout << "Acceso erróneo";
		exit(1);
	}

	if (((a & secondMask) >> 8) != ((b & thirdMask) >>2)) {
		cout << "Intruso detectado";
		exit(1);
	}

	unsigned int bitsBajos = 32 - 9;
	unsigned int bitsA = (a >> bitsBajos) << bitsBajos;
	unsigned int bitsB = b & ((1 << bitsBajos) - 1);
	unsigned int number = bitsA | bitsB;

	if (number <= 900) {
		cout << "Hubo algun fallo";
		exit(1);
	}
}

//ID: 299928
void ControlInAsm() {
	int a = 0;
	int b = 0;
	int c = 0;

	cin >> a;
	cin >> b;
	cin >> c;

	if (IsValidAssembly(a, b, c) == 0) {
		cout << "Algo salió mal" << std::endl;
		exit(1);
	}
}

void CheckArray() {
	unsigned char array[3];

	cout << "Ingrese tres valores enteros (8 bits): ";
	cin >> array[0] >> array[1] >> array[2];

	unsigned char result = array[0] & array[1] & array[2];

	if (result != 200) {  // 200 en decimal = 11001000 en binario
		cout << "Fallo" << endl;
		exit(1);
	}
}

int main()
{
	MaskControl();
	ControlInAsm();
	return 0;
}