CC = g++
RM = rm
MAKEDEP = makedepend
DISTRIBUTION=$(shell cat /etc/os-release | grep VERSION_ID | cut -d '=' -f2)

SRC_INCLUDES = -I../src/
ifeq ("16.04", $(DISTRIBUTION))
	INCLUDES = -I. $(SRC_INCLUDES) `cppunit-config --cflags`
endif
ifeq ("18.04",$(DISTRIBUTION))
	INCLUDES = -I. $(SRC_INCLUDES) `pkg-config --cflags cppunit`
endif
GENERIC_CFLAGS = -g -O2 $(INCLUDES)
ifeq ("16.04", $(DISTRIBUTION))
	GENERIC_LIBS = `cppunit-config --libs`
endif
ifeq ("18.04",$(DISTRIBUTION))
	GENERIC_LIBS = `pkg-config --libs cppunit`
endif

TARGET=testsUnitairesEstChiffre
TESTS_UNITAIRES = ../src/exemple.o

HEADERFILES	:= $(wildcard *.h)
SRCFILES	:= $(wildcard *.cpp)
OBJFILES	:= $(patsubst %.cpp, %.o, $(SRCFILES))

.PHONY: clean $(TARGET)

all: $(TARGET)

%.o: %.cpp %.h
	$(CXX) -c $< $(GENERIC_CFLAGS) -o $@

$(TARGET): $(OBJFILES)
	$(CXX) -o $(TARGET) $^ $(TESTS_UNITAIRES) $(GENERIC_CFLAGS) $(GENERIC_LIBS)

clean: 
	rm -f $(TARGET) $(OBJFILES) *~
