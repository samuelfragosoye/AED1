/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0120
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double r;
    printf("Digite o raio da esfera: ");
    scanf("%lf", &r);

    double rn = (3.0/8.0) * r;
    double volume = (4.0/3.0) * M_PI * rn * rn * rn;

    printf("Volume = %.2f\n", volume);
    return 0;
}
