
#include "io.h"
#include <math.h>

void method_01 (){
    int raio = 0;
    int divisores = 0;
    double area_fatia = 0.0;
    const double PI = 3.1415926535;

    printf("\nMethod 01 - Calcular Area da Fatia\n");
    do
    {
       printf("Digite o valor do raio (ou 0 para sair)\n");
       scanf("%d", &raio);
       printf("Digite o número de fatias iguais (ou 0 para sair)\n");
       scanf("%d", &divisores);

       if (raio > 0 && divisores > 0)
       {
        area_fatia = (PI * ((double)raio * (double)raio))/divisores;
        printf("A área da fatia é = %.2f\n", area_fatia);
       }
       else if (raio < 0 || divisores < 0) {
        printf("\n ERRO - o numero deve ser positivo\n");
       }
    } while (raio != 0 || divisores != 0);
}
void method_02 (){
    char caractere1;
    char caractere2;
    char caractere3;
    int nteste;
    int i = 1;
    bool resposta;
    
    printf("\nMethod 02 - Verificar Ordem Decrescente de Caracteres\n");
    printf("Digite o número de testes: ");
    scanf("%d", &nteste);

    /* for (i = 1; i <= nteste; i++)
    {

        printf("\nDigite o primeiro caractere: ");
        scanf (" %c", &caractere1);
       
        printf("\nDigite o segundo caractere: ");
        scanf (" %c", &caractere2);
       
        printf("\nDigite o terceiro caractere: ");
        scanf (" %c", &caractere3);

        resposta = (caractere1 > caractere2 && caractere2 > caractere3);

        if (resposta){
            printf("\nResultado: Os caracteres ESTAO em ordem decrescente ('%c' > '%c' > '%c').\n", caractere1, caractere2, caractere3);
        } else {
            printf("\nResultado: Os caracteres NÃO ESTÃO em ordem decrescente.\n");
        }


    }*/
   while (i <= nteste){
        printf("\nDigite o primeiro caractere: ");
        scanf (" %c", &caractere1);
       
        printf("\nDigite o segundo caractere: ");
        scanf (" %c", &caractere2);
       
        printf("\nDigite o terceiro caractere: ");
        scanf (" %c", &caractere3);

        resposta = (caractere1 > caractere2 && caractere2 > caractere3);

        if (resposta){
            printf("\nResultado: Os caracteres ESTAO em ordem decrescente ('%c' > '%c' > '%c').\n", caractere1, caractere2, caractere3);
        } else {
            printf("\nResultado: Os caracteres NÃO ESTÃO em ordem decrescente.\n");
        }
        i++;
   }
IO_flush();    
IO_pause("Aperte ENTER para continuar");
}
void method_03 (){
    int a, b, n, x;
    int i;
    int contador = 0;

    printf("\nMethod 03 - fiscal de números\n");
    printf("Digite o primeiro número do intervalo:\n");
    scanf("%d", &a);
    printf("Digite o último número do intervalo:\n");
    scanf("%d", &b);
    printf("Quantos números vão ser testados?\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
      printf("x = ");
      scanf("%d", &x);

      if ((x % 2 == 0) && (x/3 >= a && x/3 <= b) && (x*3 >= a && x*3 <= b)){
        contador++;
      }
    }
    printf("quantidade de valores que possuem as 3 caracteristicas = %d", contador);
    IO_flush();   
    IO_pause("Aperte ENTER para continuar");
}
bool is_maiuscula(char c){
    return (c>= 'A' && c<= 'Z');
}
bool is_minuscula(char c){
    return (c >= 'a' && c<= 'z');
}
bool is_digito(char c){
    return (c >= '0' && c <= '9');
}
bool is_espaco(char c){
    return (c == ' ');
}
int contar_simbolos(const char* texto){
    int contador = 0;
    int i = 0;
    while (texto[i] != '\0'){
        char caractere_atual = texto[i];
        if(is_maiuscula(caractere_atual)||
           is_minuscula(caractere_atual)||
           is_digito(caractere_atual)   ||
           is_espaco(caractere_atual))
           {
            contador++;
           }
           i++;
    }
    return contador;
}
void method_04(){
    char texto[81];
    int total_simbolos = 0;

    printf("\nMethod 04 - Contar Simbolos Alfanumericos\n");
    printf("Digite uma sequência de caracteres: ");
    fgets(texto, 80, stdin);
    texto[strcspn(texto, "\n")] = '\0';

    total_simbolos = contar_simbolos(texto);

    printf("Resultado: A quantidade de letras, digitos e espacos eh = %d\n", total_simbolos);
    IO_pause("Aperte ENTER para continuar");
}

    /*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
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
printf ( "\n%s" , "1 - Method_01 - Calcular Area da Fatia" );
printf ( "\n%s" , "2 - Method_02 - Verificar Ordem Decrescente de Caracteres" );
printf ( "\n%s" , "3 - Method_03 - Fiscal de Numeros" );
printf ( "\n%s" , "4 - Method_04 - Contar Simbolos Alfanumericos" );
printf ( "\n%s" , "5 - Method_05" );
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
/*case 5: method_05 ( ); break;
*/
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
 // end main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) a
b.) 4.2
c.) 10
d.) 1
e.) abc def
f .) abc def
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/