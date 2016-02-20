CC= g++
CPPFLAGS= -Wall -I /usr/local/include
LDFLAGS= -L /usr/local/lib
SOURCES= matrix.cpp
TESTS=$(SOURCES:.cpp=_test.cpp)

all:
	$(CC) $(SOURCES) -o matrix.o
main:
	$(CC) $(SOURCES) main.cpp -o main.o
test:
	$(CC) $(CPPFLAGS) $(LDFLAGS) -lcgreen++ $(TESTS) -o test.o
clean:
	rm *o
