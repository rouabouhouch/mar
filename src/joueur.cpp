#include"joueur.h"
#include"biblio.h"

void joueur::init_joueur(SDL_Renderer* render){
    SDL_Surface* ijoueur= SDL_LoadBMP("data/image.bmp");
    if(!ijoueur)
            {
                cout<<"Erreur de chargement de l'ijoueur :"<<SDL_GetError()<< endl;
            }else
            {
                cout<<"ijoueur a ete bien charge hihihi "<< endl;
            }
    monjoueur = SDL_CreateTextureFromSurface(render, ijoueur);

     if(monjoueur==NULL){
         cout<<"erreur de telechargement de monjoueur"<<SDL_GetError()<< endl;

     }else{
        cout<<"telecharge avec succe de monjoueur"<<SDL_GetError()<< endl;
     }
}



void joueur::draw_player(SDL_Renderer* render){
    dst.x=700/2;
    dst.y=600/2;
    dst.h=50;
    dst.w=50;
    SDL_RenderCopy(render, monjoueur, NULL, &dst);
}
void joueur::mouvement_joueur(SDL_Renderer* render,SDL_Rect sol ,SDL_Event event){
if(event.type == SDL_KEYDOWN)
        {
            cout<<"position x = "<< dst.x<< endl;
            cout<<"position y = "<< dst.y<< endl;
            if(event.key.keysym.sym == SDLK_RIGHT)
            {
                cout<<"RIGHT"<< endl;
                collision(sol);
                dst.x=dst.x+10;
            }

             if(event.key.keysym.sym == SDLK_LEFT)
            {
                if(dst.x-10 <= -5 ){
                    cout<<"collision avec la fentre"<< endl;
                }else{
                    cout<<"LEFT"<< endl;
                    collision(sol);
                dst.x=dst.x-10;
                }
                
            }

             if(event.key.keysym.sym == SDLK_UP)
            {
                cout<<"UP"<< endl;
                collision(sol);
                dst.y=dst.y-10;;
            }

             if(event.key.keysym.sym == SDLK_DOWN)
            {
                cout<<"DOWN"<< endl;
                collision(sol);
                dst.y=dst.y+10;
            }
        }

}
void joueur::collision(SDL_Rect sol){
    if(
        dst.x+dst.w >= sol.x &&
        sol.x+sol.w >= dst.x &&
        dst.y+dst.h >= sol.y &&
        sol.y+sol.h >= dst.y
    ){
        cout<<"collision detecte "<<endl;
        cout<<"dst.x : "<< dst.x <<" dst.y : "<<dst.y<< endl;
        cout<<"sol.x : "<< sol.x <<" sol.y : "<<sol.y<< endl;
    }

}
/*
void joueur::gravite(){
    bool touche=false;
    while(touche)
    {
        dst.y=dst.y+1;
        
    }
}
*/