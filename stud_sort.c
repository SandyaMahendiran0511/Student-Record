#include "student.h"

static void swap_data(Student* a, Student* b) {
    int temp_roll = a->roll_no;
    char temp_name[50];
    float temp_pct = a->percentage;

    strcpy(temp_name, a->name);

    a->roll_no = b->roll_no;
    strcpy(a->name, b->name);
    a->percentage = b->percentage;

    b->roll_no = temp_roll;
    strcpy(b->name, temp_name);
    b->percentage = temp_pct;
}

void stud_sort(void) {
    if (head == NULL || head->next == NULL) {
        printf("Not enough records to sort.\n");
        return;
    }

    char choice;
    printf("\nN/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &choice);

    int swapped;
    Student* ptr1;
    Student* lptr = NULL;

    if (choice == 'N' || choice == 'n') {
        do {
            swapped = 0;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (strcmp(ptr1->name, ptr1->next->name) > 0) {
                    swap_data(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        printf("List sorted by Name successfully.\n");
    } else if (choice == 'P' || choice == 'p') {
        do {
            swapped = 0;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->percentage < ptr1->next->percentage) {
                    swap_data(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        printf("List sorted by Percentage successfully.\n");
    } else {
        printf("Invalid choice!\n");
    }
}