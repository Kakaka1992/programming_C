#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("ne udalos otcrit input.txt\n");
        return 1;
    }

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("ne udalos sozdat output.txt\n");
        return 1;
    }

    char surname[50], name[50], patronymic[50];
    int birth_year;
    int i=0;
    while (fscanf(input, "%s %s %s %d", 
                surname, name, patronymic, &birth_year) != EOF) {
		i++;
        
        printf(" file sting s=%d = %s %s %s %d \n",i, surname, name, patronymic, birth_year);
        if (birth_year > 1980) {
            fprintf(output, "%s %s %s %d\n", 
                   surname, name, patronymic, birth_year);
        }
        birth_year = 0;
    }
    
    fclose(input);
    fclose(output);

    printf("\n");
    return 0;
}
