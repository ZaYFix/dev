TARGET=testTemps

CFLAGS=-Wall
CXX=g++ -g -c $(CFLAGS)
LD=g++ -g -o

all: $(TARGET)

$(TARGET): $(TARGET).o Temps.o
	$(LD) $@ $^

$(TARGET).o: $(TARGET).cpp Temps.h
	$(CXX) $<

Temps.o: Temps.cpp Temps.h
	$(CXX) $<

clean:
	rm -f $(TARGET) *.o *.*~

