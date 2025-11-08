/**
 * Exemplo1200 - v0.0. - 01 / 11 / 2025
 * Author: Samuel Fragoso
 *
 * Para compilar em terminal (janela de comandos):
 * Linux   : g++ -o Exemplo1200 Exemplo1200.cpp
 * Windows : g++ -o Exemplo1200 Exemplo1200.cpp
 *
 * Para executar em terminal (janela de comandos):
 * Linux   : ./Exemplo1200
 * Windows : Exemplo1200
 */
// ----------------------------------------------- definicoes globais
// dependencias
#include <iostream>  // para entradas e saidas
#include <iomanip>   // para formatacao
#include <string>    // para cadeias de caracteres
#include <fstream>   // para arquivos
#include <cstdlib>   // para rand() e srand()
#include <ctime>     // para time()

// definicoes de tipos
#include "mymatrix.hpp" // classe para matrizes

using std::cin;    // para entrada
using std::cout;   // para saida
using std::endl;   // para mudar de linha
using std::setw;   // para definir espacamento
using std::string; // para cadeia de caracteres

// ----------------------------------------------- metodos
/**
 * Funcao para pausar a execucao.
 */
void pause(string text)
{
    string dummy;
    cout << endl
         << text;
    cin.ignore(); // Limpa o buffer de entrada
    getline(cin, dummy);
    cout << endl;
} // end pause ( )

// ----------------------------------------------- metodos
/**
Method_01 - Mostrar certa quantidade de valores.
*/
void method_01()
{
    // definir dados
    Matrix<int> int_matrix(2, 2, 0);
    int_matrix.set(0, 0, 1);
    int_matrix.set(0, 1, 2);
    int_matrix.set(1, 0, 3);
    int_matrix.set(1, 1, 4);
    // identificar
    cout << "\nMethod_01 - v0.0\n"
         << endl;
    // mostrar dados
    int_matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_01 ( )

/**
Method_02.
*/
void method_02()
{
    // definir dados
    Matrix<int> matrix(2, 2, 0);
    // identificar
    cout << endl
         << "Method_02 - v0.0" << endl;
    // ler dados
    matrix.read();
    // mostrar dados
    matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_02 ( )

/**
Method_03.
*/
void method_03()
{
    // definir dados
    Matrix<int> matrix(2, 2, 0);
    // identificar
    cout << endl
         << "Method_03 - v0.0" << endl;
    // ler dados
    matrix.read();
    // mostrar dados
    matrix.print();
    // gravar dados
    matrix.fprint("MATRIX1.TXT");
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_03 ( )

/**
Method_04.
*/
void method_04()
{
    // definir dados
    Matrix<int> matrix(1, 1, 0);
    // identificar
    cout << endl
         << "Method_04 - v0.0" << endl;
    // ler dados
    matrix.fread("MATRIX1.TXT");
    // mostrar dados
    matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_04 ( )

/**
Method_05.
*/
void method_05()
{
    // definir dados
    Matrix<int> int_matrix1(1, 1, 0);
    Matrix<int> int_matrix2(1, 1, 0);
    // identificar
    cout << endl
         << "Method_05 - v0.0" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nOriginal\n"
         << endl;
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1;
    // mostrar dados
    cout << "\nCopia\n"
         << endl;
    int_matrix2.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_05 ( )

/**
Method_06.
*/
void method_06()
{
    // definir dados
    Matrix<int> int_matrix(2, 2, 0);
    // (ja esta inicializada com zeros pelo construtor)
    
    // identificar
    cout << endl
         << "Method_06 - v0.0" << endl;
    // mostrar dados
    int_matrix.print();
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros() << endl;
    
    // ler dados
    int_matrix.fread("MATRIX1.TXT");
    // mostrar dados
    int_matrix.print();
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros() << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_06 ( )

/**
Method_07.
*/
void method_07()
{
    // definir dados
    Matrix<int> int_matrix1(1, 1, 0);
    Matrix<int> int_matrix2(1, 1, 0);
    // identificar
    cout << endl
         << "Method_07 - v0.0" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1;
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // testar condicao
    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;
    // alterar dados
    int_matrix2.set(0, 0, (-1));
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // testar condicao
    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_07 ( )

/**
Method_08.
*/
void method_08()
{
    // definir dados
    Matrix<int> int_matrix1(1, 1, 0);
    Matrix<int> int_matrix2(1, 1, 0);
    Matrix<int> int_matrix3(1, 1, 0);
    // identificar
    cout << endl
         << "Method_08 - v0.0" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1;
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // operar dados
    int_matrix3 = int_matrix1 - int_matrix2;
    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_08 ( )

/**
Method_09.
*/
void method_09()
{
    // definir dados
    Matrix<int> int_matrix1(2, 2, 0);
    int_matrix1.set(0, 0, 1);
    int_matrix1.set(0, 1, 0);
    int_matrix1.set(1, 0, 0);
    int_matrix1.set(1, 1, 1);
    Matrix<int> int_matrix2(1, 1, 0);
    Matrix<int> int_matrix3(1, 1, 0);
    // identificar
    cout << endl
         << "Method_09 - v0.0" << endl;
    // ler dados
    int_matrix2.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // operar dados
    int_matrix3 = int_matrix1 * int_matrix2;
    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_09 ( )

/**
Method_10.
*/
void method_10()
{
    // definir dados
    Matrix<int> int_matrix(3, 3, 0);
    int x = 0;
    int y = 0;
    // identificar
    cout << endl
         << "Method_10 - v0.0" << endl;
    // ler dados
    int_matrix.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print();
    // operar dados
    for (int x = 0; x < int_matrix.getRows(); x = x + 1)
    {
        for (int y = 0; y < int_matrix.getColumns(); y = y + 1)
        {
            int_matrix.set(x, y, int_matrix.get(x, y) * (-1));
        } // end for
    } // end for
    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_10 ( )


// ----------------------------------------------- NOVOS METODOS (EXERCICIOS)

/**
Method_11 - (Exercicio 1211) Gerar matriz aleatoria e salvar em arquivo.
*/
void method_11()
{
    int m = 0, n = 0, min = 0, max = 0;

    // identificar
    cout << endl
         << "Method_11 - v0.0" << endl;
    
    // Pedir dimensoes
    cout << "Digite o numero de linhas (M): ";
    cin >> m;
    cout << "Digite o numero de colunas (N): ";
    cin >> n;
    
    // Pedir intervalo
    cout << "Digite o limite inferior do intervalo: ";
    cin >> min;
    cout << "Digite o limite superior do intervalo: ";
    cin >> max;

    if (m > 0 && n > 0)
    {
        // Gerar DADOS1.TXT
        Matrix<int> matrix1(m, n, 0);
        matrix1.randomIntGenerate(min, max);
        cout << "\nGerando DADOS1.TXT...\n";
        matrix1.print();
        matrix1.fprint("DADOS1.TXT");

        // Gerar DADOS2.TXT (para testes futuros)
        Matrix<int> matrix2(m, n, 0);
        matrix2.randomIntGenerate(min, max);
        cout << "\nGerando DADOS2.TXT...\n";
        matrix2.print();
        matrix2.fprint("DADOS2.TXT");
    }
    else
    {
        cout << "Dimensoes invalidas." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_11 ( )


/**
Method_12 - (Exercicio 1212) Escalar matriz por constante.
*/
void method_12()
{
    int k = 0;
    Matrix<int> matrix1(1, 1, 0);
    
    // identificar
    cout << endl
         << "Method_12 - v0.0" << endl;
    
    // Ler matriz
    matrix1.fread("DADOS1.TXT");
    cout << "\nMatriz Original (DADOS1.TXT)\n";
    matrix1.print();

    // Pedir constante
    cout << "Digite a constante de escalonamento: ";
    cin >> k;

    // Escalar
    Matrix<int> matrix2 = matrix1.scalar(k);
    cout << "\nMatriz Escalonada por " << k << "\n";
    matrix2.print();

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_12 ( )

/**
Method_13 - (Exercicio 1213) Testar se e matriz identidade.
*/
void method_13()
{
    // identificar
    cout << endl
         << "Method_13 - v0.0" << endl;
    
    // Teste 1: Matriz de DADOS1.TXT
    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread("DADOS1.TXT");
    cout << "\nMatriz (DADOS1.TXT)\n";
    matrix1.print();
    cout << "E identidade? " << (matrix1.isIdentity() ? "Sim" : "Nao") << endl;

    // Teste 2: Matriz identidade 3x3
    Matrix<int> matrix2(3, 3, 0);
    matrix2.set(0, 0, 1);
    matrix2.set(1, 1, 1);
    matrix2.set(2, 2, 1);
    cout << "\nMatriz (Identidade Manual 3x3)\n";
    matrix2.print();
    cout << "E identidade? " << (matrix2.isIdentity() ? "Sim" : "Nao") << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_13 ( )

/**
Method_14 - (Exercicio 1214) Testar igualdade de matrizes.
*/
void method_14()
{
    // identificar
    cout << endl
         << "Method_14 - v0.0" << endl;

    Matrix<int> matrix1(1, 1, 0);
    Matrix<int> matrix2(1, 1, 0);
    
    // Ler matrizes
    matrix1.fread("DADOS1.TXT");
    cout << "\nMatriz 1 (DADOS1.TXT)\n";
    matrix1.print();
    
    matrix2.fread("DADOS2.TXT");
    cout << "\nMatriz 2 (DADOS2.TXT)\n";
    matrix2.print();
    
    // Testar igualdade
    cout << "Matriz 1 == Matriz 2 ? " << (matrix1 == matrix2 ? "Sim" : "Nao") << endl;

    // Copiar e testar de novo
    matrix2 = matrix1;
    cout << "\nCopiando Matriz 1 para Matriz 2...\n";
    cout << "\nMatriz 1\n";
    matrix1.print();
    cout << "\nMatriz 2 (agora copia)\n";
    matrix2.print();
    cout << "Matriz 1 == Matriz 2 ? " << (matrix1 == matrix2 ? "Sim" : "Nao") << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_14 ( )

/**
Method_15 - (Exercicio 1215) Somar duas matrizes.
*/
void method_15()
{
    // identificar
    cout << endl
         << "Method_15 - v0.0" << endl;

    Matrix<int> matrix1(1, 1, 0);
    Matrix<int> matrix2(1, 1, 0);
    
    // Ler matrizes
    matrix1.fread("DADOS1.TXT");
    cout << "\nMatriz 1 (DADOS1.TXT)\n";
    matrix1.print();
    
    matrix2.fread("DADOS2.TXT");
    cout << "\nMatriz 2 (DADOS2.TXT)\n";
    matrix2.print();

    // Somar
    Matrix<int> sum = matrix1.add(matrix2);
    cout << "\nSoma (Matriz 1 + Matriz 2)\n";
    sum.print();

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_15 ( )

/**
Method_16 - (Exercicio 1216) Operar linhas (R1 = R1 + k*R2).
*/
void method_16()
{
    // identificar
    cout << endl
         << "Method_16 - v0.0" << endl;
    
    Matrix<int> matrix(1, 1, 0);
    matrix.fread("DADOS1.TXT");
    
    cout << "\nMatriz Original (DADOS1.TXT)\n";
    matrix.print();

    // Operar (Ex: Linha 0 = Linha 0 + 2 * Linha 1)
    if (matrix.getRows() >= 2)
    {
        int r1 = 0;
        int r2 = 1;
        int k = 2;
        cout << "\nOperando: L" << r1 << " = L" << r1 << " + " << k << " * L" << r2 << "\n";
        matrix.addRows(r1, r2, k);
        
        cout << "\nMatriz Modificada\n";
        matrix.print();
    }
    else
    {
        cout << "A matriz nao tem linhas suficientes para o teste." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_16 ( )

/**
Method_17 - (Exercicio 1217) Operar linhas (R1 = R1 - k*R2).
*/
void method_17()
{
    // identificar
    cout << endl
         << "Method_17 - v0.0" << endl;
    
    Matrix<int> matrix(1, 1, 0);
    matrix.fread("DADOS1.TXT");
    
    cout << "\nMatriz Original (DADOS1.TXT)\n";
    matrix.print();

    // Operar (Ex: Linha 0 = Linha 0 - 2 * Linha 1)
    if (matrix.getRows() >= 2)
    {
        int r1 = 0;
        int r2 = 1;
        int k = 2;
        cout << "\nOperando: L" << r1 << " = L" << r1 << " - " << k << " * L" << r2 << "\n";
        matrix.subtractRows(r1, r2, k);
        
        cout << "\nMatriz Modificada\n";
        matrix.print();
    }
    else
    {
        cout << "A matriz nao tem linhas suficientes para o teste." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_17 ( )

/**
Method_18 - (Exercicio 1218) Procurar valor e retornar linha.
*/
void method_18()
{
    // identificar
    cout << endl
         << "Method_18 - v0.0" << endl;
    
    Matrix<int> matrix(1, 1, 0);
    matrix.fread("DADOS1.TXT");
    
    cout << "\nMatriz (DADOS1.TXT)\n";
    matrix.print();

    int valor = 0;
    cout << "Digite um valor para procurar: ";
    cin >> valor;

    int linha = matrix.searchRow(valor);

    if (linha != -1)
    {
        cout << "Valor " << valor << " encontrado na linha: " << linha << endl;
    }
    else
    {
        cout << "Valor " << valor << " nao encontrado." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_18 ( )

/**
Method_19 - (Exercicio 1219) Procurar valor e retornar coluna.
*/
void method_19()
{
    // identificar
    cout << endl
         << "Method_19 - v0.0" << endl;
    
    Matrix<int> matrix(1, 1, 0);
    matrix.fread("DADOS1.TXT");
    
    cout << "\nMatriz (DADOS1.TXT)\n";
    matrix.print();

    int valor = 0;
    cout << "Digite um valor para procurar: ";
    cin >> valor;

    int coluna = matrix.searchColumn(valor);

    if (coluna != -1)
    {
        cout << "Valor " << valor << " encontrado na coluna: " << coluna << endl;
    }
    else
    {
        cout << "Valor " << valor << " nao encontrado." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_19 ( )

/**
Method_20 - (Exercicio 1220) Transpor matriz.
*/
void method_20()
{
    // identificar
    cout << endl
         << "Method_20 - v0.0" << endl;
    
    Matrix<int> matrix1(1, 1, 0);
    matrix1.fread("DADOS1.TXT");
    
    cout << "\nMatriz Original (DADOS1.TXT)\n";
    matrix1.print();

    Matrix<int> matrix2 = matrix1.transpose();
    
    cout << "\nMatriz Transposta\n";
    matrix2.print();

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_20 ( )


// ----------------------------------------------- acao principal
int main(int argc, char **argv)
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    
    // inicializar gerador de numeros aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    // identificar
    cout << "Estudo Dirigido 12 - v0.0" << endl;
    cout << "Author: _________________________" << endl;
    cout << endl; // mudar de linha
    
    // acoes
    // repetir
    do
    {
        // para mostrar opcoes
        cout << "Opcoes:" << endl;
        cout << " 0 - parar" << endl;
        cout << " 1 - Method_01 (hardcoded 2x2)" << endl;
        cout << " 2 - Method_02 (ler 2x2 do console)" << endl;
        cout << " 3 - Method_03 (ler 2x2 e salvar em MATRIX1.TXT)" << endl;
        cout << " 4 - Method_04 (ler MATRIX1.TXT)" << endl;
        cout << " 5 - Method_05 (copiar matriz)" << endl;
        cout << " 6 - Method_06 (testar se e' zeros)" << endl;
        cout << " 7 - Method_07 (testar diferenca !=)" << endl;
        cout << " 8 - Method_08 (subtrair matrizes)" << endl;
        cout << " 9 - Method_09 (multiplicar matrizes)" << endl;
        cout << "10 - Method_10 (acessar getters/setters)" << endl;
        cout << "11 - Method_11 (1211: Gerar matriz aleatoria e salvar)" << endl;
        cout << "12 - Method_12 (1212: Escalar matriz)" << endl;
        cout << "13 - Method_13 (1213: Testar identidade)" << endl;
        cout << "14 - Method_14 (1214: Testar igualdade ==)" << endl;
        cout << "15 - Method_15 (1215: Somar matrizes)" << endl;
        cout << "16 - Method_16 (1216: Operar linhas R1 = R1 + k*R2)" << endl;
        cout << "17 - Method_17 (1217: Operar linhas R1 = R1 - k*R2)" << endl;
        cout << "18 - Method_18 (1218: Procurar valor (retorna linha))" << endl;
        cout << "19 - Method_19 (1219: Procurar valor (retorna coluna))" << endl;
        cout << "20 - Method_20 (1220: Transpor matriz)" << endl;
        
        // ler a opcao do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;
        
        // escolher acao
        switch (x)
        {
        case 1:
            method_01();
            /*
            Method_01 - v0.0

            1       2
            3       4

            Apertar ENTER para continuar
            */
            break;
        case 2:
            method_02();
            /* (Supondo entrada: 5, 6, 7, 8)
            Method_02 - v0.0

             0,  0 : 5
             0,  1 : 6
             1,  0 : 7
             1,  1 : 8

            5       6
            7       8

            Apertar ENTER para continuar
            */
            break;
        case 3:
            method_03();
            /* (Supondo entrada: 1, 2, 3, 4. Esta entrada cria MATRIX1.TXT)
            Method_03 - v0.0

             0,  0 : 1
             0,  1 : 2
             1,  0 : 3
             1,  1 : 4

            1       2
            3       4

            Apertar ENTER para continuar
            */
            break;
        case 4:
            method_04();
            /* (Lendo MATRIX1.TXT criado no passo 3)
            Method_04 - v0.0

            1       2
            3       4

            Apertar ENTER para continuar
            */
            break;
        case 5:
            method_05();
            /*
            Method_05 - v0.0

            Original

            1       2
            3       4

            Copia

            1       2
            3       4

            Apertar ENTER para continuar
            */
            break;
        case 6:
            method_06();
            /*
            Method_06 - v0.0

            0       0
            0       0

            Zeros = 1

            1       2
            3       4

            Zeros = 0

            Apertar ENTER para continuar
            */
            break;
        case 7:
            method_07();
            /*
            Method_07 - v0.0

            Matrix_1

            1       2
            3       4

            Matrix_2

            1       2
            3       4

            Diferentes = 0

            Matrix_1

            1       2
            3       4

            Matrix_2

            -1      2
            3       4

            Diferentes = 1

            Apertar ENTER para continuar
            */
            break;
        case 8:
            method_08();
            /*
            Method_08 - v0.0

            Matrix_1

            1       2
            3       4

            Matrix_2

            1       2
            3       4

            Matrix_3

            0       0
            0       0

            Apertar ENTER para continuar
            */
            break;
        case 9:
            method_09();
            /*
            Method_09 - v0.0

            Matrix_1

            1       0
            0       1

            Matrix_2

            1       2
            3       4

            Matrix_3

            1       2
            3       4

            Apertar ENTER para continuar
            */
            break;
        case 10:
            method_10();
            /*
            Method_10 - v0.0

            Matrix

            1       2
            3       4

            Matrix

            -1      -2
            -3      -4

            Apertar ENTER para continuar
            */
            break;
        case 11:
            method_11();
            /* (Supondo M=3, N=2, min=10, max=99. Valores aleatorios variam)
            Method_11 - v0.0
            Digite o numero de linhas (M): 3
            Digite o numero de colunas (N): 2
            Digite o limite inferior do intervalo: 10
            Digite o limite superior do intervalo: 99

            Gerando DADOS1.TXT...

            42      68
            35      92
            51      23

            Gerando DADOS2.TXT...

            11      78
            45      19
            66      99

            Apertar ENTER para continuar
            */
            break;
        case 12:
            method_12();
            /* (Usando DADOS1.TXT do passo 11. Supondo k=2)
            Method_12 - v0.0

            Matriz Original (DADOS1.TXT)

            42      68
            35      92
            51      23

            Digite a constante de escalonamento: 2

            Matriz Escalonada por 2

            84      136
            70      184
            102     46

            Apertar ENTER para continuar
            */
            break;
        case 13:
            method_13();
            /*
            Method_13 - v0.0

            Matriz (DADOS1.TXT)

            42      68
            35      92
            51      23

            E identidade? Nao

            Matriz (Identidade Manual 3x3)

            1       0       0
            0       1       0
            0       0       1

            E identidade? Sim

            Apertar ENTER para continuar
            */
            break;
        case 14:
            method_14();
            /*
            Method_14 - v0.0

            Matriz 1 (DADOS1.TXT)

            42      68
            35      92
            51      23

            Matriz 2 (DADOS2.TXT)

            11      78
            45      19
            66      99

            Matriz 1 == Matriz 2 ? Nao

            Copiando Matriz 1 para Matriz 2...

            Matriz 1

            42      68
            35      92
            51      23

            Matriz 2 (agora copia)

            42      68
            35      92
            51      23

            Matriz 1 == Matriz 2 ? Sim

            Apertar ENTER para continuar
            */
            break;
        case 15:
            method_15();
            /*
            Method_15 - v0.0

            Matriz 1 (DADOS1.TXT)

            42      68
            35      92
            51      23

            Matriz 2 (DADOS2.TXT)

            11      78
            45      19
            66      99

            Soma (Matriz 1 + Matriz 2)

            53      146
            80      111
            117     122

            Apertar ENTER para continuar
            */
            break;
        case 16:
            method_16();
            /* (Usando DADOS1.TXT: L0 = L0 + 2 * L1)
            Method_16 - v0.0

            Matriz Original (DADOS1.TXT)

            42      68
            35      92
            51      23

            Operando: L0 = L0 + 2 * L1
            (L0[0] = 42 + 2*35 = 112)
            (L0[1] = 68 + 2*92 = 252)

            Matriz Modificada

            112     252
            35      92
            51      23

            Apertar ENTER para continuar
            */
            break;
        case 17:
            method_17();
            /* (Usando DADOS1.TXT: L0 = L0 - 2 * L1)
            Method_17 - v0.0

            Matriz Original (DADOS1.TXT)

            42      68
            35      92
            51      23

            Operando: L0 = L0 - 2 * L1
            (L0[0] = 42 - 2*35 = -28)
            (L0[1] = 68 - 2*92 = -116)

            Matriz Modificada

            -28     -116
            35      92
            51      23

            Apertar ENTER para continuar
            */
            break;
        case 18:
            method_18();
            /* (Usando DADOS1.TXT. Supondo busca por 92 e depois 999)
            Method_18 - v0.0

            Matriz (DADOS1.TXT)

            42      68
            35      92
            51      23

            Digite um valor para procurar: 92
            Valor 92 encontrado na linha: 1

            (Nova execucao)
            Digite um valor para procurar: 999
            Valor 999 nao encontrado.

            Apertar ENTER para continuar
            */
            break;
        case 19:
            method_19();
            /* (Usando DADOS1.TXT. Supondo busca por 92 e depois 999)
            Method_19 - v0.0

            Matriz (DADOS1.TXT)

            42      68
            35      92
            51      23

            Digite um valor para procurar: 92
            Valor 92 encontrado na coluna: 1

            (Nova execucao)
            Digite um valor para procurar: 999
            Valor 999 nao encontrado.

            Apertar ENTER para continuar
            */
            break;
        case 20:
            method_20();
            /*
            Method_20 - v0.0

            Matriz Original (DADOS1.TXT)

            42      68
            35      92
            51      23

            Matriz Transposta

            42      35      51
            68      92      23

            Apertar ENTER para continuar
            */
            break;
        default:
            if (x != 0)
            {
                cout << "Opcao invalida." << endl;
                pause("Apertar ENTER para continuar");
            }
            break;
        } // end switch
    } while (x != 0);
    // encerrar
    cout << endl
         << "Apertar ENTER para terminar." << endl;
    return (0);
} // end main ( )