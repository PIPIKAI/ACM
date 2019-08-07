#ifndef POINTHEAD_H_INCLUDED
#define POINTHEAD_H_INCLUDED
class point
{
private :
    int x,y;
public :
    point(int x=0,int y=0);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
};



#endif // POINTHEAD_H_INCLUDED
