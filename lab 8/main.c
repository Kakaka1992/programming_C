#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 50 // Максимум 50 человек
#define MAX_NAME 30   // Максимум 30 символов в имени

// Структура для человека
typedef struct {
    char name[MAX_NAME]; // Имя
    int year;           // Год рождения
    char gender;       // Пол ('M' или 'F')
    float height;      // Рост в метрах
} Person;

int main() {
    Person people[MAX_PEOPLE];
    int count = 0; 
	int i, j; // Количество людей

    // Открываем файл
    FILE *file = fopen("people.txt", "r");
    if (!file) {
        printf("Не могу открыть файл!\n");
        return 1;
    }

    // Читаем данные из файла
    while (count < MAX_PEOPLE && 
           fscanf(file, "%s %d %c %f\n", 
                  people[count].name, &people[count].year, 
                  &people[count].gender, &people[count].height) == 4) {
        count++;
    }
    fclose(file);

    // Выбор поля для сортировки
    int choice;
    printf("po chemu sorterovat?\n");
    printf("1 - got rojdeniya\n2 - imya\n3 - pol\n4 - rost\n");
    printf("vash vibor: ");
    scanf("%d", &choice);

    // Простая сортировка пузырьком
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            int swap = 0;
            if (choice == 1) { // Сортировка по году
                if (people[j].year > people[j + 1].year) swap = 1;
            } else if (choice == 2) { // Сортировка по имени
                if (strcmp(people[j].name, people[j + 1].name) > 0) swap = 1;
            } else if (choice == 3) { // Сортировка по полу
                if (people[j].gender > people[j + 1].gender) swap = 1;
            } else if (choice == 4) { // Сортировка по росту
                if (people[j].height > people[j + 1].height) swap = 1;
            }

            // Обмен элементов
            if (swap) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }

    // Вывод результатов
    printf("\notsortirovanni danni:\n");
    printf("imya\tgod\tpol\trost\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%d\t%c\t%.2f\n", 
               people[i].name, people[i].year, 
               people[i].gender, people[i].height);
    }

    return 0;
}
