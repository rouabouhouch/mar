#include"biblio.h"
#include"mafenetre.h"
#include"map.h"
#include"joueur.h"

using namespace std;



//linitialisation et la creation du la fenetre et du render
void fenetre::init_window(const char* titre, int w, int h){

    if(0 != SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)){
            cout<<"erreur d'initialisation"<< SDL_GetError() << endl;
    }else{
         cout<<"initialisation réussi"<< endl;
    }

    window = SDL_CreateWindow(titre, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h,  SDL_WINDOW_SHOWN);
    
    if(NULL == window)
    {
        cout<<"Erreur SDL_CreateWindow : "<< SDL_GetError();
    }else{
        cout<<"la creation de la fenetre est bien faite"<< endl;
    }

    rendere =SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);

    if(NULL==rendere)
   {
       cout<<"un probleme dean la creation du rendere"<< SDL_GetError()<< endl;
   }
   else{
       cout<<"notre rendere est bien creer"<< endl ;
   }

    
}
//comme il est en prive on doit faire une fonction qui le retourne pour qu'on puisse l'utiliser
SDL_Renderer* fenetre::getRendere(){
    return rendere;
}

//l'affichage de la fenetre et le rendere
void fenetre::draw_window(SDL_Renderer* render){
    SDL_JoystickEventState(SDL_ENABLE);
    map map;
    map.init_map(render);
    joueur joueur;
    joueur.init_joueur(render);
    
    
   //map.draw_map(getRendere());
   //mon isrruning sert à laisse la boucle activer
   
    bool isrunning=true;
    
    SDL_Event event;
      //on affiche notre joueur
    joueur.draw_player(render);
     while(isrunning){

        while(SDL_PollEvent(&event)){
            //le programme va faire ce qui est donne dans ces fonction faites par l'utilisateur
             switch(event.type){
                 //si l'utilisateur appuie sur x pour quitter la fenetre
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_CLOSE)
                    isrunning = SDL_FALSE;
                 break;
                 //si l'utilisateur appuisur un des fleche pour bouger le joueur
            case SDL_KEYDOWN: // Un événement de type touche enfoncée est effectué
                joueur.mouvement_joueur(render,map.dst_sol ,event);
                
                
                }
                //ici on nettoie notre render
                SDL_RenderClear(render);
                 //on affiche notre map
            map.draw_map(render);
            
            //on redonne la nouvelle position du joueur
         SDL_RenderCopy(render, joueur.monjoueur, NULL, &joueur.dst);
    //on affiche le tt
    SDL_RenderPresent(render);
        
     }
}
}

void fenetre::cleanup_window(){
    SDL_DestroyRenderer(getRendere());
    rendere = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
}