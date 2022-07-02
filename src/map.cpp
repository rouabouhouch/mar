#include"biblio.h"
#include"map.h"

int lev1[3][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0},
    {1,1,1,0,1,1,1,0,1,1}
};

void map::init_map(SDL_Renderer* rendere){
    background= SDL_LoadBMP("data/ciel2.bmp");
    if(!background)
            {
                cout<<"Erreur de chargement de l'background :"<<SDL_GetError()<< endl;
            }else
            {
                cout<<"background a ete bien charge hihihi "<< endl;
            }
    monBackground = SDL_CreateTextureFromSurface(rendere, background);

     if(monBackground==NULL){
         cout<<"erreur de telechargement de monBackground"<<SDL_GetError()<< endl;

     }else{
        cout<<"telecharge avec succe de monBackground"<<SDL_GetError()<< endl;
     }

     int x,y;
SDL_Surface* solf = SDL_LoadBMP("data/sol.bmp");
            if(!solf)
            {
                cout<<"Erreur de chargement de l'solf :"<<SDL_GetError()<< endl;
            }else
            {
                cout<<"solf a ete bien charge hihi "<< endl;
            }
            sol= SDL_CreateTextureFromSurface(rendere,solf); 
        for(x=0; x<3;x++){
            for(y=0; y<10;y++){
            ter[x][y]=lev1[x][y];
        }
    }
}

void map::draw_map(SDL_Renderer* rendere){
    
    SDL_RenderCopy(rendere, monBackground, NULL, NULL);
    int x, y;
    
    for(x=0; x<3;x++){
        for(y=0; y<10;y++){
            int sol_aff;
            sol_aff=ter[x][y];
            if(sol_aff==1){
               dst_sol.x=y*50;
                    
                if(x==1){
                    dst_sol.y=350;
                    
                }else if (x==2)
                {
                    dst_sol.y=400;
                    
                }
                dst_sol.h=40;
                dst_sol.w=40;
                SDL_RenderCopy(rendere, sol, NULL, &dst_sol);
            }
            
        }
    }
}