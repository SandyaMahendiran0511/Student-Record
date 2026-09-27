# Student Record Management System

A modular, file-backed Student Record Management System written in C. This program utilizes a dynamic linked list for in-memory data manipulation and handles binary file operations for persistent storage.

## Key Features

- Automatic Roll Number Assignment: Automatically assigns the smallest available positive integer roll number to prevent gaps.
- Dynamic Linked List: Memory-efficient record handling using dynamic node allocation.
- Search & Filter Operations: Locate student records by Roll Number, Name, or Percentage.
- Multi-Field Sorting: In-memory linked list sorting by Name (Alphabetical) or Percentage (Descending) using an optimized Bubble Sort algorithm.
- Data Persistence: Automatic binary file loading on launch and manual saving to maintain state between sessions.
- Modular Architecture: Divided into individual function modules for high maintainability.

## File Architecture

- student.h: Core structure definitions, global head pointer, and function prototypes.
- main.c: Interactive menu system and program entry point.
- stud_add.c: Dynamic creation of new student records and roll number calculation.
- stud_del.c: Record deletion by Roll Number or Name search.
- stud_show.c: Formatted output for listing student records.
- stud_mod.c: Modification of student fields (Name or Percentage).
- stud_save.c: Binary file read/write operations to student.dat.
- stud_sort.c: In-memory linked list node sorting logic.
- Makefile: Build rules for compilation and cleanup.

## Program Menu Options

- A / a: Add New Record
- D / d: Delete a Record
- S / s: Show the List
- M / m: Modify a Record
- T / t: Sort the List
- V / v: Save
- E / e: Exit Program (with prompt to save before freeing memory)

## Build Instructions

Using Make:
  make

Manual GCC Compilation:
  gcc main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c -o student

Run Program:
  ./student

Clean Build Artifacts:
  make clean
