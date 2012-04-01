Chemistry: main.o
	g++ -g -o Chemistry main.o

main.o:
	g++ -g -c -o main.o main.cpp


clean:
	rm *.o