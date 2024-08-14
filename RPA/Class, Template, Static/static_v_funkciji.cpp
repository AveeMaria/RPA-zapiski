#include <iostream>


void IzpisiCounter() {
	//definiramo staticno spremenljivko
	static int counter;

	//tega nemores narediti	
//	static int counter = 0;

	counter++;

	std::cout << "counter: " << counter << "\n";
}

//inicializacija staticne spremenljivke v funkciji
	static int counter = 0;
//	int counter = 0;//tudi to dela sam je bol iffy



int main(int argc, char const *argv[])
{
	IzpisiCounter();
	IzpisiCounter();
	IzpisiCounter();

	return 0;
}