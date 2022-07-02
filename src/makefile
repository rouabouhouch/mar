all :test
test:map.o main.o
			g++ -g map.o main.o -o test -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
main.o:map.h main.cpp
			g++ -g -Wall -c main.cpp -o main.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
map.o:map.cpp map.h
			g++ -g -Wall -c map.cpp -o map.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

veryclean : 
			rm *.o  test