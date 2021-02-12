slither: main.cpp
	g++ -std=c++11  UI.cpp game.cpp Score.cpp Obstacles.cpp Snake.cpp Food.cpp -lncurses -o Slither && ./Slither

rebuild: 
	rm -f Slither
	g++ -std=c++11 main.cpp UI.cpp Score.cpp Obstacles.cpp game.cpp Snake.cpp Food.cpp -lncurses -o Slither && ./Slither
