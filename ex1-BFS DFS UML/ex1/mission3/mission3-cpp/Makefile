a.out:main.o Node.o
	g++ main.o Node.o

Node.o:Node.cpp Node.h
	g++ -c -std=c++98 Node.cpp

main.o:main.cpp Node.h
	g++ -c -std=c++98 main.cpp

clean:
	rm -f *.o a.out
