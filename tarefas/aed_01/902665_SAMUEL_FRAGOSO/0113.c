/*
   Autor: Samuel Fragoso
   Matrícula: 902665
   Exercício: 0113
*/

#include <stdio.h>

int main(void) {
    int a, b;
    printf("Digite dois lados (inteiros): ");
    scanf("%d %d", &a, &b);

    int area = (a * 3) * (b * 3);
    printf("Area = %d\n", area);
    return 0;
}
