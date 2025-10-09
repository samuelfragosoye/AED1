#include "io.h"
#include <math.h>

int SomaAteN(int n){  
    int i;
    int resultado = 0;
    for (i = 1; i <= n; i++)
    {
       resultado = resultado + i;
    }
 return resultado;
}
void method_01 (){
    int numero = 5;
    int soma = SomaAteN(numero);


    printf("A soma dos numeros de 1 ate %d e': %d\n", numero, soma);
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
printf ( "\n%s" , "1 - Method_01" );
printf ( "\n%s" , "2 - Method_02" );
printf ( "\n%s" , "3 - Method_03" );
printf ( "\n%s" , "4 - Method_04" );
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
/*case 2: method_02 ( ); break;
case 3: method_03 ( ); break;
case 4: method_04 ( ); break;
case 5: method_05 ( ); break;*/

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