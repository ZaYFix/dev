MAKE=make
CXX=g++
RM=rm
MAKEDEP=makedepend

GENERIC_CFLAGS := 
GENERIC_LIBS := 

TARGET := mesure

HEADERFILES	:= $(wildcard *.h)
SRCFILES	:= $(wildcard *.cpp)
OBJFILES	:= $(patsubst %.cpp, %.o, $(SRCFILES))

.PHONY: clean $(TARGET)

all: $(TARGET)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(GENERIC_CFLAGS)

$(TARGET): $(OBJFILES)
	$(CXX) -o $(TARGET) $^ $(GENERIC_CFLAGS) $(GENERIC_LIBS)

clean: 
	$(RM) -f $(TARGET) $(OBJFILES) *~

dep:
	$(MAKEDEP) $(CFLAGS) -Y -s "# Dependances by 'make dep'" *.cpp 2> /dev/null
	rm -f Makefile.bak
