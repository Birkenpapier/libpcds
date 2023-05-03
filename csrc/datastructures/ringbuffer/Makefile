all:
	g++ -c -o ./test_builds/ringbuffer.o ringbuffer.cpp
	g++ -c -o ./test_builds/main.o main.cpp
	g++ -o ./test_builds/ringbuffer_test ./test_builds/ringbuffer.o ./test_builds/main.o
	clear
	./test_builds/ringbuffer_test