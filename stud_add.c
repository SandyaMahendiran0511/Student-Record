#include "student.h"

static int get_smallest_roll(void) {
    int roll = 1;
    while (1) {
        int found = 0;
        Student* curr = head;
        while (curr != NULL) {
            if (curr->roll_no == roll) {
                found = 1;
                break;
            }
            curr = curr->next;
        }
        if (!found) return roll;
        roll++;
    }
}

void stud_add(void) {
    Student* new_node = (Student*)malloc(sizeof(Student));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        return;
    }

    new_node->roll_no = get_smallest_roll();

    printf("Enter Student Name: ");
    scanf(" %[^\n]", new_node->name);
    printf("Enter Percentage: ");
    scanf("%f", &new_node->percentage);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Record added successfully with Roll No: %d\n", new_node->roll_no);
}