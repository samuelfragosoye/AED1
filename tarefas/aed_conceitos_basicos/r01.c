#include "io.h"

int somaImpares (int x){
   int i;
   int somaImpares = 0;
   
    for (i = 1; i <= x; i++){
        if (x % i == 0){
            if (i % 2 != 0){
            somaImpares = somaImpares + i;
        }
    }
}
    return somaImpares;
}

int somaPares (int x){
    int somaPares = 0;
    int i;

    for (i = 1; i <= x; i++){
        if (x % i == 0){
            if (i % 2 == 0){
                somaPares = somaPares + i;
            }
        }
    }
    return somaPares;
}

void somaDivisores (int n){
    int i, x;
    int totalImpares;
    int totalPares;

    if (n > 0){
        for (i = 0; i < n; i++)
        {
            printf("\nx=");
            scanf("%d", &x);

            totalImpares = somaImpares(x);
            totalPares = somaPares(x);

            if (totalImpares > totalPares){
                printf("Para %d: Soma dos impares (%d) E MAIOR que a dos pares (%d)\n", x, totalImpares, totalPares);
            } 
            if (totalImpares <= totalPares){
                printf("Para %d: Soma dos impares (%d) NAO E MAIOR que a dos pares (%d)\n", x, totalImpares, totalPares);
            }
    }
}
}

void method_01 (){
    int n;
    IO_id("Method 01 - Exercicio 1");

    printf("n= ");
    scanf("%d", &n);
    somaDivisores(n);

    
IO_flush();    
IO_pause("Aperte ENTER para continuar");
}

int testePrimo(int x){
    int i = 0;
    int divisores = 0;
    int resposta =0;

    if (x > 1){
        for (i = 1; i <= x; i++){
            if (x % i == 0){
                divisores = divisores + 1;
            }
        }
    }
    if (divisores == 2){
        resposta = 1;
    }

    return resposta;
}


void procedimento_02(int n){
    int i = 0;
    int x = 0;
    int cont = 0;

    if (n > 0){
        for(i = 1; i <= n; i++){
            printf("\nx= ");
            scanf("%d", &x);

            if (testePrimo(x)==1){
                cont = cont + 1;
            }
        }
    }
    printf("\nForam digitados %d numeros primos.\n", cont);
}
void method_02 (){
    int n;
    IO_id("Method 02 - Exercicio 2");
    
    printf("n= ");
    scanf("%d", &n);

    procedimento_02(n);

    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}

int testarSimbolo(char c){
    int resposta = 0;

    switch (c){
        case '&':
        case '|':
        case '!':

        resposta = 1;
        break;
    }
    return resposta;
}

int testarAritmetico(char c){
    int resposta = 0;

    switch (c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':

        resposta = 1;
        break;
    }
    return resposta;
}

int testarRelacional(char c){
    int resposta = 0;

    switch (c){
        case '<':
        case '>':
        case '=':

        resposta = 1;
        break;
    }
    return resposta;
}

int testarSeparador(char c){
    int resposta = 0;

    switch (c){
        case ' ':
        case ',':
        case ';':
        case '.':
        case ':':
        case '_':

        resposta = 1;
        break;
    }
    return resposta;
}

void procedimento_03(){
    char cadeia[100];
    int i = 0;
    char c;

    printf("Digite a cadeia: ");
    fgets(cadeia, 100, stdin);  

    for (i = 0; cadeia[i] != '\0'; i++){
        c = cadeia[i];

        if (testarSimbolo(c) == 1){
            printf("'%c' -> Logico\n", c);
        }
        else if (testarAritmetico(c) == 1){
            printf("'%c' -> Aritmetico\n", c);
        }
        else if (testarRelacional(c) == 1){
            printf("'%c' -> Relacional\n", c);
        }
        else if (testarSeparador(c) == 1){
            printf("'%c' -> Separador\n", c);
        }
        else if (c != '\n') { 
            printf("'%c' -> Outro simbolo\n", c);
        }
        else {
            printf("'%c' -> Nao identificado\n", c);
        }
    }
}

void method_03 (){
    int n;
    IO_id("Method 03 - Exercicio 3");

    procedimento_03();

    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}

/**
 * Funções auxiliares para Ex 04
 * [cite: 64] (Não usar biblioteca padrão)
 */
int isLetraMaiuscula(char c) {
    int resposta = 0;
    if (c >= 'A' && c <= 'Z') {
        resposta = 1;
    }
    return resposta;
}

int isLetraMinuscula(char c) {
    int resposta = 0;
    if (c >= 'a' && c <= 'z') {
        resposta = 1;
    }
    return resposta;
}

int isDigito(char c) {
    int resposta = 0;
    if (c >= '0' && c <= '9') {
        resposta = 1;
    }
    return resposta;
}

void procedimento_04() {
    char cadeia[100];
    int i = 0;
    char c;

    // Contadores [cite: 61]
    int count_maiusculas = 0;
    int count_minusculas = 0;
    int count_digitos = 0;
    int count_operadores = 0;
    int count_separadores = 0;

    printf("Digite a cadeia: ");
    fgets(cadeia, 100, stdin); [cite: 59]

    for (i = 0; cadeia[i] != '\0'; i++) {
        c = cadeia[i];

        // Reutilizar funções [cite: 63]
        if (isLetraMaiuscula(c) == 1) {
            count_maiusculas++;
        } else if (isLetraMinuscula(c) == 1) {
            count_minusculas++;
        } else if (isDigito(c) == 1) {
            count_digitos++;
        } else if (testarSimbolo(c) == 1 || testarAritmetico(c) == 1 || testarRelacional(c) == 1) {
            // Operadores (lógicos, aritméticos, relacionais) [cite: 62]
            count_operadores++;
        } else if (testarSeparador(c) == 1) {
            count_separadores++;
        }
    }

    printf("Letras maiusculas: %d\n", count_maiusculas);
    printf("Letras minusculas: %d\n", count_minusculas);
    printf("Digitos: %d\n", count_digitos);
    printf("Operadores (log, arit, rel): %d\n", count_operadores);
    printf("Separadores: %d\n", count_separadores);
}

void method_04 (){
    IO_id("Method 04 - Exercicio 4");
    procedimento_04();
    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}

// ----------------- EXERCICIO 05 -----------------

/**
 * Função auxiliar para Ex 05
 * Encontra o maior entre três valores. [cite: 73]
 */
double maior_de_tres(double a, double b, double c) {
    double maior = a;
    if (b > maior) {
        maior = b;
    }
    if (c > maior) {
        maior = c;
    }
    return maior;
}

void procedimento_05() {
    int n, i;
    double x;
    
    // Contadores e somas para as 3 faixas
    double soma1 = 0.0, soma2 = 0.0, soma3 = 0.0;
    int count1 = 0, count2 = 0, count3 = 0;
    double media1 = 0.0, media2 = 0.0, media3 = 0.0;

    printf("n= ");
    scanf("%d", &n); [cite: 68]

    for (i = 0; i < n; i++) {
        printf("x= ");
        scanf("%lf", &x); [cite: 69]

        if (x < -27.25) { [cite: 70]
            soma1 += x;
            count1++;
        } else if (x >= -21.75 && x <= 72.5) { [cite: 71]
            soma2 += x;
            count2++;
        } else if (x > 72.5) { [cite: 72]
            soma3 += x;
            count3++;
        }
    }

    // Calcular médias (evitando divisão por zero)
    if (count1 > 0) {
        media1 = soma1 / count1;
    }
    if (count2 > 0) {
        media2 = soma2 / count2;
    }
    if (count3 > 0) {
        media3 = soma3 / count3;
    }

    printf("Media (x < -27.25): %lf\n", media1);
    printf("Media (-21.75 <= x <= 72.5): %lf\n", media2);
    printf("Media (x > 72.5): %lf\n", media3);

    double maiorMedia = maior_de_tres(media1, media2, media3);
    printf("A maior media e: %lf\n", maiorMedia); [cite: 72]
}

void method_05 (){
    IO_id("Method 05 - Exercicio 5");
    procedimento_05();
    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}

// ----------------- EXERCICIO 06 -----------------

/**
 * Funções auxiliares para Ex 06
 */
// Testa pertencimento ao intervalo aberto ]a:b[ [cite: 85]
int estaNoIntervaloAberto(int x, int a, int b) {
    return (x > a && x < b);
}

// Calcula o termo da soma, se as condições forem válidas [cite: 83, 85]
double calcularTermo(int x) {
    double termo = 0.0;
    // Testa se é ímpar, não múltiplo de 3, e não é zero [cite: 83, 84]
    if (x % 2 != 0 && x % 3 != 0 && x != 0) {
        termo = 1.0 / (double)(x * x * x);
    }
    return termo;
}

void procedimento_06() {
    int a, b, x;
    double soma_total = 0.0;

    printf("a= ");
    scanf("%d", &a); [cite: 79]
    printf("b= ");
    scanf("%d", &b); [cite: 79]

    // Usar do-while [cite: 86]
    do {
        printf("x= ");
        scanf("%d", &x); [cite: 80]

        if (x != -1) { [cite: 81]
            if (estaNoIntervaloAberto(x, a, b)) { [cite: 82]
                soma_total += calcularTermo(x);
            }
        }
    } while (x != -1);

    printf("A soma dos cubos dos inversos e: %lf\n", soma_total);
}

void method_06 (){
    IO_id("Method 06 - Exercicio 6");
    procedimento_06();
    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}

// ----------------- EXERCICIO 07 -----------------

/**
 * Função auxiliar para Ex 07
 * Testa pertencimento ao intervalo aberto ]a:b[ para reais [cite: 101]
 */
int estaNoIntervaloAbertoReal(double x, double a, double b) {
    return (x > a && x < b);
}

void procedimento_07() {
    double a, b, x;
    int count_dentro = 0, count_fora = 0, count_acima = 0, count_abaixo = 0;
    int count_total = 0; // Total de valores válidos lidos

    printf("a= ");
    scanf("%lf", &a); [cite: 92]
    printf("b= ");
    scanf("%lf", &b); [cite: 92]

    // Usar do-while [cite: 103]
    do {
        printf("x= ");
        scanf("%lf", &x); [cite: 93]

        if (x != 0.0) { [cite: 95]
            count_total++;
            if (estaNoIntervaloAbertoReal(x, a, b)) { [cite: 97]
                count_dentro++;
            } else {
                count_fora++;
                if (x >= b) { // Acima do intervalo (ou no limite superior)
                    count_acima++;
                } else if (x <= a) { // Abaixo do intervalo (ou no limite inferior)
                    count_abaixo++;
                }
            }
        }
    } while (x != 0.0); [cite: 94]

    printf("Valores DENTRO do intervalo ]%lf:%lf[ : %d\n", a, b, count_dentro);
    printf("Valores FORA do intervalo: %d\n", count_fora);

    // Calcular porcentagens [cite: 99]
    double perc_acima = 0.0, perc_abaixo = 0.0;
    
    // Evitar divisão por zero [cite: 100]
    if (count_total > 0) {
        perc_acima = 100.0 * count_acima / count_total;
        perc_abaixo = 100.0 * count_abaixo / count_total;
    }

    printf("Porcentagem ACIMA do intervalo: %.2lf%%\n", perc_acima);
    printf("Porcentagem ABAIXO do intervalo: %.2lf%%\n", perc_abaixo);
}

void method_07 (){
    IO_id("Method 07 - Exercicio 7");
    procedimento_07();
    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}

// ----------------- EXERCICIO 08 -----------------

/**
 * Funções auxiliares para Ex 08 [cite: 114]
 */
int isCrescente(double x, double y, double z) {
    return (x < y && y < z); [cite: 111]
}

int isDecrescente(double x, double y, double z) {
    return (x > y && y > z); [cite: 112]
}

double getMaior(double x, double y, double z) { [cite: 123]
    double maior = x;
    if (y > maior) maior = y;
    if (z > maior) maior = z;
    return maior;
}

double getMenor(double x, double y, double z) { [cite: 126]
    double menor = x;
    if (y < menor) menor = y;
    if (z < menor) menor = z;
    return menor;
}

void procedimento_08() {
    double x, y, z;
    
    printf("x= ");
    scanf("%lf", &x); [cite: 110]
    printf("y= ");
    scanf("%lf", &y); [cite: 110]
    printf("z= ");
    scanf("%lf", &z); [cite: 110]

    if (isCrescente(x, y, z)) {
        printf("Os valores estao em ordem CRESCENTE.\n"); [cite: 111]
    } else if (isDecrescente(x, y, z)) {
        printf("Os valores estao em ordem DECRESCENTE.\n"); [cite: 112]
    } else {
        printf("Os valores NAO estao em ordem.\n"); [cite: 112]
        printf("Maior valor: %lf\n", getMaior(x, y, z));
        printf("Menor valor: %lf\n", getMenor(x, y, z));
    }
}

void method_08 (){
    IO_id("Method 08 - Exercicio 8");
    procedimento_08();
    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}

// ----------------- EXERCICIO 09 -----------------

/**
 * Funções auxiliares para Ex 09 [cite: 134]
 */
// Compara o código ASCII [cite: 132]
int isCrescenteChar(char x, char y, char z) {
    return (x < y && y < z); [cite: 130]
}

int isDecrescenteChar(char x, char y, char z) {
    return (x > y && y > z); [cite: 131]
}

// DICA: [cite: 133, 143]
int isSucessor(char c1, char c2) {
    return (c2 == c1 + 1);
}

void procedimento_09() {
    char x, y, z;
    
    // Usar " %c" para consumir newlines/espaços do buffer
    printf("x= ");
    scanf(" %c", &x); [cite: 129]
    printf("y= ");
    scanf(" %c", &y); [cite: 129]
    printf("z= ");
    scanf(" %c", &z); [cite: 129]

    if (isCrescenteChar(x, y, z)) {
        printf("Os caracteres estao em ordem CRESCENTE.\n"); [cite: 130]
    } else if (isDecrescenteChar(x, y, z)) {
        printf("Os caracteres estao em ordem DECRESCENTE.\n"); [cite: 131]
    } else {
        printf("Os caracteres NAO estao em ordem.\n"); [cite: 131]
    }
}

void method_09 (){
    IO_id("Method 09 - Exercicio 9");
    procedimento_09();
    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}

// ----------------- EXERCICIO 10 -----------------

/**
 * Funções auxiliares para Ex 10
 */
// Compara strings usando strcmp 
int isCrescenteStr(char x[], char y[], char z[]) {
    // crescente: x < y E y < z [cite: 152]
    return (strcmp(x, y) < 0 && strcmp(y, z) < 0);
}

int isDecrescenteStr(char x[], char y[], char z[]) {
    // decrescente: x > y E y > z [cite: 147, 154]
    return (strcmp(x, y) > 0 && strcmp(y, z) > 0);
}

void procedimento_10() {
    char x[100], y[100], z[100];
    
    printf("Cadeia x= ");
    scanf("%s", x); [cite: 146]
    printf("Cadeia y= ");
    scanf("%s", y); [cite: 146]
    printf("Cadeia z= ");
    scanf("%s", z); [cite: 146]

    if (isCrescenteStr(x, y, z)) {
        printf("As cadeias estao em ordem CRESCENTE.\n");
    } else if (isDecrescenteStr(x, y, z)) {
        printf("As cadeias estao em ordem DECRESCENTE.\n"); [cite: 147]
    } else {
        char *menor = x;
        char *maior = x;

        // Encontra a menor (alfabeticamente primeira)
        if (strcmp(y, menor) < 0) menor = y;
        if (strcmp(z, menor) < 0) menor = z;

        // Encontra a maior (alfabeticamente última)
        if (strcmp(y, maior) > 0) maior = y;
        if (strcmp(z, maior) > 0) maior = z;

        printf("As cadeias NAO estao em ordem.\n"); [cite: 148]
        printf("Menor cadeia (primeira em ordem alf.): %s\n", menor);
        printf("Maior cadeia (ultima em ordem alf.): %s\n", maior);
    }
}

void method_10 (){
    IO_id("Method 10 - Exercicio 10");
    procedimento_10();
    IO_flush();    
    IO_pause("Aperte ENTER para continuar");
}



int main ( int argc, char* argv [ ] )
{
    // definir dado
int opcao = 0;
// identificar
printf ( "%s\n", "Exemplo0100 - Programa = v0.0" );
printf ( "%s\n", "Autor: Samuel Fragoso" );
printf ( "\n" ); // mudar de linha

// acoes
// repetir
    
do
{
// para mostrar opcoes
printf ( "\n%s\n", "Opcoes:" );
printf ( "\n%s" , "0 - Terminar" );
printf ( "\n%s" , "1 - Method_01 - Exercicio 1" );
printf ( "\n%s" , "2 - Method_02 - Exercicio 2" );
printf ( "\n%s" , "3 - Method_03 - Exercicio 3" );
printf ( "\n%s" , "4 - Method_04 - Exercicio 4" );
printf ( "\n%s" , "5 - Method_05 - Exercicio 5" );
printf ( "\n%s" , "6 - Method_06 - Exercicio 6" );
printf ( "\n%s" , "7 - Method_07 - Exercicio 7" );
printf ( "\n%s" , "8 - Method_08 - Exercicio 8" );
printf ( "\n%s" , "9 - Method_09 - Exercicio 9" );
printf ( "\n%s" , "10 - Method_10 - Exercicio 10" );
printf ( "\n" );
// ler a opcao do teclado
printf ( "\n%s", "Opcao = " );
scanf ( "%d", &opcao );
getchar( ); // para limpar a entrada de dados

// para mostrar a opcao lida
printf ( "\n%s%d", "Opcao = ", opcao );

// escolher acao dependente da opcao
switch ( opcao )
{
case 0:  break;
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

default: // comportamento padrao
printf ( "\nERRO: Opcao invalida.\n" );
break;
} // end switch
}
while ( opcao != 0 );
// encerrar
printf ( "\n\nApertar ENTER para terminar." );
getchar( ); // aguardar por ENTER

return 0 ; // voltar ao SO (sem erros)
}
