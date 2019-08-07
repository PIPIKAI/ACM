#include"pointhead.h"
class line
{
public :
    line(int ,int ,int );
    friend double dis(line ,point);
private :
    int a,b,c;
};
