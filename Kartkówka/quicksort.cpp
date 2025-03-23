#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void quicksort(int *tablica, int lewy, int prawy) {
    int v = tablica[(lewy + prawy) / 2];
    int i = lewy, j = prawy, x;

    do {
        while (tablica[i] < v) i++;
        while (tablica[j] > v) j--;
        if (i <= j) {
            x = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = x;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > lewy) quicksort(tablica, lewy, j);
    if (i < prawy) quicksort(tablica, i, prawy);
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

    quicksort(tablica, 0, ile - 1);
    
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