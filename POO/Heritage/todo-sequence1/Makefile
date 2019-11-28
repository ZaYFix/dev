TARGET = histoire-1

CFLAGS = -Wall
CXX = g++ $(CFLAGS) -c
LD = g++ -o

all: $(TARGET)

$(TARGET): $(TARGET).o humain.o
	$(LD) $@ $^

$(TARGET).o: $(TARGET).cpp humain.h
	$(CXX) $<

humain.o: humain.cpp humain.h
	$(CXX) $<

clean:
	rm -f $(TARGET) *.o *~