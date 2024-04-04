#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Dijak{
	char priimek[11];
	float visina;
};

void IzpisizDatoteke(const char* filename) {
	ifstream datai(filename);
	if(datai.is_open()) {
		cout<<"izpis:\n";
		Dijak x;
		//izpisemo vse iz fila
		while(datai.read((char*) &x,sizeof(x))) {
			cout<<x.priimek<<x.visina<<"\n";
		}
		datai.close();
	}
	else {
		cout<<"file not open\n";
	}
}

void VpisDijak(Dijak &a) {
	fgets(a.priimek,11,stdin);
	cin>>a.visina;cin.ignore();
}

void SortiranVpis(const char* filename,Dijak a) {
	ifstream datai(filename,ios::binary);
	ofstream datao("tmp.bin",ios::binary);

	//to je ce se ni fila zato da ga ustvari da ne joka
	if(datai.is_open()==false) {
		ofstream nardimofile(filename,ios::binary);
		datai.open(filename,ios::binary);
		nardimofile.close();
	}

	//prever da ni prazna in da je ze vpisu novga dijaka
	bool neki=false;
	Dijak b;//tega preberemo

	if((datai.is_open())&&(datao.is_open())) {
		//prebere celo dat
		while(datai.read((char*)&b,sizeof(b))) {
			//ce je vecji ga zapisemo prej
			if(a.visina>b.visina&&neki==false) {
				datao.write((char*)&a,sizeof(a));
				neki=true;
			}
			//v vsakem primeru prepisemo b v tmp.bin
			datao.write((char*)&b,sizeof(b));
		}
		//ce je prazna dat se while ne izvede in zapise na prvo mesto
		if(neki==false) {
			datao.write((char*)&a,sizeof(a));
		}
		datai.close();
		datao.close();
	}
	
	//deletamo staro dat, preimenujemo tmp v ime stare datoteke
	remove(filename);rename("tmp.bin",filename);
}

int main() {
	Dijak a;
	
	//vpise 3 dijake
	for(int i=0;i<3;++i) {
		VpisDijak(a);
		SortiranVpis("Dijaki.bin",a);	
	}

	IzpisizDatoteke("Dijaki.bin");
	return 0;
}
