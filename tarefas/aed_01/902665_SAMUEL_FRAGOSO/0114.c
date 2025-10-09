/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0114
*/

#include <stdio.h>

int main(void) {
    int a, b;
    printf("Digite dois lados (inteiros): ");
    scanf("%d %d", &a, &b);

    double na = a / 6.0, nb = b / 6.0;
    double area = na * nb;
    double perimetro = 2.0 * (na + nb);

    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f\n", perimetro);
    return 0;
}
