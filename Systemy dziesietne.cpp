#include <iostream> // tu daje bibloteke co wypisuje i wczytuje
#include <fstream> // bibloteka do plikow
#include <string> // bibloteka do tekstow

using namespace std; // zeby nie pisac std:: caly czas

bool pierwszaostatnia(const string& liczba) { // sprawdza czy 1 i ostatnia cyfra taka sama
    return liczba[0] == liczba[liczba.length() - 1]; // porownuje pierwsza i ostatnia litere
}

bool rosnaca(const string& liczba) { // sprawdza czy cyfry rosna
    for (size_t i = 1; i < liczba.length(); i++) { // petla po kazdej literze oprocz pierwszej
        if (liczba[i] < liczba[i-1]) return false; // jak mniejsza to nie rosnaca
    }
    return true; // jak przeszlo to znaczy ze rosnie
}

int osemkowynadziesietny(const string& osemkowy) { // zamienia z 8-kowego na 10-kowy
    int dziesietny = 0; // zaczynamy od 0
    for (char cyfra : osemkowy) { // petla po kazdej cyfrze
        dziesietny = dziesietny * 8 + (cyfra - '0'); // przelicza na 10-kowy
    }
    return dziesietny; // zwraca wynik
}

string dziesietnynastring(int dziesietny) { // zamienia liczbe na tekst
    string wynik; // tu bedzie wynik
    while (dziesietny > 0) { // dopoki liczba wieksza od 0
        wynik = char('0' + (dziesietny % 10)) + wynik; // dodaje reszte z dzielenia na poczatek
        dziesietny /= 10; // zmniejsza liczbe
    }
    return wynik.empty() ? "0" : wynik; // jak nic nie ma to zwraca "0"
}

int main() { // glowny program
    ifstream plik("dane.txt"); // otwiera plik
    if (!plik.is_open()) { // sprawdza czy sie otworzyl
        cout << "nie mozna otworzyc pliku" << endl; // blad jak nie mozna otworzyc
        return 1; // konczy program z bledem
    }

    int liczbaosemkowych = 0; // liczy ile liczb osiemkowych pasuje
    int liczbadziesietnych = 0; // liczy ile dziesietnych pasuje
    int liczbarosnacych = 0; // liczy ile rosnacych
    int minrosnaca = -1; // najmniejsza rosnaca liczba
    int maxrosnaca = -1; // najwieksza rosnaca liczba
    string liczba; // tu bedzie przechowywana liczba

    while (getline(plik, liczba)) { // czyta linie z pliku
        if (pierwszaostatnia(liczba)) { // jak pierwsza i ostatnia cyfra taka sama
            liczbaosemkowych++; // zwieksza licznik
        }

        int dziesietny = osemkowynadziesietny(liczba); // zamienia na 10-kowy
        string dziesietnystr = dziesietnynastring(dziesietny); // zamienia na tekst
        if (pierwszaostatnia(dziesietnystr)) { // jak pierwsza i ostatnia taka sama w 10-kowym
            liczbadziesietnych++; // zwieksza licznik
        }

        if (rosnaca(liczba)) { // jak cyfry rosnace
            liczbarosnacych++; // zwieksza licznik
            int wartosc = osemkowynadziesietny(liczba); // zamienia na 10-kowy
            if (minrosnaca == -1 || wartosc < minrosnaca) minrosnaca = wartosc; // sprawdza min
            if (maxrosnaca == -1 || wartosc > maxrosnaca) maxrosnaca = wartosc; // sprawdza max
        }
    }

    cout << "a) liczby z taka sama pierwsza i ostatnia cyfra (osemkowe): " << liczbaosemkowych << endl; // wypisuje wynik
    cout << "b) liczby z taka sama pierwsza i ostatnia cyfra (dziesietne): " << liczbadziesietnych << endl; // wypisuje wynik
    cout << "c) liczby z rosnacymi cyframi: " << liczbarosnacych << endl; // wypisuje wynik
    if (liczbarosnacych > 0) { // jak sa liczby rosnace
        cout << "   minimum: " << minrosnaca << endl; // wypisuje najmniejsza
        cout << "   maksimum: " << maxrosnaca << endl; // wypisuje najwieksza
    }

    plik.close(); // zamyka plik
    return 0; // koniec programu
}
