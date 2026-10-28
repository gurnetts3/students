CC = gcc
CFLAGS = -Wall -std=c99

students: main.o students.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c students.h
	$(CC) $(CFLAGS) $< -c

students.o: students.c students.h
	$(CC) $(CFLAGS) $< -c

clean:
	rm -f students students.o main.o

tar: clean
	tar -czvf quiz3SG.tar.gz Makefile main.c students.c students.h

.PHONY: clean tar
