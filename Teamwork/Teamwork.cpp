#include <iostream>

extern "C" bool IsValidAssembly(int a, int b, int c);

using namespace std;



void ControlWithReversedStrings() {
	//Almacena la cadena de caracteres (no es válido usar string)
	char string1[20];
	char string2[20];

	//Primera cadena
	cout << "Ingrese una cadena de caracteres: ";
	cin >> string1;

	/**
	* Si la cadena es menor a 10 caracteres o si el caracter en la posición ID[2] = 0 es distinto al de la
	* posición ID[5] = 8, entonces se imprime "Acceso incorrecto" y se llamará a la función exit
	*/
	if (strlen(string1) < 10 || string1[0] != string1[8]) {
		cout << "Acceso incorrecto" << endl;
		exit(EXIT_FAILURE);
	}

	//Segunda cadena
	cout << "Ingrese otra cadena de caracteres: ";
	cin >> string2;


	/**
	* Comprobar si la inversa de la cadena es 9n7g4fd1 y, en caso contrario, imprimir "El acceso no fue correcto" y llamar a exit
	*/
	if (strcmp(_strrev(string2), "9n7g4fd1") != 0) {
		cout << "El acceso no fue correcto" << endl;
		exit(EXIT_FAILURE);
	}

	cout << endl;

}


void MaskControl() {
	/*
	En esta función se usará el Id 299928
	*/

	unsigned int a;
	unsigned int b;

	unsigned int maskId2 = 0x200;	// 00000000 00000000 00000010 00000000. Id[2] = 9
	unsigned int maskId5 = 0x100;	// 00000000 00000000 00000001 00000000. Id[5] = 8
	unsigned int maskId0 = 0x4;		// 00000000 00000000 00000000 00000100. Id[0] = 2


	cout << "Ingresa el primer numero: ";
	cin >> a;
	cout << "Ingresa el segundo numero: ";
	cin >> b;

	//Se comprueba si el bit en la posicion 9 es 0
	if ((a & maskId2) != 0) {
		cout << "Acceso erroneo" << endl;
		exit(EXIT_FAILURE);
	}

	//Se comprueba si el bit en la posicion 8 del primer numero es igual al bit en la posicion 2 del segundo numero
	if (((a & maskId5) >> 8) != ((b & maskId0) >>2)) {
		cout << "Intruso detectado" << endl;
		exit(EXIT_FAILURE);
	}

	unsigned int numBitsBajos = 32 - 9;							//Obtiene los bits bajos segun el enunciado: 32 - Id[3]
	unsigned int bitsA = (a >> numBitsBajos) << numBitsBajos;	//Nos quedamos con los 9 bits mas altos del primer numero
	unsigned int bitsB = b & ((1 << numBitsBajos) - 1);			//Nos quedamos con los bits bajos del segundo numero
	unsigned int result = bitsA | bitsB;						//Calculamos el numero

	//Hacemos la comprobación pedida en el guión. Id[1] = 9
	if (result <= 900) {
		cout << "Hubo algun fallo";
		exit(EXIT_FAILURE);
	}

	cout << endl;

}


void ControlInAsm() {
	/*
	En esta función se usará el Id 299928
	*/

	int a = 0;
	int b = 0;
	int c = 0;

	/**
	* Pide tres números para después comprobar si son válidos o no. Si no lo son, se imprime "Algo salió mal" y se llama a exit
	*/
	cout << "Ingrese el primer numero entero: ";
	cin >> a;
	cout << "Ingrese el segundo numero entero: ";
	cin >> b;
	cout << "Ingrese el tercer numero entero: ";
	cin >> c;

	//Se llama a la función IsValidAssembly
	if (IsValidAssembly(a, b, c) == 0) {
		cout << "Algo salió mal" << std::endl;
		exit(EXIT_FAILURE);
	}

	cout << endl;

}

void CheckArray() {
	unsigned char array[3];

	// Se piden tres valores de 8 bits ( 1 byte )
	cout << "Ingrese tres valores (8 bits): " << endl;
	cin >> array[0] >> array[1] >> array[2];

	unsigned char result = array[0] & array[1] & array[2]; // Se realiza la operación AND, a nivel de bit, entre los tres valores 

	// Si el resultado de la operación AND es distinto de 200, se imprime "Fallo" y se llama a exit
	if (result != 200) { 
		/*
		* 200d = 11001000b = C8h 
		* el resultado de la operación AND entre 11001000 y 11001000 es 11001000
		* que codifca ╚
		*/ 
		cout << "Fallo" << endl;
		exit(EXIT_FAILURE);
	}

	cout << endl;
}


int main()
{
	ControlWithReversedStrings();
	MaskControl();
	ControlInAsm();
	CheckArray();

	cout << "Acceso permitido" << endl;

	return 0;
}