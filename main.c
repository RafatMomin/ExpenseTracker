#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold expense details
typedef struct {
    char description[50];
    float amount;
} Expense;

// Function prototypes
void addExpense(Expense *expenses, int *count);
void listExpenses(Expense *expenses, int count);
void showTotalExpenses(Expense *expenses, int count);

int main() {
    Expense expenses[100];
    int count = 0;
    int choice;

    while (1) {
        // Display menu
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Show Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                listExpenses(expenses, count);
                break;
            case 3:
                showTotalExpenses(expenses, count);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add an expense
void addExpense(Expense *expenses, int *count) {
    if (*count >= 100) {
        printf("Expense list is full!\n");
        return;
    }

    printf("Enter expense description: ");
    getchar(); // To consume the newline character left by scanf
    fgets(expenses[*count].description, sizeof(expenses[*count].description), stdin);
    // Remove newline character from fgets input
    size_t len = strlen(expenses[*count].description);
    if (len > 0 && expenses[*count].description[len - 1] == '\n') {
        expenses[*count].description[len - 1] = '\0';
    }

    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully.\n");
}

// Function to list all expenses
void listExpenses(Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses to show.\n");
        return;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

// Function to show the total of all expenses
void showTotalExpenses(Expense *expenses, int count) {
    float total = 0.0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("Total expenses: $%.2f\n", total);
}
