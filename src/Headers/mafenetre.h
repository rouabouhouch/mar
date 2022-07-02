//#define MAFENETRE_H
#ifndef MAFENETRE_H
#include"biblio.h"

class fenetre{
    public:
    //SDL_Renderer* rendere;
    //l'initialisation
    void init_window(const char* titre, int w, int h);
    SDL_Renderer* getRendere();
    //l'affichage
    void draw_window(SDL_Renderer* render);
    //destruction
    void cleanup_window();
    

    private:
    SDL_Window* window;
    SDL_Renderer* rendere;
    
};



#endif //MAFENETRE_H