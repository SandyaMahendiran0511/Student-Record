#include "student.h"

static Student* find_by_roll(int roll) {
    Student* curr = head;
    while (curr != NULL) {
        if (curr->roll_no == roll) return curr;
        curr = curr->next;
    }
    return NULL;
}

static void apply_modification(Student* target) {
    char choice;
    printf("\nN/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    if (choice == 'N' || choice == 'n') {
        printf("Enter New Name: ");
        scanf(" %[^\n]", target->name);
        printf("Name updated successfully.\n");
    } else if (choice == 'P' || choice == 'p') {
        printf("Enter New Percentage: ");
        scanf("%f", &target->percentage);
        printf("Percentage updated successfully.\n");
    } else {
        printf("Invalid choice!\n");
    }
}

void stud_mod(void) {
    if (head == NULL) {
        printf("No records available to modify.\n");
        return;
    }

    char choice;
    printf("\nR/r : Roll Number\n");
    printf("N/n : Name\n");
    printf("P/p : Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    Student* target = NULL;

    if (choice == 'R' || choice == 'r') {
        int roll;
        printf("Enter Roll Number: ");
        scanf("%d", &roll);
        target = find_by_roll(roll);
        if (target == NULL) {
            printf("Record not found.\n");
            return;
        }
    } else if (choice == 'N' || choice == 'n') {
        char name[50];
        printf("Enter Name: ");
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
            printf("No records found.\n");
            return;
        }

        int roll;
        printf("Enter Roll Number to modify: ");
        scanf("%d", &roll);
        target = find_by_roll(roll);
    } else if (choice == 'P' || choice == 'p') {
        float pct;
        printf("Enter Percentage: ");
        scanf("%f", &pct);

        Student* curr = head;
        int count = 0;
        printf("\n--------------------------------------\n");
        printf("%-10s %-15s %-10s\n", "Roll No", "Name", "Percentage");
        printf("--------------------------------------\n");
        while (curr != NULL) {
            if (curr->percentage == pct) {
                printf("%-10d %-15s %-10.1f\n", curr->roll_no, curr->name, curr->percentage);
                count++;
            }
            curr = curr->next;
        }
        printf("--------------------------------------\n");

        if (count == 0) {
            printf("No records found.\n");
            return;
        }

        int roll;
        printf("Enter Roll Number to modify: ");
        scanf("%d", &roll);
        target = find_by_roll(roll);
    } else {
        printf("Invalid choice!\n");
        return;
    }

    if (target != NULL) {
        apply_modification(target);
    } else {
        printf("Invalid Roll Number selected.\n");
    }
}