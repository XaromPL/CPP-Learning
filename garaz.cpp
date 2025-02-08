#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

//LOSOWANIE MASY POJAZDU
int pojazdy() {
    srand(time(0));
    int masa = rand() % 15 + 1;
    return masa;
}

//MENU
int menu() {
    cout << "1. Wjazd pojazdu" << endl;
    cout << "2. Wyjazd pojazdu" << endl;
    cout << "3. Wizualizacja" << endl;
    cout << "4. Bilans" << endl;
    cout << "5. Restart" << endl;
    int wybor = 0;
    cout << "Co chcesz zrobic? ";
    cin >> wybor;
    return wybor;
}

//WIZUALIZACJA
void wizualizacja(int parking[3][10]) {
    cout << "Wizualizacja parkingu:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Poziom " << i + 1 << ": ";
        for (int j = 0; j < 10; j++) {
            if (parking[i][j] == 1) {
                cout << "[X] "; // Zajete miejsce
            } else {
                cout << "[ ] "; // Wolne miejsce
            }
        }
        cout << endl;
    }
}

//WYJAZD POJAZDU
void wyjazd(int parking[3][10], double& zarobki) {
    int poziom, miejsce;
    cout << "Podaj poziom (1-3): ";
    cin >> poziom;
    cout << "Podaj miejsce (1-10): ";
    cin >> miejsce;

    if (poziom < 1 || poziom > 3 || miejsce < 1 || miejsce > 10 || parking[poziom - 1][miejsce - 1] == 0) {
        cout << "To miejsce jest puste lub nie istnieje!" << endl;
    } else {
        parking[poziom - 1][miejsce - 1] = 0; // Zwolnienie miejsca

        int godziny;
        cout << "Podaj ile godzin pojazd byl na parkingu: ";
        cin >> godziny;

        int masa_pojazdu = pojazdy();
        double koszt = 0;

        if (masa_pojazdu <= 3) {
            koszt = 5 * godziny; // 5 zł za godzinę dla pojazdów do 3 ton
        } else if (masa_pojazdu > 3 && masa_pojazdu <= 5) {
            koszt = 10 * godziny; // 10 zł za godzinę dla pojazdów powyżej 3 ton i do 5 ton
        } else {
            koszt = 15 * godziny; // 15 zł za godzinę dla pojazdów powyżej 5 ton
        }

        zarobki += koszt;

        cout << "Pojazd wyjechal z miejsca: " << miejsce << " na poziomie " << poziom << endl;
        cout << "Czas parkowania: " << godziny << " godzin." << endl;
        cout << "Koszt parkowania: " << koszt << " zl." << endl;
        cout << "Samochod stal na pietrze " << poziom << ", miejscu " << miejsce << endl;
    }
}

//BILANS
void bilans(double zarobki, int liczba_obsluzonych_aut) {
    cout << "Bilans: " << endl;
    cout << "Zarobki: " << zarobki << " zl" << endl;
    cout << "Liczba obsluzonych aut: " << liczba_obsluzonych_aut << endl;
}

int main() {
    int parking[3][10] = {};  
    double zarobki = 0;
    int liczba_obsluzonych_aut = 0;

    while (true) {
        int wybor = menu();

        if (wybor == 1) { // Wjazd pojazdu
            system("cls");
            cout << "Oczekiwanie na wjazd pojazdu:" << endl;
            int czas_oczekiwania = rand() % 4 + 2;
            Sleep(czas_oczekiwania * 1000);

            cout << "Pojazd czeka przed szlabanem." << endl;
            cout << "Masa pojazdu: " << pojazdy() << endl;
            cout << "Na ktory poziom chcesz wjechac (1-3): " << endl;
            int poziom = 0;
            int miejsce = 0;

            int masa_pojazdu = pojazdy();
            if (masa_pojazdu <= 3) {
                poziom = 3;
            } else if (masa_pojazdu > 3 && masa_pojazdu <= 5) {
                poziom = 2;
            } else {
                poziom = 1;
            }

            cout << "Pojazd wjezdza na poziom " << poziom << endl;
            cout << "Na ktore miejsce (1-10): ";
            cin >> miejsce;
            if (miejsce < 1 || miejsce > 10 || parking[poziom - 1][miejsce - 1] == 1) {
                cout << "Miejsce jest zajete lub niepoprawne!" << endl;
                continue;
            }

            parking[poziom - 1][miejsce - 1] = 1; 

            cout << "Pojazd zajal miejsce na poziomie " << poziom << ", miejscu " << miejsce << endl;
            liczba_obsluzonych_aut++;

        } else if (wybor == 2) { // Wyjazd pojazdu
            system("cls");
            wyjazd(parking, zarobki);
        } else if (wybor == 3) { // Wizualizacja
            system("cls");
            wizualizacja(parking);
        } else if (wybor == 4) { // Bilans
            system("cls");
            bilans(zarobki, liczba_obsluzonych_aut);
        } else if (wybor == 5) { // Restart
            system("cls");
            cout << "Restartowanie programu..." << endl;
            zarobki = 0;
            liczba_obsluzonych_aut = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 10; j++) {
                    parking[i][j] = 0;
                }
            }
        }
    }
}
