#include "student.h"

void stud_show(void) {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n--------------------------------------\n");
    printf("%-10s %-15s %-10s\n", "Roll No", "Name", "Percentage");
    printf("--------------------------------------\n");

    Student* curr = head;
    while (curr != NULL) {
        printf("%-10d %-15s %-10.1f\n", curr->roll_no, curr->name, curr->percentage);
        curr = curr->next;
    }
    printf("--------------------------------------\n");
}