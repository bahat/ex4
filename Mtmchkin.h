#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "utilities.h"
#include "Cards/Card.h"
#include "Cards/BattleCard.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include <queue>
#include <fstream>
#include <array>
class Mtmchkin{
private:
    void initializePlayers();
    void newPlayer();
    std::queue<std::shared_ptr<Player>> m_players;
    std::queue<std::unique_ptr<Card>> m_cards;
    bool isntLetter(char &i);
    void initializeDeck(const std::string &fileName);
    bool isValidCard(const std::string cardName);
    void createAndPushNewCard(const std::string cardName);
    Mtmchkin(const Mtmchkin &toCopy);//in here so won't be available from outside
    Mtmchkin& operator=(const Mtmchkin &toAssign);//in here so won't be available from outside
    int m_numberOfRounds;
    int m_numberOfActivePlayers;
    std::vector<std::shared_ptr<Player>> m_winners;
    std::vector<std::shared_ptr<Player>> m_losers;

protected:
    static const std::string HEALER_NAME;
    static const std::string NINJA_NAME;
    static const std::string WARRIOR_NAME;
    static const int NUM_OF_CARD_OPTIONS = 8;
    static const std::array<std::string, NUM_OF_CARD_OPTIONS> CARD_OPTIONS;
    static const int MINIMUM_DECK_SIZE = 5;


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

const std::array<std::string, Mtmchkin::NUM_OF_CARD_OPTIONS> Mtmchkin::CARD_OPTIONS = {"Barfight", "Dragon", "Gremlin", "Mana", "Merchant", "Treasure", "Well", "Witch"};

#endif /* MTMCHKIN_H_ */
