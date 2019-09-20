CXX=g++

GENERIC_CFLAGS := 
GENERIC_LIBS := 

TARGET1=mastermind
TARGET2=mastermind-cheat

HEADERFILES	:= $(wildcard *.h)
SRCFILES	:= $(wildcard *.cpp)
OBJFILES	:= $(patsubst %.cpp, %.o, $(SRCFILES))

.PHONY: clean $(TARGET)

all: $(TARGET1) $(TARGET2)

%.o: %.cpp %.h
	$(CXX) -o $@ -c $< $(GENERIC_CFLAGS) 

$(TARGET1): $(OBJFILES) mastermind.o
	$(CXX) -o $(TARGET1) $(GENERIC_CFLAGS) $(GENERIC_LIBS) $^

$(TARGET2): $(OBJFILES) mastermind-cheat.o
	$(CXX) -o $(TARGET2) $(GENERIC_CFLAGS) $(GENERIC_LIBS) $^

clean: 
	rm -f $(TARGET1) $(TARGET2) $(OBJFILES) *~
