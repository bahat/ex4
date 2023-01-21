//
// Created by omer.bahat on 1/21/23.
//
#include "Mtmchkin.h"

int main()
{
    try {
        Mtmchkin game("deck.txt");
        while(!game.isGameOver()) 
        {
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() <<std::endl;
    }
    return 0;
}