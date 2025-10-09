/*
  Exemplo0700.c - v0.0. - 27/09/2025
  Author: Samuel Fragoso
  Matricula: 902665

  Para o Estudo Dirigido 06 - Recursividade
*/
#include "io.h"     // para definicoes proprias
#include <stdio.h>
#include <math.h> 

// ------------------------------------------- EXEMPLOS
/**
  writelints - Gravar em arquivo texto certa quantidade de valores
  @param fileName - nome do arquivo
  @param x - quantidade de valores a serem gravados
 */
void writelints ( chars fileName, int x )
{
  // definir dados
  FILE* arquivo = fopen (fileName, "wt");
  int y = 0;

  //repetir para cada quantidade de dados
  for ( y = 1; y <= x; y = y + 1)
  {
    //gravar valor
    fprintf ( arquivo, "%d\n", y );
  }
  // fechar arquivo
  fclose ( arquivo );
}
/**
 * Method_01 - Mostrar certa quantidade de valores
 */
void method_01()
{
  //identificar
  IO_id ("Method_01 - v0.0");
  writelints ("DADOS1.TXT", 10);

  //encerrar
  IO_pause ("Apertar ENTER para continuar");
}

/**
  readints - Ler de arquivo texto certa quantidade de valores
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void readints ( chars fileName)
{
  // definir dados 
  FILE* arquivo = fopen (fileName, "rt");
  int x = 0;
  //ler o primeiro
  fscanf  (arquivo, "%d", &x);
  //repetir enquanto houver dados
  while (! feof (arquivo))
  {
    //mostrar valor 
    printf ("%d\n", x);
    //ler o proximo
    fscanf (arquivo, "%d", &x);
  }
  //fechar arquivo
  fclose (arquivo);
}
/**
 * Method_02 - Mostrar certa quantidade de valores
 */
void method_02()
{
  //identificar
  IO_id ("Method_02 - v0.0");
  readints ("DADOS1.TXT");
  
  //encerrar
  IO_pause ("Apertar ENTER para continuar");
}     
/**
  writeDoubles - Gravar em arquivo texto certa quantidade de valores
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void writeDoubles (chars fileName, int x)
{
  // definir dados
  FILE* arquivo = fopen (fileName, "wt");
  int y = 0;
  //gravar quantidade de valores
    IO_fprintf (arquivo, "%d\n", x);
  for (y = 1; y <= x; y = y + 1)
  {
    //gravar valor
    IO_fprintf (arquivo, "%lf\n", (0.1 * y));
  }
  // fechar arquivo
  fclose (arquivo);
}
/**
 * Method_03 - Mostrar certa quantidade de valores
 */
void method_03()
{
  //identificar
  IO_id ("Method_03 - v0.0");
  writeDoubles ("DADOS2.TXT", 10);

  //encerrar
  IO_pause ("Apertar ENTER para continuar");
}
/**
 readDoubles - Ler de arquivo texto certa quantidade de valores
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void readDoubles ( chars fileName)
{
  // definir dados
  FILE* arquivo = fopen (fileName, "rt");
  int x = 0;
  int y = 1;
  double z = 0.0;

  //ler a quantidade de valores
  fscanf  (arquivo, "%d", &x);
  //repetir enquanto houver dados
  while (! feof (arquivo) && y <= x)
  {
    //tentar ler
    fscanf (arquivo, "%lf", &z);
    //mostrar valor
    printf ("%2d: %lf\n", y, z);
    y = y + 1;
  }
  //fechar arquivo
  fclose (arquivo);
}
/**
 * Method_04 - Mostrar certa quantidade de valores
 */
void method_04()
{
  //identificar
  IO_id ("Method_04 - v0.0");
  readDoubles ("DADOS2.TXT");
  //encerrar
  IO_pause ("Apertar ENTER para continuar");  
}
/**
 writeText - Gravar em arquivo texto certa quantidade de valores
  @param fileName - nome do arquivo
  @param x - quantidade de valores
 */
void writeText ( chars fileName)
{
  // definir dados
  FILE* arquivo = fopen (fileName, "wt");
  chars linha = IO_new_chars (STR_SIZE);
  //repetir ate decidir parar
  IO_println ("Gravar linhas (PARAR p/ parar):\n");
  do 
  {
    //ler do teclado
    strcpy (linha, IO_readln (""));
    //gravar valor
    IO_fprintf (arquivo, "%s\n", linha);
  }
  while (strcmp ("PARAR", linha) != 0);
  //fechar arquivo
  fclose (arquivo);

}
/**
 * Method_05 - Mostrar certa quantidade de valores
 */
void method_05()
{
  //indentificar
  IO_id ("Method_05 - v0.0");
  writeText ("DADOS3.TXT");
  //encerrar
  IO_pause ("Apertar ENTER para continuar");
}
/**
  readText - Ler de arquivo texto certa quantidade de valores
  @param fileName - nome do arquivo
 */
void readText ( chars fileName)
{
  // definir dados
  FILE* arquivo = fopen (fileName, "rt");
  chars linha = IO_new_chars (STR_SIZE);
  //ler o primeiro
  strcpy (linha, IO_freadln (arquivo));
  //repetir enquanto houver dados
  while (! feof (arquivo) && (strcmp ("PARAR", linha) != 0))
  {
    //mostrar valor
    printf ("%s\n", linha);
    //ler o proximo
    strcpy (linha, IO_freadln (arquivo));
  }
  //fechar arquivo
  fclose (arquivo);
}
/**
 * Method_06 - Mostrar certa quantidade de valores
 */
void method_06()
{
  //indentificar
  IO_id ("Method_06 - v0.0");
  readText ("DADOS3.TXT");
  //encerrar
  IO_pause ("Apertar ENTER para continuar");
}
/**
  copyText - Copiar arquivo de texto
  @param fileOut - nome do arquivo de saida (destino)
  @param fileIn - nome do arquivo de entrada (origem)
 */
void copyText ( chars fileOut, chars fileIn)
{ 
  // definir dados
  FILE* saida = fopen (fileOut, "wt");
  FILE* entrada = fopen (fileIn, "rt");
  chars linha = IO_new_chars (STR_SIZE);
  int contador = 0;
  //ler da origem
  strcpy (linha, IO_freadln (entrada));
  //repetir enquanto houver dados
  while (! feof (entrada));
  {
    //contar linhas
    contador = contador + 1;
    // gravar no destino
    if (strcmp ("PARAR", linha) != 0)
    {
      IO_fprintf (saida, linha);
    }
    //ler da origem
    strcpy (linha, IO_freadln (entrada));
  }
  //informar quantidade de linhas copiadas
  IO_printf ("\n%d linhas copiadas\n", contador);
  //fechar arquivos
  fclose (saida);
  fclose (entrada);
}
/**
  Method_07 - Teste da funcao copyText.
 */
void method_07 ( )
{
  //identificar
  IO_id ( "Method_07 - v0.0" );
  copyText ( "DADOS4.TXT", "DADOS3.TXT" );
  //encerrar
  IO_pause ( "Apertar ENTER para continuar" );
}
/**
 appendText - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void appendText ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "at" );
 chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
 IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
 do
 {
 // ler do teclado
 strcpy ( linha, IO_readln ( "" ) );
 // gravar valor
 IO_fprintln ( arquivo, linha );
 }
 while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end appendText ( )
/**
 Method_08.
*/
void method_08 ( )
{
// identificar
 IO_id ( "EXEMPLO0710 - Method_08 - v0.0" );
// executar o metodo auxiliar
 appendText ( "DADOS4.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
/**
 readWords - Ler palavras de arquivo.
 @param fileName - nome do arquivo
*/
void readWords ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 chars linha = IO_new_chars ( STR_SIZE );
// tentar ler a primeira
 strcpy ( linha, IO_fread ( arquivo ) );
// repetir enquanto houver dados
 while ( ! feof (arquivo) &&
 strcmp ( "PARAR", linha ) != 0 )
 {
 // mostrar valor
 printf ( "%s\n", linha );
 // tentar ler o proximo
 strcpy ( linha, IO_fread ( arquivo ) );
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readWords ( )
/**
 Method_09.
*/
void method_09 ( )
{
// identificar
 IO_id ( "Method_09 - v0.0" );
// executar o metodo auxiliar
 readWords ( "DADOS4.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )
/**
 searchWord - Procurar palavra em arquivo.
 @return true, se encontrar; false, caso contrario
 @param fileName - nome do arquivo
 @param word - palavra a procurar
*/
bool searchWord ( chars fileName, chars word )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 chars linha = IO_new_chars ( STR_SIZE );
// tentar ler a primeira
 strcpy ( linha, IO_fread ( arquivo ) );
// repetir enquanto houver dados
 while ( ! feof (arquivo) &&
 strcmp ( word, linha ) != 0 )
 {
 // tentar ler o proximo
 strcpy ( linha, IO_fread ( arquivo ) );
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );

// retornar resultado
 return ( strcmp ( word, linha ) == 0 );
} // end ifarchdWord ( )
/**
 Method_10.
*/
void method_10 ( )
{
// identificar
 IO_id ( "Method_10 - v0.0" );
// procurar palavra
 IO_printf ( "Procurar (\"%s\") = %d\n", "pqr", searchWord ( "DADOS4.TXT", "pqr" ) );
 IO_printf ( "Procurar (\"%s\") = %d\n", "pqs", searchWord ( "DADOS4.TXT", "pqs" ) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
}
// ------------------------------------------- EXERCICIOS
void gravarMultiplosImpares ( chars fileName, int x )
{
  // definir dados
      FILE *arquivo = fopen(fileName, "wt");
    int termo = 0;
    int i = 0;

  //repetir para cada quantidade de dados
  for (i = 1; i <= x; i = i + 1)
    {
        // Calcular o termo usando a fórmula
        termo = 3 * (2 * i - 1);
        // Gravar o valor no arquivo
        fprintf(arquivo, "%d\n", termo);
    }
  // fechar arquivo
  fclose ( arquivo );
} 
void Method_0711 ()
{
  // identificar
  IO_id ( "Method_0711 - v0.0" );
  int n = 0;
  n = IO_readint ( "Entre com o numero de valores: " );
  gravarMultiplosImpares ( "DADOS5.TXT", n );
  IO_printf("Dados gravados no arquivo DADOS5.TXT\n");

  // encerrar
  IO_pause ( "Apertar ENTER para continuar" );
} // end Method_0711 ()
void gravarMultiplosDe12Decrescente(const char *fileName, int n)
{
    FILE *arquivo = fopen(fileName, "wt");
    int i = 0;

    // A fórmula para encontrar o valor inicial da sequência é 24 + 12*(n-1)
    int termoInicial = 24 + 12 * (n - 1);

    // Laço 'for' que começa no termo inicial e decrementa de 12 em 12
    for (i = termoInicial; i >= 24; i = i - 12)
    {
        fprintf(arquivo, "%d\n", i);
    }

    fclose(arquivo);
}
/**
 * Method_0712 - Pede um valor ao usuario e chama a funcao para gravar em arquivo.
 */
void Method_0712()
{
    // Identificar
    IO_id("Method_0712 - v0.0");

    int n = IO_readint("Digite a quantidade de valores: ");

    gravarMultiplosDe12Decrescente("DADOS12.TXT", n);

    IO_printf("Dados gravados em DADOS12.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
void gravarPotenciasDe4(const char *fileName, int n)
{
    FILE *arquivo = fopen(fileName, "wt");
    int i = 0;
    int termo = 1; // O primeiro termo da sequência é 1 (4^0)

    for (i = 0; i < n; i = i + 1)
    {
        fprintf(arquivo, "%d\n", termo);
        termo = termo * 4; // Calcula o próximo termo multiplicando por 4
    }

    fclose(arquivo);
}
/**
 * Method_0713 - Pede um valor ao usuario e chama a funcao para gravar em arquivo.
 */
void Method_0713()
{
    // Identificar
    IO_id("Method_0713 - v0.0");

    int n = IO_readint("Digite a quantidade de valores: ");

    gravarPotenciasDe4("DADOS13.TXT", n);

    IO_printf("Dados gravados em DADOS13.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
void gravarPotenciasDe4Inversas(const char *fileName, int n)
{
    FILE *arquivo = fopen(fileName, "wt");
    int i = 0;
    double termo = 1.0; // O primeiro termo é 1.0

    for (i = 0; i < n; i = i + 1)
    {
        // Usamos pow() da biblioteca <math.h> para calcular a potência
        termo = 1.0 / pow(4, i);
        fprintf(arquivo, "%lf\n", termo);
    }

    fclose(arquivo);
}
/**
 * Method_0714 - Pede um valor ao usuario e chama a funcao para gravar em arquivo.
 */
void Method_0714()
{
    // Identificar
    IO_id("Method_0714 - v0.0");

    int n = IO_readint("Digite a quantidade de valores: ");

    gravarPotenciasDe4Inversas("DADOS14.TXT", n);

    IO_printf("Dados gravados em DADOS14.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
void gravarSequenciaX(const char *fileName, int n, double x)
{
    FILE *arquivo = fopen(fileName, "wt");
    int i = 0;
    double termo = 1.0;
    int expoente = 0;

    for (i = 0; i < n; i = i + 1)
    {
        expoente = 2 * i; // O expoente é sempre par: 0, 2, 4, ...
        termo = 1.0 / pow(x, expoente);
        fprintf(arquivo, "%lf\n", termo);
    }

    fclose(arquivo);
}
/**
 * Method_0715 - Pede 'n' e 'x' ao usuario e chama a funcao para gravar em arquivo.
 */
void Method_0715()
{
    // Identificar
    IO_id("Method_0715 - v0.0");

    // Este método precisa ler dois valores: um inteiro e um double
    int n = IO_readint("Digite a quantidade de valores (n): ");
    double x = IO_readdouble("Digite a base da potencia (x): ");

    gravarSequenciaX("DADOS15.TXT", n, x);

    IO_printf("Dados gravados em DADOS15.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
double somarValoresDeArquivo(const char *fileName, int k)
{
    FILE *arquivo = fopen(fileName, "rt");
    double soma = 0.0;
    double valor = 0.0;
    int i = 0;

    if (arquivo == NULL) {
        IO_printf("ERRO: Nao foi possivel abrir o arquivo %s\n", fileName);
        return 0.0; // Retorna 0 se o arquivo não existir
    }

    for (i = 0; i < k; i = i + 1) {
        // fscanf retorna o número de itens lidos com sucesso
        if (fscanf(arquivo, "%lf", &valor) == 1) {
            soma = soma + valor;
        }
    }

    fclose(arquivo);
    return soma;
}
/**
 * Method_0716 - Soma valores de DADOS15.TXT e grava em RESULTADO06.TXT.
 */
void Method_0716()
{
    // Identificar
    IO_id("Method_0716 - v0.0");

    int k = IO_readint("Digite a quantidade de valores a somar: ");
    
    // Chama a função para obter a soma
    double soma = somarValoresDeArquivo("DADOS15.TXT", k);

    // Abre o arquivo de resultados para adicionar (append)
    FILE *arquivoResultado = fopen("RESULTADO06.TXT", "at");

    fprintf(arquivoResultado, "Quantidade lida: %d, Soma: %lf\n", k, soma);

    fclose(arquivoResultado);

    IO_printf("Resultado gravado em RESULTADO06.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
double somarInversosPotenciasDe4(int n)
{
    double soma = 0.0;
    int i = 0;

    for (i = 0; i < n; i = i + 1) {
        soma = soma + pow(4, i);
    }
    return soma;
}
/**
 * Method_0717 - Calcula a soma e grava em RESULTADO07.TXT.
 */
void Method_0717()
{
    // Identificar
    IO_id("Method_0717 - v0.0");

    int n = IO_readint("Digite a quantidade de termos a somar: ");

    double soma = somarInversosPotenciasDe4(n);

    FILE *arquivo = fopen("RESULTADO07.TXT", "at");
    fprintf(arquivo, "Para n = %d, a soma dos inversos e: %lf\n", n, soma);
    fclose(arquivo);

    IO_printf("Resultado gravado em RESULTADO07.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
void gravarPrimeirosFibonacciPares(const char *fileName, int n)
{
    FILE *arquivo = fopen(fileName, "wt");
    int paresEncontrados = 0;
    int f_ant = 0, f_atual = 1, f_prox = 0;

    while (paresEncontrados < n)
    {
        f_prox = f_ant + f_atual;
        f_ant = f_atual;
        f_atual = f_prox;

        // Verifica se o número é par e maior que zero
        if (f_prox > 0 && f_prox % 2 == 0) {
            fprintf(arquivo, "%d\n", f_prox);
            paresEncontrados = paresEncontrados + 1;
        }
    }
    fclose(arquivo);
}
/**
 * Method_0718 - Grava termos pares de Fibonacci em RESULTADO08.TXT.
 */
void Method_0718()
{
    // Identificar
    IO_id("Method_0718 - v0.0");

    int n = IO_readint("Digite a quantidade de termos pares de Fibonacci: ");
    
    gravarPrimeirosFibonacciPares("RESULTADO08.TXT", n);
    
    IO_printf("Resultado gravado em RESULTADO08.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
int contarMinusculas(const char* linha)
{
    int contador = 0;
    int i = 0;
    for (i = 0; linha[i] != '\0'; i = i + 1) {
        if (linha[i] >= 'a' && linha[i] <= 'z') {
            contador = contador + 1;
        }
    }
    return contador;
}
/**
 * Method_0719 - Lê um arquivo, conta minúsculas e grava em RESULTADO09.TXT.
 */
void Method_0719()
{
    // Identificar
    IO_id("Method_0719 - v0.0");

    // Abrir arquivos
    FILE *entrada = fopen("DADOS3.TXT", "rt"); 
    FILE *saida = fopen("RESULTADO09.TXT", "wt");
    
    // Verificar se os arquivos foram abertos
    if (entrada == NULL || saida == NULL) {
        IO_printf("ERRO: Nao foi possivel abrir os arquivos.\n");
        return;
    }
    
    // Ler cada linha da entrada
    while (!feof(entrada)) {
        char linha[STR_SIZE];
        if (fgets(linha, STR_SIZE, entrada) != NULL) {
            // Remove o \n que o fgets pode ler
            linha[strcspn(linha, "\n")] = 0; 

            int contagem = contarMinusculas(linha);
            fprintf(saida, "[%s] -> Minusculas: %d\n", linha, contagem);
        }
    }

    // Fechar arquivos
    fclose(entrada);
    fclose(saida);

    IO_printf("Resultado gravado em RESULTADO09.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
int contarDigitosMaiores(const char* linha)
{
    int contador = 0;
    int i = 0;
    for (i = 0; linha[i] != '\0'; i = i + 1) {
        if (linha[i] >= '4' && linha[i] <= '9') {
            contador = contador + 1;
        }
    }
    return contador;
}
/**
 * Method_0720 - Lê um arquivo, conta dígitos e grava em RESULTADO10.TXT.
 */
void Method_0720()
{
    // Identificar
    IO_id("Method_0720 - v0.0");

    FILE *entrada = fopen("DADOS3.TXT", "rt"); // Usando DADOS3.TXT como exemplo
    FILE *saida = fopen("RESULTADO10.TXT", "wt");

    if (entrada == NULL || saida == NULL) {
        IO_printf("ERRO: Nao foi possivel abrir os arquivos.\n");
        return;
    }

    while (!feof(entrada)) {
        char linha[STR_SIZE];
        if (fgets(linha, STR_SIZE, entrada) != NULL) {
            linha[strcspn(linha, "\n")] = 0; 
            int contagem = contarDigitosMaiores(linha);
            fprintf(saida, "[%s] -> Digitos >= '4': %d\n", linha, contagem);
        }
    }

    fclose(entrada);
    fclose(saida);

    IO_printf("Resultado gravado em RESULTADO10.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
void gravarDivisoresImparesDecrescente(const char *fileName, int numero)
{
    FILE *arquivo = fopen(fileName, "wt");
    int i = 0;

    // Laço decrescente, do número até 1
    for (i = numero; i >= 1; i = i - 1) {
        // Verifica se é divisor E se é ímpar
        if (numero % i == 0 && i % 2 != 0) {
            fprintf(arquivo, "%d\n", i);
        }
    }
    fclose(arquivo);
}
/**
 * Method_07E1 - Grava divisores ímpares de um número em arquivo.
 */
void Method_07E1()
{
    // Identificar
    IO_id("Method_07E1 - v0.0");

    int numero = IO_readint("Digite um numero inteiro: ");
    
    gravarDivisoresImparesDecrescente("DADOSE1.TXT", numero);
    
    IO_printf("Divisores impares gravados em DADOSE1.TXT\n");
    IO_pause("Apertar ENTER para continuar");
}
int contarPalavrasComF(const char *fileName)
{
    FILE *arquivo = fopen(fileName, "rt");
    int contador = 0;
    char palavra[STR_SIZE];

    if (arquivo == NULL) {
        IO_printf("ERRO: Nao foi possivel abrir o arquivo %s\n", fileName);
        return 0;
    }
    
    // fscanf lê uma palavra por vez (separada por espaços ou quebras de linha)
    while (fscanf(arquivo, "%s", palavra) == 1) {
        if ((palavra[0] == 'f' || palavra[0] == 'F') && strlen(palavra) <= 15) {
            contador = contador + 1;
        }
    }

    fclose(arquivo);
    return contador;
}
/**
 * Method_07E2 - Conta palavras em um arquivo que começam com 'F'.
 */
void Method_07E2()
{
    // Identificar
    IO_id("Method_07E2 - v0.0");

    int contagem = contarPalavrasComF("DADOS3.TXT"); // Usando DADOS3.TXT como exemplo
    
    IO_printf("O arquivo contem %d palavras que comecam com 'f' ou 'F' e tem ate 15 caracteres.\n", contagem);
    IO_pause("Apertar ENTER para continuar");
}

// main
int main ()
{
  int x = 0;
  do {
  //identificar
  IO_id ("Exemplo0700 - v0.0");

  // ler do teclado
  IO_println ("Opcoes:");
  IO_println (" 0 - parar");
  IO_println (" 1 - Method_01 - Gravar valores em arquivo");
  IO_println (" 2 - Method_02 - Ler valores de arquivo");
  IO_println (" 3 - Method_03 - Gravar valores double em arquivo");
  IO_println (" 4 - Method_04 - Ler valores double de arquivo");
  IO_println (" 5 - Method_05 - Gravar texto em arquivo");
  IO_println (" 6 - Method_06 - Ler texto de arquivo");
  IO_println (" 7 - Method_07 - Copiar texto de arquivo");
  IO_println (" 8 - Method_08 - Acrescentar texto a arquivo");
  IO_println (" 9 - Method_09 - Ler palavras de arquivo");
  IO_println ("10 - Method_10 - Procurar palavra em arquivo");
  IO_println ("11 - Method_0711 - Gravar valores em arquivo (Exercicio)");
  IO_println ("12 - Method_0712 - Gravar multiplos de 12 em ordem decrescente (Exercicio)");
  IO_println ("13 - Method_0713 - Gravar potencias de 4 (Exercicio)");
  IO_println ("14 - Method_0714 - Gravar potencias inversas de 4 (Exercicio)");
  IO_println ("15 - Method_0715 - Gravar sequencia 1/(x^(2n)) (Exercicio)");
  IO_println ("16 - Method_0716 - Somar valores de arquivo (Exercicio)");
  IO_println ("17 - Method_0717 - Somar inversos de potencias de 4 (Exercicio)");
  IO_println ("18 - Method_0718 - Gravar primeiros n termos pares de Fibonacci (Exercicio)");
  IO_println ("19 - Method_0719 - Contar letras minusculas em arquivo (Exercicio)");
  IO_println ("20 - Method_0720 - Contar digitos maiores ou iguais a 4 em arquivo (Exercicio)");
  IO_println ("21 - Method_07E1 - Gravar divisores impares de um numero (Exercicio Extra)");
  IO_println ("22 - Method_07E2 - Contar palavras que comecam com 'f' ou 'F' (Exercicio Extra)");

  x = IO_readint ("Entrar com uma opcao: ");

  // testar valor
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
  case 11: Method_0711(); break;
  case 12: Method_0712(); break;
  case 13: Method_0713(); break;
  case 14: Method_0714(); break;
  case 15: Method_0715(); break;
  case 16: Method_0716(); break;
  case 17: Method_0717(); break;
  case 18: Method_0718(); break;
  case 19: Method_0719(); break;
  case 20: Method_0720(); break;
  case 21: Method_07E1(); break;
  case 22: Method_07E2(); break;

  default:IO_println ( "ERRO: Valor invalido." );
  }

  } while (x != 0);

  // encerrar
  IO_pause ("Apertar ENTER para terminar");
  return (0);
} // end main ( )

// ------------------------------------------- testes
// EXEMPLOS
/**
 Method_01:
 - Saída em DADOS1.TXT: 1
                        2   
                        3
                        4
                        5
                        6
                        7
                        8
                        9
                        10
  - Resultado: ( OK )

 Method_02:
  - Saída: 1
            2   
            3
            4
            5
            6
            7
            8
            9
            10
  - Resultado: ( OK )      

  Method_03:
  - Saída em DADOS2.TXT: 10
                         0.100000
                         0.200000
                         0.300000
                         0.400000
                         0.500000
                         0.600000
                         0.700000
                         0.800000
                         0.900000
                         1.000000
  - Resultado: ( OK )     

  Method_04:
  - Saída: 1: 0.100000
            2: 0.200000
            3: 0.300000
            4: 0.400000
            5: 0.500000
            6: 0.600000
            7: 0.700000
            8: 0.800000
            9: 0.900000
           10: 1.000000
 - Resultado: ( OK )   
 
 Method_05:
  - Entrada: OLA
             TUDO
             BEM
             PARAR
  - Saída em DADOS3.TXT: OLA
                         TUDO
                         BEM
                         PARAR
  - Resultado: ( OK )

  Method_06:
  - Saída: OLA
           TUDO
           BEM
 - Resultado: ( OK )

 Method_07:
  - Saída em DADOS4.TXT: OLA
                         TUDO
                         BEM
  - Resultado: ( OK )

  Method_08:
  - Entrada: COMO
             VOCE
             ESTA
             PARAR
  - Saída em DADOS4.TXT:
                        COMO
                         VOCE
                         ESTA
  - Resultado: ( OK )    
  
  Method_09:
  - Saída: COMO
           VOCE
           ESTA
  - Resultado: ( OK )   
  
  Method_10:
  - Saída: Procurar ("pqr") = 1
           Procurar ("pqs") = 0
  - Resultado: ( OK )

    // EXERCICIOS

  Method_0711:
  - Entrada: 5
  - Saída em DADOS5.TXT: 3
                         9
                         15
                         21
                         27
  - Resultado: ( OK )

  Method_0712:
  - Entrada: 5
  - Saída em DADOS12.TXT: 72
                         60
                         48
                         36
                         24
  - Resultado: ( OK )
  
  Method_0713:
  - Entrada: 5
  - Saída em DADOS13.TXT: 1
                         4
                         16
                         64
                         256
  - Resultado: ( OK )

  Method_0714:
  - Entrada: 5
  - Saída em DADOS14.TXT: 1.000000
                         0.250000
                         0.062500
                         0.015625
                         0.00390625
  - Resultado: ( OK )

  Method_0715:
  - Entrada: n = 5, x = 2.0
  - Saída em DADOS15.TXT: 1.000000
                         0.250000
                         0.062500
                         0.015625
                         0.00390625
  - Resultado: ( OK )

 Method_0716:
  - Entrada: 5
  - Saída em RESULTADO06.TXT: Quantidade lida: 5, Soma: 1.333333
  - Resultado: ( OK )

  Method_0717:
  - Entrada: 5
  - Saída em RESULTADO07.TXT: Para n = 5, a soma dos inversos e: 1.333333
  - Resultado: ( OK )

  Method_0718:
  - Entrada: 5
  - Saída em RESULTADO08.TXT: 2
                         8
                         34
                         144
                         610
  - Resultado: ( OK )

  Method_0719:
  - Saída em RESULTADO09.TXT: [OLA] -> Minusculas: 2
                              [TUDO] -> Minusculas: 2
                              [BEM] -> Minusculas: 2
  - Resultado: ( OK )

  Method_0720:
  - Saída em RESULTADO10.TXT: [OLA] -> Digitos >= '4': 0
                              [TUDO] -> Digitos >= '4': 0
                              [BEM] -> Digitos >= '4': 0
  - Resultado: ( OK )

  Method_07E1:
  - Entrada: 105
  - Saída em DADOSE1.TXT: 105
                         35
                         15
                         7
                         3
                         1 
  - Resultado: ( OK )

  Method_07E2:
  - Saída: O arquivo contem 0 palavras que comecam com 'f' ou 'F' e tem ate 15 caracteres.
  - Resultado: ( OK )
  
 */