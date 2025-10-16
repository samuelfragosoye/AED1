/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0118
*/

#include <stdio.h>

int main(void) {
    double c, l, h;
    printf("Digite comprimento, largura e altura: ");
    scanf("%lf %lf %lf", &c, &l, &h);

    double vc = 7.0 * c, vl = 7.0 * l, vh = 7.0 * h;
    double volume = vc * vl * vh;

    printf("Volume = %.2f\n", volume);
    return 0;
}
