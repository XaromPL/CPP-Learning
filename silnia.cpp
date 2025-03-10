    #include <iostream>
    using namespace std;

    long long int silnia(int n)
    {
        if (n == 0 ) return 1;
        else return n*silnia(n-1);

    }

    long long int silnia2(int n) {
        long long int wynik = 1;
        for (int i = 1; i <= n; i++) {
            wynik *= i;
        }
        return wynik;
    }


    int main() {
    cout << silnia(49) << endl;
    cout << silnia2(49) << endl;
    }
