MAKE=make
CXX=g++
RM=rm
MAKEDEP=makedepend

GENERIC_CFLAGS := 
WARN := 
GENERIC_LIBS := 

TARGET := recette-secrete

HEADERFILES	:= $(wildcard *.h)
SRCFILES	:= $(wildcard *.cpp)
OBJFILES	:= $(patsubst %.cpp, %.o, $(SRCFILES))

#OBJFILES := $(TARGET).o

ifndef VERSION
VERSION = RELEASE
endif

ifeq (CHEAT, $(VERSION))
   CFLAGS = $(GENERIC_CFLAGS) $(WARN) -DCHEAT
else
   CFLAGS = $(GENERIC_CFLAGS)
endif

.PHONY: clean $(TARGET)

all: $(TARGET)

cheat:
	@$(MAKE) VERSION=CHEAT

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

$(TARGET): $(OBJFILES)
	$(CXX) -o $(TARGET) $^ $(CFLAGS) $(GENERIC_LIBS)

clean: 
	$(RM) -f $(TARGET) $(OBJFILES) *~

dep:
	$(MAKEDEP) $(CFLAGS) -Y -s "# Dependances by 'make dep'" *.c 2> /dev/null
	rm -f Makefile.bak
# Dependances by 'make dep'

tonneau.o: tonneau.h
main.o: tonneau.h
