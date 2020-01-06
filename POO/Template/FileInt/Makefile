CFLAGS=-Wall
CC=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: testFileInt

testFileInt: testFileInt.o FileInt.o
	$(LD) $@ $^

testFileInt.o: testFileInt.cpp FileInt.h
	$(CC) $<

FileInt.o: FileInt.cpp FileInt.h
	$(CC) $<

clean:
	rm -f testFileInt *.o *.*~

