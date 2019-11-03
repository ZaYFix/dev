CFLAGS=-Wall
CC=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: testPileChar

testPileChar: testPileChar.o PileChar.o
	$(LD) $@ $^

testPileChar.o: testPileChar.cpp PileChar.h
	$(CC) $<

PileChar.o: PileChar.cpp PileChar.h
	$(CC) $<

clean:
	rm -f testPileChar *.o *~

