#include "key_class.h"

key_class::key_class(int x, colors i)
{
    position = x;
    color_type = i;
    flag_type = none;
}


colors key_class::get_color(){


    return color_type;

}



flag_state key_class::flag_getter(){


return flag_type;


}


void key_class::flag_setter(flag_state x){

flag_type = x;


}










int key_class::get_position(){


    return position;
}



void key_class::peak_keys(){


std::cout << "position =" << position << " color = " << color_reader(color_type) << std::endl;

}

std::string key_class::color_reader(colors x){
using namespace std;
string returnthis;
switch (x){
    case red : returnthis = "red";break;
    case blue : returnthis = "blue"; break;
    case yellow : returnthis = "yellow";break;
    case green : returnthis = "green"; break;
}
return returnthis;
}
