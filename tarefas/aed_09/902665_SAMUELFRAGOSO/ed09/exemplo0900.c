/*
  Exemplo0900.c - v0.0. - 10/10/2025
  Author: Samuel Fragoso
  Matricula: 902665

  Para o Estudo Dirigido 09 - Matrizes
*/

// dependencias
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// ------------------------------------------- EXEMPLOS (Metodos 01-10)

/**
 * printIntMatrix - Mostrar arranjo bidimensional com valores inteiros.
 * @param rows    - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param matrix  - grupo de valores inteiros
 */
void printIntMatrix(int rows, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;
    for (x = 0; x < rows; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            IO_printf("%3d\t", matrix[x][y]);
        }
        IO_printf("\n");
    }
}

/**
 * Method_01 - Mostrar certa quantidade de valores.
 */
void method_01() {
    int matrix[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    IO_id("Method_01 - v0.0");
    printIntMatrix(3, 3, matrix);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * readIntMatrix - Ler arranjo bidimensional com valores inteiros.
 * @param rows    - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param matrix  - grupo de valores inteiros
 */
void readIntMatrix(int rows, int columns, int matrix[][columns]) {
    int x = 0;
    int y = 0;
    int z = 0;
    chars text = IO_new_chars(STR_SIZE);
    for (x = 0; x < rows; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            strcpy(text, STR_EMPTY);
            z = IO_readint(IO_concat(
                IO_concat(IO_concat(text, IO_toString_d(x)), ","),
                IO_concat(IO_concat(text, IO_toString_d(y)), " : ")));
            matrix[x][y] = z;
        }
    }
}

/**
 * Method_02 - Ler e mostrar matriz.
 */
void method_02() {
    int n = 2;
    int matrix[n][n];
    IO_id("Method_02 - v0.0");
    readIntMatrix(n, n, matrix);
    IO_printf("\n");
    printIntMatrix(n, n, matrix);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 * @param fileName - nome do arquivo
 * @param rows     - quantidade de linhas
 * @param columns  - quantidade de colunas
 * @param matrix   - grupo de valores inteiros
 */
void fprintIntMatrix(chars fileName, int rows, int columns, int matrix[][columns]) {
    FILE* arquivo = fopen(fileName, "wt");
    int x = 0;
    int y = 0;
    IO_fprintf(arquivo, "%d\n", rows);
    IO_fprintf(arquivo, "%d\n", columns);
    for (x = 0; x < rows; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            IO_fprintf(arquivo, "%d\n", matrix[x][y]);
        }
    }
    fclose(arquivo);
}

/**
 * Method_03 - Gravar matriz em arquivo.
 */
void method_03() {
    int rows = 0;
    int columns = 0;
    IO_id("Method_03 - v0.0");
    rows = IO_readint("\nRows = ");
    columns = IO_readint("Columns = ");
    if (rows <= 0 || columns <= 0) {
        IO_println("\nERRO: Valor invalido.");
    } else {
        int matrix[rows][columns];
        readIntMatrix(rows, columns, matrix);
        IO_printf("\n");
        fprintIntMatrix("MATRIX1.TXT", rows, columns, matrix);
        IO_println("Dados gravados em MATRIX1.TXT");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * freadMatrixRows - Ler tamanho (linhas) da matriz de arquivo.
 * @return quantidade de linhas
 * @param fileName - nome do arquivo
 */
int freadMatrixRows(chars fileName) {
    int n = 0;
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo) {
        IO_fscanf(arquivo, "%d", &n);
        fclose(arquivo);
    }
    if (n <= 0) {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }
    return (n);
}

/**
 * freadMatrixColumns - Ler tamanho (colunas) da matriz de arquivo.
 * @return quantidade de colunas
 * @param fileName - nome do arquivo
 */
int freadMatrixColumns(chars fileName) {
    int n = 0;
    int x = 0;
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo) {
        IO_fscanf(arquivo, "%d", &x); // ler linhas
        IO_fscanf(arquivo, "%d", &n); // ler colunas
        fclose(arquivo);
    }
    if (n <= 0) {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }
    return (n);
}

/**
 * freadIntMatrix - Ler arranjo bidimensional com valores inteiros de arquivo.
 * @param fileName - nome do arquivo
 * @param rows     - quantidade de linhas
 * @param columns  - quantidade de colunas
 * @param matrix   - grupo de valores inteiros
 */
void freadIntMatrix(chars fileName, int rows, int columns, int matrix[][columns]) {
    int x = 0, y = 0, z = 0;
    int file_rows = 0, file_cols = 0;
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo) {
        IO_fscanf(arquivo, "%d", &file_rows);
        IO_fscanf(arquivo, "%d", &file_cols);
        if (rows <= 0 || rows > file_rows || columns <= 0 || columns > file_cols) {
            IO_println("ERRO: Dimensoes invalidas.");
        } else {
            x = 0;
            while (!feof(arquivo) && x < rows) {
                y = 0;
                while (!feof(arquivo) && y < columns) {
                    IO_fscanf(arquivo, "%d", &z);
                    matrix[x][y] = z;
                    y = y + 1;
                }
                x = x + 1;
            }
        }
        fclose(arquivo);
    }
}

/**
 * Method_04 - Ler matriz de arquivo.
 */
void method_04() {
    IO_id("Method_04 - v0.0");
    int rows = freadMatrixRows("MATRIX1.TXT");
    int columns = freadMatrixColumns("MATRIX1.TXT");

    if (rows <= 0 || columns <= 0) {
        IO_printf("\nERRO: Dimensoes invalidas.\n");
    } else {
        int matrix[rows][columns];
        freadIntMatrix("MATRIX1.TXT", rows, columns, matrix);
        IO_printf("\nDados lidos de MATRIX1.TXT:\n");
        printIntMatrix(rows, columns, matrix);
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * copyIntMatrix - Copiar matriz com valores inteiros.
 * @param rows    - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param copy    - copia da matriz
 * @param matrix  - matriz original
 */
void copyIntMatrix(int rows, int columns, int copy[][columns], int matrix[][columns]) {
    int x = 0, y = 0;
    if (rows <= 0 || columns <= 0) {
        IO_println("ERRO: Valor invalido.");
    } else {
        for (x = 0; x < rows; x = x + 1) {
            for (y = 0; y < columns; y = y + 1) {
                copy[x][y] = matrix[x][y];
            }
        }
    }
}

/**
 * Method_05 - Copiar matriz.
 */
void method_05() {
    IO_id("Method_05 - v0.0");
    int rows = freadMatrixRows("MATRIX1.TXT");
    int columns = freadMatrixColumns("MATRIX1.TXT");

    if (rows <= 0 || columns <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        int matrix[rows][columns];
        int other[rows][columns];
        freadIntMatrix("MATRIX1.TXT", rows, columns, matrix);
        copyIntMatrix(rows, columns, other, matrix);
        IO_printf("\nOriginal\n");
        printIntMatrix(rows, columns, matrix);
        IO_printf("\nCopia\n");
        printIntMatrix(rows, columns, other);
    }
    IO_pause("Apertar ENTER para continuar");
}


/**
 * transposeIntMatrix - Transpor valores inteiros em matriz.
 * @param rows    - quantidade de linhas da original
 * @param columns - quantidade de colunas da original
 * @param transposed - matriz transposta (destino)
 * @param matrix  - matriz original
 */
void transposeIntMatrix(int rows, int columns, int transposed[][rows], int matrix[][columns]) {
    int x = 0, y = 0;
    for (x = 0; x < rows; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            transposed[y][x] = matrix[x][y];
        }
    }
}


/**
 * Method_06 - Transpor matriz.
 */
void method_06() {
    IO_id("Method_06 - v0.0");
    int matrix1[][2] = {{1, 2}, {3, 4}, {5, 6}}; // 3x2
    int transposed[2][3]; // 2x3

    IO_printf("\nMatriz Original (3x2):\n");
    printIntMatrix(3, 2, matrix1);

    transposeIntMatrix(3, 2, transposed, matrix1);

    IO_printf("\nMatriz Transposta (2x3):\n");
    printIntMatrix(2, 3, transposed);

    IO_pause("Apertar ENTER para continuar");
}


/**
 * isIdentity - Testar se matriz e' identidade.
 * @return      - true, se for; false, caso contrario
 * @param rows    - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param matrix  - matriz
 */
bool isIdentity(int rows, int columns, int matrix[][columns]) {
    bool result = true;
    int x = 0, y = 0;

    if (rows <= 0 || columns <= 0 || rows != columns) {
        return false; // Nao e' quadrada, nao pode ser identidade
    }

    x = 0;
    while (x < rows && result) {
        y = 0;
        while (y < columns && result) {
            if (x == y) {
                result = result && (matrix[x][y] == 1);
            } else {
                result = result && (matrix[x][y] == 0);
            }
            y = y + 1;
        }
        x = x + 1;
    }
    return result;
}

/**
 * Method_07 - Testar se matriz e' identidade.
 */
void method_07() {
    int matrix1[][2] = {{1, 0}, {0, 1}};
    int matrix2[][2] = {{1, 2}, {0, 1}};
    int matrix3[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    IO_id("Method_07 - v0.0");

    IO_println("\nMatrix1:");
    printIntMatrix(2, 2, matrix1);
    IO_printf("isIdentity(matrix1) = %d\n", isIdentity(2, 2, matrix1));

    IO_println("\nMatrix2:");
    printIntMatrix(2, 2, matrix2);
    IO_printf("isIdentity(matrix2) = %d\n", isIdentity(2, 2, matrix2));

    IO_println("\nMatrix3:");
    printIntMatrix(3, 3, matrix3);
    IO_printf("isIdentity(matrix3) = %d\n", isIdentity(3, 3, matrix3));

    IO_pause("Apertar ENTER para continuar");
}


/**
 * isEqual - Testar se matrizes sao iguais.
 * @return      - true, se forem; false, caso contrario
 * @param rows    - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param matrix1 - primeira matriz
 * @param matrix2 - segunda matriz
 */
bool isEqual(int rows, int columns, int matrix1[][columns], int matrix2[][columns]) {
    bool result = true;
    int x = 0, y = 0;
    while (x < rows && result) {
        y = 0;
        while (y < columns && result) {
            result = result && (matrix1[x][y] == matrix2[x][y]);
            y = y + 1;
        }
        x = x + 1;
    }
    return result;
}

/**
 * Method_08 - Testar igualdade de matrizes.
 */
void method_08() {
    int matrix1[][2] = {{1, 2}, {3, 4}};
    int matrix2[][2] = {{1, 2}, {3, 4}};
    int matrix3[][2] = {{5, 6}, {7, 8}};

    IO_id("Method_08 - v0.0");

    IO_println("\nMatrix1:");
    printIntMatrix(2, 2, matrix1);
    IO_println("\nMatrix2:");
    printIntMatrix(2, 2, matrix2);
    IO_printf("isEqual(matrix1, matrix2) = %d\n", isEqual(2, 2, matrix1, matrix2));

    IO_println("\nMatrix3:");
    printIntMatrix(2, 2, matrix3);
    IO_printf("isEqual(matrix1, matrix3) = %d\n", isEqual(2, 2, matrix1, matrix3));

    IO_pause("Apertar ENTER para continuar");
}

/**
 * addIntMatrix - Somar matrizes com inteiros.
 * @param rows    - quantidade de linhas
 * @param columns - quantidade de colunas
 * @param result  - matriz resultante
 * @param matrix1 - primeira parcela
 * @param k       - constante para multiplicar a segunda parcela
 * @param matrix2 - segunda parcela
 */
void addIntMatrix(int rows, int columns, int result[][columns], int matrix1[][columns], int k, int matrix2[][columns]) {
    int x = 0, y = 0;
    for (x = 0; x < rows; x = x + 1) {
        for (y = 0; y < columns; y = y + 1) {
            result[x][y] = matrix1[x][y] + k * matrix2[x][y];
        }
    }
}

/**
 * Method_09 - Somar matrizes.
 */
void method_09() {
    int matrix1[][2] = {{1, 2}, {3, 4}};
    int matrix2[][2] = {{5, 6}, {7, 8}};
    int sum[2][2];

    IO_id("Method_09 - v0.0");

    IO_println("\nMatrix1:");
    printIntMatrix(2, 2, matrix1);
    IO_println("\nMatrix2:");
    printIntMatrix(2, 2, matrix2);

    addIntMatrix(2, 2, sum, matrix1, 2, matrix2);

    IO_println("\nSoma (matrix1 + 2 * matrix2):");
    printIntMatrix(2, 2, sum);

    IO_pause("Apertar ENTER para continuar");
}


/**
 * mulIntMatrix - Multiplicar matrizes com inteiros.
 * @param rows1    - linhas da primeira matriz
 * @param columns1 - colunas da primeira matriz
 * @param matrix1  - primeira matriz
 * @param rows2    - linhas da segunda matriz
 * @param columns2 - colunas da segunda matriz
 * @param matrix2  - segunda matriz
 * @param result   - matriz resultante
 */
void mulIntMatrix(int rows1, int columns1, int matrix1[][columns1], int rows2, int columns2, int matrix2[][columns2], int result[][columns2]) {
    int x = 0, y = 0, z = 0;
    int soma = 0;

    if (columns1 != rows2) {
        IO_printf("\nERRO: Dimensoes incompativeis para multiplicacao.\n");
    } else {
        for (x = 0; x < rows1; x = x + 1) {
            for (y = 0; y < columns2; y = y + 1) {
                soma = 0;
                for (z = 0; z < columns1; z = z + 1) {
                    soma = soma + matrix1[x][z] * matrix2[z][y];
                }
                result[x][y] = soma;
            }
        }
    }
}

/**
 * Method_10 - Multiplicar matrizes.
 */
void method_10() {
    int matrix1[][2] = {{1, 2}, {3, 4}}; // 2x2
    int matrix2[][3] = {{5, 6, 7}, {8, 9, 10}}; // 2x3
    int product[2][3]; // 2x3

    IO_id("Method_10 - v0.0");

    IO_println("\nMatrix1 (2x2):");
    printIntMatrix(2, 2, matrix1);

    IO_println("\nMatrix2 (2x3):");
    printIntMatrix(2, 3, matrix2);

    mulIntMatrix(2, 2, matrix1, 2, 3, matrix2, product);

    IO_println("\nProduto (Matrix1 * Matrix2):");
    printIntMatrix(2, 3, product);

    IO_pause("Apertar ENTER para continuar");
}


// ------------------------------------------- EXERCICIOS (Metodos 11-20 e E1-E2)

// Funcoes auxiliares para matrizes de double
#define MAX_SIZE 10

/**
 * printDoubleMatrix - Mostrar arranjo bidimensional com valores reais.
 */
void printDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            IO_printf("%.2lf\t", matrix[x][y]);
        }
        IO_printf("\n");
    }
}

/**
 * readPositiveDoubleMatrix - Ler matriz com valores reais positivos.
 */
void readPositiveDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    double z = 0.0;
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < columns; y++) {
            do {
                z = IO_readdouble(IO_concat_i_s_i_s(x, ",", y, " : "));
            } while (z < 0);
            matrix[x][y] = z;
        }
    }
}

/**
 * fprintDoubleMatrix - Gravar matriz com valores reais em arquivo.
 */
void fprintDoubleMatrix(const char* fileName, int rows, int columns, double matrix[][columns]) {
    FILE* arquivo = fopen(fileName, "wt");
    if (arquivo) {
        IO_fprintf(arquivo, "%d\n", rows);
        IO_fprintf(arquivo, "%d\n", columns);
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < columns; y++) {
                IO_fprintf(arquivo, "%lf\n", matrix[x][y]);
            }
        }
        fclose(arquivo);
    }
}

/**
 * freadDoubleMatrix - Ler matriz com valores reais de arquivo.
 */
void freadDoubleMatrix(const char* fileName, int rows, int columns, double matrix[][columns]) {
    int file_rows = 0, file_cols = 0;
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo) {
        fscanf(arquivo, "%d", &file_rows);
        fscanf(arquivo, "%d", &file_cols);
        if (rows <= file_rows && columns <= file_cols) {
            for (int x = 0; x < rows; x++) {
                for (int y = 0; y < columns; y++) {
                    fscanf(arquivo, "%lf", &matrix[x][y]);
                }
            }
        }
        fclose(arquivo);
    }
}

/**
 * Method_11 (0911) - Ler e mostrar matriz com reais positivos.
 */
void method_11() {
    IO_id("Method_11 - v0.0");
    int rows = 0, columns = 0;

    do {
        rows = IO_readint("Digite o numero de linhas (1-10): ");
    } while (rows <= 0 || rows > MAX_SIZE);
    do {
        columns = IO_readint("Digite o numero de colunas (1-10): ");
    } while (columns <= 0 || columns > MAX_SIZE);

    double matrix[rows][columns];
    IO_println("Digite os elementos da matriz (positivos ou zero):");
    readPositiveDoubleMatrix(rows, columns, matrix);

    IO_println("\nMatriz lida:");
    printDoubleMatrix(rows, columns, matrix);
    IO_pause("Apertar ENTER para continuar");
}


/**
 * Method_12 (0912) - Gravar e ler matriz de reais de arquivo.
 */
void method_12() {
    IO_id("Method_12 - v0.0");
    int rows = 3, columns = 3;
    double matrix[rows][columns];
    const char* fileName = "MATRIX_01.TXT";

    IO_println("Digite os elementos da matriz 3x3 (positivos ou zero):");
    readPositiveDoubleMatrix(rows, columns, matrix);

    fprintDoubleMatrix(fileName, rows, columns, matrix);
    IO_printf("\nMatriz gravada em %s\n", fileName);

    double matrix_read[rows][columns];
    freadDoubleMatrix(fileName, rows, columns, matrix_read);

    IO_println("\nMatriz lida do arquivo:");
    printDoubleMatrix(rows, columns, matrix_read);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * printDiagonalDoubleMatrix - Mostrar diagonal principal.
 */
void printDiagonalDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    if (rows != columns) {
        IO_println("ERRO: A matriz nao e' quadrada.");
    } else {
        IO_println("\nDiagonal Principal:");
        for (int i = 0; i < rows; i++) {
            IO_printf("%.2lf\t", matrix[i][i]);
        }
        IO_printf("\n");
    }
}

/**
 * Method_13 (0913) - Mostrar diagonal principal.
 */
void method_13() {
    IO_id("Method_13 - v0.0");
    double matrix[][3] = {{1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}, {3.1, 3.2, 3.3}};
    IO_println("Matriz de teste:");
    printDoubleMatrix(3, 3, matrix);
    printDiagonalDoubleMatrix(3, 3, matrix);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * printSDiagonalDoubleMatrix - Mostrar diagonal secundaria.
 */
void printSDiagonalDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    if (rows != columns) {
        IO_println("ERRO: A matriz nao e' quadrada.");
    } else {
        IO_println("\nDiagonal Secundaria:");
        for (int i = 0; i < rows; i++) {
            IO_printf("%.2lf\t", matrix[i][rows - 1 - i]);
        }
        IO_printf("\n");
    }
}

/**
 * Method_14 (0914) - Mostrar diagonal secundaria.
 */
void method_14() {
    IO_id("Method_14 - v0.0");
    double matrix[][3] = {{1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}, {3.1, 3.2, 3.3}};
    IO_println("Matriz de teste:");
    printDoubleMatrix(3, 3, matrix);
    printSDiagonalDoubleMatrix(3, 3, matrix);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * printLDTriangleDoubleMatrix - Mostrar triangulo inferior.
 */
void printLDTriangleDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    if (rows != columns) {
        IO_println("ERRO: A matriz nao e' quadrada.");
    } else {
        IO_println("\nValores abaixo da diagonal principal:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (j < i) {
                    IO_printf("%.2lf\t", matrix[i][j]);
                } else {
                    IO_printf(" \t");
                }
            }
            IO_printf("\n");
        }
    }
}

/**
 * Method_15 (0915) - Mostrar valores abaixo da diagonal principal.
 */
void method_15() {
    IO_id("Method_15 - v0.0");
    double matrix[][3] = {{1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}, {3.1, 3.2, 3.3}};
    IO_println("Matriz de teste:");
    printDoubleMatrix(3, 3, matrix);
    printLDTriangleDoubleMatrix(3, 3, matrix);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * printLUTriangleDoubleMatrix - Mostrar triangulo superior.
 */
void printLUTriangleDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    if (rows != columns) {
        IO_println("ERRO: A matriz nao e' quadrada.");
    } else {
        IO_println("\nValores acima da diagonal principal:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (j > i) {
                    IO_printf("%.2lf\t", matrix[i][j]);
                } else {
                    IO_printf(" \t");
                }
            }
            IO_printf("\n");
        }
    }
}

/**
 * Method_16 (0916) - Mostrar valores acima da diagonal principal.
 */
void method_16() {
    IO_id("Method_16 - v0.0");
    double matrix[][3] = {{1.1, 1.2, 1.3}, {2.1, 2.2, 2.3}, {3.1, 3.2, 3.3}};
    IO_println("Matriz de teste:");
    printDoubleMatrix(3, 3, matrix);
    printLUTriangleDoubleMatrix(3, 3, matrix);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * printSLDTriangleDoubleMatrix - Mostrar triangulo inferior secundario.
 */
void printSLDTriangleDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    if (rows != columns) {
        IO_println("ERRO: A matriz nao e' quadrada.");
    } else {
        IO_println("\nValores abaixo e na diagonal secundaria:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (j >= rows - 1 - i) {
                    IO_printf("%.2lf\t", matrix[i][j]);
                } else {
                    IO_printf(" \t");
                }
            }
            IO_printf("\n");
        }
    }
}

/**
 * Method_17 (0917) - Mostrar valores abaixo e na diagonal secundaria.
 */
void method_17() {
    IO_id("Method_17 - v0.0");
    double matrix[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    IO_println("Matriz de teste:");
    printDoubleMatrix(4, 4, matrix);
    printSLDTriangleDoubleMatrix(4, 4, matrix);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * printSLUTriangleDoubleMatrix - Mostrar triangulo superior secundario.
 */
void printSLUTriangleDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    if (rows != columns) {
        IO_println("ERRO: A matriz nao e' quadrada.");
    } else {
        IO_println("\nValores acima e na diagonal secundaria:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (j <= rows - 1 - i) {
                    IO_printf("%.2lf\t", matrix[i][j]);
                } else {
                    IO_printf(" \t");
                }
            }
            IO_printf("\n");
        }
    }
}

/**
 * Method_18 (0918) - Mostrar valores acima e na diagonal secundaria.
 */
void method_18() {
    IO_id("Method_18 - v0.0");
    double matrix[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    IO_println("Matriz de teste:");
    printDoubleMatrix(4, 4, matrix);
    printSLUTriangleDoubleMatrix(4, 4, matrix);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * allZerosLTriangleDoubleMatrix - Verifica se triangulo inferior e' nulo.
 */
bool allZerosLTriangleDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    if (rows != columns) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0.0) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Method_19 (0919) - Verificar se triangulo inferior e' nulo.
 */
void method_19() {
    IO_id("Method_19 - v0.0");
    double matrix1[][3] = {{1, 2, 3}, {0, 5, 6}, {0, 0, 9}};
    double matrix2[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    IO_println("Matrix1:");
    printDoubleMatrix(3, 3, matrix1);
    IO_printf("Triangulo inferior nulo? %s\n", allZerosLTriangleDoubleMatrix(3, 3, matrix1) ? "SIM" : "NAO");

    IO_println("\nMatrix2:");
    printDoubleMatrix(3, 3, matrix2);
    IO_printf("Triangulo inferior nulo? %s\n", allZerosLTriangleDoubleMatrix(3, 3, matrix2) ? "SIM" : "NAO");

    IO_pause("Apertar ENTER para continuar");
}

/**
 * allNonZerosUTriangleDoubleMatrix - Verifica se triangulo superior nao contem zeros.
 */
bool allNonZerosUTriangleDoubleMatrix(int rows, int columns, double matrix[][columns]) {
    if (rows != columns) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < columns; j++) {
            if (matrix[i][j] == 0.0) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Method_20 (0920) - Verificar se triangulo superior nao tem zeros.
 */
void method_20() {
    IO_id("Method_20 - v0.0");
    double matrix1[][3] = {{1, 2, 3}, {0, 5, 6}, {0, 0, 9}};
    double matrix2[][3] = {{1, 2, 0}, {4, 5, 6}, {7, 8, 9}};

    IO_println("Matrix1:");
    printDoubleMatrix(3, 3, matrix1);
    IO_printf("Triangulo superior sem zeros? %s\n", allNonZerosUTriangleDoubleMatrix(3, 3, matrix1) ? "SIM" : "NAO");

    IO_println("\nMatrix2:");
    printDoubleMatrix(3, 3, matrix2);
    IO_printf("Triangulo superior sem zeros? %s\n", allNonZerosUTriangleDoubleMatrix(3, 3, matrix2) ? "SIM" : "NAO");

    IO_pause("Apertar ENTER para continuar");
}

/**
 * Method_E1 (09E1) - Gerar e gravar matriz com padrao 1.
 */
void method_E1() {
    IO_id("Method_E1 - v0.0");
    int rows = IO_readint("Digite o numero de linhas: ");
    int columns = IO_readint("Digite o numero de colunas: ");

    if (rows > 0 && columns > 0) {
        int matrix[rows][columns];
        int k = 1;
        for (int j = 0; j < columns; j++) {
            for (int i = 0; i < rows; i++) {
                matrix[i][j] = k++;
            }
        }

        IO_println("\nMatriz Gerada (E1):");
        printIntMatrix(rows, columns, matrix);
        fprintIntMatrix("MATRIX_E1.TXT", rows, columns, matrix);
        IO_println("\nMatriz gravada em MATRIX_E1.TXT");
    } else {
        IO_println("ERRO: Dimensoes invalidas.");
    }
    IO_pause("Apertar ENTER para continuar");
}


/**
 * Method_E2 (09E2) - Gerar e gravar matriz com padrao 2.
 */
void method_E2() {
    IO_id("Method_E2 - v0.0");
    int rows = IO_readint("Digite o numero de linhas: ");
    int columns = IO_readint("Digite o numero de colunas: ");

    if (rows > 0 && columns > 0) {
        int matrix[rows][columns];
        int k = 1;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = columns - 1; j >= 0; j--) {
                matrix[i][j] = k++;
            }
        }

        IO_println("\nMatriz Gerada (E2):");
        printIntMatrix(rows, columns, matrix);
        fprintIntMatrix("MATRIX_E2.TXT", rows, columns, matrix);
        IO_println("\nMatriz gravada em MATRIX_E2.TXT");
    } else {
        IO_println("ERRO: Dimensoes invalidas.");
    }
    IO_pause("Apertar ENTER para continuar");
}

/*
  Funcao principal.
*/
int main() {
    int x = 0;

    do {
        IO_println("Exemplo0900 - Programa - v0.0");
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - Method_01 (Exemplo) - Mostrar matriz estatica");
        IO_println(" 2 - Method_02 (Exemplo) - Ler e mostrar matriz");
        IO_println(" 3 - Method_03 (Exemplo) - Gravar matriz em arquivo");
        IO_println(" 4 - Method_04 (Exemplo) - Ler matriz de arquivo");
        IO_println(" 5 - Method_05 (Exemplo) - Copiar matriz");
        IO_println(" 6 - Method_06 (Exemplo) - Transpor matriz");
        IO_println(" 7 - Method_07 (Exemplo) - Verificar se e' matriz identidade");
        IO_println(" 8 - Method_08 (Exemplo) - Verificar igualdade de matrizes");
        IO_println(" 9 - Method_09 (Exemplo) - Somar matrizes");
        IO_println("10 - Method_10 (Exemplo) - Multiplicar matrizes");
        IO_println("-------------------------------------------------");
        IO_println("11 - Method_11 (0911) - Ler matriz de reais positivos");
        IO_println("12 - Method_12 (0912) - Gravar matriz de reais em arquivo");
        IO_println("13 - Method_13 (0913) - Mostrar diagonal principal");
        IO_println("14 - Method_14 (0914) - Mostrar diagonal secundaria");
        IO_println("15 - Method_15 (0915) - Mostrar triangulo inferior principal");
        IO_println("16 - Method_16 (0916) - Mostrar triangulo superior principal");
        IO_println("17 - Method_17 (0917) - Mostrar triangulo inferior secundario");
        IO_println("18 - Method_18 (0918) - Mostrar triangulo superior secundario");
        IO_println("19 - Method_19 (0919) - Testar se triangulo inferior e' nulo");
        IO_println("20 - Method_20 (0920) - Testar se triangulo superior nao tem zeros");
        IO_println("21 - Method_E1 (09E1) - Gerar matriz com padrao 1");
        IO_println("22 - Method_E2 (09E2) - Gerar matriz com padrao 2");
        IO_println("");

        x = IO_readint("Entrar com uma opcao: ");

        switch (x) {
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

/*
---------------------------------------------- Documentacao complementar
O programa implementa as funcionalidades descritas no Estudo Dirigido 09.
- Os metodos de 1 a 10 sao os exemplos guiados do PDF.
- Os metodos de 11 a 20 correspondem aos exercicios de 0911 a 0920.
- Os metodos E1 e E2 correspondem as tarefas extras.
Para testar as funcoes que dependem de arquivos (como MATRIX1.TXT),
execute primeiro o Method_03 para gerar o arquivo de inteiros.
Para os exercicios que usam double, o Method_12 gera o arquivo necessario.

---------------------------------------------- Historico
Versao Data Modificacao
 0.1 10/10 Esboco inicial, transcricao dos exemplos e implementacao dos exercicios 0911-09E2

---------------------------------------------- Testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa, exemplos e exercicios
*/