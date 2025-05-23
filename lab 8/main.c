#include <stdio.h>
#include <string.h>

typedef struct {
    char name[MAX_NAME]; 
    int year;           
    char gender;       
    float height;      
} Person;

int main() {
    Person people[MAX_PEOPLE];
    int count = 0; 
	int i, j; 

    
    FILE *file = fopen("people.txt", "r");
    if (!file) {
        printf("oshibka!\n");
        return 1;
    }

    
    while (count < MAX_PEOPLE && 
           fscanf(file, "%s %d %c %f\n", 
                  people[count].name, &people[count].year, 
                  &people[count].gender, &people[count].height) == 4) {
        count++;
    }
    fclose(file);

    
    int choice;
    printf("po chemu sorterovat?\n");
    printf("1 - got rojdeniya\n2 - imya\n3 - pol\n4 - rost\n");
    printf("vash vibor: ");
    scanf("%d", &choice);

    
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            int swap = 0;
            if (choice == 1) { 
                if (people[j].year > people[j + 1].year) swap = 1;
            } else if (choice == 2) {
                if (strcmp(people[j].name, people[j + 1].name) > 0) swap = 1;
            } else if (choice == 3) { 
                if (people[j].gender > people[j + 1].gender) swap = 1;
            } else if (choice == 4) { 
                if (people[j].height > people[j + 1].height) swap = 1;
            }

            
            if (swap) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }

    
    printf("\notsortirovanni danni:\n");
    printf("imya\tgod\tpol\trost\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%d\t%c\t%.2f\n", 
               people[i].name, people[i].year, 
               people[i].gender, people[i].height);
    }

    return 0;
}
