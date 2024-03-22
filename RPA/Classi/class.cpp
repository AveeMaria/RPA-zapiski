#include <iostream>

class Razred{
private:
	int x;float y;
public:
	void izpis();

	bool operator>(Razred);//isto za <,>=,<=,==,!=
	//ce bi hotl class preverjat z nekim drugim datatypom npr. int/float/char
	//bool operator>(datatype);
	//vec metod/funkcij se lahko enako imenuje ce imajo razlicne parametre in/ali razlicno st. parametrov

	Razred operator+(Razred);
	Razred operator+=(Razred);
	
	//prefix in postfix increment
	Razred operator++();//++a
	Razred operator++(int);//a++
	//lahko returnamo Razred& za oba ++ oper.

	//default konstruktor
	Razred();//ce hocmo default konstruktor k nc ne nardi: Razred() {};

	//neprazni konstruktor (da dela rab obstajat default konstruktor)
	Razred(int,float);//to ponavadi rabis za opertator+ ali opertator-

	//kopirni konstruktor
	Razred(const Razred &);

	//operator << (za izpis)
	friend ostream& operator<<(ostream& os,const Razred&);
};

//operator << loh izpises ceu class, da nerabis izpisa
ostream& operator<<(ostream& os, const Razred& R)
{
    os << R.x << " " << R.y <<"\n";
    return os;
}

void Razred::izpis() {
	std::cout<<x<<" "<<y<<"\n";
}

Razred::Razred() {
	x=5;y=3.14;
}

Razred::Razred(int a,float b) {
	x=a;y=b;
}

Razred::Razred(const Razred &a) {
	x=a.x;y=a.y;
}

//++a
Razred Razred::operator++() {
	++x;++y;
	return *this;
}

//a++
Razred Razred::operator++(int x) {
	Razred tmp=*this;
	tmp.x++;tmp.y++;
	*this=tmp;
	return *this;
}

Razred Razred::operator+(Razred a) {
	Razred tmp(x+a.x,y+a.y);
	return tmp;
}

Razred Razred::operator+=(Razred a) {
	x+=a.x;y+=a.y;
}

int main() {
	Razred a,b(10,1.3);
	a.izpis();b.izpis();
	
/*
	a++;++b;
	a.izpis();b.izpis();
*/

/*
	a.izpis();b.izpis();
	Razred c=a+b;
	c.izpis();
*/

/*
	a+=b;
	a.izpis();b.izpis();
*/

/*
	if(a>b) {
		std::cout<<"a>b\n";
	}
	else {
		std::cout<<"a<=b\n";
	}
*/

	return 0;
}