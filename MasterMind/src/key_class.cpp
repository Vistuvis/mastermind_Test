#include "key_class.h"

key_class::key_class(int x, GRIDTOKEN_H::color i)
{
    position = x;
    color_type = i;
    flag_type = GRIDTOKEN_H::Nothing;
}


GRIDTOKEN_H::color key_class::get_color(){


    return color_type;

}



GRIDTOKEN_H::color key_class::flag_getter(){


return flag_type;


}


void key_class::flag_setter(GRIDTOKEN_H::color x){

flag_type = x;


}










int key_class::get_position(){


    return position;
}



void key_class::peak_keys(){


//std::cout << "position =" << position << " color = " << color_reader(color_type) << std::endl;

}

