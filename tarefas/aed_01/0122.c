/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0122
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    double raio, altura;
    printf("Digite o raio e a altura do cilindro: ");
    scanf("%lf %lf", &raio, &altura);

    double area = 2.0 * M_PI * raio * (raio + altura);
    double volume = M_PI * raio * raio * altura;

    printf("Area = %.2f\n", area);
    printf("Volume = %.2f\n", volume);
    return 0;
}
