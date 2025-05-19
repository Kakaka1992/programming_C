#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX(n, arr) ({int max = (arr)[0]; int i; for (i = 1; i < n; i++) if (max < (arr)[i]) max = (arr)[i]; max;})

int main(){
    int numbers[10];
    int count = 5;
    int i;

	printf("vvedite chisla: ");
	for(i = 0; i < count; i++){
		scanf("%d", &numbers[i]);
    }
    printf("max chislo: %d\n", MAX(count, numbers));
    return 0;
}

