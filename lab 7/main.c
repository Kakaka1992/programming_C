#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct humen {
    char firstname[50];
    char secondname[50];
    int age;
};

int main() {
	int i,j;
    FILE *file;
    char filename[100] = "file.txt";
    struct humen *people = NULL;
    int count = 0;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    char line[150];
    while (fgets(line, sizeof(line), file)) {
        people= realloc(people, (count + 1) * sizeof(struct humen));
    
        if (sscanf(line, "%49s %49s %d",
                  people[count].firstname,
                  people[count].secondname,
                  &people[count].age) == 3) {
            count++;
        }
    }
    fclose(file);
    
    for ( i = 0; i < count - 1; i++) {
        for ( j = 0; j < count - i - 1; j++) {
            if (people[j].age > people[j + 1].age) {
                struct humen temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted data:\n");
    for ( i = 0; i < count; i++) {
        printf("%s %s %d\n", people[i].firstname, people[i].secondname, people[i].age);
    }
    
    free(people);
    return 0;
}
