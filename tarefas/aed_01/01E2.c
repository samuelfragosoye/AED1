/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 01E2
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double V;
    printf("Digite o volume da esfera: ");
    scanf("%lf", &V);

    double Vn = (3.0/5.0) * V;
    double raio = pow( Vn / ((4.0/3.0) * M_PI), 1.0/3.0 );
    double area = 4.0 * M_PI * raio * raio;

    printf("Raio = %.6f\n", raio);
    printf("Area = %.6f\n", area);
    return 0;
}
