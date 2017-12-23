#include "game.h"

game::game()
{
    srand(time(NULL));
    key_generator();

}

game::~game()
{
    //dtor
}







std::vector<GRIDTOKEN_H::color> game::run_game(std::vector<GRIDTOKEN_H::color> guess_input)
{

        guess_catcher(guess_input);

        guess_comparison();

                                                        std::cout<<"\n"<<mastermind_key[0].flag_getter()<<" "<<mastermind_key[1].flag_getter()<<" "<< mastermind_key[2].flag_getter() << " " << mastermind_key[3].flag_getter() << std::endl;

        for(int unsigned i=0;i<guess_input.size();)
        {
            guess_input.pop_back();
        }
        for(int unsigned i=0;i<mastermind_key.size();i++)
        {
            guess_input.push_back(mastermind_key[i].flag_getter());
        }

return guess_input;
}








void game::guess_comparison(){
    bool onlycolor = true;

    for(int i =0; i<4;i++)
        { mastermind_key[i].flag_setter(GRIDTOKEN_H::Nothing); mastermind_key[i].claimed = false; guesses[i].claimed = false;
    }

    std::cout<<"\n";
        for (int i=0;i<4;i++)
        {
            std::cout<<guesses[i].get_color();
        }

    for(int i =0; i<4;i++)
        {
//start
        for(int c = 0; c<4;c++)
            {


            if (mastermind_key[i].get_color() == guesses[c].get_color() &&  (mastermind_key[i].claimed == false && guesses[c].claimed ==false))
                {                    //std::cout<<"\nHere\n";


                if(mastermind_key[i].get_position() == guesses[c].get_position())
                    {
                    mastermind_key[i].flag_setter(GRIDTOKEN_H::Black);
                    mastermind_key[i].claimed = true;
                    guesses[c].claimed = true;
                    std::cout<<" Blackflag";


                    }
                else
                    {


                    onlycolor = true;
                    for (int u=c+1; u< (guesses.size());u++)
                        {
                            std::cout<<" \nI:"<<i<<" C:"<<c<<" U:"<<u<<"/"<<guesses.size()-1;

                            if(guesses[u].get_color()==mastermind_key[i].get_color())
                                if(guesses[u].claimed==false)
                                onlycolor = false;

                        }
                        if(onlycolor)
                        {
                            mastermind_key[i].claimed = true;
                            guesses[c].claimed = true;
                            mastermind_key[i].flag_setter(GRIDTOKEN_H::White);
                            std::cout<<" Whtiteflag";

                        }


                    }

                }

            }
        }

    }














void game::guess_catcher(std::vector<GRIDTOKEN_H::color> guess_thrower){

   // int counter = 1;
    guesses.clear();
/*


    while (counter < 5){

    int color_guess;
    std::cout << "Guess the color\n";
    std::cin >> color_guess;
    guesses.push_back(key_class(counter, numberToColor(color_guess)));
    guesses[counter-1].peak_keys();
    counter++;


    }*/

    for (int unsigned i=0;i<guess_thrower.size();i++)
    {
        guesses.push_back(key_class(i+1, guess_thrower[i]));
    }




}


void game::key_generator(){

     for(int i= 0; i<4;i++){
        mastermind_key.push_back(key_class(i+1, GRIDTOKEN_H::color(rand() % 6)));
        std::cout<<mastermind_key[i].get_color()<<" ";
       // mastermind_key[i].peak_keys();

        // PUT RANDOM GENERATOR HERE

    }
  //  mastermind_key.push_back(key_class(1, GRIDTOKEN_H::Red));
  //  mastermind_key.push_back(key_class(2, GRIDTOKEN_H::Red));
  //  mastermind_key.push_back(key_class(3, GRIDTOKEN_H::Blue));
  //  mastermind_key.push_back(key_class(4, GRIDTOKEN_H::Blue));


for(int i= 0; i<4;i++){
        mastermind_key[i].peak_keys();}
}




