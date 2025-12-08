#include <iostream>
#include <string>

using namespace std;

class Robo {
    public:
    string nome;
    int bateria;

    void apresentar(){
        cout<<"Ola, eu sou o "<<nome<<endl;
        cout<<"Minha bateria está em "<<bateria<<"%"<<endl;
    }
};

int main(){
    Robo r1;

    r1.nome    = "Exterminador";
    r1.bateria = 80;
    cout<<"Primeiro Robô:"<<endl;
    r1.apresentar();

    Robo r2;

    r2.nome  = "R2D2";
    r2.bateria = 40;
    cout<<"Segundo Robô:"<<endl;
    r2.apresentar();

    return 0;
}