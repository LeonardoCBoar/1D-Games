game: Objects/AssetManager.o Objects/main.o Objects/Map.o Objects/Visual.o
	g++  Objects/main.o Objects/AssetManager.o Objects/Map.o  Objects/Visual.o -LSFML/Lib -lsfml-graphics -lsfml-audio  -lsfml-window -lsfml-system -o Output/game.exe

Objects/AssetManager.o: AssetManager.cpp
	g++ AssetManager.cpp -c -ISFML/Include -o Objects/AssetManager.o

Objects/Map.o: Map.cpp
	g++ Map.cpp -c -ISFML/Include -o Objects/Map.o

Objects/Visual.o: Visual.cpp
	g++ Visual.cpp -c -ISFML/Include -o Objects/Visual.o -lsfml-graphics -lsfml-window

Objects/main.o: main.cpp
	g++ main.cpp -c -ISFML/Include -LSFML/Lib -lsfml-graphics -lsfml-audio  -lsfml-window -lsfml-system  -o Objects/main.o