#include "io.h"
#include <math.h>
#include <stdlib.h>

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
    FILE *arquivo = fopen("SAIDA_1.TXT", "r");
    int contador = 0;
    double temp;

    while (fscanf(arquivo, "%lf", &temp) == 1){
        contador++;
    }
    struct ArranjoDouble meuArranjo;
    meuArranjo.tamanho = contador;
    
    meuArranjo.dados = (double *) malloc(meuArranjo.tamanho * sizeof(double));
    fclose (arquivo);

    arquivo = fopen("SAIDA_1.TXT", "r");
    for (int i = 0; i<meuArranjo.tamanho; i++){
        fscanf(arquivo, "%lf", &meuArranjo.dados[i]);
    }

    fclose (arquivo); 
    
    if (meuArranjo.tamanho > 0){
    double maiorDistancia = acharMaior(meuArranjo);
    double menorDistancia = acharMenor(meuArranjo);

    printf("\nMaior distancia: %lf\n", maiorDistancia);
    printf("Menor distancia: %lf\n", menorDistancia);
    }else{
        printf("\nERRO: Arquivo SAIDA_1.TXT esta vazio.\n");
    }

    free(meuArranjo.dados);
}
double acharMaior(struct ArranjoDouble meuArranjo){
    double maior = meuArranjo.dados[0];
    for(int i = 1; i<meuArranjo.tamanho; i++){
        if (meuArranjo.dados[i] > maior){
            maior = meuArranjo.dados[i];
        }
    }
    return maior;
}
double acharMenor(struct ArranjoDouble meuArranjo){
    double menor = meuArranjo.dados[0];
    for(int i = 1; i<meuArranjo.tamanho; i++){
        if (meuArranjo.dados[i] < menor){
            menor = meuArranjo.dados[i];
        }
    }
    return menor;
}

double calcularSoma (struct ArranjoDouble meuArranjo){
    double soma = 0.0;
    for (int i = 0; i<meuArranjo.tamanho; i++){
        soma += meuArranjo.dados[i]; 
    }  
    return soma;
}

void Method_03 (){
    IO_id("Method 03");
    FILE *arquivo = fopen("SAIDA_1.TXT", "r");

    int contador = 0;
    double temp;
    double media;

    while (fscanf(arquivo, "%lf", &temp) == 1){
        contador++;
    }
    struct ArranjoDouble meuArranjo;
    meuArranjo.tamanho = contador;
    
    meuArranjo.dados = (double *) malloc(meuArranjo.tamanho * sizeof(double));
    fclose (arquivo);

    arquivo = fopen("SAIDA_1.TXT", "r");
    for (int i = 0; i<meuArranjo.tamanho; i++){
        fscanf(arquivo, "%lf", &meuArranjo.dados[i]);
    }
    fclose(arquivo);

    if (meuArranjo.tamanho > 2){
     media = (calcularSoma(meuArranjo) - (acharMaior(meuArranjo)+acharMenor(meuArranjo)))/ (meuArranjo.tamanho - 2);
      printf("A média subtraindo os valores de menor e maior são %lf", media);
    } else {
        printf("\nERRO: Nao e possivel calcular a media com menos de 3 valores.\n");
    } 

    free(meuArranjo.dados);
}

struct matrizDupla {
    int linhas;
    int colunas;
    double **dados;
};

void Method_04 (){
    IO_id("Method 04");
    FILE *arquivo = fopen("DADOS_1.TXT", "r");
    int contador = 0;
    double temp, temp2;

    if (arquivo == NULL) {
        printf("ERRO: Nao foi possivel abrir DADOS_1.TXT\n");
        return; 
    }

   while (fscanf(arquivo, "%lf %lf", &temp, &temp2) == 2 && (temp != 0.0 || temp2 != 0.0)){
        contador++;
    }
    fclose(arquivo);
    printf("Arquivo lido. Encontrados %d pares de valores.\n", contador);

    struct matrizDupla minhaMatriz;

    minhaMatriz.linhas = contador;
    minhaMatriz.colunas = 2;
    minhaMatriz.dados = (double **) malloc(minhaMatriz.linhas * sizeof(double *));

    for (int i = 0; i < minhaMatriz.linhas; i++){
        minhaMatriz.dados[i] = (double *) malloc (minhaMatriz.colunas * sizeof(double ));
    }

    arquivo = fopen("DADOS_1.TXT", "r");
     for (int i = 0; i < minhaMatriz.linhas; i++){
        fscanf(arquivo, "%lf %lf", &minhaMatriz.dados[i][0], &minhaMatriz.dados[i][1]);
     } 
     fclose(arquivo);
     for (int j = 0; j < minhaMatriz.linhas; j++){
     for (int i = 0; i<minhaMatriz.linhas - 1; i++){

        if ((minhaMatriz.dados[i][0] > minhaMatriz.dados[i+1][0]) || 
            (minhaMatriz.dados[i][0] == minhaMatriz.dados[i+1][0] && 
            minhaMatriz.dados[i][1] > minhaMatriz.dados[i+1][1])){

            double *temp;

            temp = minhaMatriz.dados[i];
            minhaMatriz.dados[i] = minhaMatriz.dados[i+1];
            minhaMatriz.dados[i+1] = temp;
        }
    }
    }
    for (int i = 0; i < minhaMatriz.linhas; i++)
{
    free(minhaMatriz.dados[i]);
}
    free(minhaMatriz.dados);
}

double calcularDistanciaPrimeiroUltimo(struct matrizDupla minhaMatriz){
    double x1 = minhaMatriz.dados[0][0];
    double y1 = minhaMatriz.dados[0][1];

    double x2 = minhaMatriz.dados[minhaMatriz.linhas - 1][0];
    double y2 = minhaMatriz.dados[minhaMatriz.linhas - 1][1];

    double distancia = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
    return distancia;
}

void Method_05(){
    IO_id("Method 04");
    FILE *arquivo = fopen("DADOS_1.TXT", "r");
    int contador = 0;
    double temp, temp2;

    if (arquivo == NULL) {
        printf("ERRO: Nao foi possivel abrir DADOS_1.TXT\n");
        return; 
    }

   while (fscanf(arquivo, "%lf %lf", &temp, &temp2) == 2 && (temp != 0.0 || temp2 != 0.0)){
        contador++;
    }
    fclose(arquivo);
    printf("Arquivo lido. Encontrados %d pares de valores.\n", contador);

    struct matrizDupla minhaMatriz;

    minhaMatriz.linhas = contador;
    minhaMatriz.colunas = 2;
    minhaMatriz.dados = (double **) malloc(minhaMatriz.linhas * sizeof(double *));

    for (int i = 0; i < minhaMatriz.linhas; i++){
        minhaMatriz.dados[i] = (double *) malloc (minhaMatriz.colunas * sizeof(double ));
    }

    arquivo = fopen("DADOS_1.TXT", "r");
     for (int i = 0; i < minhaMatriz.linhas; i++){
        fscanf(arquivo, "%lf %lf", &minhaMatriz.dados[i][0], &minhaMatriz.dados[i][1]);
     } 
     fclose(arquivo);
     for (int j = 0; j < minhaMatriz.linhas; j++){
     for (int i = 0; i<minhaMatriz.linhas - 1; i++){

        if ((minhaMatriz.dados[i][0] > minhaMatriz.dados[i+1][0]) || 
            (minhaMatriz.dados[i][0] == minhaMatriz.dados[i+1][0] && 
            minhaMatriz.dados[i][1] > minhaMatriz.dados[i+1][1])){

            double *temp;

            temp = minhaMatriz.dados[i];
            minhaMatriz.dados[i] = minhaMatriz.dados[i+1];
            minhaMatriz.dados[i+1] = temp;
        }
    }
    }
    if (minhaMatriz.linhas > 0){
        double dist = calcularDistanciaPrimeiroUltimo(minhaMatriz);
        printf("\nDistancia entre o primeiro e o ultimo par ordenado:\n");
        printf("%lf\n", dist);
    }
    for (int i = 0; i < minhaMatriz.linhas; i++)
{
    free(minhaMatriz.dados[i]);
}
    free(minhaMatriz.dados);

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
case 2: method_02 ( ); break;
case 3: method_03 ( ); break;
case 4: method_04 ( ); break;
case 5: method_05 ( ); break;
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