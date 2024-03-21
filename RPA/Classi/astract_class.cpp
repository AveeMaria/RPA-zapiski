#include <iostream>

using namespace std;

//abstraktni razred je razred k ma eno ali vec pure virtual funkcij
//virtualna funkcija je: virtual void funkcija() = 0; 

/*
virtualne funkcije se ne definira v abstraktnem
razredu ampak jo mors definirat v izpeljanem razredu 
*/

//nemoremo ustvariti objekta iz abstraktnega razreda

class Bazni{
protected:

public:
    virtual void PureVirtualnaFunkcija() = 0;
    //
    virtual void VirtualnaFunkcija();
};

//tega ni treba sploh pisat kr mores redefirnirat
/*
void Bazni::PureVirtualnaFunkcija() {
    cout<<"to se nebo nikol izpisalo\n";
}*/

void Bazni::VirtualnaFunkcija() {
    cout<<"mjav\n";
}

//objekt izpeljanega razreda lahko uporabimo samo ce smo redefinirali vse pure virtualne funkcije
//vedno ko dedujes poglej da ma bazni class PROTECTED
class Izpeljani:public Bazni{
private:

public:
    void PureVirtualnaFunkcija();
    //ce virt. fun. ne redefiniramo v Izp. classu se uporabi tista iz Baznega
    void VirtualnaFunkcija();//samo virtualne funkcije ni treba redefinirat
};

void Izpeljani::PureVirtualnaFunkcija() {
    cout<<"to se bo vedn izpisalo\n";
}

void Izpeljani::VirtualnaFunkcija() {
    cout<<"wuf\n";
}

int main()
{
    Izpeljani x;
    //x.PureVirtualnaFunkcija();
    x.VirtualnaFunkcija();
    return 0;
}

//fun fact 1: loh nardis pointer abstraktnga clasa
/*
Bazni *px;
Manager x;
px=&x;
px->PureVirtualnaFunkcija();

//calla funkcijo iz izpeljanega
*/

//fun fact 2:
//abstraktni class k ma samo pure virtual funkcije imenujemo interface