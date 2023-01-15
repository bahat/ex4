#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "utilities.h"
#include "Cards/Card.h"
#include "Players/Player.h"
#include "Cards/BattleCard.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include <queue>
class Mtmchkin{

    void initializePlayers();
    void newPlayer();
    std::queue<std::shared_ptr<Player>> m_players;
    bool isntLetter(char &i);
protected:
    static const std::string HEALER_NAME;
    static const std::string NINJA_NAME;
    static const std::string WARRIOR_NAME;
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


};



#endif /* MTMCHKIN_H_ */
