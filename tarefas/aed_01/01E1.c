/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 01E1
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double area;
    printf("Digite a area da circunferencia: ");
    scanf("%lf", &area);

    double area7 = 7.0 * area;
    double raio = sqrt(area7 / M_PI);

    printf("Raio = %.6f\n", raio);
    return 0;
}
