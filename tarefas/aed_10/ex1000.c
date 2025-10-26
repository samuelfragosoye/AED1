/*
  Exemplo1000.c - v0.0. 
  Author: Samuel Fragoso
  Matricula: 902665

  Para o Estudo Dirigido 10 - Grupos de dados heterogêneos (structs)
*/


#include "io.h"       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>     

// ------------------------------------------- DEFINICOES DE TIPOS (Structs)

/**
 * Definicao de tipo arranjo com inteiros
 * baseado em estrutura
 */
typedef struct s_int_Array
{
    int length;
    ints data;
    int ix;
} int_Array;

/**
 * Definicao de referencia para arranjo com inteiros
 * baseado em estrutura
 */
typedef int_Array* ref_int_Array;

/**
 * new_int_Array - Reservar espaco para arranjo com inteiros
 * @return referencia para arranjo com inteiros
 * @param n - quantidade de dados
 */
ref_int_Array new_int_Array(int n)
{
    // reserva de espaco
    ref_int_Array tmpArray = (ref_int_Array)malloc(sizeof(int_Array));
    // estabelecer valores padroes
    if (tmpArray == NULL)
    {
        IO_printf("\nERRO: Falta espaco.\n");
    }
    else
    {
        tmpArray->length = 0;
        tmpArray->data = NULL;
        tmpArray->ix = -1;
        if (n > 0)
        {
            // guardar a quantidade de dados
            tmpArray->length = n;
            // reservar espaco para os dados
            tmpArray->data = (ints)malloc(n * sizeof(int));
            // definir indicador do primeiro elemento
            tmpArray->ix = 0;
        } // end if
    } // end if
    // retornar referencia para espaco reservado
    return (tmpArray);
} // end new_int_Array()

/**
 * free_int_Array - Dispensar espaco para arranjo com inteiros
 * @param tmpArray - referencia para grupo de valores inteiros
 */
void free_int_Array(ref_int_Array tmpArray)
{
    // testar se ha' dados, antes de reciclar o espaco
    if (tmpArray != NULL)
    {
        if (tmpArray->data != NULL)
        {
            free(tmpArray->data);
        } // end if
        free(tmpArray);
    } // fim se
} // end free_int_Array ()

/**
 * printIntArray - Mostrar arranjo com valores inteiros.
 * @param array - grupo de valores inteiros
 */
void printIntArray(int_Array array)
{
    // mostrar valores no arranjo
    if (array.data)
    {
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            // mostrar valor
            printf("%2d: %d\n", array.ix, array.data[array.ix]);
        } // end for
    } // end if
} // end printIntArray ()

/**
 * Definicao de tipo arranjo bidimensional com inteiros
 * baseado em estrutura
 */
typedef struct s_int_Matrix
{
    int rows;
    int columns;
    ints* data; // Agora é um ponteiro para ponteiro (array de arrays)
    int ix, iy;
} int_Matrix;

/**
 * Definicao de referencia para arranjo bidimensional com inteiros
 * baseado em estrutura
 */
typedef int_Matrix* ref_int_Matrix;

/**
 * new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
 * @return referencia para arranjo com inteiros
 * @param rows    - quantidade de dados (linhas)
 * @param columns - quantidade de dados (colunas)
 */
ref_int_Matrix new_int_Matrix(int rows, int columns)
{
    // reserva de espaco
    ref_int_Matrix tmpMatrix = (ref_int_Matrix)malloc(sizeof(int_Matrix));
    // estabelecer valores padroes
    if (tmpMatrix != NULL)
    {
        tmpMatrix->rows = 0;
        tmpMatrix->columns = 0;
        tmpMatrix->data = NULL;
        // reservar espaco
        if (rows > 0 && columns > 0)
        {
            tmpMatrix->rows = rows;
            tmpMatrix->columns = columns;
            tmpMatrix->data = (ints*)malloc(rows * sizeof(ints)); // Array de ponteiros (linhas)
            if (tmpMatrix->data)
            {
                for (tmpMatrix->ix = 0; tmpMatrix->ix < tmpMatrix->rows; tmpMatrix->ix = tmpMatrix->ix + 1)
                {
                    // Array de inteiros (colunas)
                    tmpMatrix->data[tmpMatrix->ix] = (ints)malloc(columns * sizeof(int));
                } // end for
            } // end if
        } // end if
        tmpMatrix->ix = 0;
        tmpMatrix->iy = 0;
    } // end if
    return (tmpMatrix);
} // end new_int_Matrix ()

/**
 * free_int_Matrix - Dispensar espaco para arranjo com inteiros
 * @param tmpMatrix - referencia para grupo de valores inteiros
 */
void free_int_Matrix(ref_int_Matrix matrix)
{
    // testar se ha' dados
    if (matrix != NULL)
    {
        if (matrix->data != NULL)
        {
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                free(matrix->data[matrix->ix]); // Libera cada linha
            } // end for
            free(matrix->data); // Libera o array de ponteiros
        } // end if
        free(matrix); // Libera a struct
    } // end if
} // end free_int_Matrix ()

/**
 * printIntMatrix - Mostrar matrix com valores inteiros.
 * @param matrix - grupo de valores inteiros
 */
void printIntMatrix(ref_int_Matrix matrix)
{
    // testar a existencia
    if (matrix != NULL && matrix->data != NULL)
    {
        // mostrar valores na matriz
        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
            {
                // mostrar valor
                printf("%3d\t", matrix->data[matrix->ix][matrix->iy]);
            } // end for
            printf("\n");
        } // end for
    } // end if
} // end printIntMatrix ()


// ------------------------------------------- EXEMPLOS (Metodos 01-10)

/**
 * Method 01 - Mostrar certa quantidade de valores.
 */
void method_01()
{
    // definir dado
    int_Array array;
    // montar arranjo em estrutura
    array.length = 5;
    array.data = (ints)malloc(array.length * sizeof(int));
    // testar a existência de dados
    if (array.data)
    {
        array.data[0] = 1;
        array.data[1] = 2;
        array.data[2] = 3;
        array.data[3] = 4;
        array.data[4] = 5;
    } // fim se
    // identificar
    IO_id("Method_01 - v0.0");
    // executar o metodo auxiliar
    printIntArray(array);
    // reciclar o espaco
    if (array.data)
    {
        free(array.data);
    } // fim se
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_01 ()

/**
 * IO_readintArray - Ler arranjo com valores inteiros.
 * @return arranjo com valores lidos
 */
int_Array IO_readintArray()
{
    // definir dados locais
    chars text = IO_new_chars(STR_SIZE);
    static int_Array array;
    // ler a quantidade de dados
    do
    {
        array.length = IO_readint("\nlength = ");
    } while (array.length <= 0);
    // reservar espaco para armazenar
    array.data = IO_new_ints(array.length);
    // testar se ha' espaco
    if (array.data == NULL)
    {
        array.length = 0; // nao ha' espaco
    }
    else
    {
        // ler e guardar valores em arranjo
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            // ler valor
            strcpy(text, STR_EMPTY);
            array.data[array.ix] = IO_readint(IO_concat(
                IO_concat(text, IO_toString_d(array.ix)), " : "));
        } // end for
    } // end if
    // retornar arranjo
    return (array);
} // end IO_readintArray ()

/**
 * Method 02.
 */
void method_02()
{
    // definir dados
    int_Array array;
    // identificar
    IO_id("Method_02 - v0.0");
    // ler dados
    array = IO_readintArray();
    // testar a existência de dados
    if (array.data)
    {
        // mostrar dados
        IO_printf("\n");
        printIntArray(array);
        // reciclar o espaco
        free(array.data);
    } // end if
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_02 ()

/**
 * fprintIntArray - Gravar arranjo com valores inteiros.
 * @param fileName - nome do arquivo
 * @param array - grupo de valores inteiros
 */
void fprintIntArray(chars fileName, int_Array array)
{
    // definir dados locais
    FILE* arquivo = fopen(fileName, "wt");
    // gravar quantidade de dados
    fprintf(arquivo, "%d\n", array.length);
    // gravar valores no arquivo, se existirem
    if (array.data)
    {
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            // gravar valor
            fprintf(arquivo, "%d\n", array.data[array.ix]);
        } // end for
    } // end if
    // fechar arquivo
    fclose(arquivo);
} // end fprintIntArray ()

/**
 * Method 03.
 */
void method_03()
{
    // definir dados
    int_Array array;
    // identificar
    IO_id("Method_03 - v0.0");
    // ler dados
    array = IO_readintArray();
    // testar a existência de dados
    if (array.data)
    {
        // mostrar e gravar dados
        IO_printf("\n");
        printIntArray(array);
        fprintIntArray("ARRAY1.TXT", array);
        // reciclar o espaco
        free(array.data);
    } // end if
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_03 ()

/**
 * freadArraySize - Ler tamanho do arranjo com valores inteiros.
 * @return quantidade de valores lidos
 * @param fileName - nome do arquivo
 */
int freadArraySize(chars fileName)
{
    // definir dados locais
    int n = 0;
    FILE* arquivo = fopen(fileName, "rt");
    // testar a existencia
    if (arquivo)
    {
        // ler a quantidade de dados
        fscanf(arquivo, "%d", &n);
        if (n <= 0)
        {
            IO_printf("\nERRO: Valor invalido.\n");
            n = 0;
        } // end if
        fclose(arquivo);
    } // end if
    // retornar dados lidos
    return (n);
} // end freadArraySize ()

/**
 * fIO_readintArray - Ler arranjo com valores inteiros.
 * @return arranjo com os valores lidos
 * @param fileName - nome do arquivo
 */
int_Array fIO_readintArray(chars fileName)
{
    // definir dados locais
    FILE* arquivo = fopen(fileName, "rt");
    static int_Array array;
    // testar a existencia
    if (arquivo)
    {
        // ler a quantidade de dados
        fscanf(arquivo, "%d", &array.length);
        // testar se ha' dados
        if (array.length <= 0)
        {
            IO_printf("\nERRO: Valor invalido.\n");
            array.length = 0; // nao ha' dados
        }
        else
        {
            // reservar espaco
            array.data = IO_new_ints(array.length);
            // testar a existência
            if (array.data)
            {
                // ler e guardar valores em arranjo
                array.ix = 0;
                while (!feof(arquivo) &&
                       array.ix < array.length)
                {
                    // ler valor
                    fscanf(arquivo, "%d", &(array.data[array.ix]));
                    // passar ao proximo
                    array.ix = array.ix + 1;
                } // end while
            } // end if
        } // end if
        fclose(arquivo); // Fechar arquivo
    } // end if
    // retornar dados lidos
    return (array);
} // end fIO_readintArray ()

/**
 * Method 04.
 */
void method_04()
{
    // definir dados
    int_Array array; // arranjo sem tamanho definido
    // identificar
    IO_id("Method_04 - v0.0");
    // ler dados
    array = fIO_readintArray("ARRAY1.TXT");
    // testar a existência de dados
    if (array.data)
    {
        // mostrar dados
        IO_printf("\n");
        printIntArray(array);
        // reciclar o espaco
        free(array.data);
    } // end if
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_04 ()

/**
 * copyIntArray - Copiar arranjo com valores inteiros.
 * @return referencia para copia do arranjo
 * @param array - grupo de valores inteiros
 */
ref_int_Array copyIntArray(int_Array array)
{
    // definir dados locais
    ref_int_Array copy;
    if (array.length <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
        array.length = 0;
        copy = NULL; // Retorna nulo se o original for invalido
    }
    else
    {
        // reservar area
        copy = new_int_Array(array.length);
        // testar se ha' descritor
        if (copy)
        {
            // (new_int_Array ja' define copy->length e aloca copy->data)
            
            // testar se ha' espaco e dados
            if (copy->data == NULL || array.data == NULL)
            {
                printf("\nERRO: Falta espaco ou dados.");
                copy->length = 0; // Indica erro
            }
            else
            {
                // ler e copiar valores
                for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
                {
                    // copiar valor
                    copy->data[array.ix] = array.data[array.ix];
                } // end for
            } // end if
        } // end if
    } // end if
    // retornar dados lidos
    return (copy);
} // end copyIntArray ()

/**
 * Method 05.
 */
void method_05()
{
    // definir dados
    int_Array array; // arranjo sem tamanho definido
    ref_int_Array other; // referencia para arranjo sem tamanho definido
    // identificar
    IO_id("Method_05 - v0.0");
    // ler dados
    array = fIO_readintArray("ARRAY1.TXT");
    // copiar dados
    other = copyIntArray(array);
    // testar a existência de dados
    if (array.data && other && other->data) // Verifica ambos
    {
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(*other); // dereferenciar a copia
        
        // reciclar os espacos
        free(array.data);
        free_int_Array(other); // Usa a funcao free da struct
    } // end if
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_05 ()

/**
 * Method 06.
 */
void method_06()
{
    // definir dado
    ref_int_Matrix matrix = new_int_Matrix(3, 3);
    if (matrix != NULL && matrix->data != NULL)
    {
        matrix->data[0][0] = 1;
        matrix->data[0][1] = 2;
        matrix->data[0][2] = 3;
        matrix->data[1][0] = 3; // PDF tem 3, mas 4 seria mais logico
        matrix->data[1][1] = 4;
        matrix->data[1][2] = 5;
        matrix->data[2][0] = 6; // PDF inverte 2,0 com 2,1
        matrix->data[2][1] = 7;
        matrix->data[2][2] = 8;
    } // fim se
    // identificar
    IO_id("Method_06 - v0.0");
    // executar o metodo auxiliar
    printIntMatrix(matrix);
    // reciclar espaco
    free_int_Matrix(matrix);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_06 ()

/**
 * IO_readintMatrix - Ler arranjo bidimensional com valores inteiros.
 * @return referencia para o grupo de valores inteiros
 */
ref_int_Matrix IO_readintMatrix()
{
    // definir dados locais
    int rows = 0;
    int columns = 0;
    chars text = IO_new_chars(STR_SIZE);
    
    // ler a quantidade de dados
    do
    {
        rows = IO_readint("\nrows = ");
    } while (rows <= 0);
    do
    {
        columns = IO_readint("\ncolumns = ");
    } while (columns <= 0);
    
    // reservar espaco para armazenar valores
    ref_int_Matrix matrix = new_int_Matrix(rows, columns);
    
    // testar se ha' espaco
    if (matrix != NULL)
    {
        if (matrix->data == NULL)
        {
            // nao ha' espaco
            matrix->rows = 0;
            matrix->columns = 0;
            matrix->ix = 0;
            matrix->iy = 0;
        }
        else
        {
            // ler e guardar valores na matriz
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    // ler e guardar valor
                    strcpy(text, STR_EMPTY);
                    matrix->data[matrix->ix][matrix->iy] = IO_readint(IO_concat(
                        IO_concat(IO_concat(text, IO_toString_d(matrix->ix)), ","),
                        IO_concat(IO_concat(text, IO_toString_d(matrix->iy)), " : ")));
                } // end for
                printf("\n");
            } // end for
        } // end if
    } // end if
    
    // liberar 'text'
    free(text);
    
    // retornar dados lidos
    return (matrix);
} // end IO_readintMatrix ()

/**
 * Method 07.
 */
void method_07()
{
    // definir dados
    ref_int_Matrix matrix = NULL;
    // identificar
    IO_id("Method_07 - v0.0");
    // ler dados
    matrix = IO_readintMatrix();
    // mostrar dados
    IO_printf("\n");
    printIntMatrix(matrix);
    // reciclar espaco
    free_int_Matrix(matrix);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_07 ()

/**
 * fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 * @param fileName - nome do arquivo
 * @param matrix - grupo de valores inteiros
 */
void fprintIntMatrix(chars fileName, ref_int_Matrix matrix)
{
    // definir dados locais
    FILE* arquivo = fopen(fileName, "wt");
    
    // testar se ha' dados
    if (matrix == NULL)
    {
        printf("\nERRO: Nao ha' dados.");
    }
    else
    {
        // gravar quantidade de dados
        fprintf(arquivo, "%d\n", matrix->rows);
        fprintf(arquivo, "%d\n", matrix->columns);
        if (matrix->data != NULL)
        {
            // gravar valores no arquivo
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    // gravar valor
                    fprintf(arquivo, "%d\n", matrix->data[matrix->ix][matrix->iy]);
                } // end for
            } // end for
        } // end if
        // fechar arquivo
        fclose(arquivo);
    } // end if
} // end fprintIntMatrix ()

/**
 * Method 08.
 */
void method_08()
{
    // definir dados
    ref_int_Matrix matrix = NULL;
    // identificar
    IO_id("Method_08 - v0.0");
    // ler dados
    matrix = IO_readintMatrix();
    // gravar dados
    fprintIntMatrix("MATRIX1.TXT", matrix);
    // reciclar espaco
    free_int_Matrix(matrix);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_08 ()

/**
 * freadintMatrix - Ler arranjo bidimensional com valores inteiros.
 * @return referencia para o grupo de valores inteiros
 * @param fileName - nome do arquivo
 */
ref_int_Matrix freadintMatrix(chars fileName)
{
    // definir dados locais
    ref_int_Matrix matrix = NULL;
    int rows = 0;
    int columns = 0;
    FILE* arquivo = fopen(fileName, "rt");
    
    if (arquivo == NULL) {
        IO_printf("\nERRO: Nao foi possivel abrir o arquivo %s.\n", fileName);
        return NULL;
    }
    
    // ler a quantidade de dados
    fscanf(arquivo, "%d", &rows);
    fscanf(arquivo, "%d", &columns);
    
    if (rows <= 0 || columns <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // reservar espaco para armazenar
        matrix = new_int_Matrix(rows, columns);
        // testar se ha' espaco
        if (matrix != NULL && matrix->data == NULL)
        {
            // nao ha' espaco
            matrix->rows = 0;
            matrix->columns = 0;
            matrix->ix = 0;
            matrix->iy = 0;
        }
        else
        {
            // testar a existência
            if (matrix != NULL)
            {
                // ler e guardar valores na matriz
                matrix->ix = 0;
                while (!feof(arquivo) && matrix->ix < matrix->rows)
                {
                    matrix->iy = 0;
                    while (!feof(arquivo) && matrix->iy < matrix->columns)
                    {
                        // guardar valor
                        fscanf(arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy]));
                        // passar ao proximo
                        matrix->iy = matrix->iy + 1;
                    } // end while
                    // passar ao proximo
                    matrix->ix = matrix->ix + 1;
                } // end while
                matrix->ix = 0;
                matrix->iy = 0;
            } // end if
        } // end if
    } // end if
    
    fclose(arquivo);
    // retornar matriz lida
    return (matrix);
} // end freadintMatrix ()

/**
 * Method 09.
 */
void method_09()
{
    // identificar
    IO_id("Method_09 - v0.0");
    // ler dados
    ref_int_Matrix matrix = freadintMatrix("MATRIX1.TXT");
    // mostrar dados
    IO_printf("\n");
    if (matrix) {
        printIntMatrix(matrix);
    } else {
        IO_printf("Nao foi possivel ler a matriz.\n");
    }
    // reciclar espaco
    free_int_Matrix(matrix);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_09 ()

/**
 * copyIntMatrix - Copiar matriz com valores inteiros.
 * @return referencia para o grupo de valores inteiros
 * @param matrix - matriz original
 */
ref_int_Matrix copyIntMatrix(ref_int_Matrix matrix)
{
    // definir dados locais
    ref_int_Matrix copy = NULL;
    if (matrix == NULL || matrix->data == NULL)
    {
        IO_printf("\nERRO: Faltam dados.\n");
    }
    else
    {
        if (matrix->rows <= 0 || matrix->columns <= 0)
        {
            IO_printf("\nERRO: Valor invalido.\n");
        }
        else
        {
            // reservar espaco
            copy = new_int_Matrix(matrix->rows, matrix->columns);
            // testar se ha' espaco e dados
            if (copy == NULL || copy->data == NULL)
            {
                printf("\nERRO: Falta espaco.");
            }
            else
            {
                // copiar valores
                for (copy->ix = 0; copy->ix < copy->rows; copy->ix = copy->ix + 1)
                {
                    for (copy->iy = 0; copy->iy < copy->columns; copy->iy = copy->iy + 1)
                    {
                        // copiar valor
                        copy->data[copy->ix][copy->iy] = matrix->data[copy->ix][copy->iy];
                    } // end for
                } // end for
            } // end if
        } // end if
    } // end if
    // retornar copia
    return (copy);
} // end copyIntMatrix ()

/**
 * Method 10.
 */
void method_10()
{
    // definir dados
    ref_int_Matrix matrix = NULL;
    ref_int_Matrix other = NULL;
    // identificar
    IO_id("Method_10 - v0.0");
    // ler dados
    matrix = freadintMatrix("MATRIX1.TXT");
    // copiar dados
    other = copyIntMatrix(matrix);
    // mostrar dados
    IO_printf("\nOriginal\n");
    printIntMatrix(matrix);
    // mostrar dados
    IO_printf("\nCopia\n");
    printIntMatrix(other);
    // reciclar espaco
    free_int_Matrix(matrix);
    free_int_Matrix(other);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_10 ()


// ------------------------------------------- EXERCICIOS (Metodos 11-20, E1-E2)

/**
 * Funcao (1011) para gerar um valor inteiro aleatoriamente
 * dentro de um intervalo.
 * @param inferior - limite inferior
 * @param superior - limite superior
 * @return valor aleatorio
 */
int randomIntGenerate(int inferior, int superior)
{
    int valor = 0;
    if (inferior < superior) {
        valor = (rand() % (superior - inferior + 1)) + inferior;
    } else if (inferior > superior) {
        valor = (rand() % (inferior - superior + 1)) + superior;
    } else {
        valor = inferior; // limites iguais
    }
    
    // Limitar a 10^6 conforme dica
    if (valor > 1000000) {
        valor = valor % 1000000;
    }
    
    return valor;
}

/**
 * Method_11 (Exercicio 1011)
 * Gerar valores aleatorios, armazenar em arranjo e gravar em arquivo.
 */
void method_11()
{
    // identificar
    IO_id("Method_11 (1011) - v0.0");
    
    // ler limites
    int inferior = IO_readint("Defina o limite inferior: ");
    int superior = IO_readint("Defina o limite superior: ");
    int n = IO_readint("Defina a quantidade (N): ");
    
    if (n > 0)
    {
        // definir arranjo
        int_Array array;
        array.length = n;
        array.data = IO_new_ints(n);
        
        if (array.data)
        {
            // gerar N valores aleatorios
            for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
            {
                array.data[array.ix] = randomIntGenerate(inferior, superior);
            }
            
            // gravar em arquivo
            fprintIntArray("DADOS.TXT", array);
            IO_printf("\nArquivo \"DADOS.TXT\" gravado com sucesso.\n");
            
            // mostrar dados gerados
            IO_printf("\nValores gerados:\n");
            printIntArray(array);
            
            // reciclar espaco
            free(array.data);
        }
    }
    else
    {
        IO_printf("\nERRO: Quantidade N invalida.\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_11 ()

/**
 * Funcao (1012) para procurar certo valor inteiro em um arranjo.
 * @param valor - valor a ser procurado
 * @param array - arranjo onde procurar
 * @return true se encontrou, false caso contrario
 */
bool arraySearch(int valor, int_Array array)
{
    bool resposta = false;
    
    if (array.data && array.length > 0)
    {
        array.ix = 0;
        // Percorrer o arranjo
        while (array.ix < array.length && !resposta)
        {
            if (array.data[array.ix] == valor)
            {
                resposta = true;
            }
            array.ix = array.ix + 1;
        }
    }
    return resposta;
}

/**
 * Method_12 (Exercicio 1012)
 * Ler arranjo do arquivo "DADOS.TXT" e procurar um valor.
 */
void method_12()
{
    // identificar
    IO_id("Method_12 (1012) - v0.0");
    
    // ler arranjo do arquivo
    int_Array array = fIO_readintArray("DADOS.TXT");
    
    if (array.data && array.length > 0)
    {
        IO_printf("\nArranjo lido de \"DADOS.TXT\":\n");
        printIntArray(array);
        
        // ler valor a procurar
        int valor = IO_readint("\nDigite o valor a ser procurado: ");
        
        // aplicar a funcao
        bool resposta = arraySearch(valor, array);
        
        // mostrar resultado
        if (resposta)
        {
            IO_printf("\nO valor %d FOI encontrado no arranjo.\n", valor);
        }
        else
        {
            IO_printf("\nO valor %d NAO foi encontrado no arranjo.\n", valor);
        }
        
        // reciclar espaco
        free(array.data);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"DADOS.TXT\". Execute o Metodo 11 primeiro.\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_12 ()

/**
 * Funcao (1013) para operar a comparação de dois arranjos.
 * @param arranjo1 - primeiro arranjo
 * @param arranjo2 - segundo arranjo
 * @return true se iguais, false caso contrario
 */
bool arrayCompare(int_Array arranjo1, int_Array arranjo2)
{
    bool resposta = true;
    
    // Verificar se tamanhos sao iguais
    if (arranjo1.length != arranjo2.length)
    {
        resposta = false; // Tamanhos diferentes, nao sao iguais
    }
    else
    {
        // Verificar se os dados existem
        if (arranjo1.data && arranjo2.data)
        {
            arranjo1.ix = 0;
            // Percorrer os arranjos
            while (arranjo1.ix < arranjo1.length && resposta)
            {
                if (arranjo1.data[arranjo1.ix] != arranjo2.data[arranjo1.ix])
                {
                    resposta = false; // Encontrou diferenca
                }
                arranjo1.ix = arranjo1.ix + 1;
            }
        }
        else
        {
            resposta = false; // Um dos arranjos nao tem dados
        }
    }
    
    return resposta;
}

/**
 * Method_13 (Exercicio 1013)
 * Ler dois arranjos de arquivos e comparar.
 */
void method_13()
{
    // identificar
    IO_id("Method_13 (1013) - v0.0");
    
    // ler arranjos (Usar DADOS.TXT e ARRAY1.TXT)
    // DICA: Execute o Method 11 (para DADOS.TXT) e o Method 03 (para ARRAY1.TXT)
    
    int_Array arranjo1 = fIO_readintArray("DADOS.TXT");
    int_Array arranjo2 = fIO_readintArray("ARRAY1.TXT");
    
    if (arranjo1.data && arranjo2.data)
    {
        IO_printf("\nArranjo 1 (DADOS.TXT):\n");
        printIntArray(arranjo1);
        IO_printf("\nArranjo 2 (ARRAY1.TXT):\n");
        printIntArray(arranjo2);
        
        // aplicar a funcao
        bool resposta = arrayCompare(arranjo1, arranjo2);
        
        // mostrar resultado
        if (resposta)
        {
            IO_printf("\nOs arranjos sao IGUAIS.\n");
        }
        else
        {
            IO_printf("\nOs arranjos sao DIFERENTES.\n");
        }
        
        // reciclar espaco
        free(arranjo1.data);
        free(arranjo2.data);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler os arquivos.\n");
        IO_printf("Execute o Metodo 03 (para ARRAY1.TXT) e o Metodo 11 (para DADOS.TXT).\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_13 ()

/**
 * Funcao (1014) para operar a soma de dois arranjos (arranjo1 + k * arranjo2).
 * @param arranjo1 - primeiro arranjo
 * @param k - constante multiplicativa
 * @param arranjo2 - segundo arranjo
 * @return referencia para o arranjo com o resultado
 */
ref_int_Array arrayAdd(int_Array arranjo1, int k, int_Array arranjo2)
{
    ref_int_Array soma = NULL;
    
    // Verificar se tamanhos sao compativeis
    if (arranjo1.length != arranjo2.length)
    {
        IO_printf("\nERRO: Tamanhos incompativeis para soma.\n");
    }
    else
    {
        // Verificar se os dados existem
        if (arranjo1.data && arranjo2.data)
        {
            // Criar novo arranjo para a soma
            soma = new_int_Array(arranjo1.length);
            
            if (soma && soma->data)
            {
                // Calcular a soma
                for (soma->ix = 0; soma->ix < soma->length; soma->ix = soma->ix + 1)
                {
                    soma->data[soma->ix] = arranjo1.data[soma->ix] + k * arranjo2.data[soma->ix];
                }
            }
        }
        else
        {
            IO_printf("\nERRO: Faltam dados em um dos arranjos.\n");
        }
    }
    
    return soma;
}

/**
 * Method_14 (Exercicio 1014)
 * Somar dois arranjos (arranjo1 + k * arranjo2).
 */
void method_14()
{
    // identificar
    IO_id("Method_14 (1014) - v0.0");
    
    int_Array arranjo1 = fIO_readintArray("DADOS.TXT");
    int_Array arranjo2 = fIO_readintArray("ARRAY1.TXT");
    ref_int_Array soma = NULL;
    
    if (arranjo1.data && arranjo2.data)
    {
        IO_printf("\nArranjo 1 (DADOS.TXT):\n");
        printIntArray(arranjo1);
        IO_printf("\nArranjo 2 (ARRAY1.TXT):\n");
        printIntArray(arranjo2);
        
        int k = IO_readint("\nDigite a constante k: ");
        
        // aplicar a funcao
        soma = arrayAdd(arranjo1, k, arranjo2);
        
        if (soma)
        {
            IO_printf("\nArranjo Soma (arranjo1 + %d * arranjo2):\n", k);
            printIntArray(*soma); // Dereferenciar
            
            // reciclar espaco
            free_int_Array(soma);
        }
        
        // reciclar espaco
        free(arranjo1.data);
        free(arranjo2.data);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler os arquivos.\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_14 ()

/**
 * Funcao (1015) para dizer se um arranjo está em ordem decrescente.
 * @param arranjo - arranjo a ser verificado
 * @return true se estiver em ordem decrescente, false caso contrario
 */
bool isArrayDecrescent(int_Array arranjo)
{
    bool resposta = true;
    
    if (arranjo.data && arranjo.length > 0)
    {
        arranjo.ix = 0;
        // Percorrer o arranjo (sem break)
        while (arranjo.ix < (arranjo.length - 1) && resposta)
        {
            // Se um elemento for MENOR que o proximo, nao esta decrescente
            if (arranjo.data[arranjo.ix] < arranjo.data[arranjo.ix + 1])
            {
                resposta = false;
            }
            arranjo.ix = arranjo.ix + 1;
        }
    }
    else
    {
        IO_printf("\nERRO: Arranjo invalido ou vazio.\n");
        resposta = false; // Arranjo vazio nao e' considerado
    }
    
    return resposta;
}

/**
 * Method_15 (Exercicio 1015)
 * Verificar se arranjo esta em ordem decrescente.
 */
void method_15()
{
    // identificar
    IO_id("Method_15 (1015) - v0.0");
    
    int_Array arranjo1 = fIO_readintArray("DADOS.TXT");
    
    if (arranjo1.data)
    {
        IO_printf("\nArranjo (DADOS.TXT):\n");
        printIntArray(arranjo1);
        
        // aplicar a funcao
        bool resposta = isArrayDecrescent(arranjo1);
        
        if (resposta)
        {
            IO_printf("\nO arranjo ESTA em ordem decrescente.\n");
        }
        else
        {
            IO_printf("\nO arranjo NAO ESTA em ordem decrescente.\n");
        }
        
        free(arranjo1.data);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"DADOS.TXT\".\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_15 ()

/**
 * Funcao (1016) para obter a transposta de uma matriz.
 * @param matrix - matriz original
 * @return referencia para a matriz transposta
 */
ref_int_Matrix matrixTranspose(ref_int_Matrix matrix)
{
    ref_int_Matrix transposta = NULL;
    
    if (matrix && matrix->data && matrix->rows > 0 && matrix->columns > 0)
    {
        // Criar a matriz transposta com dimensoes invertidas
        transposta = new_int_Matrix(matrix->columns, matrix->rows);
        
        if (transposta && transposta->data)
        {
            // Preencher a transposta
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    transposta->data[matrix->iy][matrix->ix] = matrix->data[matrix->ix][matrix->iy];
                }
            }
        }
    }
    else
    {
        IO_printf("\nERRO: Matriz original invalida.\n");
    }
    
    return transposta;
}

/**
 * Method_16 (Exercicio 1016)
 * Obter a transposta de uma matriz lida de arquivo.
 */
void method_16()
{
    // identificar
    IO_id("Method_16 (1016) - v0.0");
    
    // DICA: Execute o Method 08 para criar "MATRIX1.TXT"
    ref_int_Matrix matriz1 = freadintMatrix("MATRIX1.TXT");
    ref_int_Matrix matrizT = NULL;
    
    if (matriz1)
    {
        IO_printf("\nMatriz Original (MATRIX1.TXT):\n");
        printIntMatrix(matriz1);
        
        // aplicar a funcao
        matrizT = matrixTranspose(matriz1);
        
        if (matrizT)
        {
            IO_printf("\nMatriz Transposta:\n");
            printIntMatrix(matrizT);
            
            // reciclar espaco
            free_int_Matrix(matrizT);
        }
        
        // reciclar espaco
        free_int_Matrix(matriz1);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"MATRIX1.TXT\".\n");
        IO_printf("Execute o Metodo 08 primeiro.\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_16 ()

/**
 * Funcao (1017) para testar se uma matriz só contém valores iguais a zero.
 * @param matrix - matriz a ser verificada
 * @return true se for matriz nula, false caso contrario
 */
bool matrixIsZero(ref_int_Matrix matrix)
{
    bool resposta = true;
    
    if (matrix && matrix->data && matrix->rows > 0 && matrix->columns > 0)
    {
        matrix->ix = 0;
        // Percorrer (sem break)
        while (matrix->ix < matrix->rows && resposta)
        {
            matrix->iy = 0;
            while (matrix->iy < matrix->columns && resposta)
            {
                if (matrix->data[matrix->ix][matrix->iy] != 0)
                {
                    resposta = false; // Encontrou valor nao-nulo
                }
                matrix->iy = matrix->iy + 1;
            }
            matrix->ix = matrix->ix + 1;
        }
    }
    else
    {
        IO_printf("\nERRO: Matriz invalida.\n");
        resposta = false;
    }
    
    return resposta;
}

/**
 * Method_17 (Exercicio 1017)
 * Testar se matriz lida de arquivo e' nula.
 */
void method_17()
{
    // identificar
    IO_id("Method_17 (1017) - v0.0");
    
    ref_int_Matrix matriz1 = freadintMatrix("MATRIX1.TXT");
    
    if (matriz1)
    {
        IO_printf("\nMatriz (MATRIX1.TXT):\n");
        printIntMatrix(matriz1);
        
        // aplicar a funcao
        bool resposta = matrixIsZero(matriz1);
        
        if (resposta)
        {
            IO_printf("\nA matriz CONTEM APENAS valores iguais a zero.\n");
        }
        else
        {
            IO_printf("\nA matriz NAO contem apenas valores iguais a zero.\n");
        }
        
        free_int_Matrix(matriz1);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"MATRIX1.TXT\".\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_17 ()

/**
 * Funcao (1018) para testar a igualdade de duas matrizes.
 * @param matriz1 - primeira matriz
 * @param matriz2 - segunda matriz
 * @return true se forem iguais, false caso contrario
 */
bool matrixCompare(ref_int_Matrix matriz1, ref_int_Matrix matriz2)
{
    bool resposta = true;
    
    // Verificar se sao validas
    if (!matriz1 || !matriz1->data || !matriz2 || !matriz2->data)
    {
        IO_printf("\nERRO: Uma das matrizes e' invalida.\n");
        return false;
    }
    
    // Verificar se os tamanhos sao compativeis
    if (matriz1->rows != matriz2->rows || matriz1->columns != matriz2->columns)
    {
        resposta = false;
    }
    else
    {
        // Comparar elemento a elemento (sem break)
        matriz1->ix = 0;
        while (matriz1->ix < matriz1->rows && resposta)
        {
            matriz1->iy = 0;
            while (matriz1->iy < matriz1->columns && resposta)
            {
                if (matriz1->data[matriz1->ix][matriz1->iy] != matriz2->data[matriz1->ix][matriz1->iy])
                {
                    resposta = false;
                }
                matriz1->iy = matriz1->iy + 1;
            }
            matriz1->ix = matriz1->ix + 1;
        }
    }
    
    return resposta;
}

/**
 * Method_18 (Exercicio 1018)
 * Testar a igualdade de duas matrizes.
 */
void method_18()
{
    // identificar
    IO_id("Method_18 (1018) - v0.0");
    
    // Ler a mesma matriz duas vezes para comparar
    ref_int_Matrix matriz1 = freadintMatrix("MATRIX1.TXT");
    ref_int_Matrix matriz2 = freadintMatrix("MATRIX1.TXT");
    
    if (matriz1 && matriz2)
    {
        IO_printf("\nMatriz 1:\n");
        printIntMatrix(matriz1);
        IO_printf("\nMatriz 2:\n");
        printIntMatrix(matriz2);
        
        // Teste 1: Comparar iguais
        bool resposta = matrixCompare(matriz1, matriz2);
        IO_printf("\nTeste 1 (iguais): %s\n", resposta ? "IGUAIS" : "DIFERENTES");
        
        // Modificar um valor
        if (matriz2->rows > 0 && matriz2->columns > 0)
        {
            matriz2->data[0][0] = matriz2->data[0][0] + 1;
            IO_printf("\nModificando Matriz 2 [0][0]...\n");
            
            // Teste 2: Comparar diferentes
            resposta = matrixCompare(matriz1, matriz2);
            IO_printf("\nTeste 2 (diferentes): %s\n", resposta ? "IGUAIS" : "DIFERENTES");
        }
        
        free_int_Matrix(matriz1);
        free_int_Matrix(matriz2);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"MATRIX1.TXT\".\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_18 ()

/**
 * Funcao (1019) para operar a soma de duas matrizes (matriz1 + k * matriz2).
 * @param matriz1 - primeira matriz
 * @param k - constante multiplicativa
 * @param matriz2 - segunda matriz
 * @return referencia para a matriz soma
 */
ref_int_Matrix matrixAdd(ref_int_Matrix matriz1, int k, ref_int_Matrix matriz2)
{
    ref_int_Matrix soma = NULL;
    
    // Verificar se sao validas
    if (!matriz1 || !matriz1->data || !matriz2 || !matriz2->data)
    {
        IO_printf("\nERRO: Uma das matrizes e' invalida.\n");
        return NULL;
    }
    
    // Verificar se os tamanhos sao compativeis
    if (matriz1->rows != matriz2->rows || matriz1->columns != matriz2->columns)
    {
        IO_printf("\nERRO: Tamanhos incompativeis para soma.\n");
    }
    else
    {
        // Criar matriz soma
        soma = new_int_Matrix(matriz1->rows, matriz1->columns);
        
        if (soma && soma->data)
        {
            // Calcular a soma
            for (soma->ix = 0; soma->ix < soma->rows; soma->ix = soma->ix + 1)
            {
                for (soma->iy = 0; soma->iy < soma->columns; soma->iy = soma->iy + 1)
                {
                    soma->data[soma->ix][soma->iy] = 
                        matriz1->data[soma->ix][soma->iy] + k * matriz2->data[soma->ix][soma->iy];
                }
            }
        }
    }
    
    return soma;
}

/**
 * Method_19 (Exercicio 1019)
 * Somar duas matrizes (matriz1 + k * matriz2).
 */
void method_19()
{
    // identificar
    IO_id("Method_19 (1019) - v0.0");
    
    // Usar a mesma matriz para somar (matriz1 + k * matriz1)
    ref_int_Matrix matriz1 = freadintMatrix("MATRIX1.TXT");
    ref_int_Matrix matriz2 = freadintMatrix("MATRIX1.TXT"); // Usando a mesma
    ref_int_Matrix soma = NULL;
    
    if (matriz1 && matriz2)
    {
        IO_printf("\nMatriz 1:\n");
        printIntMatrix(matriz1);
        
        int k = IO_readint("\nDigite a constante k: ");
        
        // aplicar a funcao
        soma = matrixAdd(matriz1, k, matriz2);
        
        if (soma)
        {
            IO_printf("\nMatriz Soma (matriz1 + %d * matriz2):\n", k);
            printIntMatrix(soma);
            
            free_int_Matrix(soma);
        }
        
        free_int_Matrix(matriz1);
        free_int_Matrix(matriz2);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"MATRIX1.TXT\".\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_19 ()

/**
 * Funcao (1020) para obter o produto de duas matrizes.
 * @param matriz1 - primeira matriz (A)
 * @param matriz2 - segunda matriz (B)
 * @return referencia para a matriz produto (C = A * B)
 */
ref_int_Matrix matrixProduct(ref_int_Matrix matriz1, ref_int_Matrix matriz2)
{
    ref_int_Matrix produto = NULL;
    int soma_elemento = 0;
    
    // Verificar se sao validas
    if (!matriz1 || !matriz1->data || !matriz2 || !matriz2->data)
    {
        IO_printf("\nERRO: Uma das matrizes e' invalida.\n");
        return NULL;
    }
    
    // Verificar compatibilidade (colunas A == linhas B)
    if (matriz1->columns != matriz2->rows)
    {
        IO_printf("\nERRO: Dimensoes incompativeis para multiplicacao.\n");
        IO_printf("(Colunas M1: %d != Linhas M2: %d)\n", matriz1->columns, matriz2->rows);
    }
    else
    {
        // Criar matriz produto (linhas A x colunas B)
        produto = new_int_Matrix(matriz1->rows, matriz2->columns);
        
        if (produto && produto->data)
        {
            // Calcular o produto
            for (produto->ix = 0; produto->ix < produto->rows; produto->ix = produto->ix + 1) // Linhas de A
            {
                for (produto->iy = 0; produto->iy < produto->columns; produto->iy = produto->iy + 1) // Colunas de B
                {
                    soma_elemento = 0;
                    // Somatorio (k de 0 a colunasA/linhasB)
                    for (int k = 0; k < matriz1->columns; k = k + 1)
                    {
                        soma_elemento = soma_elemento + 
                            (matriz1->data[produto->ix][k] * matriz2->data[k][produto->iy]);
                    }
                    produto->data[produto->ix][produto->iy] = soma_elemento;
                }
            }
        }
    }
    
    return produto;
}

/**
 * Method_20 (Exercicio 1020)
 * Obter o produto de duas matrizes.
 */
void method_20()
{
    // identificar
    IO_id("Method_20 (1020) - v0.0");
    
    // DICA: Crie MATRIX1.TXT (pelo Method 08) e MATRIX2.TXT (pelo Method 08)
    // CUIDADO: As dimensoes devem ser compativeis (Colunas M1 == Linhas M2)
    
    ref_int_Matrix matriz1 = freadintMatrix("MATRIX1.TXT");
    ref_int_Matrix matriz2 = freadintMatrix("MATRIX2.TXT"); // Precisa criar este
    ref_int_Matrix produto = NULL;
    
    if (matriz1 && matriz2)
    {
        IO_printf("\nMatriz 1 (MATRIX1.TXT):\n");
        printIntMatrix(matriz1);
        IO_printf("\nMatriz 2 (MATRIX2.TXT):\n");
        printIntMatrix(matriz2);
        
        // aplicar a funcao
        produto = matrixProduct(matriz1, matriz2);
        
        if (produto)
        {
            IO_printf("\nMatriz Produto:\n");
            printIntMatrix(produto);
            free_int_Matrix(produto);
        }
        
        free_int_Matrix(matriz1);
        free_int_Matrix(matriz2);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"MATRIX1.TXT\" ou \"MATRIX2.TXT\".\n");
        IO_printf("Execute o Metodo 08 duas vezes (para M1 e M2) com dimensoes compativeis.\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_20 ()

/**
 * Funcao (10E1) para colocar um arranjo em ordem decrescente (Bubble Sort).
 * @param array - arranjo original
 * @return referencia para um NOVO arranjo ordenado
 */
ref_int_Array sortArrayDown(int_Array array)
{
    // Criar uma copia para nao modificar o original
    ref_int_Array ordenado = copyIntArray(array);
    
    if (ordenado && ordenado->data)
    {
        // Metodo Bubble Sort
        for (int i = 0; i < ordenado->length - 1; i = i + 1)
        {
            for (int j = 0; j < ordenado->length - 1 - i; j = j + 1)
            {
                // Se (j) < (j+1), troca (para ordem decrescente)
                if (ordenado->data[j] < ordenado->data[j+1])
                {
                    int temp = ordenado->data[j];
                    ordenado->data[j] = ordenado->data[j+1];
                    ordenado->data[j+1] = temp;
                }
            }
        }
    }
    
    return ordenado;
}

/**
 * Method_E1 (Exercicio 10E1)
 * Ordenar arranjo em ordem decrescente.
 */
void method_E1()
{
    // identificar
    IO_id("Method_E1 (10E1) - v0.0");
    
    int_Array arranjo = fIO_readintArray("DADOS.TXT");
    ref_int_Array ordenado = NULL;
    
    if (arranjo.data)
    {
        IO_printf("\nArranjo Original (DADOS.TXT):\n");
        printIntArray(arranjo);
        
        // aplicar a funcao
        ordenado = sortArrayDown(arranjo);
        
        if (ordenado)
        {
            IO_printf("\nArranjo Ordenado (Decrescente):\n");
            printIntArray(*ordenado);
            free_int_Array(ordenado);
        }
        
        free(arranjo.data);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"DADOS.TXT\".\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_E1 ()

/**
 * Funcao (10E2) para testar se o produto de duas matrizes é igual à matriz identidade.
 * @param matrix - matriz a ser verificada
 * @return true se for identidade, false caso contrario
 */
bool isIdentityMatrix(ref_int_Matrix matrix)
{
    bool resposta = true;
    
    // Verificar se e' valida e quadrada
    if (!matrix || !matrix->data || (matrix->rows != matrix->columns))
    {
        return false;
    }
    
    // Percorrer (sem break)
    matrix->ix = 0;
    while (matrix->ix < matrix->rows && resposta)
    {
        matrix->iy = 0;
        while (matrix->iy < matrix->columns && resposta)
        {
            if (matrix->ix == matrix->iy)
            {
                // Diagonal principal
                if (matrix->data[matrix->ix][matrix->iy] != 1)
                {
                    resposta = false;
                }
            }
            else
            {
                // Fora da diagonal
                if (matrix->data[matrix->ix][matrix->iy] != 0)
                {
                    resposta = false;
                }
            }
            matrix->iy = matrix->iy + 1;
        }
        matrix->ix = matrix->ix + 1;
    }
    
    return resposta;
}

/**
 * Method_E2 (Exercicio 10E2)
 * Testar se produto de duas matrizes e' identidade.
 */
void method_E2()
{
    // identificar
    IO_id("Method_E2 (10E2) - v0.0");
    
    ref_int_Matrix matriz1 = freadintMatrix("MATRIX1.TXT");
    ref_int_Matrix matriz2 = freadintMatrix("MATRIX2.TXT");
    ref_int_Matrix produto = NULL;
    
    if (matriz1 && matriz2)
    {
        IO_printf("\nMatriz 1:\n");
        printIntMatrix(matriz1);
        IO_printf("\nMatriz 2:\n");
        printIntMatrix(matriz2);
        
        // Calcular produto
        produto = matrixProduct(matriz1, matriz2);
        
        if (produto)
        {
            IO_printf("\nMatriz Produto:\n");
            printIntMatrix(produto);
            
            // aplicar a funcao de teste
            bool resposta = isIdentityMatrix(produto);
            
            if (resposta)
            {
                IO_printf("\nO produto E' uma matriz identidade.\n");
            }
            else
            {
                IO_printf("\nO produto NAO E' uma matriz identidade.\n");
            }
            
            free_int_Matrix(produto);
        }
        
        free_int_Matrix(matriz1);
        free_int_Matrix(matriz2);
    }
    else
    {
        IO_printf("\nERRO: Nao foi possivel ler \"MATRIX1.TXT\" ou \"MATRIX2.TXT\".\n");
    }
    
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // end method_E2 ()


// ------------------------------------------- FUNCAO PRINCIPAL

/**
 * Funcao principal.
 */
int main()
{
    int x = 0;
    
    // Inicializar o gerador de numeros aleatorios
    srand(time(NULL));

    do
    {
        IO_println("Exemplo1000 - Programa - v0.0");
        IO_println("Author: Samuel Fragoso - 902665");
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - Method_01 (Exemplo 1001)");
        IO_println(" 2 - Method_02 (Exemplo 1002)");
        IO_println(" 3 - Method_03 (Exemplo 1003) - (Cria ARRAY1.TXT)");
        IO_println(" 4 - Method_04 (Exemplo 1004)");
        IO_println(" 5 - Method_05 (Exemplo 1005)");
        IO_println(" 6 - Method_06 (Exemplo 1006)");
        IO_println(" 7 - Method_07 (Exemplo 1007)");
        IO_println(" 8 - Method_08 (Exemplo 1008) - (Cria MATRIX1.TXT)");
        IO_println(" 9 - Method_09 (Exemplo 1009)");
        IO_println("10 - Method_10 (Exemplo 1010)");
        IO_println("-------------------------------------------------");
        IO_println("11 - Method_11 (Exercicio 1011) - (Cria DADOS.TXT)");
        IO_println("12 - Method_12 (Exercicio 1012)");
        IO_println("13 - Method_13 (Exercicio 1013)");
        IO_println("14 - Method_14 (Exercicio 1014)");
        IO_println("15 - Method_15 (Exercicio 1015)");
        IO_println("16 - Method_16 (Exercicio 1016)");
        IO_println("17 - Method_17 (Exercicio 1017)");
        IO_println("18 - Method_18 (Exercicio 1018)");
        IO_println("19 - Method_19 (Exercicio 1019)");
        IO_println("20 - Method_20 (Exercicio 1020) - (Requer MATRIX2.TXT)");
        IO_println("21 - Method_E1 (Exercicio 10E1)");
        IO_println("22 - Method_E2 (Exercicio 10E2)");
        IO_println("");

        x = IO_readint("Entrar com uma opcao: ");

        switch (x)
        {
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
            case 11: method_11(); break;
            case 12: method_12(); break;
            case 13: method_13(); break;
            case 14: method_14(); break;
            case 15: method_15(); break;
            case 16: method_16(); break;
            case 17: method_17(); break;
            case 18: method_18(); break;
            case 19: method_19(); break;
            case 20: method_20(); break;
            case 21: method_E1(); break;
            case 22: method_E2(); break;
            default: IO_println("ERRO: Valor invalido.");
        }
    } while (x != 0);

    IO_pause("Apertar ENTER para terminar");
    return (0);
}