#include <iostream>

/*TA DATOTEKA JE O STATIC LASTNOSTIH IN STATIC METODAH*/

class Razred{
private:
	//za vsak nov objekt tipa razred se bo stelo koliko jih je
	static int ObjCount;

	//nemores inicializirati tako, ker da error:
//	static int ObjCount=5;

	int x=5;//to loh ker ni static
public:
	//staticne metode lahko dostopajo SAMO do STATICNIH LASTNOSTI
	static void printObjCount() { std::cout << "objcount: " << ObjCount << "\n"; }

	//to je error ker static metode nemorejo dostopat do navadnih lastnosi
//	static void printX() { std::cout << x << "\n"; }

	//neka normal funkcija LAHKO uporablja navadne in STATICNE lastnosti
	void izpis() { std::cout << "objcount: " << ObjCount << " x: " << x << "\n"; }

	Razred();
	~Razred();
};

//ko nardimo nov objekt default konsturktor povisa ObjCount
Razred::Razred() {
	ObjCount++;
}

//ko nardimo nov objekt default desturktor zniza ObjCount
Razred::~Razred() {
	ObjCount--;
}

//inicializacija STATICNIH spremenljivk:

int Razred::ObjCount = 0;


int main(int argc, char const *argv[])
{
	//staticne metode lahko klicemo BREZ OBJEKTA tega tipa
	Razred::printObjCount();//tukaj je objcount = 0;

	Razred a;
	//lahko jih tudi klicemo z objektom (neuporabno)
	a.printObjCount();//tukaj je objcount = 1;

	Razred b,c;	//tukaj je objcount = 3;
	Razred::printObjCount();

	// "{" in "}" sta scope torej ce se definira spremenljivka 
	//med tema dvema oklepajema bo obstajala do "}"
	{
		Razred d;
		//tukaj je objcount = 4;
		Razred::printObjCount();
	}

	//tukaj je objcount = 3;
	Razred::printObjCount();

	return 0;
}