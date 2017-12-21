#include "game.h"

game::game()
{
    srand(time(NULL));


}

game::~game()
{
    //dtor
}







void game::run_game(){

while (true){

        if (ATTEMPTS_COUNTER == 10){
            std::cout << "you lost";
            }

        key_generator();
        guess_catcher();
        guess_comparison();
        std::cout<<mastermind_key[0].flag_getter()<<" "<<mastermind_key[1].flag_getter()<<" "<< mastermind_key[2].flag_getter() << " " << mastermind_key[3].flag_getter() << std::endl;
        ATTEMPTS_COUNTER++;

}

}








void game::guess_comparison(){

    for(int i =0; i<4;i++){ mastermind_key[i].flag_setter(none); mastermind_key[i].claimed = false;}

    for(int i =0; i<4;i++){

        for(int c = 0; c<4;c++){
            if (mastermind_key[i].get_color() == guesses[c].get_color() &&  mastermind_key[i].flag_getter() != black)
                {
// possibly set a hook to signify a mastermind key is claimed; move black flags up in algorithm binding everything to guessses


                if(mastermind_key[i].get_position() == guesses[c].get_position())
                    {
                    mastermind_key[i].flag_setter(black);
                    mastermind_key[i].claimed = true;
                    }
                else if(mastermind_key[i].claimed == false){
                    mastermind_key[i].flag_setter(white);
                    mastermind_key[i].claimed = true;
                }

                }

            }
        }

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

     for(int i= 0; i<4;i++){
        mastermind_key.push_back(key_class(i+1, colors(rand() % 4)));
       // mastermind_key[i].peak_keys();

        // PUT RANDOM GENERATOR HERE

    }
    //mastermind_key.push_back(key_class(1, red));
    //mastermind_key.push_back(key_class(2, red));
    //mastermind_key.push_back(key_class(3, green));
    //mastermind_key.push_back(key_class(4, yellow));


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

