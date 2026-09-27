#include "student.h"

void stud_save(void) {
    FILE* fp = fopen("student.dat", "wb");
    if (!fp) {
        printf("Error opening file for writing!\n");
        return;
    }

    Student* curr = head;
    while (curr != NULL) {
        fwrite(curr, sizeof(Student) - sizeof(Student*), 1, fp);
        curr = curr->next;
    }

    fclose(fp);
    printf("Records saved successfully to student.dat\n");
}

void stud_load(void) {
    FILE* fp = fopen("student.dat", "rb");
    if (!fp) return;

    Student temp;
    while (fread(&temp, sizeof(Student) - sizeof(Student*), 1, fp) == 1) {
        Student* new_node = (Student*)malloc(sizeof(Student));
        new_node->roll_no = temp.roll_no;
        strcpy(new_node->name, temp.name);
        new_node->percentage = temp.percentage;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            Student* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
    }

    fclose(fp);
}