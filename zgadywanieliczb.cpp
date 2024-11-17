#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string player1, player2;
    cout << "Witaj w grze o zgadywaniu liczb" << endl << endl;
    cout << "Gra ma 4 rundy" << endl;
    cout << "Macie 10 prób na zgadnięcie liczby" << endl;
    cout << "Jeśli jej nie odgadniecie, to jest remis" << endl;
    cout << "" << endl << endl;
    cout << "Podaj nick 1 gracza: " << endl; 
    cin >> player1; 
    cout << "Podaj nick 2 gracza: " << endl; 
    cin >> player2; 
    cout << "" << endl;
    cout << "EMOCJE JAK NA GRZYBOBRANIU" << endl;
    cout << "ZACZYNAMY ZAWODY E-Sportowe!!!" << endl;
    
    int score1 = 0, score2 = 0; 
    
    srand(time(0));  
    
    // Rozpoczęcie gry
    for (int round = 0; round < 4; round++) {
        cout << "" << endl;
        cout << "Runda " << round + 1 << endl;
        cout << "" << endl;
        
        // Generowanie sekretnej liczby na każdą rundę
        int secretNumber = rand() % 100 + 1;
        
        // 10 prób zgadywania
        for (int i = 0; i < 10; i++) {
            int guess;
            
            // Gracz 1 zgaduje
            cout << "Zgaduję: " << player1 << endl;
            cin >> guess; 
            if (guess == secretNumber) {
                score1++;
                cout << "Brawo! " << player1 << " odgadł liczbę!" << endl;
                break;  // Kończymy rundę, jeśli gracz odgadł
            } else if (guess > secretNumber) {
                cout << "Sekretna liczba jest mniejsza od " << guess << endl;
            } else {
                cout << "Sekretna liczba jest większa od " << guess << endl;
            }
            
            // Gracz 2 zgaduje
            cout << "Zgaduję: " << player2 << endl;
            cin >> guess; 
            if (guess == secretNumber) {
                score2++;
                cout << "Brawo! " << player2 << " odgadł liczbę!" << endl;
                break;  // Kończymy rundę, jeśli gracz odgadł
            } else if (guess > secretNumber) {
                cout << "Sekretna liczba jest mniejsza od " << guess << endl;
            } else {
                cout << "Sekretna liczba jest większa od " << guess << endl;
            }
        }
    }

    // Wyświetlanie wyników końcowych
    cout << "Wyniki: " << endl;
    cout << player1 << " zdobył " << score1 << " punktów" << endl;
    cout << player2 << " zdobył " << score2 << " punktów" << endl;
    cout << "Wyniki: " << endl;
    
    // Decyzja o zwycięzcy
    if (score1 > score2) {
        cout << "WIELKI TURNIEJ O 0 ZŁ WYGRYWA " << player1 << "!" << endl;
    } 
    else if (score1 < score2) {
        cout << "WIELKI TURNIEJ O 0 ZŁ WYGRYWA " << player2 << "!" << endl;
    } 
    else {
        cout << "GRA ZAKOŃCZYŁA SIĘ REMISEM!" << endl;
    }

    return 0;
}
