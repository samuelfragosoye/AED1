/*
  Exemplo0600.c - v0.0. - 19/09/2025
  Author: Samuel Fragoso
  Matricula: 902665

  Para o Estudo Dirigido 06 - Recursividade
*/

// dependencias
#include "io.h"     // para definicoes proprias
#include <string.h> // para strlen()
#include <math.h>   // para pow()
#include <stdio.h>  // para printf()

// ------------------------------------------- EXEMPLOS

/**
  Method_01a - Mostrar certa quantidade de valores recursivamente (decrescente).
  @param x - quantidade de valores a serem mostrados
*/
void method_01a ( int x )
{
    // repetir enquanto valor maior que zero
    if ( x > 0 )
    {
        // mostrar valor
        IO_printf ( "%s%d\n", "Valor = ", x );
        // passar ao proximo
        method_01a ( x - 1 ); // motor da recursividade
    } // end if
} // end method_01a()

/**
  Method_01 - Preparacao para mostrar valores.
*/
void method_01 ( )
{
    // identificar
    IO_id ( "Method_01 - v0.0" );
    // executar o metodo auxiliar
    method_01a ( 5 );
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ()

/**
  Method_02a - Mostrar certa quantidade de valores recursivamente (crescente).
  @param x - quantidade de valores a serem mostrados
*/
void method_02a ( int x )
{
    // repetir enquanto valor maior que zero
    if ( x > 0 )
    {
        // passar ao proximo
        method_02a ( x - 1 );
        // mostrar valor no retorno
        IO_printf ( "%s%d\n", "Valor = ", x );
    } // end if
} // end method_02a()

/**
  Method_02 - Preparacao para mostrar valores.
*/
void method_02 ( )
{
    // identificar
    IO_id ( "Method_02 - v0.0" );
    // executar o metodo auxiliar
    method_02a ( 5 );
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ()

/**
  Method_03a - Mostrar certa quantidade de valores recursivamente (crescente com base).
  @param x - quantidade de valores a serem mostrados
*/
void method_03a ( int x )
{
    // repetir enquanto valor maior que 1
    if ( x > 1 )
    {
        // passar ao proximo
        method_03a ( x - 1 );
        // mostrar valor no retorno
        IO_printf ( "%s%d\n", "Valor = ", x );
    }
    else
    {
        // mostrar o ultimo (base da recursividade)
        IO_printf ( "%s%d\n", "Valor = ", 1 );
    } // end if
} // end method_03a()

/**
  Method_03 - Preparacao para mostrar valores.
*/
void method_03 ( )
{
    // identificar
    IO_id ( "Method_03 - v0.0" );
    // executar o metodo auxiliar
    method_03a ( 5 );
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ()

/**
  Method_04a - Mostrar sequencia (1 2 4 6 8...) recursivamente.
  @param x - quantidade de valores a serem mostrados
*/
void method_04a ( int x )
{
    // repetir enquanto valor maior que 1
    if ( x > 1 )
    {
        // passar ao proximo
        method_04a ( x - 1 );
        // mostrar valor (motor da recursividade)
        IO_printf ( "%s%d\n", "Valor = ", 2 * (x - 1) );
    }
    else
    {
        // mostrar o primeiro (base da recursividade)
        IO_printf ( "%s%d\n", "Valor = ", 1 );
    } // end if
} // end method_04a()

/**
  Method_04 - Preparacao para mostrar sequencia.
*/
void method_04 ( )
{
    // identificar
    IO_id ( "Method_04 - v0.0" );
    // executar o metodo auxiliar
    method_04a ( 5 );
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ()

/**
  Method_05a - Mostrar parcelas do somatorio (1 + 2/3 + 4/5 + ...) recursivamente.
  @param x - quantidade de valores a serem mostrados
*/
void method_05a ( int x )
{
    if ( x > 1 )
    {
        // passar ao proximo
        method_05a ( x - 1 );
        // mostrar valor (motor da recursividade)
        IO_printf ( "%d: %d/%d\n", x, (2 * (x - 1)), (2 * (x - 1) + 1) );
    }
    else
    {
        // mostrar o primeiro (base da recursividade)
        IO_printf ( "%d: %d\n", x, 1 );
    } // end if
} // end method_05a()

/**
  Method_05 - Preparacao para mostrar somatorio.
*/
void method_05 ( )
{
    // identificar
    IO_id ( "Method_05 - v0.0" );
    // executar o metodo auxiliar
    method_05a ( 5 );
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ()

/**
  somarFracoes - Somar certa quantidade de fracoes recursivamente.
  @return soma de valores
  @param x - quantidade de valores a serem somados
*/
double somarFracoes ( int x )
{
    // definir dado local
    double soma = 0.0;
    
    if ( x > 1 )
    {
        // separar um valor e passar ao proximo (motor da recursividade)
        soma = (2.0 * (x - 1)) / (2.0 * (x - 1) + 1) + somarFracoes(x - 1);
        IO_printf ( "%d: %lf/%lf\n", x, (2.0 * (x - 1)), (2.0 * (x-1) + 1) );
    }
    else
    {
        // base da recursividade
        soma = 1.0;
        IO_printf ( "%d: %lf\n", x, 1.0 );
    } // end if
    
    // retornar resultado
    return ( soma );
} // end somarFracoes ()

/**
  Method_06 - Teste da funcao somarFracoes.
*/
void method_06 ( )
{
    // definir dado
    double soma = 0.0;
    // identificar
    IO_id ( "Method_06 - v0.0" );
    // chamar a funcao e receber o resultado
    soma = somarFracoes ( 5 );
    // mostrar resultado
    IO_printf ( "soma = %lf\n", soma );
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ()

/**
  somarFracoes2b - Funcao auxiliar para somar fracoes com acumulador.
  @return soma de valores
  @param x - controle
  @param soma - acumulador
  @param numerador - numerador da parcela
  @param denominador - denominador da parcela
*/
double somarFracoes2b ( int x, double soma, double numerador, double denominador )
{
    if ( x > 0 )
    {
        IO_printf ( "%d: %lf/%lf\n", x, numerador, denominador );
        // somar o termo atual e passar ao proximo (motor da recursividade)
        soma = somarFracoes2b ( x - 1,
                               soma + ( (1.0 * numerador) / denominador ),
                               numerador + 2.0,
                               denominador + 2.0 );
    } // end if
    return ( soma );
} // end somarFracoes2b ()

/**
  somarFracoes2a - Funcao para preparar e disparar a soma de fracoes.
  @return soma de valores
  @param x - quantidade de valores
*/
double somarFracoes2a ( int x )
{
    double soma = 0.0;
    if ( x > 0 )
    {
        IO_printf ( "%d: %lf\n", x, 1.0 );
        // preparar a soma do valor atual e o proximo
        soma = somarFracoes2b ( x - 1, 1.0, 2.0, 3.0 );
    } // end if
    return ( soma );
} // end somarFracoes2a ()

/**
  Method_07 - Teste da funcao somarFracoes2a.
*/
void method_07 ( )
{
    double soma = 0.0;
    IO_id ( "Method_07 - v0.0" );
    soma = somarFracoes2a ( 5 );
    IO_printf ( "soma = %lf\n", soma );
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ()

/**
  contarDigitos - Contar digitos de um numero recursivamente.
  @return quantidade de digitos
  @param x - numero
*/
int contarDigitos ( int x )
{
    int resposta = 1;
    if ( x >= 10 )
    {
        resposta = 1 + contarDigitos ( x / 10 ); // motor
    }
    else if ( x < 0 )
    {
        resposta = contarDigitos ( -x );
    } // end if
    return ( resposta );
} // end contarDigitos ()

/**
  Method_08 - Teste da funcao contarDigitos.
*/
void method_08 ( )
{
    IO_id ( "Method_08 - v0.0" );
    IO_printf ( "digitos (%3d) = %d\n", 123, contarDigitos (123) );
    IO_printf ( "digitos (%3d) = %d\n", 1, contarDigitos (1) );
    IO_printf ( "digitos (%3d) = %d\n", -10, contarDigitos (-10) );
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ()

/**
  fibonacci - Gerador de numero de Fibonacci.
  @return numero de Fibonacci
  @param x - ordem do numero a ser calculado
*/
int fibonacci ( int x )
{
    int resposta = 0;
    if ( x == 1 || x == 2 )
    {
        resposta = 1; // bases
    }
    else if ( x > 1 )
    {
        resposta = fibonacci ( x - 1 ) + fibonacci ( x - 2 ); // motor
    } // end if
    return ( resposta );
} // end fibonacci ()

/**
  Method_09 - Teste da funcao fibonacci.
*/
void method_09 ( )
{
    IO_id ( "Method_09 - v0.0" );
    IO_printf ( "fibonacci (%d) = %d\n", 1, fibonacci (1) );
    IO_printf ( "fibonacci (%d) = %d\n", 2, fibonacci (2) );
    IO_printf ( "fibonacci (%d) = %d\n", 3, fibonacci (3) );
    IO_printf ( "fibonacci (%d) = %d\n", 4, fibonacci (4) );
    IO_printf ( "fibonacci (%d) = %d\n", 5, fibonacci (5) );
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ()

/**
  contarMinusculas - Contar letras minusculas em uma cadeia de caracteres.
  @return quantidade de letras minusculas
  @param cadeia - cadeia de caracteres a ser avaliada
  @param x - posicao inicial
*/
int contarMinusculas ( const char* cadeia, int x )
{
    int resposta = 0;
    if ( 0 <= x && x < strlen ( cadeia ) )
    {
        if ( cadeia[x] >= 'a' && cadeia[x] <= 'z' )
        {
            resposta = 1;
        } // end if
        resposta = resposta + contarMinusculas ( cadeia, x + 1 );
    } // end if
    return ( resposta );
} // end contarMinusculas ()

/**
  Method_10 - Teste da funcao contarMinusculas.
*/
void method_10 ( )
{
    IO_id ( "Method_10 - v0.0" );
    IO_printf ( "Minusculas (\"abc\",0) = %d\n", contarMinusculas ("abc", 0) );
    IO_printf ( "Minusculas (\"aBc\",0) = %d\n", contarMinusculas ("aBc", 0) );
    IO_printf ( "Minusculas (\"AbC\",0) = %d\n", contarMinusculas ("AbC", 0) );
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ()


// ------------------------------------------- EXERCICIOS

/**
 * Procedimento recursivo para mostrar multiplos de 6 em ordem crescente.
 * @param x - quantidade de multiplos a mostrar
 */
void mostrarMultiplos6(int x) {
    if (x > 0) {
        mostrarMultiplos6(x - 1);
        printf("%d ", 6 * x);
    }
}

/**
  Method_11 (0611) - Ler um valor e mostrar n multiplos de 6.
*/
void method_11() {
    IO_id("Method_0611 - v0.0");
    int n = IO_readint("Digite a quantidade de multiplos de 6: ");
    if (n > 0) {
        mostrarMultiplos6(n);
        printf("\n");
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Procedimento recursivo para mostrar multiplos de 4 em ordem decrescente.
 * @param x - quantidade de multiplos a mostrar
 */
void mostrarMultiplos4Dec(int x) {
    if (x > 0) {
        printf("%d ", 4 * x);
        mostrarMultiplos4Dec(x - 1);
    }
}

/**
  Method_12 (0612) - Ler um valor e mostrar n multiplos de 4 decrescente.
*/
void method_12() {
    IO_id("Method_0612 - v0.0");
    int n = IO_readint("Digite a quantidade de multiplos de 4: ");
    if (n > 0) {
        mostrarMultiplos4Dec(n);
        printf("\n");
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Procedimento recursivo para mostrar inversos de multiplos de 4 (crescente).
 * @param x - quantidade de termos
 */
void mostrarInversosMult4(int x) {
    if (x > 1) {
        mostrarInversosMult4(x - 1);
        printf("1/%d ", 4 * (x - 1));
    } else if (x == 1) {
        printf("1/1 ");
    }
}

/**
  Method_13 (0613) - Mostrar n inversos de multiplos de 4.
*/
void method_13() {
    IO_id("Method_0613 - v0.0");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        mostrarInversosMult4(n);
        printf("\n");
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Procedimento recursivo para mostrar inversos de multiplos de 4 (decrescente).
 * @param x - quantidade de termos
 */
void mostrarInversosMult4Dec(int x) {
    if (x > 1) {
        printf("1/%d ", 4 * (x - 1));
        mostrarInversosMult4Dec(x - 1);
    } else if (x == 1) {
        printf("1/1 ");
    }
}

/**
  Method_14 (0614) - Mostrar n inversos de multiplos de 4 (decrescente).
*/
void method_14() {
    IO_id("Method_0614 - v0.0");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        mostrarInversosMult4Dec(n);
        printf("\n");
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao recursiva para calcular o n-esimo termo da sequencia: 4, 5, 8, 13, 20...
 * @param n - posicao do termo
 * @return o valor do termo
 */
int termoSequenciaSoma(int n) {
    if (n == 1) {
        return 4; // Base
    } else {
        return termoSequenciaSoma(n - 1) + (2 * (n - 1) - 1); // Motor
    }
}

/**
 * Funcao recursiva para somar os n primeiros termos da sequencia.
 * @param n - quantidade de termos a somar
 * @return a soma dos termos
 */
int somarTermosSequencia(int n) {
    if (n > 0) {
        int termo_atual = termoSequenciaSoma(n);
        printf("%d ", termo_atual);
        return termo_atual + somarTermosSequencia(n - 1);
    } else {
        return 0; // Base
    }
}

/**
  Method_15 (0615) - Somar termos de uma sequencia.
*/
void method_15() {
    IO_id("Method_0615 - v0.0");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        printf("Termos somados (em ordem inversa): ");
        int soma = somarTermosSequencia(n);
        printf("\nSoma = %d\n", soma);
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao recursiva para somar os inversos dos n primeiros impares multiplos de 5.
 * @param n - quantidade de termos
 * @return a soma dos inversos
 */
double somarInversosImpares5(int n) {
    if (n > 0) {
        double termo = 1.0 / (5.0 * (2 * n - 1));
        printf("1/%d ", 5 * (2 * n - 1));
        return termo + somarInversosImpares5(n - 1);
    } else {
        return 0.0; // Base
    }
}

/**
  Method_16 (0616) - Somar inversos de impares multiplos de 5.
*/
void method_16() {
    IO_id("Method_0616 - v0.0");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        printf("Termos somados (em ordem inversa): ");
        double soma = somarInversosImpares5(n);
        printf("\nSoma = %lf\n", soma);
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Procedimento recursivo para mostrar uma string de tras para frente.
 * @param s - string
 * @param index - posicao do caractere a ser mostrado
 */
void imprimirInvertido(const char* s, int index) {
    if (index >= 0) {
        printf("%c\n", s[index]);
        imprimirInvertido(s, index - 1);
    }
}

/**
  Method_17 (0617) - Mostrar string invertida.
*/
void method_17() {
    IO_id("Method_0617 - v0.0");
    char* s = IO_readstring("Digite uma cadeia de caracteres: ");
    if (s != NULL) {
        imprimirInvertido(s, strlen(s) - 1);
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao recursiva para contar digitos impares em uma string.
 * @param s - string
 * @param index - posicao a ser verificada
 * @return quantidade de digitos impares
 */
int contarDigitosImpares(const char* s, int index) {
    if (index < 0) {
        return 0; // Base
    } else {
        char c = s[index];
        int count = 0;
        if (c >= '0' && c <= '9') {
            if ((c - '0') % 2 != 0) {
                count = 1;
            }
        }
        return count + contarDigitosImpares(s, index - 1); // Motor
    }
}

/**
  Method_18 (0618) - Contar digitos impares em uma string.
*/
void method_18() {
    IO_id("Method_0618 - v0.0");
    char* s = IO_readstring("Digite uma cadeia de caracteres: ");
    if (s != NULL) {
        int count = contarDigitosImpares(s, strlen(s) - 1);
        printf("A cadeia \"%s\" contem %d digitos impares.\n", s, count);
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao recursiva para contar maiusculas entre 'F' e 'S'.
 * @param s - string
 * @param index - posicao a ser verificada
 * @return quantidade de maiusculas no intervalo
 */
int contarMaiusculasFS(const char* s, int index) {
    if (index < 0) {
        return 0; // Base
    } else {
        char c = s[index];
        int count = 0;
        if (c > 'F' && c < 'S') {
            count = 1;
        }
        return count + contarMaiusculasFS(s, index - 1);
    }
}

/**
  Method_19 (0619) - Contar maiusculas > 'F' e < 'S'.
*/
void method_19() {
    IO_id("Method_0619 - v0.0");
    char* s = IO_readstring("Digite uma cadeia de caracteres: ");
    if (s != NULL) {
        int count = contarMaiusculasFS(s, strlen(s) - 1);
        printf("A cadeia \"%s\" contem %d maiusculas entre 'F' e 'S'.\n", s, count);
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao recursiva para somar os n primeiros termos pares da serie de Fibonacci.
 * @param n - quantidade de termos pares a somar
 * @return a soma dos termos
 */
int somarParesFibonacci(int n) {
    if (n <= 0) {
        return 0; // Base
    } else {
        // A n-esima par de Fibonacci eh fib(3*n)
        return fibonacci(3 * n) + somarParesFibonacci(n - 1);
    }
}

/**
  Method_20 (0620) - Somar n termos pares de Fibonacci.
*/
void method_20() {
    IO_id("Method_0620 - v0.0");
    int n = IO_readint("Digite a quantidade de termos pares de Fibonacci a somar: ");
    if (n > 0) {
        int soma = somarParesFibonacci(n);
        printf("A soma dos %d primeiros termos pares de Fibonacci eh %d\n", n, soma);
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao recursiva para calcular a serie f(x,n) = 1 + x^2 + x^4 + ...
 * @param x - base da potencia
 * @param n - quantidade de termos
 * @return o valor da soma
 */
double serieX(double x, int n) {
    if (n <= 0) {
        return 0.0; // Base
    } else if (n == 1) {
        return 1.0; // Base do primeiro termo
    } else {
        return pow(x, 2 * (n - 1)) + serieX(x, n - 1);
    }
}

/**
  Method_E1 (06E1) - Calcular serie com potencias.
*/
void method_E1() {
    IO_id("Method_06E1 - v0.0");
    double x = IO_readdouble("Digite o valor de x: ");
    int n = IO_readint("Digite a quantidade de termos (n): ");
    if (n > 0) {
        double resultado = serieX(x, n);
        printf("f(%.2lf, %d) = %lf\n", x, n, resultado);
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao para calcular fatorial.
 * @param n - numero
 * @return fatorial de n
 */
long long fatorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

/**
 * Funcao recursiva para calcular a serie e = 1 + 3/4! + 5/8! + ...
 * @param n - quantidade de termos
 * @return o valor da soma
 */
double serieE(int n) {
    if (n <= 0) {
        return 0.0; // Base
    } else if (n == 1) {
        return 1.0; // Base do primeiro termo
    } else {
        double numerador = 2.0 * n - 1.0;
        long long denominador = fatorial((int)pow(2, n));
        return (numerador / denominador) + serieE(n - 1);
    }
}

/**
  Method_E2 (06E2) - Calcular serie com fatoriais.
*/
void method_E2() {
    IO_id("Method_06E2 - v0.0");
    int n = IO_readint("Digite a quantidade de termos (n): ");
    if (n > 0) {
        double resultado = serieE(n);
        printf("e = %lf\n", resultado);
    } else {
        printf("A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}


/*
  Funcao principal.
*/
int main ( )
{
    // definir dado
    int x = 0;
    
    // repetir até desejar parar
    do
    {
        // identificar
        IO_println ( "Exemplo0600 - Programa - v0.0" );
        
        // ler do teclado
        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - Method_01 - Contagem Decrescente" );
        IO_println ( " 2 - Method_02 - Contagem Crescente" );
        IO_println ( " 3 - Method_03 - Contagem Crescente com Base" );
        IO_println ( " 4 - Method_04 - Sequencia 1, 2, 4, 6..." );
        IO_println ( " 5 - Method_05 - Parcelas de Somatorio" );
        IO_println ( " 6 - Method_06 - Funcao Somar Fracoes" );
        IO_println ( " 7 - Method_07 - Funcao Somar Fracoes com Acumulador" );
        IO_println ( " 8 - Method_08 - Funcao Contar Digitos" );
        IO_println ( " 9 - Method_09 - Funcao Fibonacci" );
        IO_println ( "10 - Method_10 - Funcao Contar Minusculas" );
        IO_println ( "11 - Method_11 (0611) - Multiplos de 6 Crescente" );
        IO_println ( "12 - Method_12 (0612) - Multiplos de 4 Decrescente" );
        IO_println ( "13 - Method_13 (0613) - Inversos de Mult de 4 Crescente" );
        IO_println ( "14 - Method_14 (0614) - Inversos de Mult de 4 Decrescente" );
        IO_println ( "15 - Method_15 (0615) - Soma Sequencia com Impares" );
        IO_println ( "16 - Method_16 (0616) - Soma Inversos Impares Mult de 5" );
        IO_println ( "17 - Method_17 (0617) - Imprimir String Invertida" );
        IO_println ( "18 - Method_18 (0618) - Contar Digitos Impares" );
        IO_println ( "19 - Method_19 (0619) - Contar Maiusculas > 'F' e < 'S'" );
        IO_println ( "20 - Method_20 (0620) - Somar Termos Pares de Fibonacci" );
        IO_println ( "21 - Method_E1 (06E1) - Soma Serie com Potencias" );
        IO_println ( "22 - Method_E2 (06E2) - Soma Serie com Fatoriais" );
        IO_println ( "" );
        
        x = IO_readint ( "Entrar com uma opcao: " );
        
        // testar valor
        switch ( x )
        {
            case 0: break;
            case 1: method_01 ( ); break;
            case 2: method_02 ( ); break;
            case 3: method_03 ( ); break;
            case 4: method_04 ( ); break;
            case 5: method_05 ( ); break;
            case 6: method_06 ( ); break;
            case 7: method_07 ( ); break;
            case 8: method_08 ( ); break;
            case 9: method_09 ( ); break;
            case 10: method_10 ( ); break;
            case 11: method_11 ( ); break;
            case 12: method_12 ( ); break;
            case 13: method_13 ( ); break;
            case 14: method_14 ( ); break;
            case 15: method_15 ( ); break;
            case 16: method_16 ( ); break;
            case 17: method_17 ( ); break;
            case 18: method_18 ( ); break;
            case 19: method_19 ( ); break;
            case 20: method_20 ( ); break;
            case 21: method_E1 ( ); break;
            case 22: method_E2 ( ); break;
            default: IO_println ( "ERRO: Valor invalido." );
        } // end switch
    }
    while ( x != 0 );
    
    // encerrar
    IO_pause ( "Apertar ENTER para terminar" );
    return ( 0 );
} // end main ( )

/*
---------------------------------------------- Documentacao complementar

---------------------------------------------- Notas / observacoes / comentarios
O exercicio 0620 pedia para "calcular certo termo par da serie de Fibonacci",
mas o exemplo "valor = 3 => 2+8+34" indicava a SOMA dos 3 primeiros termos pares.
A implementacao seguiu o exemplo (soma), por ser mais complexo e provavel.

---------------------------------------------- Previsao de testes
Method_0611:
- Entrada: n = 5
- Saida: 6 12 18 24 30
- Resultado: ( OK )

Method_0612:
- Entrada: n = 5
- Saida: 20 16 12 8 4
- Resultado: ( OK )

Method_0613:
- Entrada: n = 5
- Saida: 1/1 1/4 1/8 1/12 1/16
- Resultado: ( OK )

Method_0614:
- Entrada: n = 5
- Saida: 1/16 1/12 1/8 1/4 1/1
- Resultado: ( OK )

Method_0615:
- Entrada: n = 5
- Saida: Termos somados (em ordem inversa): 4 5 8 13 20
         Soma = 50
- Resultado: ( OK )

Method_0616:
- Entrada: n = 5
- Saida: Termos somados (em ordem inversa): 1/5 1/15 1/25 1/35 1/45
         Soma = 0.357937
- Resultado: ( OK )

Method_0617:
- Entrada: s = "abcde"
- Saida:
e
d
c
b
a
- Resultado: ( OK )

Method_0618:
- Entrada: s = "P4LaVr@135"
- Saida: A cadeia "P4LaVr@135" contem 3 digitos impares.
- Resultado: ( OK )

Method_0619:
- Entrada: s = "P4LaVr@1GH"
- Saida: A cadeia "P4LaVr@1GH" contem 2 maiusculas entre 'F' e 'S'.
- Resultado: ( OK )

Method_0620:
- Entrada: n = 3
- Saida: A soma dos 3 primeiros termos pares de Fibonacci eh 44
- (Fibonacci: 1, 1, 2, 3, 5, 8, 13, 21, 34 -> Pares: 2, 8, 34 -> Soma = 44)
- Resultado: ( OK )

Method_06E1:
- Entrada: x = 2.0, n = 4
- Saida: f(2.00, 4) = 85.000000
- (1 + 2^2 + 2^4 + 2^6 = 1 + 4 + 16 + 64 = 85)
- Resultado: ( OK )

Method_06E2:
- Entrada: n = 3
- Saida: e = 1.125124
- (1 + 3/4! + 5/8! = 1 + 3/24 + 5/40320 = 1 + 0.125 + 0.000124)
- Resultado: ( OK )

---------------------------------------------- Historico
Versao Data Modificacao
 0.1 20/09 Esboco inicial, transcricao dos exemplos e implementacao dos exercicios 0611-06E2

---------------------------------------------- Testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa, exemplos e exercicios
*/