MAKE=make
CXX=g++
RM=rm

TARGET := recette-secrete

HEADERFILES	:= $(wildcard *.h)
SRCFILES	:= $(wildcard *.cpp)
OBJFILES	:= $(patsubst %.cpp, %.o, $(SRCFILES))

all: $(TARGET)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

$(TARGET): $(OBJFILES) tonneau.o
	$(CXX) -o $(TARGET) $^

clean: 
	$(RM) -f $(TARGET) main.o *~

dep:
	$(MAKEDEP) $(CFLAGS) -Y -s "# Dependances by 'make dep'" *.c 2> /dev/null
	rm -f Makefile.bak
