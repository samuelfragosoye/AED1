/*
 * Exemplo1500 - v0.0. - 23 / 11 / 2025
 * Author: Samuel Fragoso
 */

#include <iostream>
#include "Strings.hpp"

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
 * Method 01 - Testar str_push_back.
 */
void method_01()
{
    cout << "\nMethod_01 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("abc"); // apenas para teste inicial
    char *s2 = Strings::str_push_back(s1, 'd');
    
    cout << "Original: " << s1 << endl;
    cout << "Apos push_back('d'): " << s2 << endl;

    delete[] s2; // Limpar memoria alocada
    pause("Apertar ENTER para continuar");
}

/**
 * Method 02 - Testar str_pop_back.
 */
void method_02()
{
    cout << "\nMethod_02 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("abc");
    char *s2 = Strings::str_pop_back(s1);

    cout << "Original: " << s1 << endl;
    cout << "Apos pop_back(): " << (s2 ? s2 : "null") << endl;

    delete[] s2;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 03 - Testar str_push_front.
 */
void method_03()
{
    cout << "\nMethod_03 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("abc");
    char *s2 = Strings::str_push_front('z', s1);

    cout << "Original: " << s1 << endl;
    cout << "Apos push_front('z'): " << s2 << endl;

    delete[] s2;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 04 - Testar str_pop_front.
 */
void method_04()
{
    cout << "\nMethod_04 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("abc");
    char *s2 = Strings::str_pop_front(s1);

    cout << "Original: " << s1 << endl;
    cout << "Apos pop_front(): " << (s2 ? s2 : "null") << endl;

    delete[] s2;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 05 - Testar str_push_mid.
 */
void method_05()
{
    cout << "\nMethod_05 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("abxy");
    char *s2 = Strings::str_push_mid(s1, 'M'); // Inserir no meio (len 4 -> index 2)

    cout << "Original: " << s1 << endl;
    cout << "Apos push_mid('M'): " << s2 << endl;

    delete[] s2;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 06 - Testar str_pop_mid.
 */
void method_06()
{
    cout << "\nMethod_06 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("abcde"); // len 5 -> mid 'c'
    char *s2 = Strings::str_pop_mid(s1);

    cout << "Original: " << s1 << endl;
    cout << "Apos pop_mid(): " << s2 << endl;

    delete[] s2;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 07 - Testar str_insert.
 */
void method_07()
{
    cout << "\nMethod_07 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("abcde");
    char *s2 = Strings::str_insert(s1, 'X', 2); // inserir na pos 2 (antes do c)

    cout << "Original: " << s1 << endl;
    cout << "Apos insert('X', 2): " << s2 << endl;

    delete[] s2;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 08 - Testar str_remove.
 */
void method_08()
{
    cout << "\nMethod_08 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("abcde");
    char *s2 = Strings::str_remove(s1, 2); // remover pos 2 ('c')

    cout << "Original: " << s1 << endl;
    cout << "Apos remove(2): " << s2 << endl;

    delete[] s2;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 09 - Testar str_chr.
 */
void method_09()
{
    cout << "\nMethod_09 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("banana");
    char *res = Strings::str_chr(s1, 'n');

    cout << "Original: " << s1 << endl;
    if (res)
        cout << "Encontrado 'n' na posicao de memoria: " << (void*)res << " (Substr: " << res << ")" << endl;
    else
        cout << "'n' Nao encontrado." << endl;

    res = Strings::str_chr(s1, 'z');
    if (res)
        cout << "Encontrado 'z'." << endl;
    else
        cout << "'z' Nao encontrado." << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Method 10 - Testar str_tok.
 */
void method_10()
{
    cout << "\nMethod_10 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("user@email.com");
    char *s2 = Strings::str_tok(s1, '@');

    cout << "Original: " << s1 << endl;
    cout << "Token ate '@': " << (s2 ? s2 : "null") << endl;

    delete[] s2;
    pause("Apertar ENTER para continuar");
}

/**
 * Method 11 - Testar E1 (str_prefix).
 */
void method_11()
{
    cout << "\nMethod_11 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("prefixo_teste");
    char *pre = const_cast<char*>("prefixo");
    char *res = Strings::str_prefix(pre, s1);

    cout << "String: " << s1 << ", Prefixo: " << pre << endl;
    cout << "Resultado (ptr): " << (res ? "Encontrado" : "Nao encontrado") << endl;

    pause("Apertar ENTER para continuar");
}

/**
 * Method 12 - Testar E2 (str_suffix).
 */
void method_12()
{
    cout << "\nMethod_12 - v0.0\n" << endl;
    
    char *s1 = const_cast<char*>("arquivo.txt");
    char *suf = const_cast<char*>(".txt");
    char *res = Strings::str_suffix(s1, suf);

    cout << "String: " << s1 << ", Sufixo: " << suf << endl;
    cout << "Resultado (ptr): " << (res ? "Encontrado" : "Nao encontrado") << endl;

    if(res) cout << "Sufixo inicia em: " << res << endl;

    pause("Apertar ENTER para continuar");
}

int main(int argc, char **argv)
{
    int x = 0;

    do
    {
        cout << "EXEMPLO1500 - Programa - v0.0\n" << endl;

        cout << "Opcoes:" << endl;
        cout << " 0 - parar" << endl;
        cout << " 1 - Method_01 (Testar push_back)" << endl;
        cout << " 2 - Method_02 (Testar pop_back)" << endl;
        cout << " 3 - Method_03 (Testar push_front)" << endl;
        cout << " 4 - Method_04 (Testar pop_front)" << endl;
        cout << " 5 - Method_05 (Testar push_mid)" << endl;
        cout << " 6 - Method_06 (Testar pop_mid)" << endl;
        cout << " 7 - Method_07 (Testar insert)" << endl;
        cout << " 8 - Method_08 (Testar remove)" << endl;
        cout << " 9 - Method_09 (Testar str_chr)" << endl;
        cout << "10 - Method_10 (Testar str_tok)" << endl;
        cout << "11 - Method_11 (Extra 1: str_prefix)" << endl;
        cout << "12 - Method_12 (Extra 2: str_suffix)" << endl;

        cout << endl << "Entrar com uma opcao: ";
        cin >> x;
        cin.ignore(1000, '\n');

        switch (x)
        {
        case 0: method_00(); break;
        case 1: method_01();
            /*
            Method_01 - v0.0
            Original: abc
            Apos push_back('d'): abcd
            Apertar ENTER para continuar
            */
            break;
        case 2: method_02();
            /*
            Method_02 - v0.0
            Original: abc
            Apos pop_back(): ab
            Apertar ENTER para continuar
            */
            break;
        case 3: method_03();
            /*
            Method_03 - v0.0
            Original: abc
            Apos push_front('z'): zabc
            Apertar ENTER para continuar
            */
            break;
        case 4: method_04();
            /*
            Method_04 - v0.0
            Original: abc
            Apos pop_front(): bc
            Apertar ENTER para continuar
            */
            break;
        case 5: method_05();
            /*
            Method_05 - v0.0
            Original: abxy
            Apos push_mid('M'): abMxy
            Apertar ENTER para continuar
            */
            break;
        case 6: method_06();
            /*
            Method_06 - v0.0
            Original: abcde
            Apos pop_mid(): abde
            Apertar ENTER para continuar
            */
            break;
        case 7: method_07();
            /*
            Method_07 - v0.0
            Original: abcde
            Apos insert('X', 2): abXcde
            Apertar ENTER para continuar
            */
            break;
        case 8: method_08();
            /*
            Method_08 - v0.0
            Original: abcde
            Apos remove(2): abde
            Apertar ENTER para continuar
            */
            break;
        case 9: method_09();
            /*
            Method_09 - v0.0
            Original: banana
            Encontrado 'n' na posicao de memoria: 0x... (Substr: nana)
            'z' Nao encontrado.
            Apertar ENTER para continuar
            */
            break;
        case 10: method_10();
            /*
            Method_10 - v0.0
            Original: user@email.com
            Token ate '@': user
            Apertar ENTER para continuar
            */
            break;
        case 11: method_11();
            /*
            Method_11 - v0.0
            String: prefixo_teste, Prefixo: prefixo
            Resultado (ptr): Encontrado
            Apertar ENTER para continuar
            */
            break;
        case 12: method_12();
            /*
            Method_12 - v0.0
            String: arquivo.txt, Sufixo: .txt
            Resultado (ptr): Encontrado
            Sufixo inicia em: .txt
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