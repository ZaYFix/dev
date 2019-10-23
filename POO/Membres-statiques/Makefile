CFLAGS=-Wall
CC=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: testPoint

testPoint: testPoint.o Point.o
	$(LD) $@ $^

testPoint.o: testPoint.cpp Point.h
	$(CC) $<

Point.o: Point.cpp Point.h
	$(CC) $<

clean:
	rm testPoint *.o *.*~

