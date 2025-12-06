#include <iostream>
#include <string>
using namespace std;

class Carta {
    private:
        string valorBruto;
        char naipeBruto;
    public:
        Carta(string entrada){
            naipeBruto = entrada.back();
            valorBruto = entrada.substr(0, entrada.length()-1);
        }
        
        string getDescricao(){
            string nomeValor;
            string nomeNaipe;

            if(valorBruto == "1"){
                nomeValor = "as";
            } else if(valorBruto == "J"){
                nomeValor = "valete";
            } else if (valorBruto == "Q"){
                nomeValor = "dama";
            } else if (valorBruto == "K"){
                nomeValor = "rei";
            } else {
                nomeValor = valorBruto;
            }

            switch(naipeBruto){
                case 'C': nomeNaipe = "paus";         break;
                case 'D': nomeNaipe = "ouros";        break;
                case 'H': nomeNaipe = "copas";        break;
                case 'S': nomeNaipe = "espadas";      break;

                default:  nomeNaipe = "desconhecido"; break;
            }
            if (naipeBruto == '@'){
                return "coringa";
            }
            return nomeValor + "_de_" + nomeNaipe;
        }
};

int main(){
    string entrada;

    while(cin >> entrada){
        Carta carta(entrada);
        cout << carta.getDescricao() << endl;
    }
    return 0;
}