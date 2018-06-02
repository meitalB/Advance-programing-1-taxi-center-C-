a.out:main.o Point.o Node.o Matrix.o Grid.o BFS.o NodeMatrix.o
	g++ main.o Point.o Node.o Matrix.o Grid.o BFS.o NodeMatrix.o

Point.o:Point.cpp Point.h
	g++ -c -std=c++98 Point.cpp

Node.o:Node.cpp Node.h
	g++ -c -std=c++98 Node.cpp

Matrix.o:Matrix.cpp Matrix.h
	g++ -c -std=c++98 Matrix.cpp

Grid.o:Grid.cpp Grid.h
	g++ -c -std=c++98 Grid.cpp

BFS.o:BFS.cpp BFS.h
	g++ -c -std=c++98 BFS.cpp

NodeMatrix.o:NodeMatrix.cpp NodeMatrix.h
	g++ -c -std=c++98 NodeMatrix.cpp

main.o:main.cpp Point.h Node.h Matrix.h Grid.h BFS.h NodeMatrix.h
	g++ -c -std=c++98 main.cpp

clean:
	rm -f *.o a.out
