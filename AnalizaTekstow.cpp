#include <iostream>
#include <string>
using namespace std;

int main() {
    char znak;
    int iloscZnaku = 0;
    int bialeZnaki = 0;

    cout << "Podaj tekst" << endl;
    string txt;
    getline(cin, txt);

    cout << "Podaj znak do policzenia: ";
    cin >> znak;

    int szczur = txt.size();
    cout << "Rozmiar wprowadzonego napisu: " << szczur << endl;

    for (char c : txt) {
        if (c == ' ' || c == '\t' || c == '\n') {
            bialeZnaki++;
        }
        if (c == znak) {
            iloscZnaku++;
        }
    }

    cout << "Liczba bialych znakow: " << bialeZnaki << endl;
    cout << "Liczba wystapien znaku '" << znak << "': " << iloscZnaku << endl;

    return 0;
}
