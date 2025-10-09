/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0115
*/

#include <stdio.h>

int main(void) {
    double base, altura;
    printf("Digite base e altura: ");
    scanf("%lf %lf", &base, &altura);

    double area = (base * (altura / 2.0)) / 2.0; // = base*altura/4
    printf("Area = %.2f\n", area);
    return 0;
}
