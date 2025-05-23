#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100]; // Массив для хранения входной строки
    char *token; // Указатель для токенов
    double result = 0.0; // Переменная для результата
    int first = 1; // Флаг для первого числа

    // Запрашиваем выражение у пользователя
    printf("vvedite virajeniya: ");
    fgets(input, 100, stdin);

    // Удаляем символ новой строки, если он есть
    input[strcspn(input, "\n")] = 0;

    // Разбиваем строку на токены, используя пробел как разделитель
    token = strtok(input, " ");

    while (token != NULL) {
        // Проверяем, является ли токен числом
        if (token[0] == '+' || token[0] == '-') {
            // Если токен - оператор, пропускаем его
            token = strtok(NULL, " ");
            if (token == NULL) break; // Если нет числа после оператора, выходим

            double number = atof(token); // Преобразуем строку в число

            // Если это первое число, учитываем унарный минус
            if (first) {
                result = (input[0] == '-') ? -number : number;
                first = 0;
            } else {
                // Выполняем бинарную операцию
                if (input[token - input - 2] == '+') {
                    result += number;
                } else if (input[token - input - 2] == '-') {
                    result -= number;
                }
            }
        } else {
            // Если токен - число (без оператора перед ним)
            double number = atof(token);
            if (first) {
                result = number;
                first = 0;
            }
        }

        // Получаем следующий токен
        token = strtok(NULL, " ");
    }

    // Выводим результат
    printf("rezultat: %.2f\n", result);

    return 0;
}
