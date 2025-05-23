#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


void print_normal(int n) {
    if (n < 10) {
        printf("%d ", n);
    } else {
        
        print_normal(n / 10);
        
        printf("%d ", n % 10);
    }
}

void print_reverse(int n) {
    if (n < 10) {
        printf("%d ", n);
    } else {
        printf("%d ", n % 10);
        print_reverse(n / 10);
    }
}

int main() {
    int number;
    
    printf("vvedite chisla: ");
    scanf("%d", &number);
    
    printf("normalni poryadok: ");
    print_normal(number);
    printf("\n");
    
    printf("obratni poryadok: ");
    print_reverse(number);
    printf("\n");
    
    return 0;
}

