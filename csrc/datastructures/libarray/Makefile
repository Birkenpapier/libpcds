all:
	g++ -c -o ./test_builds/libarray.o libarray.cpp
	g++ -c -o ./test_builds/libarray_test.o libarray_test.cpp
	g++ -o ./test_builds/libarray_test ./test_builds/libarray.o ./test_builds/libarray_test.o

ifeq ($(OS), Windows_NT)
	cls
else
	clear
endif

	./test_builds/libarray_test

linux-lib:
	g++ -shared -o ./test_builds/libarray.so ./test_builds/libarray.o
	clear
	