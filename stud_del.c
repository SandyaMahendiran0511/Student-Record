#include "student.h"

static void delete_by_roll(int roll) {
    Student *curr = head, *prev = NULL;

    while (curr != NULL && curr->roll_no != roll) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Record with Roll No %d not found.\n", roll);
        return;
    }

    if (prev == NULL) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
    printf("Record with Roll No %d deleted successfully.\n", roll);
}

void stud_del(void) {
    if (head == NULL) {
        printf("No records available to delete.\n");
        return;
    }

    char choice;
    printf("\nR/r : Delete using Roll Number\n");
    printf("N/n : Delete using Name\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r') {
        int roll;
        printf("Enter Roll Number to delete: ");
        scanf("%d", &roll);
        delete_by_roll(roll);
    } else if (choice == 'N' || choice == 'n') {
        char name[50];
        printf("Enter Name to search: ");
        scanf(" %[^\n]", name);

        Student* curr = head;
        int count = 0;
        printf("\n--------------------------------------\n");
        printf("%-10s %-15s %-10s\n", "Roll No", "Name", "Percentage");
        printf("--------------------------------------\n");
        while (curr != NULL) {
            if (strcmp(curr->name, name) == 0) {
                printf("%-10d %-15s %-10.1f\n", curr->roll_no, curr->name, curr->percentage);
                count++;
            }
            curr = curr->next;
        }
        printf("--------------------------------------\n");

        if (count == 0) {
            printf("No matching records found for name: %s\n", name);
            return;
        }

        int roll;
        printf("Enter Roll Number from the above list to delete: ");
        scanf("%d", &roll);
        delete_by_roll(roll);
    } else {
        printf("Invalid choice!\n");
    }
}