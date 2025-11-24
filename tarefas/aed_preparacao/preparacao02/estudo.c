#include <stdio.h>
#include "io.h"

void Method_01 (){
    int i = 0;
    int j = 0;
    char s[]= " amarelo  branco   dourado ";
    
    int eraEspaco = 0;
    while (s[i]!= '\0'){
        if(s[i]!= ' '){
            s[j] = s[i];
            j++;
            eraEspaco = 0;
        }else{
            if(eraEspaco == 0){
                s[j] = s[i];
                j++;
            }
            eraEspaco = 1;
        }
        i++;
    }
    while (j > 0 && s[j-1] == ' ') {
        j--;
    }

    s[j] = '\0';
    printf("Limpa: \"%s\"\n", s);
    IO_pause("Aperte ENTER para continuar");
}

struct  {
    int l, c;
    int  data[10][10];
} matriz;

void Method_02 (){
    int i = 0;
    
    int m;
    scanf("%d", &m);
    while(i<m){
        int a = 0;
        while(a<m){
            if(a<=i){
                matriz.data[i][a] = 1;
            } else {
                matriz.data[i][a] = 0;
            }
            a++;
        }
        i++;
    }
}

void Method_03 (){
    FILE *arquivo = fopen("teste.txt", "w");
    if(arquivo == NULL){
        printf("ERRO");
        return;
    }
    int n;
    int i = 1;
    scanf("%d", &n);
    while (i<=n){
        int a = 1;
        while (a<=i){
            fprintf(arquivo, "*");
            a++;
        }
        fprintf(arquivo, "\n");
        i++;
    }
    i = n - 1;
    while(i>=1){
        int a = 1;
        while(a<=i){
            fprintf(arquivo, "*");
            a++;
        }
        fprintf(arquivo, "\n");
        i--;
    }
    fclose(arquivo);
    printf("Arquivo 'teste.txt' criado com sucesso.\n");
}

struct matriz {
    int linhas;
    int colunas;
    double **dados;
};

void Method_04(){
    double x, y, z;
    int cont = 0;
    FILE *arquivo = fopen("DADOS_RAPIDO.TXT", "r");
    if (arquivo == NULL){
        printf("ERRO");
        return;
    }
    while(fscanf(arquivo, "%lf %lf %lf", &x, &y, &z)==3){
        cont++;
    }
    fclose(arquivo);
    struct matriz minhaMatriz;
    minhaMatriz.linhas = cont;
    minhaMatriz.colunas = 3;

    minhaMatriz.dados = (double**) malloc(minhaMatriz.linhas * sizeof(double *));
    for(int i = 0; i < minhaMatriz.linhas; i++){
        minhaMatriz.dados[i] = (double *) malloc(minhaMatriz.linhas[i] * sizeof(double));

    }
    arquivo = fopen("DADOS_RAPIDO.TXT", "r");
    if (arquivo == NULL){
        printf("ERRO");
        return;
    }
    for (int i = 0; i < minhaMatriz.linhas; i++){
        fscanf(arquivo, "%lf %lf %lf", 
                        &minhaMatriz.dados[i][0]
                        &minhaMatriz.dados[i][1]
                        &minhaMatriz.dados[i][2]);
    }
    fclose(arquivo);    
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
case 1: Method_01 ( ); break;
case 2: Method_02 ( ); break;
case 3: Method_03 ( ); break;
//case 4: Method_04 ( ); break;
//case 5: Method_05 ( ); break;
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