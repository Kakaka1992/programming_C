#include <stdio.h>
#include "triangle.h"

int main() {
    double a, b, c;
    printf("vvedite 3 znacheniya: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double p = perimeter(a, b, c);
    double s = area(a, b, c);
    double h = height(a, s);

    printf("perimitr: %.2lf\n", perimeter(a, b, c));
    printf("ploshad: %.2lf\n", area(a, b, c));
    printf("Высота к стороне a: %.2lf\n", h);

    return 0;
}
