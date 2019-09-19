CXX=g++

main: main.o echange.o
	$(CXX) -o $@ $^

main.o : main.cpp echange.h
	$(CXX) -c $<

echange.o: echange.cpp echange.h
	$(CXX) -c $<

clean:
	rm -f main *.o
