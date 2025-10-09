/*
  Exemplo0500 - v0.0. - 14/09/2025
  Author: Samuel Fragoso
  Matricula: 902665
*/

// dependencias
#include "io.h"     // para definicoes proprias
#include <math.h>   // para funcoes matematicas, como pow()

/**
  Method_01a - Mostrar certa quantidade de valores.
  @param x - quantidade de valores a serem mostrados
*/
void method_01a ( int x )
{
    // definir dado local
    int y = 1; // controle
    
    // repetir enquanto controle menor que a quantidade desejada
    while ( y <= x )
    {
        // mostrar valor
        IO_printf ( "%s%d\n", "Valor = ", y );
        // passar ao proximo
        y = y + 1;
    } // end while
} // end method_01a()

/**
  Method_01 - Mostrar certa quantidade de valores.
  OBS.: Preparacao e disparo de outro metodo.
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
  Method_02a - Mostrar certa quantidade de valores pares.
  @param x - quantidade de valores a serem mostrados
*/
void method_02a ( int x )
{
    // definir dado local
    int y = 1; // controle
    int z = 2;
    
    // repetir enquanto controle menor que a quantidade desejada
    while ( y <= x )
    {
        // mostrar valor
        IO_printf ( "%d: %d\n", y, z );
        // passar ao proximo par
        z = z + 2;
        // passar ao proximo valor controlado
        y = y + 1;
    } // end while
} // end method_02a()

/**
  Method_02.
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
  Method_03a - Mostrar certa quantidade de valores pares.
  @param x - quantidade de valores a serem mostrados
*/
void method_03a ( int x )
{
    // definir dado local
    int y = 1; // controle
    int z = 0;
    
    // repetir enquanto controle menor que a quantidade desejada
    while ( y <= x )
    {
        // vincular o valor a ser mostrado ao controle
        z = 2 * y;
        // mostrar valor
        IO_printf ( "%d: %d\n", y, z );
        // passar ao proximo valor controlado
        y = y + 1;
    } // end while
} // end method_03a()


/**
  Method_03.
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
  Method_04a - Mostrar certa quantidade de valores pares em ordem decrescente.
  @param x - quantidade de valores a serem mostrados
*/
void method_04a ( int x )
{
    // definir dado local
    int y = x; // controle
    int z = 0;
    
    // repetir enquanto controle maior que zero
    while ( y > 0 )
    {
        // vincular o valor a ser mostrado ao controle
        z = 2 * y;
        // mostrar valor
        IO_printf ( "%d: %d\n", y, z );
        // passar ao proximo valor controlado
        y = y - 1;
    } // end while
} // end method_04a()

/**
  Method_04.
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
  Method_05a - Mostrar certa quantidade de valores pares (alternativo).
  @param x - quantidade de valores a serem mostrados
*/
void method_05a ( int x )
{
    // definir dado local
    int y = x; // controle
    
    // repetir enquanto controle maior que zero
    for ( y = x; y > 0; y = y - 1 )
    {
        // mostrar valor
        IO_printf ( "%d: %d\n", y, (2*y) );
    } // end for
} // end method_05a()


/**
  Method_05.
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
  somarValores - Funcao para somar certa quantidade de pares.
  @return soma dos valores
  @param x - quantidade de valores a serem somados
*/
int somarValores ( int x )
{
    // definir dados locais
    int soma = 1;
    int y = 0; // controle
    
    // repetir enquanto controle menor que a quantidade desejada
    for ( y = 1; y <= (x-1); y = y + 1 )
    {
        // mostrar valor
        IO_printf ( "%d: %d\n", y, (2*y) );
        // somar valor
        soma = soma + (2*y);
    } // end for
    
    // retornar resultado
    return ( soma );
} // end somarValores ()

/**
  Method_06.
*/
void method_06 ( )
{
    // definir dado
    int soma = 0;
    
    // identificar
    IO_id ( "Method_06 - v0.0" );
    
    // chamar e receber resultado da funcao
    soma = somarValores ( 5 );
    
    // mostrar resultado
    IO_printf ( "soma de pares = %d\n", soma );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ()


/**
  somarFracao1 - Funcao para somar certa quantidade de fracoes.
  @return soma dos valores
  @param x - quantidade de valores a serem somados
*/
double somarFracao1 ( int x )
{
    // definir dados locais
    double soma = 1.0;
    double numerador = 1.0;
    double denominador = 0.0;
    int y = 0; // controle
    
    // repetir enquanto controle menor que a quantidade desejada
    for ( y = 1; y <= (x-1); y = y + 1 )
    {
        // calcular denominador
        denominador = 2.0 * y;
        // mostrar valor
        IO_printf ( "%d: %7.4lf/%7.4lf\n", y, numerador, denominador );
        // somar valor
        soma = soma + (1.0) / denominador;
    } // end for
    
    // retornar resultado
    return ( soma );
} // end somarFracao1 ()

/**
  Method_07.
*/
void method_07 ( )
{
    // definir dado
    double soma = 0.0;
    
    // identificar
    IO_id ( "Method_07 - v0.0" );
    
    // chamar e receber resultado da funcao
    soma = somarFracao1 ( 5 );
    
    // mostrar resultado
    IO_printf ( "soma de fracoes = %lf\n", soma );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ()


/**
  somarFracao2 - Funcao para somar certa quantidade de fracoes.
  @return soma dos valores
  @param x - quantidade de valores a serem somados
*/
double somarFracao2 ( int x )
{
    // definir dados locais
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    int y = 0; // controle
    
    // mostrar primeiro valor
    IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, 1.0 );
    
    // repetir enquanto controle menor que a quantidade desejada
    for ( y = 1; y <= (x-1); y = y + 1 )
    {
        // calcular numerador
        numerador = 2.0 * y - 1;
        // calcular denominador
        denominador = 2.0 * y;
        // mostrar valor
        IO_printf ( "%d: %7.4lf/%7.4lf\n", y+1, numerador, denominador );
        // somar valor
        soma = soma + numerador / denominador;
    } // end for
    
    // retornar resultado
    return ( soma );
} // end somarFracao2 ()

/**
  Method_08.
*/
void method_08 ( )
{
    // definir dado
    double soma = 0.0;
    
    // identificar
    IO_id ( "Method_08 - v0.0" );
    
    // chamar e receber resultado da funcao
    soma = somarFracao2 ( 5 );
    
    // mostrar resultado
    IO_printf ( "soma de fracoes = %lf\n", soma );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ()


/**
  somarFracao3 - Funcao para somar certa quantidade de fracoes.
  @return soma dos valores
  @param x - quantidade de valores a serem somados
*/
double somarFracao3 ( int x )
{
    // definir dados locais
    double soma = 1.0;
    int y = 0; // controle
    
    // mostrar primeiro valor
    IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, 1.0 );
    
    // repetir enquanto controle menor que a quantidade desejada
    for ( y = 1; y < x; y = y + 1 )
    {
        double numerador = 2.0 * y;
        double denominador = 2.0 * y + 1;
        // mostrar valor
        IO_printf ( "%d: %7.4lf/%7.4lf\n", y+1, numerador, denominador );
        // somar valor
        soma = soma + numerador / denominador;
    } // end for
    
    // retornar resultado
    return ( soma );
} // end somarFracao3 ()

/**
  Method_09.
*/
void method_09 ( )
{
    // definir dado
    double soma = 0.0;
    
    // identificar
    IO_id ( "Method_09 - v0.0" );
    
    // chamar e receber resultado da funcao
    soma = somarFracao3 ( 5 );
    
    // mostrar resultado
    IO_printf ( "soma de fracoes = %lf\n", soma );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ()


/**
  multiplicarValores - Funcao para multiplicar certa quantidade de valores impares.
  @return produto de valores
  @param x - quantidade de valores
*/
int multiplicarValores ( int x )
{
    // definir dados locais
    int produto = 1;
    int y = 0; // controle
    
    // repetir enquanto controle menor que a quantidade desejada
    for ( y = 1; y <= x; y = y + 1 )
    {
        int impar = 2 * y - 1;
        // mostrar valor
        IO_printf ( "%d: %d\n", y, impar );
        // calcular o produto
        produto = produto * impar;
    } // end for
    
    // retornar resultado
    return ( produto );
} // end multiplicarValores ()


/**
  Method_10.
*/
void method_10 ( )
{
    // identificar
    IO_id ( "Method_10 - v0.0" );
    
    // mostrar produto de valores
    IO_printf ( "%s%d\n", "produto = ", multiplicarValores ( 5 ) );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ()

// ------------------------------------------- EXERCICIOS
/**
 * Procedimento para mostrar n multiplos de 6.
 * @param n - quantidade de multiplos a serem mostrados
 */
void multiplosDe6(int n) {
    int i = 0;
    
    // Repetir n vezes
    for (i = 1; i <= n; i++) {
        // O i-esimo multiplo de 6 é i * 6
        printf("%d ", i * 6);
    }
    printf("\n"); // Pula uma linha no final
}
/**
  Method_11.
*/
void method_0511() {
    int n = 0;

    // Identificador
    IO_id("Method_0511 - Multiplos de 6");

    // Ler dados
    n = IO_readint("Digite a quantidade de multiplos de 6: ");

    // Chamar o procedimento para executar a tarefa
    if (n > 0) {
        multiplosDe6(n);
    } else {
        printf("A quantidade deve ser maior que zero.\n");
    }

    // Encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Procedimento para mostrar n multiplos de 30.
 * @param n - quantidade de multiplos a serem mostrados
 */
void multiplosDe5e6(int n) {
    int i = 0;
    
    printf("Multiplos de 30: ");
    for (i = 1; i <= n; i++) {
        // O i-esimo multiplo de 30 é i * 30
        printf("%d ", i * 30);
    }
    printf("\n");
}

/**
  Method_12.
*/
void method_0512() {
    int n = 0;

    // Identificador
    IO_id("Method_0512 - Multiplos de 5 e 6");

    // Ler dados
    n = IO_readint("Digite a quantidade: ");

    // Chamar o procedimento para executar a tarefa
    if (n > 0) {
        multiplosDe5e6(n);
    } else {
        printf("A quantidade deve ser maior que zero.\n");
    }

    // Encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Procedimento para gerar potencias de 8 em ordem decrescente.
 * @param n - quantidade de potencias a serem geradas
 */
void gerarPotenciasDe8(int n) {
    int i = 0; // Variavel de controle do loop (expoente)
    int potencia = 0;

    printf("Potencias de 8: ");
    // Loop decrescente, de n ate 1
    for (i = n; i >= 1; i--) {
        // Calcula 8 elevado a i
        potencia = (int)pow(8, i);
        // Mostra o resultado
        printf("%d ", potencia);
    }
    printf("\n"); // Pula uma linha no final para organizar
}


/**
  Method_13.
*/
void method_0513() {
    int n = 0;

    // Identificador
    IO_id("Method_0513 - Potencias de 8 decrescentes");

    // Ler a quantidade do teclado
    n = IO_readint("Digite a quantidade de potencias: ");

    // Verificar se n e' valido antes de chamar o procedimento
    if (n > 0) {
        // Chamar o procedimento para executar a tarefa
        gerarPotenciasDe8(n);
    } else {
        printf("Erro: A quantidade deve ser um valor positivo.\n");
    }

    // Encerrar
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Procedimento para mostrar n termos inversos de multiplos de 4.
 * @param n - quantidade de termos
 */
void mostrarInversosDe4(int n) {
    int i = 0;
    double fracao = 0.0;
    
    printf("Inversos dos multiplos de 4:\n");
    for (i = 1; i <= n; i++) {
        fracao = 1.0 / (4 * i);
        printf("1/%d = %lf\n", (4 * i), fracao);
    }
}

/**
  Method_14.
*/
void method_0514() {
    IO_id("Method_0514 - Inversos de multiplos de 4");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        mostrarInversosDe4(n);
    } else {
        printf("Erro: A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Procedimento para mostrar sequencia com potencias de x.
 * @param x - base da potencia
 * @param n - quantidade de termos
 */
void mostrarSequenciaX(double x, int n) {
    int i = 0;
    
    printf("1. Termo = 1\n"); // O primeiro termo e' sempre 1
    
    // Comeca do segundo termo em diante
    for (i = 1; i < n; i++) {
        double expoente = 2.0 * i + 1.0;
        double denominador = pow(x, expoente);
        printf("%d. Termo = 1/%.2lf^%.0lf = %lf\n", i + 1, x, expoente, 1.0 / denominador);
    }
}

/**
  Method_15.
*/
void method_0515() {
    IO_id("Method_0515 - Sequencia com potencias de x");
    double x = IO_readdouble("Digite o valor real (x): ");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        mostrarSequenciaX(x, n);
    } else {
        printf("Erro: A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao para somar os n primeiros multiplos de 4 e nao de 5.
 * @return soma dos valores
 * @param n - quantidade de termos
 */
int somarMultiplos4Nao5(int n) {
    int soma = 0;
    int count = 0; // Quantos numeros validos ja encontramos
    int numero = 4; // Comeca a testar a partir do 4

    printf("Termos somados: ");
    while (count < n) {
        if (numero % 4 == 0 && numero % 5 != 0) {
            soma += numero;
            printf("%d ", numero);
            count++;
        }
        numero++; // Passa para o proximo numero para testar
    }
    printf("\n");
    return soma;
}

/**
  Method_16.
*/
void method_0516() {
    IO_id("Method_0516 - Soma de multiplos de 4 e nao de 5");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        int soma = somarMultiplos4Nao5(n);
        printf("Soma = %d\n", soma);
    } else {
        printf("Erro: A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao para somar inversos dos n primeiros multiplos de 3 e nao de 5.
 * @return soma dos valores
 * @param n - quantidade de termos
 */
double somarInversos3Nao5(int n) {
    double soma = 0.0;
    int count = 0;
    int numero = 3;

    printf("Inversos somados: ");
    while (count < n) {
        if (numero % 3 == 0 && numero % 5 != 0) {
            soma += 1.0 / numero;
            printf("1/%d ", numero);
            count++;
        }
        numero++;
    }
    printf("\n");
    return soma;
}

/**
  Method_17.
*/
void method_0517() {
    IO_id("Method_0517 - Soma de inversos de multiplos de 3 e nao de 5");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        double soma = somarInversos3Nao5(n);
        printf("Soma = %lf\n", soma);
    } else {
        printf("Erro: A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao para somar n termos da sequencia que comeca com 6.
 * @return soma dos valores
 * @param n - quantidade de termos
 */
int somarSequencia6(int n) {
    int soma = 0;
    int termo = 6; // Primeiro termo da sequencia

    printf("Termos somados: ");
    for (int i = 0; i < n; i++) {
        soma += termo;
        printf("%d ", termo);
        termo = termo + (i + 1); // O proximo termo e' o atual + a posicao
    }
    printf("\n");
    return soma;
}

/**
  Method_18.
*/
void method_0518() {
    IO_id("Method_0518 - Soma da sequencia comecando em 6");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        int soma = somarSequencia6(n);
        printf("Soma = %d\n", soma);
    } else {
        printf("Erro: A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao para somar n quadrados a partir do 16.
 * @return soma dos valores
 * @param n - quantidade de termos
 */
long long somarQuadrados(int n) {
    long long soma = 0; // Usar long long para evitar estouro com numeros grandes
    
    printf("Termos somados: ");
    for (int i = 0; i < n; i++) {
        long long base = 4 + i;
        long long quadrado = base * base;
        soma += quadrado;
        printf("%lld ", quadrado);
    }
    printf("\n");
    return soma;
}

/**
  Method_19.
*/
void method_0519() {
    IO_id("Method_0519 - Soma de quadrados a partir do 16");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        long long soma = somarQuadrados(n);
        printf("Soma = %lld\n", soma);
    } else {
        printf("Erro: A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao para somar inversos de n termos de uma sequencia que termina em 4.
 * @return soma dos valores
 * @param n - quantidade de termos
 */
double somarInversosTerminando4(int n) {
    double soma = 0.0;
    int termo = 4;
    int i = 1;
    
    // Primeiro, descobrimos quais sao os n termos
    // Para isso, criamos um array temporario
    int termos[n];
    termos[n-1] = 4; // O ultimo e' 4
    for(i = n - 2; i >= 0; i--) {
        termos[i] = termos[i+1] + (n - 1 - i);
    }

    // Agora que temos os termos, somamos os inversos
    printf("Inversos somados: ");
    for(i = 0; i < n; i++) {
        soma += 1.0 / termos[i];
        printf("1/%d ", termos[i]);
    }

    printf("\n");
    return soma;
}


/**
  Method_20.
*/

void method_0520() {
    IO_id("Method_0520 - Soma de inversos da sequencia terminando em 4");
    int n = IO_readint("Digite a quantidade de termos: ");
    if (n > 0) {
        double soma = somarInversosTerminando4(n);
        printf("Soma = %lf\n", soma);
    } else {
        printf("Erro: A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Funcao para calcular o fatorial de um numero.
 * @return fatorial do numero
 * @param n - numero para calcular o fatorial
 */
long long fatorial(int n) {
    long long fat = 1;
    if (n < 0) return -1; // Fatorial de negativo nao existe
    if (n == 0) return 1; // Fatorial de 0 e' 1

    for (int i = n; i >= 1; i--) {
        fat = fat * i;
    }
    return fat;
}

/**
  Method_E1.
*/
void method_05E1() {
    IO_id("Method_05E1 - Fatorial");
    int n = IO_readint("Digite um numero para calcular o fatorial: ");
    long long fat = fatorial(n);
    if (fat >= 0) {
        printf("Fatorial de %d = %lld\n", n, fat);
    } else {
        printf("Erro: Nao existe fatorial de numero negativo.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}// end method_05E1 ( )

/**
 * Funcao para calcular o produto de uma serie com fatoriais.
 * @return produto da serie
 * @param n - quantidade de termos
 */
double produtoSerieFatorial(int n) {
    double produto = 1.0;
    
    printf("Termos multiplicados:\n");
    for (int i = 1; i <= n; i++) {
        double numerador = 2.0 * i + 1.0;
        long long den_fat_arg = 2 * i + 2;
        long long denominador_fatorial = fatorial(den_fat_arg);
        
        double termo = 1.0 + (numerador / denominador_fatorial);
        printf("(1 + %.0lf/%lld!) ", numerador, den_fat_arg);
        
        produto = produto * termo;
    }
    printf("\n");
    return produto;
}

/**
  Method_E2.
*/
void method_05E2() {
    IO_id("Method_05E2 - Produto de serie com fatorial");
    int n = IO_readint("Digite a quantidade de termos (n > 0): ");
    if (n > 0) {
        double produto = produtoSerieFatorial(n);
        printf("Produto = %lf\n", produto);
    } else {
        printf("Erro: A quantidade deve ser positiva.\n");
    }
    IO_pause("Apertar ENTER para continuar");
} // end method_05E2 ( )


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
        IO_println ( "Exemplo0500 - Programa - v0.0" );
        
        // ler do teclado
        IO_println ( "Opcoes" );
        IO_println ( " 0 - parar" );
        IO_println ( " 1 - Method_01" );
        IO_println ( " 2 - Method_02" );
        IO_println ( " 3 - Method_03" );
        IO_println ( " 4 - Method_04" );
        IO_println ( " 5 - Method_05" );
        IO_println ( " 6 - Method_06" );
        IO_println ( " 7 - Method_07" );
        IO_println ( " 8 - Method_08" );
        IO_println ( " 9 - Method_09" );
        IO_println ( "10 - Method_10" );
        IO_println ( "11 - Method_0511" );
        IO_println ( "12 - Method_0512" );
        IO_println ( "13 - Method_0513" );
        IO_println ( "14 - Method_0514" );
        IO_println ( "15 - Method_0515" );
        IO_println ( "16 - Method_0516" );
        IO_println ( "17 - Method_0517" );
        IO_println ( "18 - Method_0518" );
        IO_println ( "19 - Method_0519" );
        IO_println ( "20 - Method_0520" );
        IO_println ( "21 - Method_05E1" );
        IO_println ( "22 - Method_05E2" );
        IO_println ( "" );
        
        x = IO_readint ( "Entrar com uma opcao: " );
        
        // testar valor
        switch ( x )
        {
            case 0:
            break;
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
            case 11: method_0511 ( ); break;
            case 12: method_0512 ( ); break;
            case 13: method_0513 ( ); break;
            case 14: method_0514 ( ); break;
            case 15: method_0515 ( ); break;
            case 16: method_0516 ( ); break;
            case 17: method_0517 ( ); break;
            case 18: method_0518 ( ); break;
            case 19: method_0519 ( ); break;
            case 20: method_0520 ( ); break;
            case 21: method_05E1 ( ); break;
            case 22: method_05E2 ( ); break;
            default:
            IO_println ( "ERRO: Valor invalido." );
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
---------------------------------------------- Previsao de testes

Method_0511:
- Entrada: n = 5
- Saída obtida: 6 12 18 24 30
- Resultado: ( OK )

Method_0512:
- Entrada: n = 5
- Saída obtida: 30 60 90 120 150
- Resultado: ( OK )

Method_0513:
- Entrada: n = 5
- Saída obtida: 32768 4096 512 64 8
- Resultado: ( OK )

Method_0514:
- Entrada: n = 5
- Saída obtida: 
1/4 = 0.250000
1/8 = 0.125000
1/12 = 0.083333
1/16 = 0.062500
1/20 = 0.050000
- Resultado: ( OK )

Method_0515:
- Entrada: x = 2.0, n = 5
- Saída obtida: 
1. Termo = 1
2. Termo = 1/2.00^3 = 0.125000
3. Termo = 1/2.00^5 = 0.031250
4. Termo = 1/2.00^7 = 0.007813
5. Termo = 1/2.00^9 = 0.001953
- Resultado: ( OK )

Method_0516:
- Entrada: n = 6
- Saída obtida: 
Termos somados: 4 8 12 16 24 28 
Soma = 92
- Resultado: ( OK )

Method_0517:
- Entrada: n = 5
- Saída obtida: 
Inversos somados: 1/3 1/6 1/9 1/12 1/18 
Soma = 0.750000
- Resultado: ( OK )

Method_0518:
- Entrada: n = 5
- Saída obtida: 
Termos somados: 6 7 9 12 16 
Soma = 50
- Resultado: ( OK )

Method_0519:
- Entrada: n = 5
- Saída obtida: 
   Termos somados: 16 25 36 49 64 
   Soma = 190
- Resultado: ( OK )

Method_0520:
- Entrada: n = 5
- Saída obtida: 
Inversos somados: 1/14 1/10 1/7 1/5 1/4 
Soma = 0.764286
- Resultado: ( OK )

Method_05E1:
- Entrada: n = 7
- Saída obtida:  Fatorial de 7 = 5040
- Resultado: ( OK )

Method_05E2:
- Entrada: n = 3
- Saída obtida: Termos multiplicados:
(1 + 3/4!) (1 + 5/6!) (1 + 7/8!)
Produto = 1.133009
- Resultado: ( OK )

---------------------------------------------- Historico
Versao Data Modificacao
 0.1 12/09 Esboco inicial e exemplos do PDF
 0.2 14/09 Implementacao dos exercicios 0511-0520 e extras E1-E2
 
---------------------------------------------- Testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa e exemplos
 0.2 01. ( OK ) teste dos exercicios
*/
