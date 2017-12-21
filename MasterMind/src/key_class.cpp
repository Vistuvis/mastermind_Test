#include "key_class.h"

key_class::key_class(int x, colors i)
{
    position = x;
    color_type = i;
}

key_class::~key_class()
{
    //dtor
}

void key_class::peak_keys(){


std::cout << "position =" << position << " color = " << color_reader(color_type) << std::endl;

}

std::string key_class::color_reader(colors x){
using namespace std;
switch (x){
 case red : return "red";break;
 case blue : return "blue"; break;
 case yellow : return "yellow";break;
 case green : return "green"; break;

}
}
