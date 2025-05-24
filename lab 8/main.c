#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct humen {
    char name[50]; 
    int year;           
    char gender;       
    float height;  
};

int main() {
    FILE *file;
    struct humen people[100], temp;
    int count = 0;
    int i, j;

    file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Îøèáêà îòêðûòèÿ ôàéëà!\n");
        return 1;
    }

   
    while (count < 100 && 
           fscanf(file, "%49s %d %c %f", 
                  people[count].name, 
                  &people[count].year, 
                  &people[count].gender, 
                  &people[count].height) == 4) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("îøèáêè!\n");
        return 1;
    }

    
    int choice;
    printf("po chemu sorterovat:\n");
    printf("1 - god rojd\n2 - imya\n3 - pol\n4 - rost\n");
    printf("vibor: ");
    scanf("%d", &choice);

    
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            int swap = 0;
            
            if (choice == 1) { 
                if (people[j].year > people[j + 1].year) swap = 1;
            } 
            else if (choice == 2) {
                if (strcmp(people[j].name, people[j + 1].name) > 0) swap = 1;
            } 
            else if (choice == 3) { 
                if (people[j].gender > people[j + 1].gender) swap = 1;
            } 
            else if (choice == 4) { 
                if (people[j].height > people[j + 1].height) swap = 1;
            }

            if (swap) {
                temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }

    
    printf("\notsorterovanni:\n");
    printf("imya\t\tgod\tpol\trost\n");
    for (i = 0; i < count; i++) {
        printf("%-15s\t%d\t%c\t%.2f\n", 
               people[i].name, 
               people[i].year, 
               people[i].gender, 
               people[i].height);
    }

    return 0;
}
