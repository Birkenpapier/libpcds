all:
	g++ -c -o ./test_builds/ringbuffer.o ringbuffer.cpp
	g++ -c -o ./test_builds/main.o main.cpp
	g++ -o ./test_builds/ringbuffer_test ./test_builds/ringbuffer.o ./test_builds/main.o

ifeq ($(OS), Windows_NT)
	cls
else
	clear
endif

	./test_builds/ringbuffer_test

linux-lib:
	g++ -shared -o ./test_builds/ringbuffer.so ./test_builds/ringbuffer.o ./test_builds/main.o
	clear
	