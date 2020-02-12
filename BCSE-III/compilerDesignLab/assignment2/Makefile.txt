A2.out: A2.o get_type.o
	g++ A2.o get_type.o -o A2.out -g

A2.o: A2.cpp
	g++ -c A2.cpp -g

get_type.o: get_type.cpp get_type.h
	g++ -c get_type.cpp -g

run: 
	./A2.out

clean:
	rm -f *.o A2.out
