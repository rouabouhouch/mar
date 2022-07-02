#ifndef JOUEUR_H
#include"biblio.h"
using namespace std;

class joueur{
    public:
    int x_j, y_j,x_v,y_v;
    SDL_Texture* monjoueur;
    SDL_Rect dst;
    void init_joueur(SDL_Renderer* render);
    void mouvement_joueur(SDL_Renderer* render,SDL_Rect sol,SDL_Event event);
    void draw_player(SDL_Renderer* render);
    //void touchepresse(SDL_Event event);
    void collision(SDL_Rect dst);
    void gravite();
};
#endif // !JOUEUR_H
