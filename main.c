#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

typedef struct {
    char title[MAX_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

void loadTasks() {
    FILE *file = fopen("tasks.txt", "r");

    if (file == NULL)
        return;

    while (fscanf(file, "%d|%99[^\n]\n",
                  &tasks[taskCount].completed,
                  tasks[taskCount].title) == 2) {
        taskCount++;
    }

    fclose(file);
}

void saveTasks() {
    FILE *file = fopen("tasks.txt", "w");

    if (file == NULL) {
        printf("Blad zapisu pliku!\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%d|%s\n",
                tasks[i].completed,
                tasks[i].title);
    }

    fclose(file);
}

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Osiagnieto limit zadan.\n");
        return;
    }

    getchar();

    printf("Nazwa zadania: ");
    fgets(tasks[taskCount].title,
          MAX_LENGTH,
          stdin);

    tasks[taskCount].title[
        strcspn(tasks[taskCount].title, "\n")
    ] = '\0';

    tasks[taskCount].completed = 0;

    taskCount++;

    saveTasks();

    printf("Zadanie dodane.\n");
}

void showTasks() {
    if (taskCount == 0) {
        printf("Brak zadan.\n");
        return;
    }

    printf("\n===== LISTA ZADAN =====\n");

    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%c] %s\n",
               i + 1,
               tasks[i].completed ? 'X' : ' ',
               tasks[i].title);
    }
}

void completeTask() {
    int index;

    showTasks();

    printf("\nNumer zadania: ");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("Niepoprawny numer.\n");
        return;
    }

    tasks[index - 1].completed = 1;

    saveTasks();

    printf("Zadanie oznaczone jako wykonane.\n");
}

void deleteTask() {
    int index;

    showTasks();

    printf("\nNumer zadania do usuniecia: ");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("Niepoprawny numer.\n");
        return;
    }

    for (int i = index - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    taskCount--;

    saveTasks();

    printf("Zadanie usuniete.\n");
}

void menu() {
    int choice;

    do {
        printf("\n===== TASK MANAGER =====\n");
        printf("1. Dodaj zadanie\n");
        printf("2. Wyswietl zadania\n");
        printf("3. Oznacz jako wykonane\n");
        printf("4. Usun zadanie\n");
        printf("5. Wyjdz\n");
        printf("Wybor: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                showTasks();
                break;

            case 3:
                completeTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                printf("Koniec programu.\n");
                break;

            default:
                printf("Nieprawidlowa opcja.\n");
        }

    } while (choice != 5);
}

int main() {
    loadTasks();
    menu();
    return 0;
}
