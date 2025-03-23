#include <iostream>
using namespace std;

long int fib(int n) {
    if (n == 1 || n == 2) return 1;
    else return fib(n - 1) + fib(n - 2);
}

int main() {
    cout << fib(20) << endl;
    cin.get(); 
    return 0;
}

