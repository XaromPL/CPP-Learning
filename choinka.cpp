#include <iostream>
using namespace std;

void rysujGalaz(int wysokosc, int szerokoscStartowa) {
    for (int i = 0; i < wysokosc; i++) {
        int liczbaSpacji = szerokoscStartowa - i - 1;
        int liczbaGwiazdek = 2 * i + 1;

        for (int j = 0; j < liczbaSpacji; j++) {
            cout << " ";
        }

        for (int j = 0; j < liczbaGwiazdek; j++) {
            cout << "*";
        }

        cout << endl;
    }
}

void rysujPien(int liczbaGalezi, int szerokoscPnia) {
    int wysokoscPnia = 2;
    int liczbaSpacji = szerokoscPnia - 1;

    for (int i = 0; i < wysokoscPnia; i++) {
        for (int j = 0; j < liczbaSpacji; j++) {
            cout << " ";
        }

        for (int j = 0; j < 3; j++) {
            cout << "|";
        }

        cout << endl;
    }
}

int main() {
    int wysokoscPierwszejGalazki, liczbaGalezi;

    cout << "Podaj wysokosc pierwszej galdzi: ";
    cin >> wysokoscPierwszejGalazki;
    cout << "Podaj liczbe galezi: ";
    cin >> liczbaGalezi;

    int szerokoscStartowa = wysokoscPierwszejGalazki + liczbaGalezi - 1;

    for (int i = 0; i < liczbaGalezi; i++) {
        int wysokosc = wysokoscPierwszejGalazki + i;
        rysujGalaz(wysokosc, szerokoscStartowa);
    }

    rysujPien(liczbaGalezi, szerokoscStartowa);

    return 0;
}