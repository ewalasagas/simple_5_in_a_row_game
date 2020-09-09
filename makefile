output: game.o GBoard.o 
	g++ game.o GBoard.o -g -o Game

game.o: game.cpp
	g++ -c game.cpp

GBoard.o: GBoard.cpp GBoard.hpp
	g++ -c GBoard.cpp
clean:
	rm *.o Game
