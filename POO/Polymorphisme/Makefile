CFLAGS=-Wall
CC=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: testFigures

testFigures: testFigures.o Figure.o Triangle.o Carre.o Rectangle.o Cercle.o Cube.o Parallelepipede.o Sphere.o
	$(LD) $@ $^

testFigures.o: testFigures.cpp Figure.h Triangle.h Carre.h Rectangle.h Cercle.h Cube.h Parallelepipede.h Sphere.h
	$(CC) $<

Figure.o: Figure.cpp Figure.h
	$(CC) $<

Triangle.o: Triangle.cpp Triangle.h Figure.h
	$(CC) $<

Carre.o: Carre.cpp Carre.h Figure.h
	$(CC) $<

Rectangle.o: Rectangle.cpp Rectangle.h Figure.h
	$(CC) $<

Cercle.o: Cercle.cpp Cercle.h Figure.h
	$(CC) $<

Cube.o: Cube.cpp Cube.h Cube.h
	$(CC) $<

Parallelepipede.o: Parallelepipede.cpp Parallelepipede.h Figure.h
	$(CC) $<

Sphere.o: Sphere.cpp Sphere.h Figure.h
	$(CC) $<

clean:
	rm -f testFigures *.o *.*~

