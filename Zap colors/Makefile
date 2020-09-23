game: Objects/AssetManager.o Objects/main.o Objects/GameFuncs.o
	g++  Objects/main.o Objects/AssetManager.o Objects/GameFuncs.o  -LSFML/Lib -lsfml-graphics -lsfml-audio  -lsfml-window -lsfml-system -o Output/game.exe

Objects/AssetManager.o: AssetManager.cpp
	g++ AssetManager.cpp -c -ISFML/Include -o Objects/AssetManager.o

Objects/GameFuncs.o: GameFuncs.cpp
	g++ GameFuncs.cpp -c -ISFML/Include -o Objects/GameFuncs.o

Objects/main.o: main.cpp
	g++ main.cpp -c -ISFML/Include -LSFML/Lib -lsfml-graphics -lsfml-audio  -lsfml-window -lsfml-system  -o Objects/main.o