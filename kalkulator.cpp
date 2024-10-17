#include<iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y;
    char znak;
    cout << "Podaj pierwsza liczbe " << endl;
    cin >> x;
    cout << "Podaj druga liczbe " << endl;
    cin >> y;
    cout << "Wybierz dzialanie ktore chcesz wykonac *, ^, /, -, +, >, # (pierwiastkowanie), %: " << endl;
    cin >> znak;
    switch (znak)
    {
    case '*':
        cout << "Wynik to: " << x * y << endl;
        break;
    case '-':
        cout << "Wynik to: " << x - y << endl;
        break;
    case '+':
        cout << "Wynik to: " << x + y << endl;
        break;
    case '%':
        cout << "Wynik to: " << (int)x % (int)y << endl;
        break;
    case '^':
        cout << "Wynik to: " << pow(x, y) << endl;
        break;
    case '>':
        cout << (x > y ? "Pierwsza liczba jest wieksza." : "Druga liczba jest wieksza.") << endl;
        break;
    case '#':
        cout << "Pierwiastek z pierwszej liczby to: " << sqrt((int)x) << endl << "Pierwiastek z drugiej liczby to: " << sqrt((int)y) << endl;
        break;
    case '/':
        cout << "Wymik to: " << x/y << endl;
        break;
    default:
        cout << "To nie jest znak dzialania!" << endl;
        break;
    
    
    }
    return 0;
}