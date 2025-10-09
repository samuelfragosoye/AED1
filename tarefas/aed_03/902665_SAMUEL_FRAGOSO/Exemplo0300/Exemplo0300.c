/*
   Exemplo0300 - v0.0. - 26/08/2025
   Author: Samuel
*/

// dependencias
#include "io.h"  // para definicoes proprias
#include <string.h> // strlen, etc.

/**
   Method_00 - nao faz nada.
 */
void method_00 ( void )
{
    // nao faz nada
}
/**
 Method_01 - Repeticao com teste no inicio.
*/
void method_01 ( void )
{
// definir dado
 int x = 0;
// identificar
 IO_id ( "Method_01 - v0.0" );
// ler do teclado o valor inicial
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
 while ( x > 0 )
 {
 // mostrar valor atual
 IO_println ( IO_toString_d ( x ) );
 // passar ao proximo valor
 x = x - 1;
 } // end while
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )



/**
 Method_02 - Repeticao com teste no inicio.
*/
void method_02 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
// identificar
 IO_id ( "Method_02 - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
 y = x; // copiar o valor lido (e' melhor)
 while ( y > 0 )
 {
 // mostrar valor atual
 IO_println ( IO_toString_d ( x ) );
 // passar ao proximo valor
 y = y - 1;
 } // end while
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )



/**
 Method_03 - Repeticao com teste no inicio.
*/
void method_03 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
// identificar
 IO_id ( "Method_03 - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
 y = 1; // o valor lido devera' ser preservado
 while ( y <= x )
 {
 // mostrar valor atual
 IO_printf ( "%d\n", y );
 // passar ao proximo valor
 y = y + 1;
 } // end while
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )



/**
 Method_04 - Repeticao com teste no inicio e variacao.
*/
void method_04 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int z = 0;
// identificar
 IO_id ( "Method_04 - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
 for ( y = 1; y <= x; y = y + 1 )
 {
 // ler valor do teclado
 z = IO_readint ( "Valor = " );
 // mostrar valor atual
 IO_printf ( "%d. %d\n", y, z );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )



/**
 Method_05 - Repeticao com teste no inicio e variacao.
*/
void method_05 ( void )
{
// definir dado
 int x = 0;
 int y = 0;
 int z = 0;
// identificar
 IO_id ( "Method_05 - v0.0" );
// ler do teclado
 x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
 for ( y = x; y >= 1; y = y - 1 )
 {
 // ler valor do teclado
 z = IO_readint ( "Valor = " );
 // mostrar valor atual
 IO_printf ( "%d. %d\n", y, z );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )



/**
 Method_06 - Repeticao sobre cadeia de caracateres.
*/
void method_06 ( void )
{
// definir dado
 int x = 0;
 int y = 0;

 chars palavra = IO_new_chars (STR_SIZE);
 int tamanho = 0;
// identificar
 IO_id ( "Method_06 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// repetir para cada letra
 tamanho = strlen ( palavra ) - 1;
// OBS: A cadeia de caracteres iniciam suas posições em zero.
// inicio teste variacao
 for ( y = tamanho; y >= 0; y = y - 1 )
 {
 // mostrar valor atual
 IO_printf ( "%d: [%c]\n", y, palavra [y] );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )



/**
 Method_07 - Repeticao sobre cadeia de caracateres.
*/
void method_07 ( void )
{
// definir dado
 int x = 0;
 int y = 0;

chars palavra = IO_new_chars(STR_SIZE);
 int tamanho = 0;
// identificar
 IO_id ( "Method07 - v0.0" );
// ler do teclado
 IO_printf ( "Entrar com uma palavra: " );
 scanf ( "%s", palavra ); getchar( );
// OBS: A cadeia de caracteres dispensa a indicacao de endereco (&) na leitura.
// repetir para cada letra
 tamanho = strlen ( palavra );
// OBS: A cadeia de caracteres iniciam suas posições em zero.
// inicio teste variacao
 for ( y = 0; y < tamanho; y = y + 1 )
 {
 // mostrar valor atual
 IO_printf ( "%d: [%c]\n", y, palavra [y] );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )



/** 
 Method_08 - Repeticao com intervalos.
*/
void method_08 ( void )
{
// definir dado
 int inferior = 0;
 int superior = 0;
 int x = 0;
// identificar
 IO_id ( "Method08 - v0.0" );
// ler do teclado
 inferior = IO_readint ( "Limite inferior do intervalo: " );
 superior = IO_readint ( "Limite superior do intervalo : " );
// inicio teste variacao
 for ( x = inferior; x <= superior; x = x + 1 )
 {
 // mostrar valor atual
 IO_printf ( "%d\n", x );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )



/**
 Method_09 - Repeticao com intervalos.
*/
void method_09 ( void )
{
// definir dado
 double inferior = 0;
 double superior = 0;
 double passo = 0;
 double x = 0;
// identificar
 IO_id ( "Method_09 - v0.0" );
// ler do teclado
 inferior = IO_readdouble ( "Limite inferior do intervalo : " );
 superior = IO_readdouble ( "Limite superior do intervalo : " );
 passo = IO_readdouble ( "Variacao no intervalo (passo): " );
// inicio teste variacao
 for ( x = superior; x >= inferior; x = x - passo )
 {
 // mostrar valor atual
 IO_printf ( "%lf\n", x );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )



/**
 Method_10 - Repeticao com confirmacao.
*/
void method_10 ( void )
{
// definir dado
 double inferior = 0;
 double superior = 0;
 double passo = 0;
 double x = 0;
// identificar
 IO_id ( "Method10 - v0.0" );
// ler do teclado
 inferior = IO_readdouble ( "Limite inferior do intervalo : " );
// repetir ate' haver confirmacao de validade
 do
 {
 superior = IO_readdouble ( "Limite superior do intervalo: " );
 }
 while ( inferior >= superior );
// repetir ate' haver confirmacao de validade
 do
 {
 passo = IO_readdouble ( "Variacao no intervalo (passo): " );
 }
 while ( passo <= 0.0 );
// inicio teste variacao
 for ( x = inferior; x <= superior; x = x + passo )
 {
 // mostrar valor atual
 IO_printf ( "%lf\n", x );
 } // end for
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )



void method_0311 ( void )
{
    chars palavra = IO_new_chars ( STR_SIZE );
    int i;

    IO_id ( "Method_0311 - v0.0" );
    palavra = IO_readstring ( "Entrar com uma palavra: " );

    for ( i = 0; i < strlen(palavra); i++ )
    {
        if ( palavra[i] >= 'A' && palavra[i] <= 'Z' && palavra[i] < 'K' )
        {
            IO_printf ( "[%c]\n", palavra[i] );
        }
    }

    IO_pause ( "Apertar ENTER para continuar" );
}

void method_0312 ( void )
{
    chars palavra = IO_new_chars ( STR_SIZE );
    int i, count = 0;

    IO_id ( "Method_0312 - v0.0" );
    palavra = IO_readstring ( "Entrar com uma palavra: " );

    for ( i = 0; i < strlen(palavra); i++ )
    {
        if ( palavra[i] >= 'a' && palavra[i] <= 'z' && palavra[i] > 'k' )
        {
            IO_printf ( "[%c]\n", palavra[i] );
            count++;
        }
    }

    IO_printf ( "Total = %d\n", count );
    IO_pause ( "Apertar ENTER para continuar" );
}

void method_0313 ( void ) {
chars palavra = IO_new_chars(STR_SIZE);
int i, count = 0;
IO_id("Method_0313 - v0.0");
palavra = IO_readstring("Entrar com uma palavra: ");
for (i = strlen(palavra) - 1; i >= 0; i--) {
if (palavra[i] >= 'a' && palavra[i] <= 'z' && palavra[i] < 'k') {
IO_printf("[%c]\n", palavra[i]);
count++;
}
}
IO_printf("Total = %d\n", count);
IO_pause("Apertar ENTER para continuar");
}


void method_0314 ( void ) {
chars palavra = IO_new_chars(STR_SIZE);
int i, count = 0;
IO_id("Method_0314 - v0.0");
palavra = IO_readstring("Entrar com uma cadeia: ");
for (i = 0; i < strlen(palavra); i++) {
if ((palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= 'a' && palavra[i] <= 'z')) {
IO_printf("[%c]\n", palavra[i]);
count++;
}
}
IO_printf("Total = %d\n", count);
IO_pause("Apertar ENTER para continuar");
}


void method_0315 ( void ) {
chars palavra = IO_new_chars(STR_SIZE);
int i, count = 0;
IO_id("Method_0315 - v0.0");
palavra = IO_readstring("Entrar com uma cadeia: ");
for (i = strlen(palavra) - 1; i >= 0; i--) {
if (palavra[i] >= '0' && palavra[i] <= '9') {
int digito = palavra[i] - '0';
if (digito % 2 == 1) {
IO_printf("[%c]\n", palavra[i]);
count++;
}
}
}
IO_printf("Total = %d\n", count);
IO_pause("Apertar ENTER para continuar");
}


void method_0316 ( void ) {
chars palavra = IO_new_chars(STR_SIZE);
int i, count = 0;
IO_id("Method_0316 - v0.0");
palavra = IO_readstring("Entrar com uma cadeia: ");
for (i = 0; i < strlen(palavra); i++) {
if (!((palavra[i] >= '0' && palavra[i] <= '9' && (palavra[i]-'0')%2==0) ||
(palavra[i] >= 'A' && palavra[i] <= 'Z') ||
(palavra[i] >= 'a' && palavra[i] <= 'z')) ) {
IO_printf("[%c]\n", palavra[i]);
count++;
}
}
IO_printf("Total = %d\n", count);
IO_pause("Apertar ENTER para continuar");
}


void method_0317 ( void ) {
int a, b, n, x, i, count = 0;
IO_id("Method_0317 - v0.0");
a = IO_readint("Limite inferior: ");
b = IO_readint("Limite superior: ");
n = IO_readint("Quantidade de valores: ");
for (i = 0; i < n; i++) {
x = IO_readint("Valor = ");
if (x % 6 == 0 && x >= a && x <= b) {
IO_printf("Valido: %d\n", x);
count++;
}
}
IO_printf("Total = %d\n", count);
IO_pause("Apertar ENTER para continuar");
}


void method_0318 ( void ) {
int a, b, n, x, i, count = 0;
IO_id("Method_0318 - v0.0");
a = IO_readint("Limite inferior: ");
b = IO_readint("Limite superior: ");
n = IO_readint("Quantidade de valores: ");
for (i = 0; i < n; i++) {
x = IO_readint("Valor = ");
if (x % 4 == 0 && x % 6 != 0 && x >= a && x <= b) {
IO_printf("Valido: %d\n", x);
count++;
}
}
IO_printf("Total = %d\n", count);
IO_pause("Apertar ENTER para continuar");
}

void method_0319 ( void ) {
    double a, b, x;
    int n, i, parteInt, count = 0;
    IO_id("Method_0319 - v0.0");
    do {
        a = IO_readdouble("Valor a: ");
        b = IO_readdouble("Valor b: ");
    } while (a >= b);
    n = IO_readint("Quantidade: ");
    for (i = 0; i < n; i++) {
        x = IO_readdouble("Valor = ");
        if (x > a && x < b) {
            parteInt = (int)x;
            if (parteInt % 2 == 1 && parteInt < 5) {
                IO_printf("Valido: %lf\n", x);
                count++;
            }
        }
    }
    IO_printf("Total = %d\n", count);
    IO_pause("Apertar ENTER para continuar");
}

void method_0320 ( void ) {
    double a, b, x, frac;
    int n, i, count = 0;
    IO_id("Method_0320 - v0.0");
    do {
        a = IO_readdouble("Valor a (0<a<1): ");
        b = IO_readdouble("Valor b (0<b<1): ");
    } while (a >= b || a <= 0 || b >= 1);
    n = IO_readint("Quantidade: ");
    for (i = 0; i < n; i++) {
        x = IO_readdouble("Valor = ");
        frac = x - (int)x;
        if (!(frac > a && frac < b)) {
            IO_printf("Valido: %lf\n", x);
            count++;
        }
    }
    IO_printf("Total = %d\n", count);
    IO_pause("Apertar ENTER para continuar");
}

// -------------------------- métodos extras --------------------------

void method_03E1 ( void ) {
    char cadeia[STR_SIZE];
    int i;
    IO_id("Method_03E1 - v0.0");
    IO_printf("Digite uma linha: ");
    fgets(cadeia, STR_SIZE, stdin);
    cadeia[strcspn(cadeia, "\n")] = '\0';
    for (i = 0; i < strlen(cadeia); i++) {
        if (!((cadeia[i] >= '0' && cadeia[i] <= '9') ||
              (cadeia[i] >= 'A' && cadeia[i] <= 'Z') ||
              (cadeia[i] >= 'a' && cadeia[i] <= 'z'))) {
            IO_printf("[%c]\n", cadeia[i]);
        }
    }
    IO_pause("Apertar ENTER para continuar");
}

void method_03E2 ( void ) {
    char cadeia[STR_SIZE];
    int i, soNaoAlfaNum = 1;
    IO_id("Method_03E2 - v0.0");
    IO_printf("Digite uma cadeia: ");
    fgets(cadeia, STR_SIZE, stdin);
    cadeia[strcspn(cadeia, "\n")] = '\0';
    for (i = 0; i < strlen(cadeia); i++) {
        if ((cadeia[i] >= '0' && cadeia[i] <= '9') ||
            (cadeia[i] >= 'A' && cadeia[i] <= 'Z') ||
            (cadeia[i] >= 'a' && cadeia[i] <= 'z')) {
            soNaoAlfaNum = 0;
        }
    }
    if (soNaoAlfaNum) IO_printf("Sequencia contem apenas nao-alfanumericos\n");
    else IO_printf("Ha letras ou digitos na sequencia\n");
    IO_pause("Apertar ENTER para continuar");
}







int main ( )
{
    int x = 0;

    do
    {
        IO_id ( "EXEMPLO0300 - Programa - v0.0" );

        IO_println ( "Opcoes"  );
        IO_println ( "0 - parar" );
        IO_println ( "1 - repeticao com teste no inicio" );
        IO_println ( "2 - metodo 02" );
        IO_println ( "3 - metodo 03" );
        IO_println ( "4 - metodo 04" );
        IO_println ( "5 - metodo 05" );
        IO_println ( "6 - metodo 06" );
        IO_println ( "7 - metodo 07" );
        IO_println ( "8 - metodo 08" );
        IO_println ( "9 - metodo 09" );
        IO_println ( "10 - metodo 10" );
        IO_println ( "11 - metodo 0311" );
        IO_println ( "12 - metodo 0312" );
        IO_println ( "13 - metodo 0313" );
        IO_println ( "14 - metodo 0314" );
        IO_println ( "15 - metodo 0315" );
        IO_println ( "16 - metodo 0316" );
        IO_println ( "17 - metodo 0317" );
        IO_println ( "18 - metodo 0318" );
        IO_println ( "19 - metodo 0319" );
        IO_println ( "20 - metodo 0320" );
        IO_println ( "21 - metodo extra 03E1" );
        IO_println ( "22 - metodo extra 03E2" );
        IO_println ( "" );

        x = IO_readint ( "Entrar com uma opcao: " );

        switch ( x )
        {
          case 0:  method_00 ( ); break;
          case 1:  method_01 ( ); break;
          case 2:  method_02 ( ); break;
          case 3:  method_03 ( ); break;
          case 4:  method_04 ( ); break;
          case 5:  method_05 ( ); break;
          case 6:  method_06 ( ); break;
          case 7:  method_07 ( ); break;
          case 8:  method_08 ( ); break;
          case 9:  method_09 ( ); break;
          case 10: method_10 ( ); break;
          case 11: method_0311 ( ); break;
          case 12: method_0312 ( ); break;
          case 13: method_0313 ( ); break;
          case 14: method_0314 ( ); break;
          case 15: method_0315 ( ); break;
          case 16: method_0316 ( ); break;
          case 17: method_0317 ( ); break;
          case 18: method_0318 ( ); break;
          case 19: method_0319 ( ); break;
          case 20: method_0320 ( ); break;
          // extras
          case 21: method_03E1 ( ); break;
          case 22: method_03E2 ( ); break;
          default:
            IO_pause ( IO_concat ( "Valor diferente das opcoes (", IO_toString_d ( x ) ) );
        }
    }
    while ( x != 0 );

    IO_pause ( "Apertar ENTER para terminar" );
    return 0;
}

/*
---------------------------------------------- comentarios de teste ----------------------------------------------


Previsão de testes para os métodos principais:
- method_0311: Entrada "PaLaVrA" → Saída: A (maiúsculas menores que K)
- method_0312: Entrada "PaLaVrA" → Saída: r (1 minúscula > 'k')
- method_0313: Entrada "PaLaVrA" → Saída: a, a (2 minúsculas < 'k' do fim ao início)
- method_0314: Entrada "P4LaVr@" → Saída: P, L, a, V, r
- method_0315: Entrada "P4LaVr@1" → Saída: 1
- method_0316: Entrada "P4LaVr@O!" → Saída: @, !
- method_0317: Intervalo [20:50], n=7, {10,20,30,42,54,60,84} → Saída: 20,30,42
- method_0318: Intervalo [15:55], n=7, {10,20,30,48,52,60,84} → Saída: 20,52
- method_0319: Intervalo (1.5:8.1), n=7, {1.0,2.4,3.3,4.1,5.5,6.3,8.6} → Saída: 3.3
- method_0320: Intervalo (0.25:0.50), n=7, {1.0,2.8,3.3,4.1,5.5,6.9,8.4} → Saída: 1.0, 2.8, 5.5, 6.9, 8.4
- method_03E1: Entrada "P4LaVr@O! & pAl4vR1n#a" → Saída: @, !, &, #
- method_03E2: Entrada "@!$%" → Saída: confirma apenas não alfanuméricos


---------------------------------------------- historico ----------------------------------------------
Versao Data Modificacao
0.1 26/08/2025 Criacao inicial com metodos 00-10
0.2 30/08/2025 Inclusao dos metodos 0311-0320
0.3 31/08/2025 Inclusao dos metodos extras 03E1-03E2
*/
