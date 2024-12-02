#include <iostream>
using namespace std;

int a, b, c, d;

void ulamki() {
    cout << "Podaj licznik pierwszej liczby: " << endl;
    cin >> a;
    cout << "Podaj licznik drugiej liczby: " << endl;
    cin >> c;
    cout << "Podaj mianownik pierwszej liczby: " << endl;
    cin >> b;
    cout << "Podaj mianownik drugiej liczby: " << endl;
    cin >> d;
}

int nwd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

void wyciagnij_calosci(int licznik, int mianownik) {
    int calosci = licznik / mianownik;
    licznik = licznik % mianownik;
    if (calosci != 0) {
        cout << "Calkowita czesc: " << calosci << endl;
    }
}

void dodaj_ulamki() {
    int licznik = a * d + b * c;
    int mianownik = b * d;
    int wartoscnwd = nwd(licznik, mianownik);
    licznik = licznik / wartoscnwd;
    mianownik = mianownik / wartoscnwd;

    wyciagnij_calosci(licznik, mianownik);

    cout << "Wynik dodawania ulamkow: " << licznik << "/" << mianownik << endl;
}

int main() {
    ulamki();
    dodaj_ulamki();
    return 0;
}
