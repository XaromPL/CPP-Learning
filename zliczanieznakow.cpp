#include <iostream>
using namespace std;

int main() {
    double liczba;
    double suma = 0;
    double maxLiczba = 0;
    double minLiczba = 0;
    int liczbaLiczb = 0;
    bool pierwszaLiczba = true;

    cout << "Wprowadzaj liczby (wprowadź 0 aby zakończyć):\n";

    while (true) {
        cout << "Podaj liczbę: ";
        cin >> liczba;

        if (liczba == 0) {
            break;  
        }


        suma += liczba;
        liczbaLiczb++;

        if (pierwszaLiczba) {
            maxLiczba = liczba;
            minLiczba = liczba;
            pierwszaLiczba = false;
        } else {
            if (liczba > maxLiczba) {
                maxLiczba = liczba;
            }
            if (liczba < minLiczba) {
                minLiczba = liczba;
            }
        }
    }

    if (liczbaLiczb > 0) {
        double srednia = suma / liczbaLiczb;

        cout << "Liczba wprowadzonych liczb: " << liczbaLiczb << endl;
        cout << "Największa liczba: " << maxLiczba << endl;
        cout << "Najmniejsza liczba: " << minLiczba << endl;
        cout << "Suma liczb: " << suma << endl;
        cout << "Średnia: " << srednia << endl;
    } else {
        cout << "Nie wprowadzono żadnych liczb." << endl;
    }

    return 0;
}
