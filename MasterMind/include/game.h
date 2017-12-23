#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <vector>
#include <key_class.h>
#include <colors.h>
#include "GridToken.h"






class game
{
    public:
        game();
        virtual ~game();

        std::vector<GRIDTOKEN_H::color> run_game(std::vector<GRIDTOKEN_H::color>);
        int black_flags = 0;
        int white_flags = 0;
        std::vector<key_class> mastermind_key;






    private:



    std::vector<key_class> guesses;
    void key_generator();
    void guess_catcher(std::vector<GRIDTOKEN_H::color>);
    void guess_comparison();
    GRIDTOKEN_H::color numberToColor(int x);

    int ATTEMPTS_COUNTER = 0;
};

#endif // GAME_H
