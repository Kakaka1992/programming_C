#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Функция обработчика сигналов
void signal_handler(int signum) {
    switch (signum) {
        case SIGABRT:
            printf("poluchen signal SIGABRT (Abort)");
            break;
        case SIGFPE:
            printf("poluchen signal SIGFPE (Floating-Point Exception)");
            break;
        case SIGILL:
            printf("poluchen signal SIGILL (Illegal Instruction)");
            break;
        case SIGINT:
            printf("poluchen signal SIGINT (Interrupt)");
            break;
        case SIGSEGV:
            printf("poluchen signal SIGSEGV (Segmentation Violation)");
            break;
        case SIGTERM:
            printf("poluchen signal SIGTERM (Termination)");
            break;
        default:
            printf("poluchen neizvestni signal %d", signum);
    }
}

int main() {
    // Регистрируем обработчики для сигналов
    signal(SIGABRT, signal_handler);
    signal(SIGFPE, signal_handler);
    signal(SIGILL, signal_handler);
    signal(SIGINT, signal_handler);
    signal(SIGSEGV, signal_handler);
    signal(SIGTERM, signal_handler);

    int choice;
    printf("viberite signal dlya vozbujdeniya:");
    printf("1 - SIGABRT 2 - SIGFPE 3 - SIGILL 4 - SIGINT 5 - SIGSEGV 6 - SIGTERM0 - viiti");

    while (1) {
        printf("vash vibor: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                raise(SIGABRT);
                break;
            case 2:
                raise(SIGFPE);
                break;
            case 3:
                raise(SIGILL);
                break;
            case 4:
                raise(SIGINT);
                break;
            case 5:
                raise(SIGSEGV);
                break;
            case 6:
                raise(SIGTERM);
                break;
            case 0:
                printf("vihod iz programmi.");
                exit(0);
            default:
                printf("neverni vibor poprobuite snova.");
        }
    }

    return 0;
}
