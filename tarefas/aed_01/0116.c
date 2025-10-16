/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0116
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double lado;
    printf("Digite o lado do triangulo equilatero: ");
    scanf("%lf", &lado);

    double novo = (2.0/3.0) * lado;
    double altura = (sqrt(3.0)/2.0) * novo;
    double area = (sqrt(3.0)/4.0) * novo * novo;
    double perimetro = 3.0 * novo;

    printf("Altura = %.2f\n", altura);
    printf("Area = %.2f\n", area);
    printf("Perimetro = %.2f\n", perimetro);
    return 0;
}
