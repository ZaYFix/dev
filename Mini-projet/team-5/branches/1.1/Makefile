CFLAGS=-Wall
CXX=g++ -c
LD=g++ -o

TARGET=main

FICHIER1=JeuPoulePoule
FICHIER2=Joueur
FICHIER3=IHM

all: $(TARGET)

$(TARGET): main.o $(FICHIER1).o $(FICHIER2).o $(FICHIER3).o
	$(LD) $@ $^

main.o: main.cpp $(FICHIER1).h
	$(CXX) $<

$(FICHIER1).o: $(FICHIER1).cpp $(FICHIER1).h $(FICHIER2).h $(FICHIER3).h
	$(CXX) $<

$(FICHIER2).o: $(FICHIER2).cpp $(FICHIER2).h
	$(CXX) $<

$(FICHIER3).o: $(FICHIER3).cpp $(FICHIER3).h $(FICHIER1).h
	$(CXX) $<

clean:
	rm -f $(TARGET) *.o *.*~
