#include <stdio.h>

int main() {
    double a[3][3];
    printf("vvesti 9 chisel 3x3:\n");
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) 
            scanf("%lf", &a[i][j]);
    
    double main_sum = 0, anti_sum = 0;
    
    for(int i = 0; i < 3; i++) {
        main_sum += a[i][i];
    }
    
    for(int i = 0; i < 3; i++) {
        anti_sum += a[i][2 - i];
    }

    int b[2][2], res[2][2] = {0};
    printf("vvesti 4 chisla 2x2:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &b[i][j]);
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                res[i][j] += b[i][k] * b[k][j];
    
    printf("kvadrat:\n");
    for(int i = 0; i < 2; i++) {
        printf("%d %d\n", res[i][0], res[i][1]);
    }

    return 0;
}
