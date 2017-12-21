#ifndef SELECTIONGRID_H
#define SELECTIONGRID_H
#include <vector>
#include "GridToken.h"
#include <iostream>

class Selectiongrid
{
    public:
        Selectiongrid(int Tries, int passwordlength);
        virtual ~Selectiongrid();

        std::vector<GridToken> Grid;


        void setcolor(int currentid, GRIDTOKEN_H::color newcolor);

        int getgridsize();

        GRIDTOKEN_H::color getcolor(int x, int y);


    protected:

    private:
    int Xvalues, Yvalues, gridsize;


};

#endif // SELECTIONGRID_H
