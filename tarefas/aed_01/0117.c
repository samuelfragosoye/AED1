/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0117
*/

#include <stdio.h>

int main(void) {
    double lado;
    printf("Digite a medida do lado do cubo: ");
    scanf("%lf", &lado);

    double novo = 5.0 * lado;
    double volume = novo * novo * novo;

    printf("Volume = %.2f\n", volume);
    return 0;
}
