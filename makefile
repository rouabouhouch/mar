all :bin/test
bin/test:src/biblio.h obj/main.o obj/mafenetre.o obj/map.o obj/joueur.o
			g++ -g obj/main.o obj/mafenetre.o obj/map.o obj/joueur.o -o bin/test -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
obj/main.o:src/biblio.h src/main.cpp src/mafenetre.h src/map.h src/joueur.h
			g++ -g -Wall -c src/main.cpp -o obj/main.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
obj/mafenetre.o:src/biblio.h src/mafenetre.cpp src/mafenetre.h src/joueur.h
			g++ -g -Wall -c src/mafenetre.cpp -o obj/mafenetre.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
obj/joueur.o:src/biblio.h src/joueur.cpp src/joueur.h
			g++ -g -Wall -c src/joueur.cpp -o obj/joueur.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
obj/map.o:src/biblio.h src/map.cpp src/map.h
			g++ -g -Wall -c src/map.cpp -o obj/map.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

veryclean : 
			rm obj/*.o  bin/test