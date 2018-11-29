#include"media.h"
#include"player.h"
#include<iostream>
using namespace std;
int main(int argc, char **argv)
{
    media *pmusic=new music();
    media *pmovie=new movie();
player *pmc=new music_player(pmusic);
player *pmo=new movie_player(pmovie);

pmc->play();
pmo->play();
delete pmc;
delete pmo;
delete pmusic;
delete pmovie;

return 0;

}
