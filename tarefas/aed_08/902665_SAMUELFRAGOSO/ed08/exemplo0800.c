/*
  Exemplo0800.c - v0.0. - 05/10/2025
  Author: Samuel Fragoso
  Matricula: 902665

  Para o Estudo Dirigido 08 - Arranjos
*/

// dependencias
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

// ------------------------------------------- EXEMPLOS (Metodos 01-10)

/**
 * printIntArray - Mostrar arranjo com valores inteiros.
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
 */
void printIntArray(int n, int array[]) {
    int x = 0;
    for (x = 0; x < n; x = x + 1) {
        IO_printf("%2d: %d\n", x, array[x]);
    }
}

/**
 * Method_01 - Mostrar certa quantidade de valores.
 */
void method_01() {
    int array[] = {1, 2, 3, 4, 5};
    IO_id("Method_01 - v0.0");
    printIntArray(5, array);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * readIntArray - Ler arranjo com valores inteiros.
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
 */
void readIntArray(int n, int array[]) {
    int x = 0;
    int y = 0;
    chars text = IO_new_chars(STR_SIZE);
    for (x = 0; x < n; x = x + 1) {
        strcpy(text, STR_EMPTY);
        y = IO_readint(IO_concat(IO_concat(text, IO_toString_d(x)), " : "));
        array[x] = y;
    }
}

/**
 * Method_02 - Ler e mostrar valores.
 */
void method_02() {
    int n = 5;
    int array[n];
    IO_id("Method_02 - v0.0");
    readIntArray(n, array);
    IO_printf("\n");
    printIntArray(n, array);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * fprintIntArray - Gravar arranjo com valores inteiros.
 * @param fileName - nome do arquivo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
 */
void fprintIntArray(chars fileName, int n, int array[]) {
    FILE* arquivo = fopen(fileName, "wt");
    int x = 0;
    IO_fprintf(arquivo, "%d\n", n);
    for (x = 0; x < n; x = x + 1) {
        IO_fprintf(arquivo, "%d\n", array[x]);
    }
    fclose(arquivo);
}

/**
 * Method_03 - Gravar valores em arquivo.
 */
void method_03() {
    int n = 5;
    int array[n];
    IO_id("Method_03 - v0.0");
    readIntArray(n, array);
    fprintIntArray("ARRAY1.TXT", n, array);
    IO_println("\nDados gravados em ARRAY1.TXT");
    IO_pause("Apertar ENTER para continuar");
}

/**
 * freadArraySize - Ler tamanho do arranjo de arquivo.
 * @return quantidade de valores lidos
 * @param fileName - nome do arquivo
 */
int freadArraySize(chars fileName) {
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
 * freadIntArray - Ler arranjo com valores inteiros de arquivo.
 * @param fileName - nome do arquivo
 * @param n - quantidade de valores
 * @param array - grupo de valores inteiros
 */
void freadIntArray(chars fileName, int n, int array[]) {
    int x = 0;
    int y = 0;
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo) {
        IO_fscanf(arquivo, "%d", &x); // ler o tamanho
        if (n <= 0 || n > x) {
            IO_println("ERRO: Valor invalido.");
        } else {
            x = 0;
            while (!feof(arquivo) && x < n) {
                IO_fscanf(arquivo, "%d", &y);
                array[x] = y;
                x = x + 1;
            }
        }
        fclose(arquivo);
    }
}

/**
 * Method_04 - Ler valores de arquivo.
 */
void method_04() {
    int n = 0;
    IO_id("Method_04 - v0.0");
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        int array[n];
        freadIntArray("ARRAY1.TXT", n, array);
        IO_printf("\nDados lidos de ARRAY1.TXT:\n");
        printIntArray(n, array);
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * copyIntArray - Copiar arranjo com valores inteiros.
 * @param n - quantidade de valores
 * @param copy - copia do grupo de valores
 * @param array - grupo de valores original
 */
void copyIntArray(int n, int copy[], int array[]) {
    int x = 0;
    if (n <= 0) {
        IO_println("ERRO: Valor invalido.");
    } else {
        for (x = 0; x < n; x = x + 1) {
            copy[x] = array[x];
        }
    }
}

/**
 * Method_05 - Copiar arranjo.
 */
void method_05() {
    int n = 0;
    IO_id("Method_05 - v0.0");
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        int array[n];
        int other[n];
        freadIntArray("ARRAY1.TXT", n, array);
        copyIntArray(n, other, array);
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        IO_printf("\nCopia\n");
        printIntArray(n, other);
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * sumIntArray - Somar valores em arranjo com inteiros.
 * @return soma dos valores
 * @param n - quantidade de valores
 * @param array - grupo de valores
 */
int sumIntArray(int n, int array[]) {
    int soma = 0;
    int x = 0;
    for (x = 0; x < n; x = x + 1) {
        soma = soma + array[x];
    }
    return (soma);
}

/**
 * Method_06 - Somar valores em arranjo.
 */
void method_06() {
    int n = 0;
    IO_id("Method_06 - v0.0");
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        int array[n];
        freadIntArray("ARRAY1.TXT", n, array);
        IO_printf("\nSoma = %d\n", sumIntArray(n, array));
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * isAllZeros - Testar se arranjo so contem zeros.
 * @return true, se todos forem iguais a zero; false, caso contrario
 * @param n - quantidade de valores
 * @param array - grupo de valores
 */
bool isAllZeros(int n, int array[]) {
    bool result = true;
    int x = 0;
    while (x < n && result) {
        result = result && (array[x] == 0);
        x = x + 1;
    }
    return (result);
}

/**
 * Method_07 - Testar se arranjo e' nulo.
 */
void method_07() {
    int n = 5;
    int array1[] = {0, 0, 0, 0, 0};
    int array2[] = {1, 2, 3, 4, 5};
    int array3[] = {1, 2, 0, 4, 5};
    IO_id("Method_07 - v0.0");
    IO_println("\nArray1");
    printIntArray(n, array1);
    IO_printf("isAllZeros(array1) = %d\n", isAllZeros(n, array1));
    IO_println("\nArray2");
    printIntArray(n, array2);
    IO_printf("isAllZeros(array2) = %d\n", isAllZeros(n, array2));
    IO_println("\nArray3");
    printIntArray(n, array3);
    IO_printf("isAllZeros(array3) = %d\n", isAllZeros(n, array3));
    IO_pause("Apertar ENTER para continuar");
}

/**
 * addIntArray - Somar arranjos com inteiros.
 * @param n - quantidade de valores
 * @param array3 - soma
 * @param array1 - parcela 1
 * @param k - constante para multiplicar a parcela 2
 * @param array2 - parcela 2
 */
void addIntArray(int n, int array3[], int array1[], int k, int array2[]) {
    int x = 0;
    for (x = 0; x < n; x = x + 1) {
        array3[x] = array1[x] + k * array2[x];
    }
}

/**
 * Method_08 - Somar arranjos.
 */
void method_08() {
    int n = 0;
    IO_id("Method_08 - v0.0");
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        int array[n];
        int other[n];
        int sum[n];
        freadIntArray("ARRAY1.TXT", n, array);
        copyIntArray(n, other, array);
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        IO_printf("\nCopia\n");
        printIntArray(n, other);
        addIntArray(n, sum, array, (-2), other);
        IO_printf("\nSoma (original + (-2)*copia)\n");
        printIntArray(n, sum);
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * isEqual - Testar se arranjos com inteiros sao iguais.
 * @return true, se todos os dados forem iguais; false, caso contrario
 * @param n - quantidade de valores
 * @param array1 - grupo de valores (1)
 * @param array2 - grupo de valores (2)
 */
bool isEqual(int n, int array1[], int array2[]) {
    bool result = true;
    int x = 0;
    while (x < n && result) {
        result = result && (array1[x] == array2[x]);
        x = x + 1;
    }
    return (result);
}

/**
 * Method_09 - Testar igualdade de arranjos.
 */
void method_09() {
    int n = 0;
    IO_id("Method_09 - v0.0");
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        int array[n];
        int other[n];
        freadIntArray("ARRAY1.TXT", n, array);
        copyIntArray(n, other, array);
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        IO_printf("\nCopia\n");
        printIntArray(n, other);
        IO_printf("\niguais = %d\n", isEqual(n, array, other));
        other[0] = (-1) * other[0];
        IO_printf("\nCopia alterada\n");
        printIntArray(n, other);
        IO_printf("\niguais = %d\n", isEqual(n, array, other));
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * searchArray - Procurar valor em arranjo com inteiros.
 * @return true, se encontrar; false, caso contrario
 * @param value - valor a ser procurado
 * @param n - quantidade de valores
 * @param array - grupo de valores
 */
bool searchArray(int value, int n, int array[]) {
    bool result = false;
    int x = 0;
    while (x < n && !result) {
        result = (value == array[x]);
        x = x + 1;
    }
    return (result);
}

/**
 * Method_10 - Procurar valor em arranjo.
 */
void method_10() {
    int n = 0;
    int value = 0;
    IO_id("Method_10 - v0.0");
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0) {
        IO_printf("\nERRO: Valor invalido.\n");
    } else {
        int array[n];
        freadIntArray("ARRAY1.TXT", n, array);
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        value = array[0];
        IO_printf("\nProcurar por (%d) = %d\n", value, searchArray(value, n, array));
        value = array[n / 2];
        IO_printf("Procurar por (%d) = %d\n", value, searchArray(value, n, array));
        value = array[n - 1];
        IO_printf("Procurar por (%d) = %d\n", value, searchArray(value, n, array));
        value = -1;
        IO_printf("Procurar por (%d) = %d\n", value, searchArray(value, n, array));
    }
    IO_pause("Apertar ENTER para continuar");
}

// ------------------------------------------- EXERCICIOS (Metodos 11-20 e E1-E2)

/**
 * lerImpares - Ler arranjo com valores positivos e impares.
 * @param n - ponteiro para a quantidade de valores
 * @param array - grupo de valores inteiros
 */
void lerImpares(int* n, int array[]) {
    int i = 0, valor = 0;
    do {
        *n = IO_readint("Digite o tamanho do arranjo: ");
    } while (*n <= 0);

    for (i = 0; i < *n; i++) {
        do {
            valor = IO_readint(IO_concat(IO_toString_d(i), " : "));
        } while (valor <= 0 || valor % 2 == 0);
        array[i] = valor;
    }
}

/**
 * Method_11 (0811) - Ler arranjo com positivos e impares.
 */
void method_11() {
    IO_id("Method_11 - v0.0");
    int n = 0;
    int array[100]; // Supor no maximo 100 elementos
    lerImpares(&n, array);
    IO_printf("\nArranjo com positivos e impares:\n");
    printIntArray(n, array);
    IO_pause("Apertar ENTER para continuar");
}

/**
 * gravarImparesPositivos - Grava apenas numeros impares e positivos de um arranjo em arquivo.
 * @param fileName - nome do arquivo de saida
 * @param n - quantidade de valores no arranjo original
 * @param array - arranjo original
 */
void gravarImparesPositivos(const char* fileName, int n, int array[]) {
    FILE* arquivo = fopen(fileName, "wt");
    int i = 0, count = 0;
    int impares[n]; // arranjo temporario

    for (i = 0; i < n; i++) {
        if (array[i] > 0 && array[i] % 2 != 0) {
            impares[count] = array[i];
            count++;
        }
    }

    IO_fprintf(arquivo, "%d\n", count);
    for (i = 0; i < count; i++) {
        IO_fprintf(arquivo, "%d\n", impares[i]);
    }

    fclose(arquivo);
}

/**
 * Method_12 (0812) - Gravar impares e positivos de um arranjo lido.
 */
void method_12() {
    IO_id("Method_12 - v0.0");
    int n = freadArraySize("DADOS.TXT");
    if (n > 0) {
        int array[n];
        freadIntArray("DADOS.TXT", n, array);
        gravarImparesPositivos("IMPARES_POSITIVOS.TXT", n, array);
        IO_printf("Numeros impares e positivos de DADOS.TXT foram gravados em IMPARES_POSITIVOS.TXT\n");
    } else {
        IO_printf("ERRO: Nao foi possivel ler DADOS.TXT ou o arquivo esta vazio.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * gerarInt - Gera um valor inteiro aleatorio dentro de um intervalo.
 * @param inferior - limite inferior do intervalo
 * @param superior - limite superior do intervalo
 * @return valor aleatorio gerado
 */
int gerarInt(int inferior, int superior) {
    return (rand() % (superior - inferior + 1)) + inferior;
}

/**
 * Method_13 (0813) - Gerar e gravar valores aleatorios.
 */
void method_13() {
    IO_id("Method_13 - v0.0");
    int n = IO_readint("Digite a quantidade de numeros a gerar: ");
    int inferior = IO_readint("Digite o limite inferior do intervalo: ");
    int superior = IO_readint("Digite o limite superior do intervalo: ");
    if (n > 0 && inferior < superior) {
        int array[n];
        for (int i = 0; i < n; i++) {
            array[i] = gerarInt(inferior, superior);
        }
        fprintIntArray("DADOS.TXT", n, array);
        IO_printf("\n%d valores aleatorios gravados em DADOS.TXT\n", n);
    } else {
        IO_printf("ERRO: Parametros invalidos.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * acharMenorImpar - Procura o menor valor impar em um arranjo.
 * @param n - tamanho do arranjo
 * @param array - arranjo de inteiros
 * @return o menor valor impar, ou -1 se nao houver impares
 */
int acharMenorImpar(int n, int array[]) {
    int menor = -1;
    bool primeiro = true;
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 != 0) {
            if (primeiro) {
                menor = array[i];
                primeiro = false;
            } else if (array[i] < menor) {
                menor = array[i];
            }
        }
    }
    return menor;
}

/**
 * Method_14 (0814) - Achar menor valor impar em arquivo.
 */
void method_14() {
    IO_id("Method_14 - v0.0");
    int n = freadArraySize("DADOS.TXT");
    if (n > 0) {
        int array[n];
        freadIntArray("DADOS.TXT", n, array);
        int menor = acharMenorImpar(n, array);
        if (menor != -1) {
            IO_printf("O menor valor impar em DADOS.TXT e': %d\n", menor);
        } else {
            IO_printf("Nao ha valores impares em DADOS.TXT\n");
        }
    } else {
        IO_printf("ERRO: Nao foi possivel ler DADOS.TXT ou o arquivo esta vazio.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * acharMaiorImparDivisivelPorTres - Procura o maior impar, multiplo de 3 e nao de 5.
 * @param n - tamanho do arranjo
 * @param array - arranjo de inteiros
 * @return o maior valor encontrado, ou -1 se nenhum for encontrado
 */
int acharMaiorImparDivisivelPorTres(int n, int array[]) {
    int maior = -1;
    bool primeiro = true;
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 != 0 && array[i] % 3 == 0 && array[i] % 5 != 0) {
            if (primeiro) {
                maior = array[i];
                primeiro = false;
            } else if (array[i] > maior) {
                maior = array[i];
            }
        }
    }
    return maior;
}

/**
 * Method_15 (0815) - Achar maior valor impar especifico.
 */
void method_15() {
    IO_id("Method_15 - v0.0");
    int n = freadArraySize("DADOS.TXT");
    if (n > 0) {
        int array[n];
        freadIntArray("DADOS.TXT", n, array);
        int maior = acharMaiorImparDivisivelPorTres(n, array);
        if (maior != -1) {
            IO_printf("O maior impar, mult de 3 e nao de 5 e': %d\n", maior);
        } else {
            IO_printf("Nenhum valor com as caracteristicas foi encontrado.\n");
        }
    } else {
        IO_printf("ERRO: Nao foi possivel ler DADOS.TXT ou o arquivo esta vazio.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * acharMedia - Determina a media dos valores em um arranjo.
 * @param n - tamanho do arranjo
 * @param array - arranjo de inteiros
 * @return a media dos valores
 */
double acharMedia(int n, int array[]) {
    if (n <= 0) return 0.0;
    return (double)sumIntArray(n, array) / n;
}

/**
 * Method_16 (0816) - Calcular media e separar valores.
 */
void method_16() {
    IO_id("Method_16 - v0.0");
    int n = freadArraySize("DADOS.TXT");
    if (n > 0) {
        int array[n];
        freadIntArray("DADOS.TXT", n, array);
        double media = acharMedia(n, array);
        IO_printf("Media dos valores: %.2lf\n", media);

        int menores[n], maiores[n];
        int countMenores = 0, countMaiores = 0;

        for (int i = 0; i < n; i++) {
            if (array[i] <= media) {
                menores[countMenores++] = array[i];
            } else {
                maiores[countMaiores++] = array[i];
            }
        }
        fprintIntArray("MENORES.TXT", countMenores, menores);
        fprintIntArray("MAIORES.TXT", countMaiores, maiores);

        IO_printf("Valores <= media gravados em MENORES.TXT\n");
        IO_printf("Valores > media gravados em MAIORES.TXT\n");

    } else {
        IO_printf("ERRO: Nao foi possivel ler DADOS.TXT ou o arquivo esta vazio.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * estaOrdenadoDecrescente - Verifica se um arranjo esta ordenado em ordem decrescente.
 * @param n - tamanho do arranjo
 * @param array - arranjo de inteiros
 * @return true se ordenado, false caso contrario
 */
bool estaOrdenadoDecrescente(int n, int array[]) {
    bool ordenado = true;
    int i = 0;
    while (i < n - 1 && ordenado) {
        if (array[i] < array[i + 1]) {
            ordenado = false;
        }
        i++;
    }
    return ordenado;
}

/**
 * Method_17 (0817) - Verificar ordenacao decrescente.
 */
void method_17() {
    IO_id("Method_17 - v0.0");
    int n = freadArraySize("DADOS.TXT");
    if (n > 0) {
        int array[n];
        freadIntArray("DADOS.TXT", n, array);
        bool ordenado = estaOrdenadoDecrescente(n, array);
        IO_printf("O arranjo em DADOS.TXT esta' ordenado de forma decrescente? %s\n", ordenado ? "SIM" : "NAO");
    } else {
        IO_printf("ERRO: Nao foi possivel ler DADOS.TXT ou o arquivo esta vazio.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * acharValor - Procura por um valor a partir de uma posicao.
 * @param procurado - valor a ser procurado
 * @param startPos - posicao inicial da busca
 * @param n - tamanho do arranjo
 * @param array - arranjo
 * @return true se encontrou, false caso contrario
 */
bool acharValor(int procurado, int startPos, int n, int array[]) {
    bool achou = false;
    int i = startPos;
    while (i < n && !achou) {
        if (array[i] == procurado) {
            achou = true;
        }
        i++;
    }
    return achou;
}

/**
 * Method_18 (0818) - Procurar valor a partir de uma posicao.
 */
void method_18() {
    IO_id("Method_18 - v0.0");
    int n = freadArraySize("DADOS.TXT");
    if (n > 0) {
        int array[n];
        freadIntArray("DADOS.TXT", n, array);
        int procurado = IO_readint("Digite o valor a procurar: ");
        int startPos = IO_readint("Digite a posicao inicial da busca: ");
        if (startPos >= 0 && startPos < n) {
            bool achou = acharValor(procurado, startPos, n, array);
            IO_printf("O valor %d foi encontrado a partir da posicao %d? %s\n", procurado, startPos, achou ? "SIM" : "NAO");
        } else {
            IO_printf("ERRO: Posicao inicial invalida.\n");
        }
    } else {
        IO_printf("ERRO: Nao foi possivel ler DADOS.TXT ou o arquivo esta vazio.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * acharPosicao - Procura por um valor e retorna sua primeira posicao.
 * @param procurado - valor a ser procurado
 * @param startPos - posicao inicial da busca
 * @param n - tamanho do arranjo
 * @param array - arranjo
 * @return a posicao do valor, ou -1 se nao encontrado
 */
int acharPosicao(int procurado, int startPos, int n, int array[]) {
    int posicao = -1;
    int i = startPos;
    bool achou = false;
    while (i < n && !achou) {
        if (array[i] == procurado) {
            posicao = i;
            achou = true;
        }
        i++;
    }
    return posicao;
}

/**
 * Method_19 (0819) - Procurar posicao de um valor.
 */
void method_19() {
    IO_id("Method_19 - v0.0");
    int n = freadArraySize("DADOS.TXT");
    if (n > 0) {
        int array[n];
        freadIntArray("DADOS.TXT", n, array);
        int procurado = IO_readint("Digite o valor a procurar: ");
        int startPos = IO_readint("Digite a posicao inicial da busca: ");
        if (startPos >= 0 && startPos < n) {
            int pos = acharPosicao(procurado, startPos, n, array);
            if (pos != -1) {
                IO_printf("O valor %d foi encontrado na posicao %d.\n", procurado, pos);
            } else {
                IO_printf("O valor %d nao foi encontrado.\n", procurado);
            }
        } else {
            IO_printf("ERRO: Posicao inicial invalida.\n");
        }
    } else {
        IO_printf("ERRO: Nao foi possivel ler DADOS.TXT ou o arquivo esta vazio.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * acharQuantos - Conta quantas vezes um valor aparece em um arranjo.
 * @param procurado - valor a ser procurado
 * @param startPos - posicao inicial da busca
 * @param n - tamanho do arranjo
 * @param array - arranjo
 * @return o numero de ocorrencias
 */
int acharQuantos(int procurado, int startPos, int n, int array[]) {
    int count = 0;
    for (int i = startPos; i < n; i++) {
        if (array[i] == procurado) {
            count++;
        }
    }
    return count;
}

/**
 * Method_20 (0820) - Contar ocorrencias de um valor.
 */
void method_20() {
    IO_id("Method_20 - v0.0");
    int n = freadArraySize("DADOS.TXT");
    if (n > 0) {
        int array[n];
        freadIntArray("DADOS.TXT", n, array);
        int procurado = IO_readint("Digite o valor a procurar: ");
        int startPos = IO_readint("Digite a posicao inicial da busca: ");
        if (startPos >= 0 && startPos < n) {
            int vezes = acharQuantos(procurado, startPos, n, array);
            IO_printf("O valor %d aparece %d vez(es) a partir da posicao %d.\n", procurado, vezes, startPos);
        } else {
            IO_printf("ERRO: Posicao inicial invalida.\n");
        }
    } else {
        IO_printf("ERRO: Nao foi possivel ler DADOS.TXT ou o arquivo esta vazio.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * acharDivisoresImpares - Encontra os divisores impares de um numero.
 * @param numero - o numero para encontrar os divisores
 * @param n_divisores - ponteiro para armazenar a quantidade de divisores
 * @return um arranjo contendo os divisores
 */
int* acharDivisoresImpares(int numero, int* n_divisores) {
    int* divisores = (int*)malloc(numero * sizeof(int));
    *n_divisores = 0;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0 && i % 2 != 0) {
            divisores[*n_divisores] = i;
            (*n_divisores)++;
        }
    }
    return divisores;
}

/**
 * Method_E1 (08E1) - Encontrar e gravar divisores impares.
 */
void method_E1() {
    IO_id("Method_E1 - v0.0");
    int numero = IO_readint("Digite um numero inteiro: ");
    if (numero > 0) {
        int n_div = 0;
        int* divisores = acharDivisoresImpares(numero, &n_div);
        IO_printf("\nDivisores impares de %d:\n", numero);
        printIntArray(n_div, divisores);
        fprintIntArray("DIVISORES.TXT", n_div, divisores);
        IO_printf("\nDivisores gravados em DIVISORES.TXT\n");
        free(divisores); // Liberar memoria alocada
    } else {
        IO_printf("ERRO: O numero deve ser positivo.\n");
    }
    IO_pause("Apertar ENTER para continuar");
}

/**
 * Method_E2 (08E2) - Filtrar palavras de um arquivo.
 */
void method_E2() {
    IO_id("Method_E2 - v0.0");
    FILE* arquivo = fopen("PALAVRAS.TXT", "rt");
    if (arquivo == NULL) {
        IO_printf("ERRO: Nao foi possivel abrir o arquivo PALAVRAS.TXT\n");
        return;
    }

    char palavra[STR_SIZE];
    int count = 0;
    IO_printf("10 primeiras palavras que nao comecam ou terminam com 'D' ou 'd':\n");

    while (fscanf(arquivo, "%s", palavra) != EOF && count < 10) {
        int len = strlen(palavra);
        if (len > 0) {
            char primeira = tolower(palavra[0]);
            char ultima = tolower(palavra[len - 1]);
            if (primeira != 'd' && ultima != 'd') {
                IO_printf("%s\n", palavra);
                count++;
            }
        }
    }

    fclose(arquivo);
    IO_pause("Apertar ENTER para continuar");
}

/*
  Funcao principal.
*/
int main() {
    int x = 0;
    srand(time(NULL)); // Seed para gerador de numeros aleatorios

    do {
        IO_println("Exemplo0800 - Programa - v0.0");
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - Method_01 (Exemplo) - Mostrar arranjo");
        IO_println(" 2 - Method_02 (Exemplo) - Ler e mostrar arranjo");
        IO_println(" 3 - Method_03 (Exemplo) - Gravar arranjo em arquivo");
        IO_println(" 4 - Method_04 (Exemplo) - Ler arranjo de arquivo");
        IO_println(" 5 - Method_05 (Exemplo) - Copiar arranjo");
        IO_println(" 6 - Method_06 (Exemplo) - Somar elementos de arranjo");
        IO_println(" 7 - Method_07 (Exemplo) - Verificar se arranjo e' nulo");
        IO_println(" 8 - Method_08 (Exemplo) - Somar arranjos");
        IO_println(" 9 - Method_09 (Exemplo) - Verificar igualdade de arranjos");
        IO_println("10 - Method_10 (Exemplo) - Procurar valor em arranjo");
        IO_println("-------------------------------------------------");
        IO_println("11 - Method_11 (0811) - Ler arranjo de impares positivos");
        IO_println("12 - Method_12 (0812) - Gravar impares positivos de arquivo");
        IO_println("13 - Method_13 (0813) - Gerar valores aleatorios");
        IO_println("14 - Method_14 (0814) - Achar menor impar");
        IO_println("15 - Method_15 (0815) - Achar maior impar (mult 3, nao 5)");
        IO_println("16 - Method_16 (0816) - Calcular media e separar em arquivos");
        IO_println("17 - Method_17 (0817) - Verificar ordenacao decrescente");
        IO_println("18 - Method_18 (0818) - Procurar valor a partir de posicao");
        IO_println("19 - Method_19 (0819) - Achar posicao de valor");
        IO_println("20 - Method_20 (0820) - Contar ocorrencias de valor");
        IO_println("21 - Method_E1 (08E1) - Achar divisores impares");
        IO_println("22 - Method_E2 (08E2) - Filtrar palavras de arquivo");
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
O programa implementa as funcionalidades descritas no Estudo Dirigido 08.
- Os metodos de 1 a 10 sao os exemplos guiados do PDF.
- Os metodos de 11 a 20 correspondem aos exercicios de 0811 a 0820.
- Os metodos E1 e E2 correspondem as tarefas extras.
Para testar as funcoes que dependem de arquivos (como DADOS.TXT),
execute primeiro o Method_13 para gerar o arquivo.


---------------------------------------------- Historico
Versao Data Modificacao
 0.1 05/10 Esboco inicial, transcricao dos exemplos e implementacao dos exercicios 0811-08E2

---------------------------------------------- Testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa, exemplos e exercicios
*/