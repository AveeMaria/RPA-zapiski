#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ZapisivDatoteko(const char filename[],const char text[]) {
	ofstream datao(filename,ios::app);//odpre file v append mode
	//append mode doda text na konc fila in ne overwrita starega fila (leaderboards)
	if(datao.is_open()) {
		datao<<text<<"\n";
		datao.close();
	}
	else {
		cout<<"file not open\n";
	}
}

void IzpisiVseVRSTICE(const char filename[]) {
	ifstream datai(filename);
	if(datai.is_open()) {
		string s;
		while(getline(datai,s)) {
			cout<<s<<"\n";
		}
		datai.close();
	}
	else {
		cout<<"file not open\n";
	}
}

void IzpisiVseBESEDE(const char filename[]) {
	ifstream datai(filename);
	if(datai.is_open()) {
		string s;
		while(datai>>s) {
			cout<<s<<"\n";
		}
		datai.close();
	}
	else {
		cout<<"file not open\n";
	}
}

void Kopiraj(const char inputfile[],const char outputfile[]) {
	ifstream datai(inputfile);
    ofstream datao(outputfile);
	if(datai.is_open()&&datao.is_open()) {
		string s;
		while (std::getline(datai, s)) {
			datao<<s<<"\n";
		}
		datai.close();
		datao.close();
	}
	else {
		cout<<"files not open\n";
	}
}

void KopirajIzbrisi(const char inputfile[],const char outputfile[]) {
	ifstream datai(inputfile);
    ofstream datao(outputfile);
	if(datai.is_open()&&datao.is_open()) {
		string s;
		while (std::getline(datai, s)) {
			datao<<s<<"\n";
		}
		datai.close();
		datao.close();

		//mormo zapret predn renamamo/removamo file
		remove(inputfile);rename(outputfile,inputfile);
	}
	else {
		cout<<"files not open\n";
	}	
}

int main(int argc, char const *argv[])
{
//	IzpisiVseVRSTICE("besedilo.txt");
//	IzpisiVseBESEDE("besedilo.txt");
	
	//ta drug string je kar hoces notr zapisat
//	ZapisivDatoteko("zapis.txt","mjavmjav");
//	ZapisivDatoteko("zapis.txt","mjavmjav");

//	KopirajIzbrisi("besedilo.txt","mjav.txt");
//	Kopiraj("besedilo.txt","mjav.txt");

	//remove("stevila.txt");rename("tmp.txt","stevila.txt");
	return 0;
}