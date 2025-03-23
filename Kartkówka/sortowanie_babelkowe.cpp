#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void sortowanie_babelkowe(int *tab, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= 1; j--) {
            if (tab[j] < tab[j - 1]) {
                int bufor = tab[j - 1];
                tab[j - 1] = tab[j];
                tab[j] = bufor;
            }
        }
    }
}

int main() {
    int ile = 0;
    cout << "Ile losowych liczb dac?:" << endl;
    cin >> ile;
    
    if (ile <= 0) {  
        cout << "Liczba musi być większa od 0!" << endl;
        return 1;
    }

    int *tablica = new int[ile]; 

    srand(time(NULL)); 

    for (int i = 0; i < ile; i++) {
        tablica[i] = rand() % 100 + 1;
        cout << tablica[i] << " ";
    }

    cout << endl;

    sortowanie_babelkowe(tablica, ile);

    cout << "Posortowane liczby:" << endl;
    for (int i = 0; i < ile; i++) {  
        cout << tablica[i] << " ";
    }
    cout << endl;

    delete[] tablica;
    cin.get();
    cin.get();
    return 0;
}