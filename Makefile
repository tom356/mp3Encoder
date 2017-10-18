CC= g++
CFLAGS = -c

encoder: main.o InputParser.o
	$(CC) main.o InputParser.o -o encoder
	
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

InputParser.o: InputParser.cpp InputParser.h
	$(CC) $(CFLAGS) InputParser.cpp
	
clean:
	rm *.o encoder