/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0112
*/

#include <stdio.h>

int main(void) {
    int lado;
    printf("Digite o lado (inteiro): ");
    scanf("%d", &lado);

    double novo = 2.0 * lado;
    double area = novo * novo;
    double perimetro = 4.0 * novo;

    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f\n", perimetro);
    return 0;
}
