#ifndef KEY_CLASS_H
#define KEY_CLASS_H
#include <colors.h>
#include <iostream>
#include <string>
#include "GridToken.h"
class key_class
{
    public:
        key_class(int x, GRIDTOKEN_H::color i);
        GRIDTOKEN_H::color get_color();
        int get_position();



        void flag_setter(GRIDTOKEN_H::color x);
        GRIDTOKEN_H::color flag_getter();
        bool claimed;




        void peak_keys();






    private:


        int position;
        GRIDTOKEN_H::color color_type;
        GRIDTOKEN_H::color flag_type;
        std::string color_reader(GRIDTOKEN_H::color x);
};

#endif // KEY_CLASS_H
