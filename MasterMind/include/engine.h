#ifndef ENGINE_H
#define ENGINE_H
#include "Selectiongrid.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "game.h"

class engine
{
    public:
        engine();
        virtual ~engine();
        int run();
    protected:

    private:

};

#endif // ENGINE_H
