#include <stdio.h>
#include <string.h>

struct humen {
    char name[50];
    char sname[50];
    int byear;
};

int main() {
	int i,j;
    const int N = 4;
    struct humen a[N], b[N], temp;

	for (i = 0; i < N; i++) {
        printf("vvedite imya %d cheloveka: ", i + 1, "\n");
        scanf("%s", a[i].name); 

        printf("vvedite familiy %d cheloveka: ", i + 1, "\n");
        scanf("%s", a[i].sname);

        printf("vvedite god %d cheloveka: ", i + 1, "\n");
        scanf("%d", &a[i].byear);
    }

    
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - i - 1; j++) {
            if (b[j].byear > b[j + 1].byear) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    printf("\sorterovanni spisok:\n");
	for (i = 0; i < N; i++) {
        printf("%s %s %d\n", b[i].name, b[i].sname, b[i].byear);
    }

    return 0;
