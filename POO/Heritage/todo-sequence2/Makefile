CXX=g++

GENERIC_CFLAGS := 
GENERIC_LIBS := 

TARGET=histoire-2

HEADERFILES	:= $(wildcard *.h)
SRCFILES	:= $(wildcard *.cpp)
OBJFILES	:= $(patsubst %.cpp, %.o, $(SRCFILES))

.PHONY: clean $(TARGET)

all: $(TARGET)

%.o: %.cpp %.h
	$(CXX) -c $< $(GENERIC_CFLAGS) -o $@

$(TARGET): $(OBJFILES)
	$(CXX) $(GENERIC_CFLAGS) $(GENERIC_LIBS) -o $(TARGET) $^

clean: 
	rm -f $(TARGET) $(OBJFILES) *~
