#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <vector>
#include <key_class.h>
#include <colors.h>







class game
{
    public:
        game();
        virtual ~game();
        void run_game();

        int black_flags = 0;
        int white_flags = 0;







    private:


    std::vector<key_class> mastermind_key;
    std::vector<key_class> guesses;
    void key_generator();
    void guess_catcher();
    void guess_comparison();
    colors numberToColor(int x);

    int ATTEMPTS_COUNTER = 0;
};

#endif // GAME_H
