/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0119
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double r;
    printf("Digite o raio do circulo: ");
    scanf("%lf", &r);

    double R = 8.0 * r;
    double area = 0.5 * M_PI * R * R;

    printf("Area do semicirculo = %.2f\n", area);
    return 0;
}
