/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0121
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double raio;
    printf("Digite o raio da esfera: ");
    scanf("%lf", &raio);

    double area = 4.0 * M_PI * raio * raio;
    double volume = (4.0/3.0) * M_PI * raio * raio * raio;

    printf("Area = %.2f\n", area);
    printf("Volume = %.2f\n", volume);
    return 0;
}
