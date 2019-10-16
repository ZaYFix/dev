CFLAGS=-Wall
CXX=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: testPoint

testPoint: testPoint.o Point.o
	$(LD) $@ $^

testPoint.o: testPoint.cpp Point.h
	$(CXX) $<

Point.o: Point.cpp Point.h
	$(CXX) $<

clean:
	rm testPoint *.o *.*~

