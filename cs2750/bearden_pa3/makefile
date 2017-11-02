CC = gcc
CFLAGS = -g -Wall
TARGET = main
OBJS = main.o min.o max.o sum.o avg.o
$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
min.o: min.c
	$(CC) $(CFLAGS) -c min.c
max.o: max.c
	$(CC) $(CFLAGS) -c max.c
sum.o: sum.c
	$(CC) $(CFLAGS) -c sum.c
avg.o: avg.c
	$(CC) $(CFLAGS) -c avg.c
clean:
	/bin/rm -f *.o $(TARGET)
