#ifndef KEY_CLASS_H
#define KEY_CLASS_H
#include <colors.h>
#include <iostream>
#include <string>


class key_class
{
    public:
        key_class(int x, colors i);
        colors get_color();
        int get_position();



        void flag_setter(flag_state x);
        flag_state flag_getter();
        bool claimed;




        void peak_keys();






    private:


        int position;
        colors color_type;
        flag_state flag_type;
        std::string color_reader(colors x);
};

#endif // KEY_CLASS_H
