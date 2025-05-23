#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100]; // ������ ��� �������� ������� ������
    char *token; // ��������� ��� �������
    double result = 0.0; // ���������� ��� ����������
    int first = 1; // ���� ��� ������� �����

    // ����������� ��������� � ������������
    printf("vvedite virajeniya: ");
    fgets(input, 100, stdin);

    // ������� ������ ����� ������, ���� �� ����
    input[strcspn(input, "\n")] = 0;

    // ��������� ������ �� ������, ��������� ������ ��� �����������
    token = strtok(input, " ");

    while (token != NULL) {
        // ���������, �������� �� ����� ������
        if (token[0] == '+' || token[0] == '-') {
            // ���� ����� - ��������, ���������� ���
            token = strtok(NULL, " ");
            if (token == NULL) break; // ���� ��� ����� ����� ���������, �������

            double number = atof(token); // ����������� ������ � �����

            // ���� ��� ������ �����, ��������� ������� �����
            if (first) {
                result = (input[0] == '-') ? -number : number;
                first = 0;
            } else {
                // ��������� �������� ��������
                if (input[token - input - 2] == '+') {
                    result += number;
                } else if (input[token - input - 2] == '-') {
                    result -= number;
                }
            }
        } else {
            // ���� ����� - ����� (��� ��������� ����� ���)
            double number = atof(token);
            if (first) {
                result = number;
                first = 0;
            }
        }

        // �������� ��������� �����
        token = strtok(NULL, " ");
    }

    // ������� ���������
    printf("rezultat: %.2f\n", result);

    return 0;
}
