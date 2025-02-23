#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream plik("napisy.txt");
    string napis;
    int parzystaDlugosc = 0;
    int rownaLiczbaZerIJedynek = 0;
    int sameZera = 0;
    int sameJedynki = 0;
    int liczbaNapisowODlugosci[17] = {0};

    while (getline(plik, napis)) {
        if (napis.length() % 2 == 0) {
            parzystaDlugosc++;}

        int liczbaZer = 0;
        for (char znak : napis) {
            if (znak == '0') liczbaZer++;}
        if (liczbaZer == (napis.length() - liczbaZer)) {
            rownaLiczbaZerIJedynek++;}

        if (liczbaZer == napis.length()) {
            sameZera++;
        } else if (liczbaZer == 0) {
            sameJedynki++;}

        if (napis.length() >= 2 && napis.length() <= 16) {
            liczbaNapisowODlugosci[napis.length()]++;}
    }

    plik.close();

    cout << "Parzysta długosc: " << parzystaDlugosc << endl;
    cout << "Rowne zera i jedynki: " << rownaLiczbaZerIJedynek << endl;
    cout << "Same zera: " << sameZera << endl;
    cout << "Same jedynki: " << sameJedynki << endl;
    cout << "Wedlug dlugosci:" << endl;
    for (int i = 2; i <= 16; i++) {
        cout << "   Dlugosc " << i << ": " << liczbaNapisowODlugosci[i] << endl;
    }

    return 0;
}