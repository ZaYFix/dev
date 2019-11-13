CFLAGS=-Wall
CXX=g++ -c
LD=g++ -o
TARGET=main
TARGET1=Joueur
TARGET2=Carte
TARGET3=JeuPoulePoule
TARGET4=IHM

all: $(TARGET)

$(TARGET): $(TARGET).o $(TARGET1).o $(TARGET2).o $(TARGET3).o $(TARGET4).o
	$(LD) $@ $^

$(TARGET).o: $(TARGET).cpp
	$(CXX) $<

$(TARGET1).o: $(TARGET1).cpp $(TARGET1).h
	$(CXX) $<

$(TARGET2).o: $(TARGET2).cpp $(TARGET2).h
	$(CXX) $<

$(TARGET3).o: $(TARGET3).cpp $(TARGET3).h
	$(CXX) $<

$(TARGET4).o: $(TARGET4).cpp $(TARGET4).h
	$(CXX) $<
clean:
	rm -f $(TARGET) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) *.o *.*~
