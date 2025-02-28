#include <stdio.h>

int main() {
    double a[3][3];
    printf("vvedite 9 chisel 3x3:\n");
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) 
            scanf("%lf", &a[i][j]);
    
    double main_sum = a[0][0] + a[1][1] + a[2][2];
    double anti_sum = a[0][2] + a[1][1] + a[2][0];
    printf("glavnaya: %.1lf\npobochnaya: %.1lf\n\n", main_sum, anti_sum);

    int b[2][2], res[2][2] = {0};
    printf("vvedite 4 chisel 2x2:\n");
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

