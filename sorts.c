#include <stdio.h>
#include <string.h>

#define MAX_NAMES 20
#define MAX_LENGTH 100

// Function to perform bubble sort
void bubbleSort(char names[MAX_NAMES][MAX_LENGTH], int n, int ascending) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Track if a swap was made
        for (int j = 0; j < n - i - 1; j++) {
            // Ascending order
            if (ascending && strcmp(names[j], names[j + 1]) > 0) {
                char temp[MAX_LENGTH];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
                swapped = 1;
            }
            // Descending order
            else if (!ascending && strcmp(names[j], names[j + 1]) < 0) {
                char temp[MAX_LENGTH];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
                swapped = 1;
            }
        }
        if (!swapped) break; // Stop if already sorted
    }
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH] = {
        "Oliver Smith", "Emma Johnson", "Ava Williams", "Liam Brown",
        "Sophia Jones", "Isabella Garcia", "Mia Martinez", "Amelia Rodriguez",
        "Lucas Hernandez", "Ethan Lopez", "Jackson Wilson", "Aiden Lee",
        "Ella Anderson", "Grace Thomas", "Chloe Taylor", "Harper Moore",
        "Scarlett Jackson", "Victoria White", "Madison Harris", "Luna Martin"
    };
    
    int order;
    char sortOrder[10]; // Increased buffer size for safety

    printf("Enter 'asc' for ascending or 'desc' for descending order: ");
    fgets(sortOrder, sizeof(sortOrder), stdin);
    sortOrder[strcspn(sortOrder, "\n")] = 0; // Remove trailing newline

    // Determine order
    if (strcmp(sortOrder, "asc") == 0) {
        order = 1;  // Ascending
    } else if (strcmp(sortOrder, "desc") == 0) {
        order = 0;  // Descending
    } else {
        printf("Invalid input! Please enter 'asc' or 'desc'.\n");
        return 1;
    }

    // Sort names
    bubbleSort(names, MAX_NAMES, order);

    // Print sorted names
    printf("Sorted names:\n");
    for (int i = 0; i < MAX_NAMES; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
