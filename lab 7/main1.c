#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct humen {
    char name[50];
    char sname[50];
    int byear;
};

int main() {
    FILE *file;
    struct humen a[100], temp;
    int count = 0;
    int i, j;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("oshibka!\n");
        return 1;
    }

    while(fscanf(file, "%s %s %d", 
        a[count].name, 
        a[count].sname, 
        &a[count].byear) == 3) {
        count++;
    }
    fclose(file);


    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (a[j].byear > a[j + 1].byear) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }


    printf("sorterovanni:\n");
    for (i = 0; i < count; i++) {
        printf("%s %s %d\n", a[i].name, a[i].sname, a[i].byear);
    }


    file = fopen("output.txt", "w");
    for (i = 0; i < count; i++) {
        fprintf(file, "%s %s %d\n", a[i].name, a[i].sname, a[i].byear);
    }
    fclose(file);

    return 0;
}
