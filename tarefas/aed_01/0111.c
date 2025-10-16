/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0111
*/

#include <stdio.h>

int main(void) {
    int lado;
    printf("Digite o lado (inteiro): ");
    scanf("%d", &lado);

    double novo = lado / 3.0;
    double area = novo * novo;

    printf("Area = %.2f\n", area);
    return 0;
}
