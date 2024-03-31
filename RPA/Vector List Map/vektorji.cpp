#include <iostream>
#include <vector>
#include <cstring>//zato kr rabm strcpy da compiler ne joka
//strcpy nekak pusti sprement "const char*" v "char []" kar drgac ni legal

using namespace std;

class Razred {
private:
    char ime[10];
    float visina;
public:
    void izpis();//self explantory

    //default konstruktor
    Razred();

    //kopirni konstruktor
    Razred(const Razred&);

    //neprazni konstruktor
    Razred(const char*, float);

    //operator << (za izpis)
    friend ostream& operator<<(ostream& os, const Razred&);
};

//operator << loh izpises ceu class, da nerabis izpisa
ostream& operator<<(ostream& os, const Razred& R)
{
    os << "ime: " << R.ime << "\nvisina: " << R.visina << "\n";
    return os;
}

void Razred::izpis() {
    cout << "ime: " << ime << "\nvisina: " << visina << "\n";
}

Razred::Razred() {
    cout << "default konstruktor\n";
    strcpy(ime, "makarovic");
    visina = 155.9;
}

Razred::Razred(const Razred& a) {
    cout << "kopirni konstruktor\n";
    //ime=a.ime;
    strcpy(ime, a.ime);
    visina = a.visina;
}

Razred::Razred(const char* a, float b) {
    cout << "neprazni konstruktor\n";
    strcpy(ime, a);
    visina = b;
}

void Funkcija(/*const*/std::vector<Razred>& v) {

}

int main()
{
    //ustvari prazn vector
    vector<Razred> v;

    //ustvari vektor zeljene velikosti, klice default konstruktor
    //vector<Razred> v(5);

    //v.size(); returna velikost vektorja
    //cout<<"velikost vektorja: "<<v.size()<<"\n\n";

/*
    "FUN" Facts:

    -vektor ima kot array[] vse elemente zaporedno v memoryju (niso randomly po spominu),
     zato loh uporabmo [] operator (index operator)

    -ko se vektor resiza skopira use elemente in deleta prejsne stvari.
*/

//nardi 2x trenutne velikosti, ce je sezmer premal pristeje razliko. Also klice default konstruktor
//v.resize(5);

//poveca vector za tocn tok k hoces, ne klice konstruktorjev
    v.reserve(5);

    /*
        namest, da nardim za Razred R("maky",20.3); v.push_back(R)
        je bolj optimalno(ne klice 2x copy konstruktorja) v oklepaju (Razred("maky",20.3))
    */

    //  metodi za dodat element na konc: push_back in emplace_back
    //  emplace_back je bolj optimalen

        //da element na konc vektorja, vedno klice copy konstruktor
    v.push_back(Razred("maky", 20.3));

    //v.push_back("maky",20.3); TO NE DELA


    //das vrednosti v neprazn konstruktor da ustvar direkt v konec vectorja, da nerabi klicat copy konstruktorja
    v.emplace_back("maky", 20.3);

    //v.emplace_back(Razred("maky",20.3));//TO SE DA sam pol je to efektivno pushback in je mnj optimalno

    //deleta cel vector, da velikost na 0
    //v.clear();

    //izbrise N-ti element v seznamu
    //int n=3;//3. element
    //v.erase(v.begin + (n-1));

    //index operator 
    //v[0].izpis();//izpise prvi element

/*
    //50 shades scrollanja skozi cel vector(za izpis, for loopi so enaki sam kodo spremenis ce kej druzga hoces):
    //ce hoces kerkol od << (cout/ofstream) variant rabis overloadat << operator

    cout<<"-----------\n";

    for(int i=0;i<v.size();++i) {
        cout<<v[i]<<"\n";
    }

    //noob si varianta
    cout<<"-----------\n";

    //ena boljse razumljivih variant, uporab kopirni konstruktor za kopirat vektor element v e(mnj optimalno kt kj druzga?)
    for(Razred e : v) {
        //e.izpis();
        cout<<e<<"\n";
    }

    cout<<"-----------\n";

    //nemaras se/makarovic varianta (gre od zacetka do konc vektorja)
    for(vector<Razred>::iterator it=v.begin(); it != v.end(); ++it) {
        //it->izpis();
        cout<<*it<<"\n";
    }
*/

    return 0;
}
