#include"biblio.h"
#include"mafenetre.h"
#include"map.h"
using namespace std;

int main(int argc, char *argv[])
{
     fenetre fenetre;
     fenetre.init_window("FakeMario",700,600);
     fenetre.draw_window(fenetre.getRendere());
     //SDL_Renderer* monrendere= fenetre.getRendere();

     fenetre.cleanup_window();

     return 0;
}