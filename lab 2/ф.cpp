#include <stdio.h>

int main() {
    double m[3][3]; 
    double gdiag = 0, pdiag = 0;
    int i, j;

   
    printf("9 chisel dlya 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%lf", &m[i][j]);
        }
    }

   
    for (i = 0; i < 3; i++) {
        gdiag += m[i][i];
        pdiag += m[i][2 - i];
    }

    printf("glavnaya: %.1lf\n", gdiag);
    printf("pobochnaya: %.1lf\n", pdiag);

	
	{
    int m[2][2];
    
    
    printf("4 chisla dlya 2x2:\n");
    int i, j, k;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    
    printf("\nkvadrat:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            int sum = 0;
            
            for(k = 0; k < 2; k++) {
                sum += m[i][k] * m[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}
}
