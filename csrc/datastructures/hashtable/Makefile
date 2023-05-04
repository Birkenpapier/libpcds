OBJS = main.o HashTable.o LinkedList.o
CC = g++
DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

all: main
# cls
	./main

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o: main.cpp HashTable.h
	$(CC) $(CFLAGS) main.cpp

HashTable.o: HashTable.cpp HashTable.h LinkedList.h
	$(CC) $(CFLAGS) HashTable.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CC) $(CFLAGS) LinkedList.cpp

clean:
	rm -f *.o *~ main
