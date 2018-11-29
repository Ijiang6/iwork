#inlcude"player.h"
#include<iostream>
#include"media.h"
using namespace std;

player::player()
{
    m_pmedia=NULL;
}
player::~player()
{
    if(m_pmedia==NULL)
    {
        return;
    }
    delete m_pmedia;
}

music_player::~music_player()
{

}

music_player::music_player(const media *pm)
{
    if(m_pmedia)
    {
        delete m_pmedia;
    }
    m_pmedia=pm;
}

void music_player::play()
{
    if(m_pmedia==NULL)
    {
        return;
    }
    m_pmedia->media_play();
}
movie_player::~movie_player()
{

}
movie_player::movie_player(const media *pm)
{
    if(m_pmedia)
    {
        delete m_pmedia;
    }
    m_pmedia=pm;
}

void movie_player::play()
{
    if(m_pmedia==NULL)
    {
        return;
    }
    m_pmedia->media_play();
}
