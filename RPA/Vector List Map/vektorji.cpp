#include <iostream>
#include <vector>

int main() {
    vector<int> v = {0, 1, 2, 3, 4};
/*
    vector<int> v(5);//uporab default konstruktor za vseh 5
    v.reserve(6);
    v.resize(6);
    //das vrednosti v neprazn konstruktor da ustvar direkt v vector (autistic micro-optimisation)
    v.emplace_back(5);
    //vstavi na konec vektorja
    v.push_back(5);
    v[10]=5;
*/
    //50 shades izpisa vektorja: 

    //noob si varianta
    for(int i=0;i<v.size();++i) {
        cout<<v[i]<<"\n";
    }

    //ena boljsih variant
    for(int element : v) {
        cout<<element<<"\n";
    }

    //nemaras se/makarovic varianta
    for(vector<int>::iterator it=v.begin(); it != values.end(); ++it) {
        cout<<*(it)<<"\n";
    }
    return 0;
}