#include "io.h"


//QUESTÕES FECHADAS
void question_01 (int a1, int b1, int a2, int b2)
{
    int c=0, d=0;
    if (a1<=b1 && b1>=a2)
    if (a1<=a2) c = a1; else if (b1>=a2) c=a2;
    if(b1>=a2 && b1>b2)
    d = b1; else if (b1>=a2) d=b2;
    printf("[%d,%d]\n", c,d);
}

void method_01 () {
    IO_id("Method 1 - Questão 1");

    printf("Primeiro Teste - (12, 36, 15, 40)\n");
    question_01 (12, 36, 15, 40);

    printf("Primeiro Teste - (12, 36, 15, 40)\n");
    question_01 (12, 40, 15, 36);

    printf("Primeiro Teste - (12, 36, 15, 40)\n");
    question_01 (12, 15, 36, 40);

    printf("Primeiro Teste - (12, 36, 15, 40)\n");
    question_01 (15, 40, 12, 36);

    IO_pause("Aperte ENTER para continuar");
}
/* 
 *  SAÌDA: 
   Primeiro Teste - (12, 36, 15, 40)
   [12,40]
   Primeiro Teste - (12, 36, 15, 40)
   [12,40]
   Primeiro Teste - (12, 36, 15, 40)
   [0,0]
   Primeiro Teste - (12, 36, 15, 40)
   [12,40]
*/

int function_02 (char * word){
    int x = 0, y = 0, z = 0;
    while(word[x] != '\0'){
        if (word[x] != ' ') y=y+1;
        else {if(y!=0) z=y; y=0;}
        x = x + 1;
    } if (y == 0) return (z); else return (y);
}

void method_02 (){
    int resultado;
    IO_id("Method 2 - Questão 2");

    
    printf("Teste para 'def bc a '");
    resultado = function_02("def bc a  ");
    printf("\nSaida: %d\n", resultado);

    IO_pause("Aperte ENTER para continuar");
}

/*
   SAÍDA
   Saída: 1
*/

int rsqr (int x){
    int y = 1;
    if (x>0){y=(x%10)*rsqr(x/10);}
    return (y);
}
int sqr (int x) {return (1+rsqr(x));}

void method_03 (){
    IO_id("Method 2 - Questão 2");
    
    int r_a = sqr(1357);
    int r_b = sqr(2345);
    int r_c = sqr(3567);
    int r_d = sqr(4678);

    printf("sqr(1357) = %d \n", r_a);
    printf("sqr(2345) = %d \n", r_b);
    printf("sqr(3567) = %d \n", r_c);
    printf("sqr(4678) = %d \n", r_d);

    IO_pause("Aperte ENTER para continuar");

}
/*
   SAÍDA:
   sqr(1357) = 106 
   sqr(2345) = 121 
   sqr(3567) = 631 
   sqr(4678) = 1345 

   **resposta: 121 é o único quadrado perfeito
*/

int function_04 (char s []) {
    int z=0;
    for (int x=0; x<strlen(s)-2;x=x+1)
    {for (int y=x+2; y<strlen(s)-1; y=y+1)
      { if (s[x]==s[y]&&s[x+1]==s[y+1])
      { z = z + 1; } } }
    return (z);
}

void method_04 () 
{
    IO_id("Method 04 - Questao 04");
    
    char s[] = "songamonga"; 
    
    int resultado = function_04(s); 
    
    printf("Entrada: s=\"songamonga\"\n");
    printf("Saida: %d\n", resultado);
    
    IO_pause("Aperte ENTER para continuar");
}

/*
   SAÍDA: 3
*/

int function_05(int a, int b){
    if (a>b) return (function_05(a-b,b)); else
    if (b>a) return (function_05(b-a,a));
    return (a);
}

void method_05(){
    int resultado;
    IO_id("Method 05 - Questao 05");

    resultado = function_05(60,75);
    printf("%d", resultado);
    
    IO_pause("Aperte ENTER para continuar");
}

/*
   SAÍDA: 15
*/
//QUESTÕES ABERTAS

int is_HalfedSquared(int n)
{
    int resposta = 0;
   
    if (n >= 1000 && n <= 9999)
    {
        int L = n / 100; 
        int R = n % 100; 
        int sum = L + R; 
        if (sum * sum == n) { 
            resposta = 1;
        }
    }
    return resposta;
}

void method_06()
{
    IO_id("Method 06 - Questao 06 (HalfedSquared)");
    int count = 0;
    
    printf("Numeros de 4 digitos com a caracteristica:\n");
    for (int i = 1000; i <= 9999; i = i + 1)
    {
        if (is_HalfedSquared(i) == 1)
        {
            printf("%d\n", i); 
            count = count + 1;
        }
    }
    printf("Total de numeros encontrados: %d\n", count);
    IO_flush();
    IO_pause("Aperte ENTER para continuar");
}

/*
   SAÍDA:
   Numeros de 4 digitos com a caracteristica:
   2025
   3025
   9801
   Total de numeros encontrados: 3
*/

int nCollatz(int n)
{
    int length = 1; 
    if (n <= 0) {
        return 0; 
    }
    
    
    while (n != 1)
    {
        if (n % 2 == 0) { 
            n = n / 2;
        } else { 
            n = 3 * n + 1;
        }
        length = length + 1;
    }
    
    return length;
}

void method_07()
{
    IO_id("Method 07 - Questao 07 (Collatz)");
    int n1 = 0, n2 = 0;
    
    printf("Digite o primeiro numero impar: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero impar: ");
    scanf("%d", &n2);
    
    // Validação
    if (n1 % 2 == 0 || n2 % 2 == 0 || n1 == n2) {
        printf("ERRO: Os numeros devem ser impares e diferentes.\n");
    } else {
        int len1 = nCollatz(n1);
        int len2 = nCollatz(n2);
        
        printf("Sequencia de %d: %d passos.\n", n1, len1);
        printf("Sequencia de %d: %d passos.\n", n2, len2);
        
        if (len1 < len2) {
            printf("O numero %d tem a menor sequencia.\n", n1);
        } else if (len2 < len1) {
            printf("O numero %d tem a menor sequencia.\n", n2);
        } else {
            printf("Os numeros tem a mesma (ou invalida) sequencia.\n");
        }
    }
    IO_flush();
    IO_pause("Aperte ENTER para continuar");
}

/*
   SAÍDA:
   Digite o primeiro numero impar: 7
   Digite o segundo numero impar: 9
   Sequencia de 7: 17 passos.
   Sequencia de 9: 20 passos.
   O numero 7 tem a menor sequencia.

*/

int trimarks(char *s)
{
    int resposta = 0;
    // A função só se aplica a sequências de 3 caracteres
    if (strlen(s) == 3) 
    {
        if (s[0] == s[1] && s[1] == s[2]) {
            resposta = 1;
        }
    }
    return resposta;
}

void method_08()
{
    IO_id("Method 08 - Questao 08 (Morse SOS)");
    char msg[100];
    int state = 0; 
    
    printf("Digite a mensagem Morse: ");
    // Limpar o buffer antes de ler
    int c;
    //while ((c = getchar()) != '\n' && c != EOF);
    
    fgets(msg, 100, stdin);
    msg[strcspn(msg, "\n")] = 0; // Remove o \n do fgets
    
    char *token = strtok(msg, " "); // Divide a string por espaços
    
    // Loop sem break ou continue
    while (token != NULL && state != 3)
    {
        // Testa se o "token" (palavra) tem 3 caracteres iguais
        if (trimarks(token) == 1)
        {
            if (token[0] == '.') { // É "..." (S)
                if (state == 0) {
                    state = 1; // Achou S1
                } else if (state == 2) {
                    state = 3; // Achou S2
                }
            } 
            else if (token[0] == '-') { // É "---" (O)
                if (state == 1) {
                    state = 2; // Achou O
                }
            }
        } 
        // Se o token não for um trimark, ou for na ordem errada,
        // (exceto se já estivermos procurando S2)
        else if (state != 2)
        { 
             state = 0; // Reseta a busca
        }
        
        token = strtok(NULL, " ");
    }
    
    if (state == 3) {
        printf("Resultado: Pedido de socorro (SOS) ENCONTRADO!\n");
    } else {
        printf("Resultado: Pedido de socorro NAO encontrado.\n");
    }
    IO_flush();
    IO_pause("Aperte ENTER para continuar");
}

/*
   SAÍDA:
   Digite a mensagem Morse: ....----
   Resultado: Pedido de socorro NAO encontrado.

*/

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
printf ( "\n%s" , "1 - Method_01 - Questão 1" );
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