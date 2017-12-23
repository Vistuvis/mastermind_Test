#include "GridToken.h"

GridToken::GridToken(int x, int y, int idtemp)
{
    xpos = x;
    ypos = y;
    id = id;
    tokencolor = Nothing;
}

void GridToken::setcolor(color newcolor)
{
    tokencolor = newcolor;
}
GridToken::~GridToken()
{
    //dtor
}
