#include "Selectiongrid.h"

Selectiongrid::Selectiongrid(int Tries, int passwordlength)
{
    Xvalues = passwordlength;
    Yvalues = Tries;


    int current = 0;
    for(int i = 0; i<Tries; i++)
    {
        for(int o = 0; o<passwordlength; o++)
        {
            Grid.push_back(GridToken(i, o, current));
            current++;
        }
    }
    gridsize = current;
}

void Selectiongrid::setcolor(int currentid, GRIDTOKEN_H::color newcolor)
{
      Grid[currentid].tokencolor = newcolor;
}

GRIDTOKEN_H::color Selectiongrid::getcolor(int x, int y)
{
    int current=0;
    int id;
    for(int i = 0; i<Selectiongrid::Yvalues; i++)
    {
        for(int o = 0; o<Selectiongrid::Xvalues; o++)
        {
            if (i==y && o==x)
                id = current;
            current++;
        }
    }
    return Grid[id].tokencolor;

}

int Selectiongrid::getgridsize()
{
    return gridsize;
}



Selectiongrid::~Selectiongrid()
{
    //dtor
}
