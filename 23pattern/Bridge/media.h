#ifndef MEDIA_H
#define MEDIA_H

class media
{

    public:
        virtual ~media();
        virtual void media_play()=0;
    protected:
        media();
    private:

};

class music:public media
{
    public:
        music();
        ~music();
        void media_play();
    protected:
    private:
};
class movie:public media
{
    public:
        movie();
        ~movie();
        void media_play();
    protected:
    private:
};
#endif
