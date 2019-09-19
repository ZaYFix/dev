CXX=g++

main: main.o fiche.o
	$(CXX) -o $@ $^
main.o: main.cpp fiche.cpp
	$(CXX) -c $<


clean:
	rm -f main *.o
