#include "io.h"
#include <math.h>

struct Ponto {
    double x;
    double y;
};

void method_01 (){
    double distancia;
    IO_id("Method 01");
    FILE *arquivo = fopen("DADOS_1.TXT", "r");

    if (arquivo == NULL){
        printf("ERRO");
    } else {
        double x1, x2, y1, y2;

        fscanf(arquivo, "%lf %lf", &x1, &y1);

        FILE *saida = fopen("SAIDA_1.TXT","w");
        while(fscanf(arquivo, "%lf %lf", &x2, &y2)== 2 && (x2 != 0.0 || y2 != 0.0)){
         distancia = sqrt(pow((x2-x1), 2.0)+pow((y2-y1), 2.0));
         fprintf(saida, "%lf\n", distancia);
         x1 = x2;
         y1 = y2;
        }
        fclose (saida);
        fclose(arquivo);
    }
}

struct ArranjoDouble {
  int tamanho;
  double *dados;
};

void method_02(){
    IO_id("Method 02");
    FILE *arquivo = fopen("DADOS_1.TXT", "r");
    int contador = 0;
    double temp;

    while (fscanf(arquivo, "%lf", &temp) == 1){
        contador++;
    }
    fclose (arquivo);

    printf("Arquivo SAIDA_1.TXT tem %d distancias.\n", contador);

    if (contador == 0) {
        printf("Arquivo vazio, nada a fazer.\n");
        return;
    }
    struct ArranjoDouble meuArranjo;
    meuArranjo.tamanho = contador;

    meuArranjo.dados = (double *) malloc(meuArranjo.tamanho * sizeof(double));

    if (meuArranjo.dados == NULL) {
        printf("ERRO: Nao foi possivel alocar memoria.\n");
        return; // Sai se não conseguir memória
    }

    arquivo = fopen("SAIDA_1.TXT", "r"); // Reabre o arquivo
    if (arquivo == NULL) {
        printf("ERRO: Nao foi possivel reabrir o arquivo SAIDA_1.TXT\n");
        free(meuArranjo.dados); // Libera a memória alocada
        return;
    }

    for (int i = 0; i < meuArranjo.tamanho; i++) {
        fscanf(arquivo, "%lf", &meuArranjo.dados[i]);
    }
    fclose(arquivo); 

}
/*
Funcao principal.
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
case 0: /* nao fazer nada */ break;
case 1: method_01 ( ); break;
//case 2: method_02 ( ); break;
//case 3: method_03 ( ); break;
//case 4: method_04 ( ); break;
//case 5: method_05 ( ); break;
default: // comportamento padrao
printf ( "\nERRO: Opcao invalida.\n" );
break;
} // end switch
}
while ( opcao != 0 );
// encerrar
printf ( "\n\nApertar ENTER para terminar." );
getchar( ); // aguardar por ENTER
return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )