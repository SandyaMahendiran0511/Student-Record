#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int roll_no;
    char name[50];
    float percentage;
    struct Student* next;
} Student;

extern Student* head;

// Function Prototypes
void stud_add(void);
void stud_del(void);
void stud_show(void);
void stud_mod(void);
void stud_save(void);
void stud_load(void);
void stud_sort(void);

#endif