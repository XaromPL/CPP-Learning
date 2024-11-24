#include <iostream>
using namespace std;

int wysokosc;

int main() {
    cout << "Podaj wysokosc trojkata strzalki: "; 
    cin >> wysokosc;
    cout << "" << endl; 

    
    
    for(int i = 0; i<wysokosc; i++)
    {
        for(int y = wysokosc; y > i ; y--)
        {
            cout << " ";
        }
        
        for (int x = 0; x <= i; x++)
        {
            cout << "*";
        }
        
        for (int z = 0; z <= i - 1; z++)
        {
            cout << "*";
        }
        cout << "" << endl; 
    }
    
    for(int i = 0; i < wysokosc; i++)
    {
        for(int y = wysokosc / 2;  y >= 0; y--)
        {
            cout << " ";
        }
        for(int x = wysokosc; x > 0; x--)
        cout << "*";
        cout << "" << endl;
    }
    
    for(int i = 0; i < wysokosc; i++)
    {
        for(int y = wysokosc; y > i ; y--)
        {
            cout << "*";
        }
        
        for (int x = 0; x <= i; x++)
        {
            cout << " ";
        }
        
        for (int z = 0; z <= i - 1; z++)
        {
            cout << " ";
        }
        
        for(int y = wysokosc; y > i ; y--)
        {
            cout << "*";
        }
        
        
        
        cout << endl;
        
    }
    return 0;
}
