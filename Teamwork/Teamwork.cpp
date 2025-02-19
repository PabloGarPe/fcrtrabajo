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

	/*unsigned int highBits = a >> 32;
	unsigned int lowBits = b & ((1 << 32) - 1);
	unsigned int number = (highBits << 32) | lowBits;*/
	//Se q el ejercicio pide desplazar x bits, pero en nuestro caso, es usar los 0 bits mas altos y el resto del otro numero
	//luego es quedarnos con el segundo numero y hacer un desplazamiento de 32 bits en un unsigned int en C++ da problemas
	unsigned int number = b; //esto es por nuestro enunciado
	if (number <= 0) {
		cout << "Hubo algun fallo";
		//exit
	}
}

int main()
{
	MaskControl();
	return 0;
}
