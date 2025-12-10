#include <iostream>
using namespace std;

class Array {
    private:
    int length;
    int* dados;

    public:
    Array(int n){
        length = n;
        dados  = new int[length];
    }

    ~Array(){
        if(dados != nullptr) delete[] dados;
    }

    void set(int index, int value){
        if(index >= 0 && index < length) dados[index] = value;
    }

    void print(){
        cout << "[ ";
        for (int i = 0; i<length; i++){
            cout<<dados[i]<<" ";
        }
        cout<<"]"<<endl;
    }

    void reverseInterval(int inicio, int fim){
        if(dados == nullptr || fim >= length || inicio > fim || inicio<0)
        { cout << "Intervalo invalido"<<endl;
            return;
        } else {
            int i = inicio;
            int f = fim;

            while (i < f){
                int temp = dados[i];
                dados[i] = dados[f];
                dados[f] = temp; 
                i++;
                f--;
            }
        }   
    }
};