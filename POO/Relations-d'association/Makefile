TARGET = commande
TARGET1 = iteration1
TARGET2 = iteration2
TARGET3 = iteration3

CFLAGS = -Wall
CXX = g++ $(CFLAGS) -c 
LD = g++ -o

all: 

$(TARGET1): $(TARGET1).o Article.o Ligne.o
	$(LD) $@ $^

$(TARGET1).o: $(TARGET1).cpp Article.h Ligne.h
	$(CXX) $<

$(TARGET2): $(TARGET2).o Commande.o Article.o Ligne.o
	$(LD) $@ $^

$(TARGET2).o: $(TARGET2).cpp Commande.h Article.h Ligne.h
	$(CXX) $<

$(TARGET3): $(TARGET3).o Client.o Commande.o Article.o Ligne.o
	$(LD) $@ $^

$(TARGET3).o: $(TARGET3).cpp Client.h Commande.h Article.h Ligne.h
	$(CXX) $<

$(TARGET): $(TARGET).o Client.o Commande.o Article.o Ligne.o
	$(LD) $@ $^

$(TARGET).o: $(TARGET).cpp Client.h Commande.h Article.h Ligne.h
	$(CXX) $<

Article.o: Article.cpp Article.h
	$(CXX) $<

Ligne.o: Ligne.cpp Ligne.h Article.h
	$(CXX) $<

Commande.o: Commande.cpp Commande.h
	$(CXX) $<

Client.o: Client.cpp Client.h
	$(CXX) $<

clean:
	rm -f $(TARGET) $(TARGET1) $(TARGET2) $(TARGET3) *.o *~

