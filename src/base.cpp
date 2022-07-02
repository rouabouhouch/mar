#include"biblio.h"
#include"mafenetre.h"
using namespace std;

int main(int argc, char *argv[])
{   
    //d'abord on initialise sdl vide(y compris cote image et cote son)
    //le point de depart
    if(0 != SDL_Init(SDL_INIT_VIDEO)){
            cout<<"erreur d'initialisation"<< SDL_GetError() << endl;
    }else{
         cout<<"initialisation réussi"<< endl;
    }

    //sdl est initialisé du coup on creer notre premiere fenetre
    /*
SDL_Window* SDL_CreateWindow(const char* title, int x, int y,  int  w,  int h,  Uint32 flags);

    -title est une chaine de caractères et correspond au nom de la fenêtre ;
    -x et y correspondent respectivement aux positions de la fenêtre sur l’axe x et y de l’écran, le point (0, 0) étant placé en haut à gauche (les valeurs SDL_WINDOWPOS_UNDEFINED et SDL_WINDOWPOS_CENTERED peuvent être passées en paramètre pour indiquer de placer la fenêtre à n’importe quelle position sur cet axe ou de la centrer sur cet axe) ;
    -w et h correspondent à la largeur (width) et à la hauteur (height) de la fenêtre ;
    -flags correspond à une série de drapeaux qui permettent de choisir des options pour la fenêtre.
    */

    SDL_Window* window = SDL_CreateWindow("notre permiere fenetre", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 600,  SDL_WINDOW_SHOWN);
    //on sassure que la fenetre est bien creer 
    if(NULL == window)
    {
        cout<<"Erreur SDL_CreateWindow : "<< SDL_GetError();
    }else{
        cout<<"la creation de la fenetre est bien faite"<< endl;
    }


    //notre fenetre est bien creer, cool! elle est vide d
    //du coup on doit creer ce quon appel un rendere plutot c'est l'espace où nous allons pouvoir dessiner, écrire..
    //pour ça , la structure est:
    /*
        SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index , Uint32 flags);
        windows: c'est notre fenetre crée en haut
        index: c'est toujours -1
        flag :le plus recommende c'est SDL_RENDERER_ACCELERATED
    */
   //lets go on cree notre rendere

   SDL_Renderer* rendere =SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
   //c'est fait notre rendere est cree
   //maitenant on sassure qu'il est bien creer
   if(NULL==rendere)
   {
       cout<<"un probleme dean la creation du rendere"<< SDL_GetError()<< endl;
   }
   else{
       cout<<"notre rendere est bien creer"<< endl ;
   }
   //sil le rendere est cree c bien jusqu'a ici
   //mais il faut l'afficher du coup on utilise la fonction de "sdl SDL_RenderPresent()"
   //et bien sur le parametre passe est le rendere creer

   //SDL_RenderPresent(rendere);

   //il ya le concepte de texture :une texture est un rectangle de pixel independant du render
   //il y a aussi le concepte de surface c'est aussi une sorte de texture mais nous on l'utiliser pour afficher des images
   //du coup pour affiche l'image on doit 
   //creer une surface dont on va stocker l'image
   //et pour l'afficher on la converti en texture

    //ici on cree une surface dont on stocke notre image à afficher
   SDL_Surface* image = SDL_LoadBMP("/home/aneos/Bureau/lifap4/projetpartie3/data/image.bmp");
            if(!image)
            {
                cout<<"Erreur de chargement de l'image :"<<SDL_GetError()<< endl;
            }else
            {
                cout<<"limage a ete bien charge hihihi "<< endl;
            }

    //ici on convertie notre surface en texture pour l'afficher
    //La texture monImage contient maintenant l'image importée
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(rendere,image); 
    //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
    //SDL_FreeSurface(image); 
    //pour afficher notre texture on utilise SDL_copi qui prend on parametre 
    //sdl_rect source et destination
    //source c les inofrmation initiale de notre texture
    //destination c comment et ou on veut l'afficher 
    //du coup on creer nos deux rectangle
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.h=256;
    src.w=256;
    SDL_Rect dst;
    dst.x=700/2;
    dst.y=600/2;
    dst.h=50;
    dst.w=50;
    //et pour les autres parametres c facile
    //on a notre render
    //et on a notre texture
    SDL_RenderCopy(rendere, monImage, &src, &dst);
    //et ici l'affichage finale du render
    //il faut faire tres attention à ces etapes parce que ils sont liées entre eux
    //apres je vais definir ça comme class sdl pour que ça soit plus claire et lisible
    SDL_RenderPresent(rendere);
    //ici on declare un boolean
    //on va le considere comme notre jeux en mode ON
    bool isrunning=true;
    //ici on creer notre evenement
    SDL_Event event;
    //cette boucle dit: tant que mon jeux est toujours vraie (il tourne encore)
    //fais moi ça et ça .....
    while(isrunning){
        //cette deuxieme boucle est d'utilisatio que notre fentre ne se ferme pas tans qu'on l'as pas decide
        while(SDL_PollEvent(&event)){
            //et ici elle se ferme quand on appui sur le boutton x en haut a droite dans la fenetre
            if(event.type==SDL_QUIT)
            //et c'est ici que mon jeux arrete de tourner et ma fentre se ferme
                isrunning= false;
        }
    }

        
    ////le point de fin
    //désallouer et quitter proprement la SDL
    //SDL_Delay(3000);
    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);
    //SDL_Quit();    
    return 0;
}