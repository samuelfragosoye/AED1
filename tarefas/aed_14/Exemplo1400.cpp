/*
 * Exemplo1400 - v0.0. - 22 / 11 / 2025
 * Author: Samuel Fragoso
 */

// ----------------------------------------------- classes
#include "MyString.hpp"

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

void method_00()
{
}

/**
 * Testar getInt().
 */
void method_01()
{
    cout << "\nMethod_01 - v0.0\n" << endl;
    
    MyString s1("123");
    MyString s2("-456");
    MyString s3("12a3"); // invalido

    cout << "s1 (" << s1.getConteudo() << ") -> int: " << s1.getInt() << endl;
    cout << "s2 (" << s2.getConteudo() << ") -> int: " << s2.getInt() << endl;
    cout << "s3 (" << s3.getConteudo() << ") -> int: " << s3.getInt() << " (Erro esperado: -1)" << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Testar getDouble().
 */
void method_02()
{
    cout << "\nMethod_02 - v0.0\n" << endl;
    
    MyString s1("123.45");
    MyString s2("-0.05");
    MyString s3("abc");

    cout << "s1 (" << s1.getConteudo() << ") -> double: " << s1.getDouble() << endl;
    cout << "s2 (" << s2.getConteudo() << ") -> double: " << s2.getDouble() << endl;
    cout << "s3 (" << s3.getConteudo() << ") -> double: " << s3.getDouble() << " (Erro esperado: 0.0)" << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Testar getBoolean().
 */
void method_03()
{
    cout << "\nMethod_03 - v0.0\n" << endl;

    MyString s1("true");
    MyString s2("F");
    MyString s3("banana");

    cout << boolalpha; // imprimir true/false ao inves de 1/0
    cout << "s1 (" << s1.getConteudo() << ") -> bool: " << s1.getBoolean() << endl;
    cout << "s2 (" << s2.getConteudo() << ") -> bool: " << s2.getBoolean() << endl;
    cout << "s3 (" << s3.getConteudo() << ") -> bool: " << s3.getBoolean() << endl;
    
    if (s3.hasErro()) cout << "s3 gerou erro de conversao." << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Testar contains().
 */
void method_04()
{
    cout << "\nMethod_04 - v0.0\n" << endl;

    MyString s("Batata Frita");
    
    cout << "Texto: " << s.getConteudo() << endl;
    cout << "Contem 'Frita'? " << (s.contains("Frita") ? "Sim" : "Nao") << endl;
    cout << "Contem 'Cozida'? " << (s.contains("Cozida") ? "Sim" : "Nao") << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Testar toUpperCase() e toLowerCase().
 */
void method_05()
{
    cout << "\nMethod_05 - v0.0\n" << endl;

    MyString s("AbCdEfG");

    cout << "Original: " << s.getConteudo() << endl;
    cout << "Upper: " << s.toUpperCase() << endl;
    cout << "Lower: " << s.toLowerCase() << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Testar replace().
 */
void method_06()
{
    cout << "\nMethod_06 - v0.0\n" << endl;

    MyString s("banana");
    cout << "Original: " << s.getConteudo() << endl;
    cout << "Trocar 'a' por 'o': " << s.replace('a', 'o') << endl;
    cout << "Trocar 'z' por 'x' (inexistente): " << s.replace('z', 'x') << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Testar encrypt() e decrypt() (Cifra de Cesar).
 */
void method_07()
{
    cout << "\nMethod_07 - v0.0\n" << endl;

    MyString s("ABCxyz");
    cout << "Original: " << s.getConteudo() << endl;
    
    MyString codificado(s.encrypt());
    cout << "Cifrado (+3): " << codificado.getConteudo() << endl;
    
    cout << "Decifrado: " << codificado.decrypt() << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Testar split() (Espacos).
 */
void method_08()
{
    cout << "\nMethod_08 - v0.0\n" << endl;

    MyString s("O rato roeu a roupa");
    string palavras[10];
    int qtd = s.split(palavras);

    cout << "Frase: " << s.getConteudo() << endl;
    cout << "Palavras encontradas (" << qtd << "):" << endl;
    
    for (int i = 0; i < qtd; i++)
    {
        cout << "[" << i << "]: " << palavras[i] << endl;
    }

    pause("Apertar ENTER para continuar");
}

/**
 * Testar split() com delimitador (Extra 1).
 */
void method_09()
{
    cout << "\nMethod_09 - v0.0\n" << endl;

    MyString s("user;id;email;senha");
    string campos[10];
    int qtd = s.split(campos, ';'); // Split por ponto e virgula

    cout << "CSV: " << s.getConteudo() << endl;
    cout << "Campos encontrados (" << qtd << "):" << endl;
    
    for (int i = 0; i < qtd; i++)
    {
        cout << "[" << i << "]: " << campos[i] << endl;
    }

    pause("Apertar ENTER para continuar");
}

/**
 * Testar reverse() (Extra 2).
 */
void method_10()
{
    cout << "\nMethod_10 - v0.0\n" << endl;

    MyString s("Roma");
    cout << "Original: " << s.getConteudo() << endl;
    cout << "Invertido: " << s.reverse() << endl;

    pause("Apertar ENTER para continuar");
}

int main(int argc, char **argv)
{
    int x = 0;

    do
    {
        cout << "EXEMPLO1400 - Programa - v0.0\n" << endl;

        cout << "Opcoes:" << endl;
        cout << " 0 - parar" << endl;
        cout << " 1 - Method_01 (Testar getInt)" << endl;
        cout << " 2 - Method_02 (Testar getDouble)" << endl;
        cout << " 3 - Method_03 (Testar getBoolean)" << endl;
        cout << " 4 - Method_04 (Testar contains)" << endl;
        cout << " 5 - Method_05 (Testar toUpper/Lower)" << endl;
        cout << " 6 - Method_06 (Testar replace)" << endl;
        cout << " 7 - Method_07 (Testar Cifra de Cesar)" << endl;
        cout << " 8 - Method_08 (Testar split espaco)" << endl;
        cout << " 9 - Method_09 (Testar split delimitador - E1)" << endl;
        cout << "10 - Method_10 (Testar reverse - E2)" << endl;

        cout << endl << "Entrar com uma opcao: ";
        cin >> x;
        cin.ignore(1000, '\n');

        switch (x)
        {
        case 0:
            method_00();
            break;
        case 1:
            method_01();
            /*
            Method_01 - v0.0

            s1 (123) -> int: 123
            s2 (-456) -> int: -456
            s3 (12a3) -> int: -1 (Erro esperado: -1)

            Apertar ENTER para continuar
            */
            break;
        case 2:
            method_02();
            /*
            Method_02 - v0.0

            s1 (123.45) -> double: 123.45
            s2 (-0.05) -> double: -0.05
            s3 (abc) -> double: 0 (Erro esperado: 0.0)

            Apertar ENTER para continuar
            */
            break;
        case 3:
            method_03();
            /*
            Method_03 - v0.0

            s1 (true) -> bool: true
            s2 (F) -> bool: false
            s3 (banana) -> bool: false
            s3 gerou erro de conversao.

            Apertar ENTER para continuar
            */
            break;
        case 4:
            method_04();
            /*
            Method_04 - v0.0

            Texto: Batata Frita
            Contem 'Frita'? Sim
            Contem 'Cozida'? Nao

            Apertar ENTER para continuar
            */
            break;
        case 5:
            method_05();
            /*
            Method_05 - v0.0

            Original: AbCdEfG
            Upper: ABCDEFG
            Lower: abcdefg

            Apertar ENTER para continuar
            */
            break;
        case 6:
            method_06();
            /*
            Method_06 - v0.0

            Original: banana
            Trocar 'a' por 'o': bonono
            Trocar 'z' por 'x' (inexistente): banana

            Apertar ENTER para continuar
            */
            break;
        case 7:
            method_07();
            /*
            Method_07 - v0.0

            Original: ABCxyz
            Cifrado (+3): DEFabc
            Decifrado: ABCxyz

            Apertar ENTER para continuar
            */
            break;
        case 8:
            method_08();
            /*
            Method_08 - v0.0

            Frase: O rato roeu a roupa
            Palavras encontradas (5):
            [0]: O
            [1]: rato
            [2]: roeu
            [3]: a
            [4]: roupa

            Apertar ENTER para continuar
            */
            break;
        case 9:
            method_09();
            /*
            Method_09 - v0.0

            CSV: user;id;email;senha
            Campos encontrados (4):
            [0]: user
            [1]: id
            [2]: email
            [3]: senha

            Apertar ENTER para continuar
            */
            break;
        case 10:
            method_10();
            /*
            Method_10 - v0.0

            Original: Roma
            Invertido: amoR

            Apertar ENTER para continuar
            */
            break;
        default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } 
    } while (x != 0);

    pause("Apertar ENTER para terminar");
    return (0);
}