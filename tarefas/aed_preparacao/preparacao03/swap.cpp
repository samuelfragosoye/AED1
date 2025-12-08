#include <iostream>
#include "estudo2.hpp"

using namespace std;

void pause(string text)
{
    string dummy;
    cin.clear();
    cout << endl << text;
    cin.ignore();
    getline(cin, dummy);
    cout << endl << endl;
}

int main(){
    cout << "=== TESTE DE INVERSAO DE INTERVALO ===\n" << endl;

    Array a(6);
    
    for (int i = 0; i<6; i++){
        a.set(i, (i+1)*10);
    }

    cout<<"Original: ";
    a.print();

    cout<<"invertendo intervalo [1,4]"<<endl;
    a.reverseInterval(1,4);

    cout<<"Resultado: ";
    a.print();

    return 0;
}