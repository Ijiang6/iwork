#ifndef PLAYER_H
#define PLAYER_H
class media;

class player
{
    public:
       virtual  ~player();
       virtual void play()=0;
    protected:
         player();
    private:
    media *m_pmedia;

};


class music_player:public player
{
    public:
        music_player(const media * ms);
        ~music_player();
        void play();
    protected:
    private:
};
class movie_player:public player
{

    public:
        movie_player(const media* mv);
        ~movie_player();
        void play();
    protected:

    private:

};
#endif
