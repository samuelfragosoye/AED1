/*
   Exemplo0300 - v0.0. - 05/09/2025
   Author: Samuel
*/
#include "io.h"

#define STR_SIZE 80   
#define STR_EMPTY ""  
/**
 Method_01 - Repeticao para ler certa quantidade de valores.
*/
void method_01() {
    int quantidade = 0;
    int valor = 0;
    int controle = 0;

    IO_id("Method 01 - v0.0");
    quantidade = IO_readint("Entrar com uma quantidade: ");

    controle = 1;
    while (controle <= quantidade) {
        printf("%d: ", controle);        // mostra o número da vez
        valor = IO_readint("");          // lê o valor do usuário
        printf("valor = %d\n", valor);   // mostra o valor lido
        controle = controle + 1;
    }

    IO_pause("Apertar ENTER para continuar");
}

 // end method_01 ( )


bool positive(int x) {
    bool result = false;
    if (x > 0) {
        result = true;
    }
    return result;
}

/**
 Method_02 - Ler valores e contar positivos.
*/
void method_02 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method02 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo
 if ( positive ( valor ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

bool belongsTo(int x, int inferior, int superior) {
    bool result = false;
    if (inferior < x && x < superior) {
        result = true;
    }
    return result;
}

/**
 Method_03 - Ler valores e contar positivos menores que 100.
*/

void method_03 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method_03 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo
 if ( belongsTo ( valor, 0, 100 ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

bool even(int x) {
    bool result = false;
    if (x % 2 == 0) {
        result = true;
    }
    return result;
}

/**
 Method_04 - Ler valores e contar positivos menores que 100 e pares.
*/
void method_04 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Method_04 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo menor que 100 e par
 if ( belongsTo ( valor, 0, 100 ) && even ( valor ) )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
 Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
*/

void method_05 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
 bool ok = false;
// identificar
 IO_id ( "EXEMPLO0405 - Method05 - v0.0" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo menor que 100 e par
 ok = belongsTo ( valor, 0, 100 );
 ok = ok && even ( valor );
 if ( ok )
 {
 contador = contador + 1;
 } // end if
 // passar ao proximo valor
 controle = controle + 1;
 } // end while
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

bool isLowerCase(char x) {
    bool result = false;
    if ('a' <= x && x <= 'z') {
        result = true;
    }
    return result;
}

/**
 Method_06 - Ler palavra e contar letras minusculas.
*/
void method_06 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Method06 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar se caractere e' letra minuscula
 if ( isLowerCase ( simbolo ) )
 {
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de minusculas
 IO_printf ( "%s%d\n", "Minusculas = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
 Method_07 - Ler palavra, contar e mostrar letras minusculas.
*/
void method_07 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Method07 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar se caractere e' letra minuscula
 if ( isLowerCase ( simbolo ) )
 {
 // mostrar
 IO_printf ( "%c ", simbolo );
 // contar
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de minusculas
 IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
 Method_08 - Ler palavra, contar e mostrar letras minusculas (alternativo).
*/
void method_08 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
 chars minusculas = IO_new_chars ( STR_SIZE );
 strcpy ( minusculas, STR_EMPTY ); // vazio
// identificar
 IO_id ( "Method08 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar as letras minusculas de uma palavra
 if ( isLowerCase ( simbolo ) )
 {
 // concatenar simbolo encontrado
 minusculas = IO_concat ( minusculas, IO_toString_c ( simbolo ) );
 // contar
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de minusculas
 IO_printf ( "\n%s%d [%s]\n", "Minusculas = ", contador, minusculas );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

bool isDigit(char x) {
    bool result = false;
    if ('0' <= x && x <= '9') {
        result = true;
    }
    return result;
}

/**
 Method_09 - Ler palavra e contar os algarismos.
*/
void method_09 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Method09 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com caracteres: " );
// determinar a quantidade de simbolos
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar os algarismos em uma cadeia de caracteres
 if ( isDigit ( simbolo ) )
 {
 // mostrar
 IO_printf ( "%c ", simbolo );
 // contar
 contador = contador + 1;
 } // end if
 } // end for
// mostrar a quantidade de digitos
 IO_printf ( "\n%s%d\n", "Algarismos = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

bool isADigit(char x) {
    return ('0' <= x && x <= '9');
}

char* concatADigit(char* string, char digit) {
    return IO_concat(string, IO_toString_c(digit));
}

/**
 Method_10.
*/
void method_10 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 chars digitos = IO_new_chars ( STR_SIZE );
 strcpy ( digitos, STR_EMPTY ); // vazio
// identificar
 IO_id ( "Method_10 - v0.0" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar os algarismos em uma cadeia de caracteres
 if ( isADigit ( simbolo ) )
 {
 // concatenar simbolo encontrado
 digitos = concatADigit ( digitos, simbolo );
 } // end if
 } // end for
// mostrar a quantidade de digitos
 IO_printf ( "\n%s%d [%s]\n", "Algarismos = ", strlen( digitos ), digitos );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

// Exercícios solicitados
void method_0411() {
    int quantidade = 0;
    double inferior = 0.0, superior = 0.0;
    double valor = 0.0;
    int dentro = 0, fora = 0;
    int controle = 0;

    IO_id("Method_0411 - Contar valores dentro e fora do intervalo");
    
    quantidade = IO_readint("Quantidade de valores reais: ");
    inferior = IO_readint("Limite inferior do intervalo: ");
    superior = IO_readint("Limite superior do intervalo: ");

    for (controle = 1; controle <= quantidade; controle++) {
        valor = IO_readint(IO_concat(IO_concat("Valor ", IO_toString_d(controle)), ": "));
        
        if (valor >= inferior && valor <= superior) {
            dentro++;
        } else {
            fora++;
        };
    }

    IO_printf("Dentro do intervalo: %d\n", dentro);
    IO_printf("Fora do intervalo: %d\n", fora);
    IO_pause("Apertar ENTER para continuar");
}

bool isUpperCase(char x) {
    return ('A' <= x && x <= 'Z');
}

void method_0412() {
    char* sequencia = IO_new_chars(STR_SIZE);
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '-';
    int contador = 0;

    IO_id("Method_0412 - Contar letras minúsculas entre 'f' e 's'");
    sequencia = IO_readstring("Entrar com uma sequência: ");
    tamanho = strlen(sequencia);

    for (posicao = 0; posicao < tamanho; posicao++) {
        simbolo = sequencia[posicao];
        if (isLowerCase(simbolo) && simbolo > 'f' && simbolo < 's') {
            contador++;
        }
    }

    IO_printf("Quantidade: %d\n", contador);
    IO_pause("Apertar ENTER para continuar");
}

int countLowerCaseBetween(char* str, char min, char max) {
    int contador = 0;
    int tamanho = strlen(str);
    
    for (int i = 0; i < tamanho; i++) {
        char c = str[i];
        if (isLowerCase(c) && c > min && c < max) {
            contador++;
        }
    }
    
    return contador;
}

void method_0413() {
    char* sequencia = IO_new_chars(STR_SIZE);

    IO_id("Method_0413 - Contar letras minúsculas entre 'f' e 's' com função");
    sequencia = IO_readstring("Entrar com uma sequência: ");
    
    int quantidade = countLowerCaseBetween(sequencia, 'f', 's');
    IO_printf("Quantidade: %d\n", quantidade);
    IO_pause("Apertar ENTER para continuar");
}

char* extractLowerCaseBetween(char* str, char min, char max) {
    static char result[STR_SIZE];
    int tamanho = strlen(str);
    int index = 0;
    
    strcpy(result, STR_EMPTY);
    
    for (int i = 0; i < tamanho; i++) {
        char c = str[i];
        if (isLowerCase(c) && c > min && c < max) {
            result[index++] = c;
        }
    }
    result[index] = '\0';
    
    return result;
}

void method_0414() {
    char* sequencia = IO_new_chars(STR_SIZE);

    IO_id("Method_0414 - Extrair letras minúsculas entre 'f' e 's'");
    sequencia = IO_readstring("Entrar com uma sequência: ");
    
    char* minusculas = extractLowerCaseBetween(sequencia, 'f', 's');
    IO_printf("Letras encontradas: %s\n", minusculas);
    IO_printf("Quantidade: %d\n", strlen(minusculas));
    IO_pause("Apertar ENTER para continuar");
}

int countLettersBetween(char* str, char min, char max) {
    int contador = 0;
    int tamanho = strlen(str);
    
    for (int i = 0; i < tamanho; i++) {
        char c = str[i];
        if ((isLowerCase(c) || isUpperCase(c)) && 
            ((c > min && c < max) || (c > toupper(min) && c < toupper(max)))) {
            contador++;
        }
    }
    
    return contador;
}

void method_0415() {
    char* sequencia = IO_new_chars(STR_SIZE);

    IO_id("Method_0415 - Contar letras entre 'f'/'F' e 's'/'S'");
    sequencia = IO_readstring("Entrar com uma sequência: ");
    
    int quantidade = countLettersBetween(sequencia, 'f', 's');
    IO_printf("Quantidade: %d\n", quantidade);
    IO_pause("Apertar ENTER para continuar");
}

char* extractLettersBetween(char* str, char min, char max) {
    static char result[STR_SIZE];
    int tamanho = strlen(str);
    int index = 0;
    
    strcpy(result, STR_EMPTY);
    
    for (int i = 0; i < tamanho; i++) {
        char c = str[i];
        if ((isLowerCase(c) || isUpperCase(c)) && 
            ((c > min && c < max) || (c > toupper(min) && c < toupper(max)))) {
            result[index++] = c;
        }
    }
    result[index] = '\0';
    
    return result;
}

void method_0416() {
    char* sequencia = IO_new_chars(STR_SIZE);

    IO_id("Method_0416 - Extrair letras entre 'f'/'F' e 's'/'S'");
    sequencia = IO_readstring("Entrar com uma sequência: ");
    
    char* letras = extractLettersBetween(sequencia, 'f', 's');
    IO_printf("Letras encontradas: %s\n", letras);
    IO_printf("Quantidade: %d\n", strlen(letras));
    IO_pause("Apertar ENTER para continuar");
}

int countEvenDigits(char* str) {
    int contador = 0;
    int tamanho = strlen(str);
    
    for (int i = 0; i < tamanho; i++) {
        char c = str[i];
        if (isDigit(c) && (c - '0') % 2 == 0) {
            contador++;
        }
    }
    
    return contador;
}

void method_0417() {
    char* sequencia = IO_new_chars(STR_SIZE);

    IO_id("Method_0417 - Contar dígitos pares");
    sequencia = IO_readstring("Entrar com uma sequência: ");
    
    int quantidade = countEvenDigits(sequencia);
    IO_printf("Dígitos pares: %d\n", quantidade);
    IO_pause("Apertar ENTER para continuar");
}

bool isAlphaNumeric(char c) {
    return isLowerCase(c) || isUpperCase(c) || isDigit(c);
}

char* extractNonAlphaNumeric(char* str) {
    static char result[STR_SIZE];
    int tamanho = strlen(str);
    int index = 0;
    
    strcpy(result, STR_EMPTY);
    
    for (int i = 0; i < tamanho; i++) {
        char c = str[i];
        if (!isAlphaNumeric(c)) {
            result[index++] = c;
        }
    }
    result[index] = '\0';
    
    return result;
}

void method_0418() {
    char* sequencia = IO_new_chars(STR_SIZE);

    IO_id("Method_0418 - Extrair símbolos não alfanuméricos");
    sequencia = IO_readstring("Entrar com uma sequência: ");
    
    char* simbolos = extractNonAlphaNumeric(sequencia);
    IO_printf("Símbolos não alfanuméricos: %s\n", simbolos);
    IO_printf("Quantidade: %d\n", strlen(simbolos));
    IO_pause("Apertar ENTER para continuar");
}

char* extractAlphaNumeric(char* str) {
    static char result[STR_SIZE];
    int tamanho = strlen(str);
    int index = 0;
    
    strcpy(result, STR_EMPTY);
    
    for (int i = 0; i < tamanho; i++) {
        char c = str[i];
        if (isAlphaNumeric(c)) {
            result[index++] = c;
        }
    }
    result[index] = '\0';
    
    return result;
}

void method_0419() {
    char* sequencia = IO_new_chars(STR_SIZE);

    IO_id("Method_0419 - Extrair símbolos alfanuméricos");
    sequencia = IO_readstring("Entrar com uma sequência: ");
    
    char* simbolos = extractAlphaNumeric(sequencia);
    IO_printf("Símbolos alfanuméricos: %s\n", simbolos);
    IO_printf("Quantidade: %d\n", strlen(simbolos));
    IO_pause("Apertar ENTER para continuar");
}

int countAlphaNumericInString(char* str) {
    int contador = 0;
    int tamanho = strlen(str);
    
    for (int i = 0; i < tamanho; i++) {
        if (isAlphaNumeric(str[i])) {
            contador++;
        }
    }
    
    return contador;
}

void method_0420() {
    int quantidade = 0;
    int total = 0;
    int controle = 0;
    char* sequencia = IO_new_chars(STR_SIZE);

    IO_id("Method_0420 - Contar alfanuméricos em múltiplas cadeias");
    quantidade = IO_readint("Quantidade de cadeias: ");

    for (controle = 1; controle <= quantidade; controle++) {
        sequencia = IO_readstring(IO_concat(IO_concat("Cadeia ", IO_toString_d(controle)), ": "));
        
        int count = countAlphaNumericInString(sequencia);
        IO_printf("Alfanuméricos: %d\n", count);
        total += count;
    }

    IO_printf("Total acumulado: %d\n", total);
    IO_pause("Apertar ENTER para continuar");
}

// Tarefas extras
void method_04E1() {
    int quantidade = 0;
    int total = 0;
    int controle = 0;
    char sequencia[STR_SIZE];

    IO_id("Method_04E1 - Contar alfanuméricos com espaços");
    quantidade = IO_readint("Quantidade de cadeias: ");

    for (controle = 1; controle <= quantidade; controle++) {
        printf("Cadeia %d: ", controle);
        fgets(sequencia, STR_SIZE, stdin);
        sequencia[strcspn(sequencia, "\n")] = '\0';
        
        int count = countAlphaNumericInString(sequencia);
        int tamanho = strlen(sequencia);
        
        if (tamanho > 4) {
            total += count;
        }
        
        IO_printf("Alfanuméricos: %d (Total: %d)\n", count, total);
    }

    IO_printf("Total final: %d\n", total);
    IO_pause("Apertar ENTER para continuar");
}

int countDigits(char* str) {
    int contador = 0;
    int tamanho = strlen(str);
    
    for (int i = 0; i < tamanho; i++) {
        if (isDigit(str[i])) {
            contador++;
        }
    }
    
    return contador;
}

void method_04E2() {
    char* sequencia1 = IO_new_chars(STR_SIZE);
    char* sequencia2 = IO_new_chars(STR_SIZE);
    int digitos1 = 0, digitos2 = 0;

    IO_id("Method_04E2 - Comparar quantidade de dígitos");
    
    sequencia1 = IO_readstring("Primeira sequência: ");
    sequencia2 = IO_readstring("Segunda sequência: ");
    
    digitos1 = countDigits(sequencia1);
    digitos2 = countDigits(sequencia2);
    
    IO_printf("Dígitos na primeira: %d\n", digitos1);
    IO_printf("Dígitos na segunda: %d\n", digitos2);
    
    if (digitos1 < digitos2) {
        IO_printf("Primeira sequência tem menos dígitos\n");
    } else if (digitos2 < digitos1) {
        IO_printf("Segunda sequência tem menos dígitos\n");
    } else {
        IO_printf("Ambas têm a mesma quantidade de dígitos\n");
    }
    
    IO_pause("Apertar ENTER para continuar");
}

/**
 Method_01:
- Entrada: quantidade = 5, valores = {1, 2, 3, 4, 5}
- Saída obtida: 
  valor = 1
  valor = 2
  valor = 3
  valor = 4
  valor = 5
- Resultado: OK

Method_02:
- Entrada: quantidade = 5, valores = {-2, 0, 3, -5, 7}
- Saída obtida: Positivos = 2
- Resultado: OK

Method_03:
- Entrada: quantidade = 6, valores = {-10, 25, 50, 75, 100, 125}
- Saída obtida: Positivos menores que 100 = 3
- Resultado: OK

Method_04:
- Entrada: quantidade = 8, valores = {2, 15, 24, 33, 50, 60, 99, 100}
- Saída obtida: Positivos menores que 100 e pares = 4
- Resultado: OK

Method_05:
- Entrada: quantidade = 7, valores = {4, 18, 25, 36, 55, 72, 88}
- Saída obtida: Positivos menores que 100 e pares = 5
- Resultado: OK

Method_06:
- Entrada: palavra = "AaKkLmM0*Nx"
- Saída obtida: Minusculas = 4
- Resultado: OK

Method_07:
- Entrada: palavra = "AaKkLmM0*Nx"
- Saída obtida: a k m x | Minusculas = 4
- Resultado: OK

Method_08:
- Entrada: palavra = "AaKkLmM0*Nx"
- Saída obtida: Minusculas = 4 [akmx]
- Resultado: OK

Method_09:
- Entrada: caracteres = "A1b2C3d4E5f6"
- Saída obtida: 1 2 3 4 5 6 | Algarismos = 6
- Resultado: OK

Method_10:
- Entrada: palavra = "A1b2C3d4E5f6"
- Saída obtida: Algarismos = 6 [123456]
- Resultado: OK

Method_0411:
- Entrada: quantidade = 10, intervalo = [10.4:23.4], valores = {5.1, 10.5, 12.4, 14.2, 15.3, 18.3, 20.4, 21.7, 23.1, 24.2}
- Saída obtida: Dentro do intervalo: 8, Fora do intervalo: 2
- Resultado: OK

Method_0412:
- Entrada: sequência = "AaKkLmM0*Nx"
- Saída obtida: Quantidade: 2
- Resultado: OK

Method_0413:
- Entrada: sequência = "AaKkLmM0*Nx"
- Saída obtida: Quantidade: 2
- Resultado: OK

Method_0414:
- Entrada: sequência = "AaKkLmM0*Nx"
- Saída obtida: Letras encontradas: km, Quantidade: 2
- Resultado: OK

Method_0415:
- Entrada: sequência = "AaKkLmM0*Nx"
- Saída obtida: Quantidade: 6
- Resultado: OK

Method_0416:
- Entrada: sequência = "AaKkLmM0*Nx"
- Saída obtida: Letras encontradas: Aakkmx, Quantidade: 6
- Resultado: OK

Method_0417:
- Entrada: sequência = "A1b2C3d4E5f6"
- Saída obtida: Dígitos pares: 3
- Resultado: OK

Method_0418:
- Entrada: sequência = "(A1b2+C3d4)*E5f6"
- Saída obtida: Símbolos não alfanuméricos: (+)*, Quantidade: 4
- Resultado: OK

Method_0419:
- Entrada: sequência = "(A1b2+C3d4)*E5f6"
- Saída obtida: Símbolos alfanuméricos: A1b2C3d4E5f6, Quantidade: 12
- Resultado: OK

Method_0420:
- Entrada: 
  Quantidade = 3
  Cadeias = {"(A1b2+C3d4)*E5f6", "[P&&Q]|[[R&&!S]", "(a<b&&b<c)"}
- Saída obtida: 
  Alfanuméricos: 12
  Alfanuméricos: 5
  Alfanuméricos: 3
  Total acumulado: 20
- Resultado: OK

Method_04E1:
- Entrada:
  Quantidade = 2
  Cadeias = {"A1b21 + C3d45", "E5f67 * G7h89"}
- Saída obtida: Total final: 20
- Resultado: OK

Method_04E2:
- Entrada:
  Primeira sequência = "A1b2"
  Segunda sequência = "C3d4E5"
- Saída obtida: 
  Dígitos na primeira: 2
  Dígitos na segunda: 3
  Primeira sequência tem menos dígitos
- Resultado: OK

 */

/**
  Funcao principal.
*/
int main() {
    int opcao = 0;

    do {
        printf("\n");
        printf("0 - Sair\n");
        printf("1 - Method_01\n");
        printf("2 - Method_02\n");
        printf("3 - Method_03\n");
        printf("4 - Method_04\n");
        printf("5 - Method_05\n");
        printf("6 - Method_06\n");
        printf("7 - Method_07\n");
        printf("8 - Method_08\n");
        printf("9 - Method_09\n");
        printf("10 - Method_10\n");
        printf("11 - Method_0411\n");
        printf("12 - Method_0412\n");
        printf("13 - Method_0413\n");
        printf("14 - Method_0414\n");
        printf("15 - Method_0415\n");
        printf("16 - Method_0416\n");
        printf("17 - Method_0417\n");
        printf("18 - Method_0418\n");
        printf("19 - Method_0419\n");
        printf("20 - Method_0420\n");
        printf("21 - Method_04E1\n");
        printf("22 - Method_04E2\n");
        
        opcao = IO_readint("Escolha uma opcao: ");

        switch (opcao) {
            case 0: break;
            case 1: method_01(); break;
            case 2: method_02(); break;
            case 3: method_03(); break;
            case 4: method_04(); break;
            case 5: method_05(); break;
            case 6: method_06(); break;
            case 7: method_07(); break;
            case 8: method_08(); break;
            case 9: method_09(); break;
            case 10: method_10(); break;
            case 11: method_0411(); break;
            case 12: method_0412(); break;
            case 13: method_0413(); break;
            case 14: method_0414(); break;
            case 15: method_0415(); break;
            case 16: method_0416(); break;
            case 17: method_0417(); break;
            case 18: method_0418(); break;
            case 19: method_0419(); break;
            case 20: method_0420(); break;
            case 21: method_04E1(); break;
            case 22: method_04E2(); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}