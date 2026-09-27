CC = gcc
CFLAGS = -Wall -g
TARGET = student
OBJS = main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_save.o stud_sort.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) student.dat