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
Array* new_Array (int n){
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
            fprintf(arquivo,"%d ", arr->data[i]);
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
                i = arr->lenght;
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
    Array* arr = arranjo_ler("DADOS1.TXT");
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

// ---------------------------------------------------------
// EXERCÍCIO 04 - INTERSEÇÃO 
// ---------------------------------------------------------
/*
  Função auxiliar: Verifica se valor existe no array
*/
int arranjo_existe(int valor, int* dados, int limite){
    int existe = 0;
    for (int i = 0; i<limite; i++){
        if (dados[i] == valor){
            existe = 1;
            i = limite;
        }
    }
    return existe;
}

/*
  Função para filtrar elementos comuns (Interseção)
  Retorna um novo Array contendo apenas os comuns sem repetição.
*/
Array* arranjo_filtrar(Array* arr1, Array* arr2){
    Array* resultado = NULL;

    if (arr1 != NULL && arr2 != NULL) {
        // Alocar tamanho máximo possível (tamanho do arr1)
        resultado = new_Array(arr1->lenght);
        int count = 0;

        for (int i = 0; i < arr1->lenght; i++) {
            int valor = arr1->data[i];

            // 1. Verifica se existe no array 2
            // 2. Verifica se JÁ foi adicionado no resultado (evitar repetidos)
            if (arranjo_existe(valor, arr2->data, arr2->lenght) && 
                !arranjo_existe(valor, resultado->data, count)) {
                
                resultado->data[count] = valor;
                count++;
            }
        }
    resultado->lenght = count;
    }
    return resultado;    
}

void method_04(){
    IO_id("Method 04 - Exercicio 4: Elementos Comuns (Intersecao)");
    Array* arr1 = arranjo_ler("DADOS1.TXT");
    Array* arr2 = arranjo_ler("DADOS2.TXT");

    if(arr1 != NULL && arr2 != NULL){
        printf("\nArranjo 1: ");
        arranjo_print(arr1);
        printf("Arranjo 2: ");
        arranjo_print(arr2);

        Array* comuns = arranjo_filtrar(arr1, arr2);
        printf("\nElementos Comuns (sem repeticao):");
        arranjo_print(comuns);

        arranjo_gravar("FILTRADOS.TXT", comuns);

        delete_Array(comuns);
        delete_Array(arr1);
        delete_Array(arr2);
    } else{
        printf("\nERRO: Nao foi possivel ler DADOS1.TXT ou DADOS2.TXT");
    }
    IO_flush();
    IO_pause("Aperte ENTER para continuar");
}

// =========================================================
// ESTRUTURA E FUNÇÕES PARA MATRIZES (Matrix)
// =========================================================

typedef struct s_Matrix {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix* new_Matrix(int rows, int cols){
    Matrix* tmp = (Matrix*) malloc(sizeof(Matrix));
    if(tmp != NULL){
        tmp->rows = rows;
        tmp->cols = cols;
        tmp->data = (int**) malloc(rows *sizeof(int*));
        for (int i = 0; i < rows; i++){
            tmp->data[i] = (int*) malloc(cols * sizeof(int));
        }
    }
    return tmp;
}

void delete_Matrix(Matrix* mat){
    if(mat != NULL){
        for(int i = 0; i < mat->rows; i++){
            free(mat->data[i]);
        }
        free(mat->data);
        free(mat);
    }
}

Matrix* matrix_ler(char* filename){
    Matrix* mat = NULL;
    FILE* arquivo = fopen(filename, "rt");
    int r = 0, c = 0;
    if(arquivo != NULL){
        fscanf(arquivo, "%d", &r);
        fscanf(arquivo, "%d", &c);
        if(r>0 && c>0){
            mat = new_Matrix(r, c);
            for (int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    fscanf(arquivo, "%d", &mat->data[i][j]);
                }
            }
        }
        fclose(arquivo);
    }
    return mat;
}

void matrix_gravar(char* filename, Matrix* mat){
    FILE* arquivo = fopen(filename, "wt");
    if(arquivo != NULL && mat != NULL){
        fprintf(arquivo, "%d\n", mat->rows);
        fprintf(arquivo, "%d\n", mat->cols);
        for(int i = 0; i < mat->rows; i++){
            for(int j = 0; j < mat->cols; j++){
                fprintf(arquivo, "%d ", mat->data[i][j]);
            }
            fprintf(arquivo, "\n");
        }
        fclose(arquivo);
    }
}

void matrix_print(Matrix* mat){
    if(mat != NULL){
        printf("\n");
        for (int i = 0; i < mat->rows; i++){
            for(int j = 0; j < mat->cols; j++){
                printf("%d\t", mat->data[i][j]);
            }
            printf("\n");
        }
    }
}

// ---------------------------------------------------------
// EXERCÍCIO 05 - BINÁRIO PARA DECIMAL
// ---------------------------------------------------------

/*
 Converte string binaria para decimal
*/
int binario_paraDecimal(char* bin){
    int decimal = 0;
    int base = 1;
    int tam = strlen(bin);

    for(int i = tam - 1; i >= 0; i--){
        if(bin[i]== '1'){
            decimal += base;
        }
        base = base * 2;
    }
    return decimal;
}

void method_05(){
    IO_id("Method 05 - Exercicio 5: Binario para Decimal");

    FILE* arq = fopen("BINARIOS1.TXT", "rt");
    char linha[80];

    if(arq != NULL){
        while(fscanf(arq, "%s", linha) != EOF){
            int valido = 1;
            for(int i = 0; i<strlen(linha); i++){
                if(linha[1] != '0' && linha[i] != '1') valido = 0;
            }

            if(valido){
                int dec = binario_paraDecimal(linha);
                printf("\nBinario: %s -> Decimal: %d", linha, dec);
            } else {
                printf("\nBinario: %s -> INVALIDO", linha);
            }
        }
        fclose(arq);
    } else {
        printf("\nErro ao abrir BINARIOS1.TXT");
    }
    IO_pause("\nENTER para continuar");
}

// ---------------------------------------------------------
// EXERCÍCIO 06 - MATRIZ TRIDIAGONAL CRESCENTE
// ---------------------------------------------------------

void method_06() {
    IO_id("Method 06 - Exercicio 6: Matriz Tridiagonal Crescente");
    
    int n;
    printf("Digite a dimensao da matriz quadrada (N): ");
    scanf("%d", &n);

    if (n > 0) {
        Matrix* mat = new_Matrix(n, n);
        int contador = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i == j - 1 || i == j + 1) {
                    mat->data[i][j] = contador; 
                    contador++;
                } else {
                    mat->data[i][j] = 0;
                }
            }
        }
        
        printf("\nMatriz Gerada:");
        matrix_print(mat);
        matrix_gravar("MATRIZ2.TXT", mat); 
        delete_Matrix(mat);
    }
    IO_pause("\nENTER para continuar");
}

// ---------------------------------------------------------
// EXERCÍCIO 07 - MATRIZ TRIDIAGONAL SECUNDÁRIA DECRESCENTE
// ---------------------------------------------------------
void method_07() {
    IO_id("Method 07 - Exercicio 7: Tridiagonal Secundaria Decrescente");
    
    int n;
    printf("Digite a dimensao da matriz quadrada (N): ");
    scanf("%d", &n);

    if (n > 0) {
        Matrix* mat = new_Matrix(n, n);
        int contador = n * 3; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int soma = i + j;
                if (soma == n - 1 || soma == n - 2 || soma == n) {
                    mat->data[i][j] = contador; 
                    contador--;
                } else {
                    mat->data[i][j] = 0;
                }
            }
        }
        
        printf("\nMatriz Gerada:");
        matrix_print(mat);
        matrix_gravar("MATRIZ2.TXT", mat);
        delete_Matrix(mat);
    }
    IO_pause("\nENTER para continuar");
}

// ---------------------------------------------------------
// EXERCÍCIO 08 - VERIFICAR POTÊNCIAS POR COLUNA
// ---------------------------------------------------------
/*
  Verifica se cada coluna segue potências de uma base.
  Ex: Coluna com 1, 2, 4, 8 (base 2).
*/
int checar_potencia_coluna(Matrix* mat) {
    int ehPotencia = 1;
    if (!mat) return 0;

    for (int j = 0; j < mat->cols; j++) {
        if (mat->rows >= 2) {
            
            if (mat->data[0][j] != 0) {
               if (mat->data[0][j] != 1) return 0; 
               
               int base = mat->data[1][j]; 
               for (int i = 1; i < mat->rows; i++) {
                   if (mat->data[i][j] != mat->data[i-1][j] * base) {
                       ehPotencia = 0;
                   }
               }
            }
        }
    }
    return ehPotencia;
}

void method_08() {
    IO_id("Method 08 - Exercicio 8: Potencias por Coluna");
    Matrix* mat = matrix_ler("MATRIZ3.TXT"); 

    if (mat != NULL) {
        matrix_print(mat);
        if (checar_potencia_coluna(mat)) {
            printf("\nA matriz segue a logica de potencias por coluna.\n");
        } else {
            printf("\nA matriz NAO segue a logica.\n");
        }
        delete_Matrix(mat);
    } else {
        printf("\nArquivo MATRIZ3.TXT nao encontrado.");
    }
    IO_pause("\nENTER para continuar");
}

// ---------------------------------------------------------
// EXERCÍCIO 09 - VERIFICAR POTÊNCIAS POR LINHA (Decrescente)
// ---------------------------------------------------------
int checar_potencia_linha_dec(Matrix* mat) {
    int ehPotencia = 1;
    if (!mat) return 0;

    for (int i = 0; i < mat->rows; i++) {
        if (mat->cols >= 2) {
            for (int j = 0; j < mat->cols - 1; j++) {
                if (mat->data[i][j] <= mat->data[i][j+1]) {
                    ehPotencia = 0; 
                }
            }
        }
    }
    return ehPotencia;
}

void method_09() {
    IO_id("Method 09 - Exercicio 9: Potencias por Linha Decrescente");
    Matrix* mat = matrix_ler("MATRIZ4.TXT"); 

    if (mat != NULL) {
        matrix_print(mat);
        if (checar_potencia_linha_dec(mat)) {
            printf("\nA matriz apresenta potencias decrescentes por linha.\n");
        } else {
            printf("\nA matriz NAO satisfaz a condicao.\n");
        }
        delete_Matrix(mat);
    } else {
        printf("\nArquivo MATRIZ4.TXT nao encontrado.");
    }
    IO_pause("\nENTER para continuar");
}

// ---------------------------------------------------------
// EXERCÍCIO 10 - SUPERMERCADOS
// ---------------------------------------------------------

typedef struct s_Supermercado {
    char nome[50];
    int codigo;
    double preco;
} Supermercado;

void method_10() {
    IO_id("Method 10 - Exercicio 10: Supermercados");


    FILE* arq = fopen("DADOS3.TXT", "rt");
    int n = 0;
    
    if (arq != NULL) {
        fscanf(arq, "%d", &n); 
        if (n > 0) {
            Supermercado* lista = (Supermercado*) malloc(n * sizeof(Supermercado));
            double soma = 0.0;

            for (int i = 0; i < n; i++) {
                fscanf(arq, "%s", lista[i].nome);
                fscanf(arq, "%d", &lista[i].codigo);
                fscanf(arq, "%lf", &lista[i].preco);
                soma += lista[i].preco;
            }

            double media = soma / n; 
            printf("\nPreco Medio do produto: %.2lf\n", media);

            printf("\nSupermercados com preco abaixo da media:\n");
            int conta_abaixo = 0;
            for (int i = 0; i < n; i++) {
                if (lista[i].preco < media) { 
                    printf("- %s (Cod: %d) Preco: %.2lf\n", lista[i].nome, lista[i].codigo, lista[i].preco);
                    conta_abaixo++;
                }
            }
            if (conta_abaixo < 2) printf("(Aviso: Menos de 2 encontrados)\n");

            free(lista);
        }
        fclose(arq);
    } else {
        printf("\nErro ao abrir DADOS3.TXT");
    }
    IO_pause("\nENTER para continuar");
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
        printf ( "\n%s" , "4 - Method_04 - Filtrar Comuns (Ex 4)" );
        printf ( "\n%s" , "5 - Method_05 - Binario para Decimal" );
        printf ( "\n%s" , "6 - Method_06 - Matriz Tridiagonal Crescente" );
        printf ( "\n%s" , "7 - Method_07 - Matriz Tridiagonal Secundaria" );
        printf ( "\n%s" , "8 - Method_08 - Checar Potencias Coluna" );
        printf ( "\n%s" , "9 - Method_09 - Checar Potencias Linha" );
        printf ( "\n%s" , "10 - Method_10 - Supermercados" );
        
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
            case 4: method_04(); break;
            case 5: method_05(); break;
            case 6: method_06(); break;
            case 7: method_07(); break;
            case 8: method_08(); break;
            case 9: method_09(); break;
            case 10: method_10(); break;

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