/*
   Exemplo1600 - v0.0. 30/11/2025
   Autor: Samuel Fragoso
*/
#include <iostream>
#include "Arrays.hpp"

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
/**
 * Method_00
 */
void method_00 (){
    //nao faz nada
}

/**
 * Method_01 - Testar definicoes da classe
 */
void method_01 (){
    cout << "\nMethod_01 - v0.0\n" << endl;

    ref_intArray a1 = nullptr;

    a1 = Arrays::array_push_back(a1, 10);
    a1 = Arrays::array_push_back(a1, 20);
    a1 = Arrays::array_push_back(a1, 30);

    cout << "Arranjo apos insercoes: ";
    Arrays::array_print(a1);
    cout << endl;

    delete[] a1;
    pause("Aperte ENTER para continuar");
}

/**
 * Method 02 - Teste array_pop_back.
 */
void method_02(){
    cout << "\nMethod_02 - v0.0\n" << endl;

    int dados[] = {3,1,2,3};
    ref_intArray a1 = new int [4];
    for(int i=0; i<4; i++) a1[i] = dados[i];

    cout<<"Original: ";
    Arrays::array_print(a1);
    cout << endl;
    
    ref_intArray a2 = Arrays::array_pop_back(a1);

    cout<<"Apos pop_back: ";
    Arrays::array_print(a2);
    cout<<endl;

    delete[] a1;
    delete[] a2;
    pause("Aperte ENTER para continuar");
}

/**
 * Method 03 - Testar array_push_front
 */
void method_03(){
    cout << "\nMethod_03 - v0.0\n" << endl;

    ref_intArray a1 = nullptr;
    a1 = Arrays::array_push_front(10, a1);
    a1 = Arrays::array_push_front(20, a1);

    cout<<"Apos push_fronts: ";
    Arrays::array_print(a1);
    cout<<endl;

    delete[] a1;
    pause("Aperte ENTER para continuar");
}

/**
 * Method 04 - Testar array_pop_front
 */
void method_04(){
    cout << "\nMethod_04 - v0.0\n" << endl;

    int dados[] = {3,10,20,30};
    ref_intArray a1 = new int[4];
    for(int i=0; i<4; i++) a1[i] = dados[i];

    cout<<"Original: ";
    Arrays::array_print(a1);
    cout<<endl;

    ref_intArray a2 = Arrays::array_pop_front(a1);

    cout << "Apos pop_front: ";
    Arrays::array_print(a2);
    cout<<endl;

    delete[] a1;
    delete[] a2;
    pause("Aperte Enter para continuar");
}

/**
 * Method 05 - Testar array_push_mid
 */
void method_05(){
    cout << "\nMethod_05 - v0.0\n" <<endl;

    int dados[] = {4,1,2,4,5};
    ref_intArray a1 = new int[5];
    for(int i=0; i<5; i++) a1[i] = dados[i];

    cout<<"Original: ";
    Arrays::array_print(a1);
    cout<<endl;

    ref_intArray a2 = Arrays::array_push_mid(a1,3);

    cout<<"Apos push_mid(3): ";
    Arrays::array_print(a2);
    cout<<endl;

    delete[] a1;
    delete[] a2;
    pause("Aperte ENTER para continuar");
}

/**
 * Method 06 - Testar array_pop_mid
 */
void method_06(){
    cout << "\nMethod_06 - V0.0\n"<<endl;
    
    int dados[] = {5,1,2,99,3,4};
    ref_intArray a1 = new int[6];
    for(int i=0; i<6; i++) a1[i] = dados[i];

    cout << "Original: ";
    Arrays::array_print(a1);
    cout<<endl;

    ref_intArray a2 = Arrays::array_pop_mid(a1);

    cout<<"Apos pop_mid: ";
    Arrays::array_print(a2);
    cout << endl;

    delete[] a1;
    delete[] a2;
    pause("Aperte ENTER para continuar");
}

/**
 * Method 07 - Testar intArray_cmp
 */
void method_07(){
    cout << "\nMethod_07 - v0.0\n" << endl;

    int d1[] = {3,10,20,30};
    int d2[] = {3,10,20,30};
    int d3[] = {3,10,25,30};

    ref_intArray p = new int[4]; for(int i=0; i<4; i++) p[i] = d1[i];
    ref_intArray q = new int[4]; for(int i=0; i<4; i++) q[i] = d2[i];
    ref_intArray r = new int[4]; for(int i=0; i<4; i++) r[i] = d3[i];

    cout << "Comparar iguais (p, q): "<< Arrays::intArray_cmp(p, q) << endl;
    cout << "Comparar diferentes (p, r): "<< Arrays::intArray_cmp(p, r) << endl;

    delete[] p; delete[] q; delete[] r;
    pause ("Aperte ENTER para continuar");
}

/**
 * Method 08 - Testar intArray_append
 */
void method_08(){
    cout << "\nMethod_08 - v0.0\n" << endl;

    int d1[] = {2,1,2};
    int d2[] = {2,3,4};
    ref_intArray p = new int[3]; for(int i=0; i<3; i++) p[i] = d1[i];
    ref_intArray q = new int[3]; for(int i=0; i<3; i++) p[i] = d2[i];

    ref_intArray uniao = Arrays::intArray_append(p,q);

    cout << "Uniao: ";
    Arrays::array_print(uniao);
    cout<<endl;

    delete[] p; delete[] q; delete[] uniao;
    pause("Aperte ENTER para continuar");
}

/**
 * Method 09 - Testar intArray_seek
 */
void method_09(){
    cout << "\nMethod_09 - v0.0\n" << endl;

    int d1[] = {4,10,20,30,40};
    ref_intArray p = new int[5]; for(int i=0; i<5; i++) p[i] = d1[i];

    ref_intArray res = Arrays::intArray_seek(p,30);

    if(res) cout << "Valor 30 encontrado" << endl;
    else cout << "Valor 30 nao encontrado" << endl;

    delete [] p;
    pause("Aperte ENTER para continuar");
}

/**
 * Method 10 - Testar intArray_sub
 */
void method_10 (){
    cout << "\nMethod_10 - v0.0\n" << endl;

    int d1[]={5,10,20,30,40,50};
    ref_intArray p = new int[6]; for(int i=0; i<6; i++) p[i] = d1[i];

    ref_intArray sub = Arrays::intArray_sub(p,1,3);

    cout<<"Original: "; Arrays::array_print(p); cout << endl;
    cout <<"Sub (start 1, size 3): "; Arrays::array_print(sub); cout<<endl;

    delete[] p; delete[] sub;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 11 - Testar E1 (Merge)
 */
void method_11(){
    cout << "\nMethod_11 - v0.0\n"<<endl;

    int d1[] = {3,1,3,5};
    int d2[] = {3,2,4,6};
    ref_intArray p = new int[4]; for(int i=0; i<4; i++) p[i] = d1[i];
    ref_intArray q = new int[4]; for(int i=0; i<4; i++) q[i] = d2[i];

    ref_intArray m = Arrays::intArray_merge(p,q);

    cout << "Merge: "; Arrays::array_print(m); cout << endl;

    delete[] p; delete[] q; delete[] m;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 12 - Testar E2 (Merge Down)
 */
void method_12(){
    cout << "\nMethod_12 - v0.0\n"<< endl;

    int d1[] = {2,10,30};
    int d2[] = {2,5,20};
    ref_intArray p = new int[3]; for (int i=0; i<3; i++) p[i] = d1[i]; 
    ref_intArray q = new int[3]; for (int i=0; i<3; i++) p[i] = d2[i]; 

    ref_intArray m = Arrays::intArray_mergeDown(p,q);

    cout << "Merge decrescente: "; Arrays::array_print(m); cout << endl;

    delete[] p; delete[] q; delete[] m;
    pause("Aperte ENTER para continuar");
}

//----------------- acao principal
/**
 * Funcao principal
 */
int main (int argc, char** argv){
    int x = 0;
    do{
        //identificar
        cout << "EXEMPLO1600 " << endl;

        //mostrar opcoes
        cout << "EXEMPLO1600 - Programa - v0.0\n" << endl;
        cout << "Opcoes:" << endl;
        cout << " 0 - parar" << endl;
        cout << " 1 - push_back" << endl;
        cout << " 2 - pop_back" << endl;
        cout << " 3 - push_front" << endl;
        cout << " 4 - pop_front" << endl;
        cout << " 5 - push_mid" << endl;
        cout << " 6 - pop_mid" << endl;
        cout << " 7 - cmp" << endl;
        cout << " 8 - append" << endl;
        cout << " 9 - seek" << endl;
        cout << "10 - sub" << endl;
        cout << "11 - merge (E1)" << endl;
        cout << "12 - mergeDown (E2)" << endl;

        //ler do teclado
        cout<<endl<<"Entrar com uma opcao:";
        cin >> x;

        //escolher acao
        switch (x)
        {
            case 0: method_00(); break;
            case 1: method_01();
                /*
                Method_01 - v0.0
                Arranjo apos insercoes: [ 10, 20, 30 ] (Tam: 3)
                Apertar ENTER para continuar
                */
                break;
            case 2: method_02();
                /*
                Method_02 - v0.0
                Original: [ 1, 2, 3 ] (Tam: 3)
                Apos pop_back: [ 1, 2 ] (Tam: 2)
                Apertar ENTER para continuar
                */
                break;
            case 3: method_03();
                /*
                Method_03 - v0.0
                Apos push_fronts: [ 20, 10 ] (Tam: 2)
                Apertar ENTER para continuar
                */
                break;
            case 4: method_04();
                /*
                Method_04 - v0.0
                Original: [ 10, 20, 30 ] (Tam: 3)
                Apos pop_front: [ 20, 30 ] (Tam: 2)
                Apertar ENTER para continuar
                */
                break;
            case 5: method_05();
                /*
                Method_05 - v0.0
                Original: [ 1, 2, 4, 5 ] (Tam: 4)
                Apos push_mid(3): [ 1, 2, 3, 4, 5 ] (Tam: 5)
                Apertar ENTER para continuar
                */
                break;
            case 6: method_06();
                /*
                Method_06 - v0.0
                Original: [ 1, 2, 99, 3, 4 ] (Tam: 5)
                Apos pop_mid: [ 1, 2, 3, 4 ] (Tam: 4)
                Apertar ENTER para continuar
                */
                break;
            case 7: method_07();
                /*
                Method_07 - v0.0
                Comparar iguais (p, q): 0
                Comparar diferentes (p, r): -5
                Apertar ENTER para continuar
                */
                break;
            case 8: method_08();
                /*
                Method_08 - v0.0
                Uniao: [ 1, 2, 3, 4 ] (Tam: 4)
                Apertar ENTER para continuar
                */
                break;
            case 9: method_09();
                /*
                Method_09 - v0.0
                Valor 30 encontrado.
                Apertar ENTER para continuar
                */
                break;
            case 10: method_10();
                /*
                Method_10 - v0.0
                Original: [ 10, 20, 30, 40, 50 ] (Tam: 5)
                Sub (start 1, size 3): [ 20, 30, 40 ] (Tam: 3)
                Apertar ENTER para continuar
                */
                break;
            case 11: method_11();
                /*
                Method_11 - v0.0
                Merge: [ 1, 2, 3, 4, 5, 6 ] (Tam: 6)
                Apertar ENTER para continuar
                */
                break;
            case 12: method_12();
                /*
                Method_12 - v0.0
                Merge Descrescente: [ 30, 20, 10, 5 ] (Tam: 4)
                Apertar ENTER para continuar
                */
                break;
            
            default:
            cout<<endl<<"ERRO: Valor invalido."<<endl;
        }
    }
    while (x != 0);

    //encerrar
    pause("Aperte ENTER para terminar");
    return (0);
}