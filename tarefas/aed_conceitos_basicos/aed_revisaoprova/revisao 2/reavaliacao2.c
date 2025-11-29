#include "io.h"

//QUESTÕES FECHADAS
char * f_01 (char * s){
    for(int x = 0; x<strlen(s)-1;x=x+1)
    { if  (s[x]=='a'|| s[x]=='e' ||
           s[x]=='i'|| s[x]=='o' || s[x]=='u')
        for (int y =x+1; y<strlen(s); y=y+1)
    { s[x]=s[x+1];}  }
    return (s);
}

void method_01 () {
    IO_id("Method 1 - Questão 1");

    char texto[] = "hipopotamo"; 
    
    printf("Original: %s\n", texto);
    printf("Resultado: %s\n", f_01(texto));

    IO_pause("Aperte ENTER para continuar");
}

/* 
 *  SAÌDA: 
   Original: hipopotamo
   Resultado: hppppttmmo
*/

void question_02 (void)
{char r [] = "0111 0100";
 int c [] = {0,0,0,0,0,0,0,0,0,0};
 for(int x = 0; x<strlen(r); x=x+1)
    if ('0'<=r[x]&&r[x]<='9') c[r[x]-48]++;
    if (c[0]<c[1])       printf("%d%d\n",1,1);
    else if (c[1]==c[0]) printf("%d%d\n",0,1);
    else                 printf("%d%d\n",0,0);
}

void method_02 (){
    IO_id("Method 2 - Questão 2");

    printf("Resultado: \n");
    question_02();

    IO_pause("Aperte ENTER para continuar");
}

/* 
 *  SAÌDA: 
   Resultado: 
   01
*/

void question_03 (void){
    int m [][10]={{1,2,3},{4,5,6},{7,8,9}}; int n=3;
    for (int x=0; x<n; x++)
    for (int y=0; y<n; y++)
    {   if (x>y) m[x][y] = m[x][x]-m[y][y]+x-n;
        if (y<x) m[x][y] = m[y][x]+1;
    }
}

void print_matrix(int* matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

void method_03(void) {
    IO_id("Method 3 - Questão 3");
    
    int m[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n = 3;
    
    printf("Matriz original:\n");
    print_matrix((int*)m, 3, 3);
    
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            if(x > y) 
                m[x][y] = m[x][x] - m[y][y] + x - n;
            if(y < x) 
                m[x][y] = m[y][x] + 1;
        }
    }
    
    printf("\nMatriz após processamento:\n");
    print_matrix((int*)m, 3, 3);
    
    IO_pause("Aperte ENTER para continuar");
}

/* 
 *  SAÌDA: 
Matriz original:
 1  2  3 
 4  5  6 
 7  8  9 

Matriz após processamento:
 1  2  3 
 3  5  6 
 4  7  9 

*/
int a1[]={0,9,8,7,4,5,6,3,2,1};
struct as {int n; int *a;} b = {.n=10,.a=&a1[0]};
void p_04 (int x, int y, struct as b){
    if(3<x && x<b.n && 5<y && y<b.n && x<y)
    {if (b.a[x]<b.a[y])
      {b.a[0]=b.a[x]; b.a[x]=b.a[y]; b.a[y]=b.a[0];
       b.a[0]=0;}  p_04(x+1, 10-x, b);
    }
}

void method_04(void) {
    IO_id("Method 4 - Questão 4");
    
    printf("Array global antes:\n");
    for(int i = 0; i < 10; i++) {
        printf("a1[%d] = %d\n", i, a1[i]);
    }
    
    int a1_backup[10];
    for(int i = 0; i < 10; i++) {
        a1_backup[i] = a1[i];
    }
    
    p_04(4, 6, b);
    
    printf("\nArray global depois:\n");
    for(int i = 0; i < 10; i++) {
        printf("a1[%d] = %d\n", i, a1[i]);
    }
    
    for(int i = 0; i < 10; i++) {
        a1[i] = a1_backup[i];
    }
    
    IO_pause("Aperte ENTER para continuar");
}
/* 
 *  SAÌDA: 
Array global antes:
a1[0] = 0
a1[1] = 9
a1[2] = 8
a1[3] = 7
a1[4] = 4
a1[5] = 5
a1[6] = 6
a1[7] = 3
a1[8] = 2
a1[9] = 1

Array global depois:
a1[0] = 0
a1[1] = 9
a1[2] = 8
a1[3] = 7
a1[4] = 6
a1[5] = 5
a1[6] = 4
a1[7] = 3
a1[8] = 2
a1[9] = 1
*/


int function_05(int na, int* a, int nb, int* b, int* c)
{ int m = 0, n = 0;
    for(int x = 0; x<nb; x=x+1)
    {for (int y = 0; y<na; y = y + 1)
       {if (b[x]==a[y]){n=n+1;}}
     if (m!=n) {c[n-1]=b[x]; m=n;}
    }
    return (n);
}

void method_05(void) {
    IO_id("Method 5 - Questão 5");
    
    int a[] = {1,2,4,5,7};
    int b[] = {2,3,4,6};
    int c[] = {0,0,0,0};
    
    printf("Arrays iniciais:\n");
    printf("a[] = {1,2,4,5,7}\n");
    printf("b[] = {2,3,4,6}\n");
    printf("c[] = {0,0,0,0}\n\n");
    
    int n = function_05(5, a, 4, b, c);
    
    printf("Resultados após function_05:\n");
    printf("n = %d\n", n);
    printf("c[] = {%d,%d,%d,%d}\n", c[0], c[1], c[2], c[3]);
    
    printf("\nExplicação:\n");
    printf("A função encontra elementos comuns entre a[] e b[]\n");
    printf("e os armazena em c[] na ordem em que são encontrados.\n");
    printf("Elementos comuns: 2 e 4\n");
    
    IO_pause("Aperte ENTER para continuar");
}

/* 
 *  SAÌDA: 
Arrays iniciais:
a[] = {1,2,4,5,7}
b[] = {2,3,4,6}
c[] = {0,0,0,0}

Resultados após function_05:
n = 2
c[] = {2,4,0,0}

Explicação:
A função encontra elementos comuns entre a[] e b[]
e os armazena em c[] na ordem em que são encontrados.
Elementos comuns: 2 e 4
*/

//QUESTÕES ABERTAS

int f_06(int n, int m[][n]) {
    int resultado = 1; 
    int pivos_colunas[n]; 
    
    int k = 0;
    while(k < n) { pivos_colunas[k] = -1; k = k + 1; }

    int i = 0;
    while (i < n && resultado) {
        int j = 0;
        int pivo_encontrado = 0;
        int col_pivo = -1;

        while (j < n && !pivo_encontrado) {
            if (m[i][j] != 0) {
                col_pivo = j;
                pivo_encontrado = 1;
            }
            j = j + 1;
        }

        if (pivo_encontrado) {
            int x = 0;
            while (x < i) { 
                if (pivos_colunas[x] == col_pivo) {
                    resultado = 0; 
                }
                x = x + 1;
            }
            pivos_colunas[i] = col_pivo;
        }
        i = i + 1;
    }
    return resultado;
}

void method_06(void) {
    IO_id("Method 6 - Questão 6 (Pivôs)");
    
    int m[3][3] = {{0,4,5}, {0,0,6}, {1,2,3}};
    
    printf("Matriz analisada:\n");
    print_matrix((int*)m, 3, 3); 
    
    int result = f_06(3, m);
    printf("\nResultado (1=Escalonavel, 0=Nao): %d\n", result);
    
    IO_pause("Aperte ENTER para continuar");
}

void q_07(int na, int* a, int nb, int* b, int* c, int* nc) {
    int i = 0; 
    int k = 0; 
    
    while (i < nb) {
        int valor = b[i];
        int achou_em_a = 0;
        int j = 0;

        while (j < na && !achou_em_a) { 
            if (a[j] == valor) {
                achou_em_a = 1;
            }
            j = j + 1;
        }

        if (!achou_em_a) {
            c[k] = valor;
            k = k + 1;
        }
        i = i + 1;
    }
    *nc = k; 
}

void method_07(void) {
    IO_id("Method 7 - Questão 7 (Diferença B - A)");
    
    int a[] = {12, 25, 33, 45, 54};
    int b[] = {11, 25, 36, 45, 54, 63};
    int c[10]; 
    int nc = 0;
    
    q_07(5, a, 6, b, c, &nc);
    
    printf("Arranjo C (Diferença): { ");
    int i = 0;
    while(i < nc) {
        printf("%d ", c[i]);
        i = i + 1;
    }
    printf("}\n");
    
    IO_pause("Aperte ENTER para continuar");
}

void q_08(char* filename) {
    FILE* arq_entrada = fopen(filename, "rt");
    FILE* arq_saida = fopen("RESPOSTA08.TXT", "wt");
    FILE* arq_temp = fopen("TEMP_PARES.TXT", "w+"); 

    if (arq_entrada == NULL || arq_saida == NULL || arq_temp == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    int n = 0;
    fscanf(arq_entrada, "%d", &n); 
    
    int x = 0;
    int contador = 0;
    
    while (contador < n && fscanf(arq_entrada, "%d", &x) == 1) {
        if (x != 0) { 
            if (x % 2 != 0) {
                fprintf(arq_saida, "%d\n", x);
            } else {
                fprintf(arq_temp, "%d\n", x);
            }
        }
        contador = contador + 1;
    }

    rewind(arq_temp);
    while (fscanf(arq_temp, "%d", &x) == 1) {
        fprintf(arq_saida, "%d\n", x);
    }

    fclose(arq_entrada);
    fclose(arq_saida);
    fclose(arq_temp);
    remove("TEMP_PARES.TXT"); 
    
    printf("Arquivo RESPOSTA08.TXT gerado com sucesso.\n");
}

void method_08(void) {
    IO_id("Method 8 - Questão 8 (Arquivos)");
    
    FILE* f = fopen("QUESTAO08.TXT", "wt");
    fprintf(f, "6\n1\n2\n3\n4\n0\n5"); 
    fclose(f);
    
    printf("Processando arquivo QUESTAO08.TXT...\n");
    q_08("QUESTAO08.TXT");
    
    IO_pause("Aperte ENTER para continuar");
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
printf ( "\n%s" , "1 - Method_01 - Questão 1" );
printf ( "\n%s" , "2 - Method_02 - Exercicio 2" );
printf ( "\n%s" , "3 - Method_03 - Exercicio 3" );
printf ( "\n%s" , "4 - Method_04 - Exercicio 4" );
printf ( "\n%s" , "5 - Method_05 - Exercicio 5" );
printf ( "\n%s" , "6 - Method_06 - Exercicio 6" );
printf ( "\n%s" , "7 - Method_07 - Exercicio 7" );
printf ( "\n%s" , "8 - Method_08 - Exercicio 8" );
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
case 2: method_02 ( ); break;
case 3: method_03 ( ); break;
case 4: method_04 ( ); break;
case 5: method_05 ( ); break;
case 6: method_06 ( ); break;
case 7: method_07 ( ); break;
case 8: method_08 ( ); break;

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