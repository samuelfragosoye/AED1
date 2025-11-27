/*
  Recuperacao 02 - AED1
  Nome: Samuel Fragoso
  Matricula: 902665
*/

#include "io.h"
#include <stdlib.h>
#include <stdio.h>

// ---------------------------------------------------------
// DEFINIÇÃO DE ESTRUTURAS 
// ---------------------------------------------------------

typedef struct s_array {
    int lenght;
    int *data;
} Array;
Array* new_array (int n){
    Array* tmp = (Array*) malloc(sizeof(Array));
    if (tmp != NULL) {
        tmp->lenght = 0;
        tmp->data   = NULL;
        if (n>0){
            tmp->lenght = n;
            tmp->data   = (int*) malloc(n * sizeof(int));
        }
    }
    return tmp;
}

void delete_Array(Array* arr){
    if (arr != NULL){
        if (arr->data != NULL) free(arr->data);
        free(arr);
    }
}

// ---------------------------------------------------------
// FUNÇÕES DE ARQUIVO (Leitura/Gravação)
// ---------------------------------------------------------
Array* arranjo_ler(char* filename){
    Array* arr = NULL;
    FILE* arquivo = fopen(filename, "rt");
    int n = 0, x = 0;

    if (arquivo != NULL){
        fscanf(arquivo, "%d", &n);
        if(n>0){
            arr = new_Array(n);
            for(int i = 0; i < n; i++){
                fscanf(arquivo, "%d", &x);
                arr->data[i] = x;
            }
        }
        fclose(arquivo);
    } else {
        printf("\nERRO: Nao foi possivel ler %s\n", filename);
    }
    return arr;
}

void arranjo_gravar(char* filename, Array* arr){
    FILE* arquivo = fopen(filename, "wt");
    if (arquivo != NULL && arr !=NULL){
        fprintf(arquivo, "%d\n", arr->lenght);
        for (int i = 0; i < arr->lenght; i++){
            fprintf("%d ", arr->data[i]);
        }
        fclose(arquivo);
        printf("\nDados gravados em %s com sucesso\n", filename);
    }
}

void arranjo_print(Array* arr){
    if(arr != NULL){
        printf("\n[ ");
        for (int i = 0; i<arr->lenght; i++){
            printf("%d ", arr->data[i]);
        }
        printf("]\n");
    }
}

// ---------------------------------------------------------
// EXERCÍCIO 01
// ---------------------------------------------------------
/*
  Função para verificar se está em ordem decrescente 
*/
int isDecrescente(Array* arr){
    int result = 1;
    if (arr != NULL && arr->lenght > 1){
        for (int i = 0; i < arr->lenght - 1; i++){
            if(arr->data[i]<arr->data[i+1]){
                result = 0;
                i = arr -> lenght;
            }
        }
    }
    return result;
}
/*
  Função para ordenar decrescente 
*/
void ordenarDecrescente(Array* arr){
    if(arr != NULL && arr->lenght > 1){
        int trocou = 0;
        int temp = 0;
        do{
            trocou = 0;
            for (int i = 0; i < arr->lenght - 1; i++){
                if (arr->data[i] < arr->data[i+1]) {
                    temp = arr->data[i];
                    arr->data[i] = arr->data[i+1];
                    arr->data[i+1] = temp;
                    trocou = 1;
                }
            }
        } while (trocou);
    }
}

void method_01(){
    IO_id("Method 01 - Exercicio 1: Ordenar Decrescente");

    Array* arr = arranjo_ler("DADOS1.TXT");
    if(arr != NULL){
        printf("\nArranjo lido:");
        arranjo_print(arr);

        if(!isDecrescente(arr)){
            printf("\nNao esta ordenado");
            ordenarDecrescente(arr);
        } else {
            printf("\nJa esta ordenado");
        }
        printf("\nArranjo final:");
        arranjo_print(arr);
        arranjo_gravar("CRESCENTE.TXT", arr);

        delete_Array(arr);
    }
    IO_flush();
    IO_pause("Aperte ENTER para continuar");
}
// ---------------------------------------------------------
// EXERCÍCIO 02
// ---------------------------------------------------------
/*
  Função para inverter arranjo 
*/
void arranjo_inverter(Array* arr){
    if(arr != NULL && arr->lenght>0){
        int temp;
        int inicio = 0;
        int fim = arr->lenght - 1;

        while(inicio<fim){
            temp = arr->data[inicio];
            arr->data[inicio] = arr->data[fim];
            arr->data[fim]=temp;

            inicio++;
            fim--;
        }
    }
}

void method_02(){
    IO_id("Method 02 - Exercicio 2: Inverter Arranjo");
    Array* arr = arranjo_ler("CRESCENTE.TXT");
    if (arr != NULL)
    {
        printf("\nArranjo lido:");
        arranjo_print(arr);

        arranjo_inverter(arr);
        printf("\nArranjo inverytido:");
        arranjo_print(arr);

        arranjo_gravar("INVERTIDOS.TXT", arr);
        delete_Array(arr);
    } else {
        printf("\nExecute o Method 1 primeiro para gerar o arquivo");
    }
    
    IO_flush();
    IO_pause("Aperte ENTER para continuar");
}
// ---------------------------------------------------------
// EXERCÍCIO 03 - MODA 
// ---------------------------------------------------------
typedef struct s_Par {
    int valor;
    int count;
} Par;

int arranjo_moda(Array* arr) {
    int moda = 0;
    int max_freq = 0;

    if (arr != NULL && arr->lenght > 0) {
        Par* tabela = (Par*) malloc(arr->lenght * sizeof(Par));
        int total_unicos = 0;

        for (int i = 0; i < arr->lenght; i++) {
            int x = arr->data[i];
            int encontrado = 0;

            for (int k = 0; k < total_unicos; k++) {
                if (tabela[k].valor == x) {
                    tabela[k].count++;
                    encontrado = 1;
                    k = total_unicos; 
                }
            }

            if (!encontrado) {
                tabela[total_unicos].valor = x;
                tabela[total_unicos].count = 1;
                total_unicos++;
            }
        }
        if (total_unicos > 0) {
            moda = tabela[0].valor;
            max_freq = tabela[0].count;

            for (int k = 1; k < total_unicos; k++) {
                if (tabela[k].count > max_freq) {
                    max_freq = tabela[k].count;
                    moda = tabela[k].valor;
                }
            }
        }
        
        printf("\n--- Tabela de Frequencia ---");
        for(int k=0; k<total_unicos; k++){
            printf("\nValor: %d | Vezes: %d", tabela[k].valor, tabela[k].count);
        }
        printf("\n----------------------------\n");

        free(tabela); 
    }
    return moda;
}

void method_03(){
    IO_id("Method 03 - Exercicio 3: Achar a Moda (Frequencia)");
    Array* arr = arranjo_ler("DADOS.TXT");
    if (arr != NULL){
        printf("\nArranjo lido:");
        arranjo_print(arr);

        int valor_moda = arranjo_moda(arr);
        printf("\nA MODA (valor mais frequente) e: %d\n", valor_moda);
        delete_Array(arr);
    } else {
        printf("\nERRO: Arquivo DADOS1.TXT nao encontrado ou vazio");
    }
    IO_flush();
    IO_pause("Aperte ENTER para continuar");
}
///main
int main ( void )
{
    int opcao = 0;
    printf ( "%s\n", "Recuperacao 02" );
    printf ( "%s\n", "Autor: Samuel Fragoso" );
    printf ( "\n" );

    do
    {
        printf ( "\n%s\n", "Opcoes:" );
        printf ( "\n%s" , "0 - Terminar" );
        printf ( "\n%s" , "1 - Method_01 - Ordenar Decrescente (Ex 1)" );
        printf ( "\n%s" , "2 - Method_02 - Inverter Arranjo (Ex 2)" );
        printf ( "\n%s" , "3 - Method_03 - Achar a Moda (Frequencia)" );
        
        printf ( "\n" );
        printf ( "\n%s", "Opcao = " );
        scanf ( "%d", &opcao );
        getchar(); 

        switch ( opcao )
        {
            case 0:  break;
            case 1: method_01(); break;
            case 2: method_02(); break;
            case 3: method_03(); break;

            default: 
                printf ( "\nERRO: Opcao invalida.\n" );
                break;
        } 
    }
    while ( opcao != 0 );

    printf ( "\n\nApertar ENTER para terminar." );
    getchar();
    return 0; 
}