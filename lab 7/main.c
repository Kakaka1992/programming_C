#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char firstname[20];
    char lastname[20];
    int year;
} humen;

int main() {
    humen array1[4];
    humen array2[4];
    
     FILE *f1;
    f1 = fopen("text.txt", "r");
    int i;
    for (i = 0; i < 4; i++) {
       fscanf(f1, "%s %s %d", array1[i].firstname, array1[i].lastname, &array1[i].year);
       
    }
  	memcpy(array2, array1, sizeof(array1));
    
    
    int N;
	N=4;
	int tmp;
    bool noSwap;
    for (i = N - 1; i >= 0; i--){
        noSwap = 1;
        int j;
        for (j = 0; j < i; j++)
        {
            if (array2[j].year > array2[j + 1].year)
            {
                tmp = array2[j].year;
                array2[j].year = array2[j + 1].year;
                array2[j + 1].year = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }
	
    printf("array2:\n");
    for (i = 0; i < 4; i++) {
        printf("%s %s %d\n", array2[i].firstname, array2[i].lastname, array2[i].year);
    }
    
    return 0;
}
