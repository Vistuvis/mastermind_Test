#ifndef KEY_CLASS_H
#define KEY_CLASS_H
#include <colors.h>
#include <iostream>
#include <string>


class key_class
{
    public:
        key_class(int x, colors i);
        virtual ~key_class();


        void peak_keys();






    private:

        int position;
        colors color_type;
        std::string color_reader(colors x);
};

#endif // KEY_CLASS_H
