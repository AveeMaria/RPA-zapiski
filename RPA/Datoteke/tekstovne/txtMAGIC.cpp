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

void IzpisiNtoVrstico(const char* filename, int n) {
	ifstream datai(filename, ios::app);
	if (datai.is_open()) {
		{
			int i = 0; string s;
			while (getline(datai, s)) {
				if (i == n) {
					cout << s << "\n";
					break;
				}
				++i;
			}
		}
		datai.close();
	}
}

void IzpisiNtoBesedo(const char* filename, int n) {
	ifstream datai(filename, ios::app);
	if (datai.is_open()) {
		{
			int i = 0; string s;
			while (datai >> s) {
				if (i == n) {
					cout << s << "\n";
					break;
				}
				++i;
			}
		}
		datai.close();
	}
}

int VrniVrstico(const char* filename, const char* iskanTXT) {
	ifstream datai(filename, ios::app);
	if (datai.is_open()) {
		int st_vrstice = 0;
		{
			string s;
			while (getline(datai, s)) {
				++st_vrstice;
				if (s == iskanTXT) {
					break;
				}
			}
		}
		return st_vrstice;
		datai.close();
	}
	else {
		std::cout << "file not open\n";
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	//fun fact tudi txt file lahko odpres v append mode:
	//ofstream datao("besedilo.txt",ios::app);

//	IzpisiVseVRSTICE("besedilo.txt");
//	IzpisiVseBESEDE("besedilo.txt");
	
	//ta drug string je kar hoces notr zapisat
//	ZapisivDatoteko("zapis.txt","mjavmjav");
//	ZapisivDatoteko("zapis.txt","mjavmjav");

//	KopirajIzbrisi("besedilo.txt","mjav.txt");
//	Kopiraj("besedilo.txt","mjav.txt");

//	IzpisiNtoVrstico("besedilo.txt",5);
//	IzpisiNtoBesedo("besedilo.txt",5);

//	cout << "iskana beseda se nahaja v: " << VrniVrstico("besedilo.txt", "iskana vrstica") << " vrstici\n";

	//remove("stevila.txt");rename("tmp.txt","stevila.txt");
	return 0;
}