#ifndef MAP_H
#include"biblio.h"

using namespace std;

class map{
    public:
    int ter[3][10];
    SDL_Texture* sol;
    SDL_Rect dst_sol;
    void init_map(SDL_Renderer* rendere);
    SDL_Surface* background;
    SDL_Texture* monBackground;
    void draw_map(SDL_Renderer* rendere);
    
    
    
};

#endif // !MAP_H
