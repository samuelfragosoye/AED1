#include <iostream>
#include <string>
using namespace std;

class Carta {
    private:
        string valorBruto;
        char naipeBruto;
        int valorNumerico;
    public:
        Carta(string entrada){
            naipeBruto = entrada.back();
            valorBruto = entrada.substr(0, entrada.length()-1);

            if(valorBruto == "A"){
                valorNumerico = 1;
            } else if(valorBruto == "J"){
                valorNumerico = 11;
            } else if(valorBruto == "Q"){
                valorNumerico = 12;
            } else if(valorBruto == "K"){
                valorNumerico = 13;
            } else {
                valorNumerico = stoi(valorBruto);
            }
        }
        
        int getValor(){
            return valorNumerico;
        }

        string getValorBruto(){
            return valorBruto;
        }

        char getNaipe(){
            return naipeBruto;
        }
};

int main(){
    int n;
    cin >> n;

    int soma = 0;
    int contadorAs = 0;

    for(int i = 0; i<n; i++){
        string entrada;
        cin >> entrada;

        Carta carta(entrada);
        soma += carta.getValor();
    }

    if (soma == 21){
        cout << soma << endl;
    } else {
        cout << "A soma não é 21" << endl;
    }
    return 0;
}