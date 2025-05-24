#include <stdio.h>
#include "stats.h"

int main() {
    printf("summa: %.2f\n", sum(5, 1.0, 2.5, 3.0, 4.5, 5.0));
    printf("maks: %.2f\n", max(3, 10.0, 20.5, 5.5));
    printf("minimum: %.2f\n", min(4, 8.0, 2.5, 3.0, 1.2));
    printf("srednee: %.2f\n", average(4, 2.0, 4.0, 6.0, 8.0));
    
    return 0;
}
