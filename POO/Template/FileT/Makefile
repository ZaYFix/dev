CFLAGS=-Wall
CC=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: testFileT 

testFileT: testFileT.o FileT.o
	$(LD) $@ $^

testFileT.o: testFileT.cpp FileT.h FileT.tcc
	$(CC) $<

FileT.o: FileT.cpp FileT.h FileT.tcc
	$(CC) $<

clean:
	rm -f testFileT *.o *.*~

