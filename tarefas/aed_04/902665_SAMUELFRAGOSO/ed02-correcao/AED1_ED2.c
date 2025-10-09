/*
Aluno: Samuel Fragoso
Matrícula: 123456

AED1 - Estudo Dirigido 02
*/
#include "io.h"

// 0211 - Ler inteiro e dizer se é par e negativo, ou ímpar e positivo
void method_0211 ( void ) 
{
    int x = 0;
    IO_id("Method_0211 - Programa - v0.0");

    x = IO_readint("Digite um valor inteiro: ");

    if (x % 2 == 0 && x <= 0)  
    {
        IO_printf("Valor (%d) é par e negativo (zero conta como par)\n", x);
    }
    else if (x % 2 != 0 && x > 0)
    {
        IO_printf("Valor (%d) é ímpar e positivo\n", x);
    }
    else 
    {
        IO_printf("Valor (%d) não se enquadra nos dois casos pedidos\n", x);
    }

    IO_pause("Apertar ENTER para continuar");
} //end method_0211

// 0212 - Par e > -15 OU ímpar e < 15
void method_0212 (void)
{
    int x = 0;
    IO_id("Method_0212 - Programa - v0.0");

    x = IO_readint("Digite um valor inteiro:");

    if (x % 2 == 0 && x > -15)
    {
      IO_printf("Valor (%d) é par e maior que -15\n", x);
    }
    else if (x % 2 != 0 && x < 15)
    {
      IO_printf("Valor (%d) é ímpar e menor que 15\n");
    }
    else
    {
        IO_printf("Valor (%d) não se enquadra nas condicoes\n", x);
    }

    IO_pause("Apertar ENTER para continuar");
        
}

// 0213 - Pertence ao intervalo (25:60)
void method_0213 (void)
{
    int x = 0;
    IO_id("Method_0213 - Programa - v0.0");

    x = IO_readint("Digite um valor inteiro: ");

    if (x > 25 && x < 60)
    {
        IO_printf("Valor (%d) pertence ao intervalo aberto (25:60)\n", x);
    }
    else
    {
        IO_printf("Valor (%d) NAO pertence ao intervalo aperto (25;60)\n", x);
    }
    
    IO_pause("Apertar ENTER para continuar");
}

// 0214 - Pertence ao intervalo [25:60]
void method_0214 (void)
{
    int x = 0;
    IO_id("Method_0214 - Programa - v0.0");

    x = IO_readint("Digite um valor inteiro: ");

    if (x >= 25 && x <= 60)
    {
        IO_printf("Valor (%d) pertence ao intervalo fechado [25:60]\n", x);
    }
    else
    {
        IO_printf("Valor (%d) nao pertence ao intervalo fechado [25:60]\n", x);
    }
    
    IO_pause("Aperte ENTER para continuar");
}

// 0215 - Interseção [12:24] e (20:50)
void method_0215 (void)
{
    int x = 0;
    IO_id("Method_0215 - Programa - v0.0");

    x = IO_readint("Digite um valor inteiro: ");

    if (x >= 12 && x <= 24 && x > 20 && x < 50)
    {
        IO_printf("Valor (%d) pertence a intersecao dos intervalos\n", x);
    }
    else if ((x >= 12 && x <= 24) || (x > 20 && x < 50))
    {
        IO_printf("Valor (%d) pertence apenas a um dos intervalos\n", x);
    }
    else
    {
        IO_printf("Valor (%d) nao pertence a nenhum intervalo\n", x);
    }
    IO_pause("Apertar ENTER para continuar");
}

// 0216 - Primeiro par e segundo ímpar
void method_0216 (void)
{
    int a = 0, b = 0;
    IO_id("Method_0216 - Programa - v0.0");

    a = IO_readint("Digite o primeiro inteiro: ");
    b = IO_readint("Digite o segundo inteiro: ");

    if (a % 2 == 0 && b % 2 !=0)
    {
        IO_printf("Primeiro (%d) é par e segundo (%d) é ímpar\n", a, b);
    }
    else
    {
        IO_printf("Condicao NAO atendida\n");
    }
    
    IO_pause("Apertar ENTER para continuar"); 
}

// 0217 - Primeiro par positivo e segundo ímpar negativo
void method_0217 (void)
{
    int a = 0, b = 0;
    IO_id("Method_0217 - Programa - v0.0");

    a = IO_readint("Digite o primeiro inteiro: ");
    b = IO_readint("Digite o segundo inteiro: ");

    if (a % 2 == 0 && a > 0 && b % 2 != 0 && b < 0)
    {
        IO_printf("Primeiro (%d) é par e positivo, segundo (%d) é ímpar e negativo\n", a, b);
    }
    else
    {
        IO_printf("Condicao nao atendida\n");
    }

    IO_pause("Aperte ENTER para continuar");
    
}
//  0218 - Primeiro comparado a 1/3 do segundo
void method_0218 (void)
{
    double a = 0.0, b = 0.0;
    IO_id("Method_0218 - Programa - v0.0");

    a = IO_readdouble("Digite o primeiro real: ");
    b = IO_readdouble("Digite o segundo real: ");

    if (a < b/3.0)
    {
        IO_printf("Primeiro (%.2lf) < 1/3 do segundo (%2lf)\n", a, b);
    }
    else if (a == b/3.0)
    {
        IO_printf("Primeiro (%.2lf) = 1/3 do segundo (%.2lf)\n", a, b);
    }
    else
    {
        IO_printf("Primeiro (%.2lf) > 1/3 do segundo (%.2lf)\n", a, b);
    }

    IO_pause("Apertar ENTER para continuar");
        
}

// 0219 - Segundo entre o primeiro e o último (quando diferentes)
void method_0219 (void)
{
    double a = 0.0, b = 0.0, c = 0.0;
    IO_id("Method_0219 - Programa - v0.0");

    a = IO_readdouble("Digite o primeiro real: ");
    b = IO_readdouble("Digite o segundo número: ");
    c = IO_readdouble("Digite o terceiro número real: ");

    if (a != c)
    {
        if ((a < b && b < c) || (c < b && b < a))
        {
            IO_printf("O segundo (%.2lf) esta entre %.2lf e %.2lf\n", b, a, c);
        }
        else
        {
            IO_printf("O segundo (%.2lf) NAO esta entre %.2lf e %.2lf\n", b, a, c);
        } 
    }
    else
    {
        IO_printf("Primeiro e ultimo iguais (%.2lf), nao avaliar\n", a);
    }
    IO_pause("Apertar ENTER para continuar"); 
}

// 0220 - Segundo NAO entre primeiro e ultimo (quando diferentes)
void method_0220 (void)
{
    double a = 0.0, b = 0.0, c = 0.0;
    IO_id("Method_0220 - Programa - v0.0");

    a = IO_readdouble("Digite o primeiro real: ");
    b = IO_readdouble("Digite o segundo real: ");
    c = IO_readdouble("Digite o terceiro real: ");

    if (a != c)
    {
        if ((a < b && b < c) || (c < b && b < a))
        {
            IO_printf("O segundo (%.2lf) esta ENTRE %.2lf e %2lf\n", b, a, c);
        }
        else
        {
            IO_printf("O segundo (%.2lf) NAO esta entre %.2lf e %.2lf\n", b, a, c);
        }   
    }
    else
    {
        IO_printf("Primeiro e ultimo iguais (%.2lf), nap avaliar\n", a);
    }
    IO_pause("Apertar ENTER para continuar");
    
}

// --------------------------------------------------------------------------------------------------------------
// EXTRAS

// 02E1 - 3 chars: primeiro entre os outros dois ou igual a um deles
void method_02E1 (void)
{
    char a, b, c;
    IO_id("Method_02E1 - Programa - v0.0");

    a = IO_readchar("Digite o primeiro caractere: ");
    b = IO_readchar("Digite o segundo caractere: ");
    c = IO_readchar("Digite o terceiro caractere: ");

    if ((a >= b && a <= c) || (a >= c && a <= b) || a == b || a == c)
    {
        IO_printf("Primeiro (%c) esta entre ou igual a um dos outros dois (%c, %c)\n", a, b, c);
    }
    else
    {
        IO_printf("Primeiro (%c) NAO esta entre nem igual aos outros dois (%c, %c)\n", a, b, c);
    }
    

    IO_pause("Apertar ENTER para continuar");
}

// 02E2 - 3 chars: primeiro fora do intervalo dos outros dois
void method_02E2 (void)
{
    char a, b, c;
    IO_id("Method_02E2 - Programa -v0.0");

    a = IO_readchar("Digite o primeiro caractere: ");
    b = IO_readchar("Digite o segundo caractere: ");
    c = IO_readchar("Digite o segundo caractere: ");

    if (b != c)
    {
        if ((a < b && a < c) || (a > b && a > c))
        {
            IO_printf("Primeiro (%c) esta fora do intervalo definido por (%c, %c)\n", a, b, c);
        }
        else
        {
            IO_printf("Primeiro (%c) esta dentro do intervalo definido por (%c, %c)\n", a, b, c);
        } 
    }
    else
    {
        IO_printf("Nao avaliar pois segundo e terceiro sao iguais (%c)\n", b);
    }

    IO_pause("Apertar ENTER para continuar");
}

///

int main (void)
{
    int opcao = 0;

    IO_id("Exemplo0220 - Programa - v0.0");

    do
    {
        IO_println("\nOpcoes:");
        IO_println("0 - Terminar");
        IO_println("1 - 0211: Par e negativo ou impar e positivo");
        IO_println("2 - 0212: Par > -15 ou impar < 15");
        IO_println("3 - 0213: Intervalo aberto (25:60)");
        IO_println("4 - 0214: Intervalo fechado [25:60]");
        IO_println("5 - 0215: Intersecao de intervalos");
        IO_println("6 - 0216: Primeiro par, segundo impar");
        IO_println("7 - 0217: Primeiro par positivo, segundo impar negativo");
        IO_println("8 - 0218: Comparar com 1/3 do segundo");
        IO_println("9 - 0219: Segundo entre primeiro e ultimo");
        IO_println("10 - 0220: Segundo NAO entre primeiro e ultimo");
        IO_println("11 - 02E1: Primeiro char entre ou igual");
        IO_println("12 - 02E2: Primeiro char fora do intervalo");

        IO_println("\nOpcao = ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao)
        {
          case 0: break;
            case 1: method_0211(); break;
            case 2: method_0212(); break;
            case 3: method_0213(); break;
            case 4: method_0214(); break;
            case 5: method_0215(); break;
            case 6: method_0216(); break;
            case 7: method_0217(); break;
            case 8: method_0218(); break;
            case 9: method_0219(); break;
            case 10: method_0220(); break;
            case 11: method_02E1(); break;
            case 12: method_02E2(); break;  

        default: IO_println("ERRO: opcao invalida"); break;
        }
    } while (opcao != 0);

    IO_pause("\nApertar ENTER para terminar");
    return 0;
    
}