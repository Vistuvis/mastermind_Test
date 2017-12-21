#include "game.h"

game::game()
{


}

game::~game()
{
    //dtor
}







void game::run_game(){

std::cout <<"hellow world\n";
while (true){

        if(ATTEMPTS_COUNTER =10){
            std::cout << "you lost";
        }

        key_generator();
        guess_catcher();
        guess_comparison();
}

}





void game::guess_comparison(){





}











void game::guess_catcher(){

    int counter = 1;
    guesses.clear();



    while (counter < 5){

    int color_guess;
    std::cout << "Guess the color\n";
    std::cin >> color_guess;
    guesses.push_back(key_class(counter, numberToColor(color_guess)));
    guesses[counter-1].peak_keys();
    counter++;


    }




}


void game::key_generator(){

     /*for(int i= 0; i<4;i++){
        mastermind_key.push_back(key_class(1, red));
        mastermind_key[i].peak_keys();

        // PUT RANDOM GENERATOR HERE

    }*/
    mastermind_key.push_back(key_class(1, red));
    mastermind_key.push_back(key_class(2, blue));
    mastermind_key.push_back(key_class(3, green));
    mastermind_key.push_back(key_class(4, yellow));


for(int i= 0; i<4;i++){
        mastermind_key[i].peak_keys();}
}




colors game::numberToColor(int x){

colors returnthis;

    switch (x){

    case 1: returnthis = red; break;
    case 2: returnthis = yellow; break;
    case 3: returnthis = green; break;
    case 4: returnthis = blue; break;
    default: std::cout << "error"; break;

    }

    return returnthis;

}

