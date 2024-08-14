#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class Tocka{
private:
    T x,y;
public:
    void vpis();
    void izpis();
    Tocka();
    Tocka(T,T);
    Tocka(const Tocka &);
    Tocka& operator++();//prefix increment
    void operator*=(T);
    bool operator==(Tocka);
    float razdalja(Tocka);
};

template <class T>
Tocka<T>& Tocka<T>::operator++() {
    ++x;++y;
    return *this;
}

template <class T>
void Tocka<T>::izpis() {
    cout<<"x: "<<x<<" y: "<<y<<"\n";
}

template <class T>
void Tocka<T>::vpis() {
    cin>>x>>y;
}

template <class T>
Tocka<T>::Tocka() {
    x=0;y=0;
}

template <class T>
Tocka<T>::Tocka(T a,T b) {
    x=a;y=b;
}

template <class T>
Tocka<T>::Tocka(const Tocka &a) {
    x=a.x;y=a.y;
}

template <class T>
void Tocka<T>::operator*=(T a) {
    x*=a;y*=a;
}

template <class T>
bool Tocka<T>::operator==(Tocka a) {
    return (x==a.x)&&(y==a.y);
}

template <class T>
float Tocka<T>::razdalja(Tocka a) {
    return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
}

int main() {
    Tocka<int> a;a.izpis();
    Tocka<int> b(2,2);++b;b.izpis();
    cout<<"enakost: "<<a.operator==(b)<<"\n";
    cout<<"razdalja: "<<a.razdalja(b)<<"\n";
    return 0;
}