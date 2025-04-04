#include <stdio.h>
#include "triangle.h"

int main() {
    double a, b, c;
    printf("vvedite 3 znacheniya: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("perimitr: %.2lf\n", perimeter(a, b, c));
    printf("ploshad: %.2lf\n", area(a, b, c));

    return 0;
}

