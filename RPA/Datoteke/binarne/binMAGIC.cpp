#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

//nesme met stringov, lahko pa je Cjevski niz :nerd:
//za scientific purpose je Podatek DIJAK
struct Podatek {
	char priimek[11];
	float visina;
	short starost;
};

//zapise podatek na N-to mesto v file
void ZapisiNaMesto(const char* filename, Podatek x, int n) {
    ofstream datao(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (datao.is_open()) {
    	//mozni so ios::beg/end/cur 
		//beg je branje/pisanje od zacetka levo in end je od konca desno
        datao.seekp((n - 1) * sizeof(x), std::ios::beg);
        datao.write((char*)&x, sizeof(x));
        datao.close();
    } else {
        cout << "File not open\n";
    }
}

//izpise podatek iz N-tega mesta iz fila
void IzpisIzMesta(const char* filename, int n) {
    ifstream datai(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (datai.is_open()) {
    	Podatek x;//ce hocmo ga loh returnamo,kle ga nebom
    	//mozni so ios::beg/end/cur 
		//beg je branje/pisanje od zacetka levo in end je od konca desno
        datai.seekg((n - 1) * sizeof(x), std::ios::beg);
        datai.read((char*)&x, sizeof(x));
        cout<<x.priimek<<" "<<x.visina<<" "<<x.starost<<"\n";
        datai.close();
    } else {
        cout << "File not open\n";
    }
}

//posljemo mu podatek ki ga nej zapise v file
void ZapisivDatoteko(const char* filename,Podatek x) {
	ofstream datao(filename, std::ios::binary | std::ios::app);//odpremo binary v append mode
	//append mode doda podatke na konc datoteke in NE overwrita stare
	if(datao.is_open()) {
		datao.write((char*) &x,sizeof(x));
		datao.close();
	}
	else {
		cout<<"file not open\n";
	}
}

void IzpisizDatoteke(const char* filename) {
	ifstream datai(filename);
	if(datai.is_open()) {
		Podatek x;
		//izpisemo vse iz fila
		while(datai.read((char*) &x,sizeof(x))) {
			cout<<x.priimek<<" "<<x.visina<<" "<<x.starost<<"\n";
		}
		datai.close();
	}
}

void vpis(Podatek& a) {
    std::cin.getline(a.priimek, 11);
    a.visina = (rand()%1500+500)/10;
    a.starost = rand()%99+1;
}

int main(int argc, char const *argv[]) {
	srand(time(NULL));

//	Podatek a;vpis(a);
//	ZapisivDatoteko("binarna.bin",a);
//	IzpisizDatoteke("binarna.bin");

//	ZapisiNaMesto("binarna.bin",a,3);
//	IzpisIzMesta("binarna.bin",4);

	return 0;
}
