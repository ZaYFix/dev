MAKE=make
CC=g++
RM=rm
MAKEDEP=makedepend

GENERIC_CFLAGS := 
WARN := 
GENERIC_LIBS := 

TARGET := vendanges

HEADERFILES	:= $(wildcard *.h)
SRCFILES	:= $(wildcard *.cpp)
#OBJFILES	:= $(patsubst %.cpp, %.o, $(SRCFILES))
OBJFILES := main.o robot.o

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

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $^ $(CFLAGS) $(GENERIC_LIBS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	$(RM) -f $(TARGET) main.o *~

dep:
	$(MAKEDEP) $(CFLAGS) -Y -s "# Dependances by 'make dep'" *.cpp 2> /dev/null
	rm -f Makefile.bak
# Dependances by 'make dep'

robot.o: robot.h
main.o: robot.h
