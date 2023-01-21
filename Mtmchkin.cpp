//
// Created by Omer Bahat on 14/01/2023.
//
#include "Mtmchkin.h"

#include <memory>

 const std::string HEALER_NAME = "Healer";
 const std::string NINJA_NAME = "Ninja";
 const std::string WARRIOR_NAME= "Warrior";
void Mtmchkin::initializePlayers() {
    printEnterTeamSizeMessage();
    int teamSize=0;

    bool firstIteration = true;
    do {
        if(firstIteration)
        {
            firstIteration = false;
        }
        else
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
        while(!(std::cin>>teamSize))
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    }
    while(teamSize>6 || teamSize<2);
    for(int i = 0; i<teamSize; i++)
    {
        newPlayer();
    }
    m_numberOfActivePlayers = teamSize;


}
void Mtmchkin::newPlayer()
{
    bool completelyValidInput = false;
    printInsertPlayerMessage();
    std::string inputString;
    std::string playerName;
    std::string playerClass;
    while(!completelyValidInput)
    {
        while(!(std::getline(std::cin, inputString))||inputString=="")
        {

        }
        int locationOfSpace = inputString.find(" ");
        if(locationOfSpace==-1)
        {
            printInvalidName();
            continue;
        }
        else
        {
            playerName = inputString.substr(0, locationOfSpace);
            if(playerName.size()>15)
            {
                printInvalidName();
                continue;
            }
            playerClass = inputString.substr(locationOfSpace + 1);
            for (int i = 0; i < static_cast<int>(playerName.length()); i++)
            {
                //check name
                completelyValidInput=true;
                if (isntLetter(playerName[i]))
                {
                    printInvalidName();
                    completelyValidInput= false;
                    break;
                }
            }
            if(completelyValidInput)
            {
                //check class
                if(playerClass==NINJA_NAME)
                {
                    m_players.push_back(std::unique_ptr<Ninja>(new Ninja(playerName)));
                }
                else if(playerClass==HEALER_NAME)
                {
                    m_players.push_back(std::unique_ptr<Healer>(new Healer(playerName)));
                }
                else if (playerClass==WARRIOR_NAME)
                {
                    m_players.push_back(std::unique_ptr<Warrior>(new Warrior(playerName)));
                }
                else
                {
                    printInvalidClass();
                    completelyValidInput= false;
                }
            }
        }
    }

}


Mtmchkin::Mtmchkin(const std::string &fileName) {
    printStartGameMessage();
    initializeDeck(fileName);
    initializePlayers();
    m_numberOfRounds= 0;
}

void Mtmchkin::initializeDeck(const std::string &fileName) {
    std::ifstream deckFile(fileName);
    std::string tempCardName;
    int lineNumber = 0;
    if(deckFile.is_open())
    {
        while(std::getline(deckFile, tempCardName))
        {
            lineNumber++;
            if (isValidCard(tempCardName))
            {
                createAndPushNewCard(tempCardName);
            }
            else
            {
                throw DeckFileFormatError(lineNumber);
            }
        }
        if(lineNumber<MINIMUM_DECK_SIZE)
        {
            throw DeckFileInvalidSize();
        }
    }
    else
    {
        throw DeckFileNotFound();
    }
}

bool Mtmchkin::isValidCard(const std::string cardName) {
    return CARD_OPTIONS.end() != std::find(CARD_OPTIONS.begin(), CARD_OPTIONS.end(), cardName);
}

void Mtmchkin::createAndPushNewCard(const std::string cardName) {
    if(cardName==CARD_OPTIONS[0])
    {

        m_cards.push(std::unique_ptr<Barfight>(new Barfight()));
    }
    else if(cardName==CARD_OPTIONS[1])
    {
        m_cards.push(std::unique_ptr<Dragon>(new Dragon()));
    }
    else if(cardName==CARD_OPTIONS[2])
    {
        m_cards.push(std::unique_ptr<Gremlin>(new Gremlin()));
    }
    else if(cardName==CARD_OPTIONS[3])
    {
        m_cards.push(std::unique_ptr<Mana>(new Mana()));
    }
    else if(cardName==CARD_OPTIONS[4])
    {
        m_cards.push(std::unique_ptr<Merchant>(new Merchant()));
    }
    else if(cardName==CARD_OPTIONS[5])
    {
        m_cards.push(std::unique_ptr<Treasure>(new Treasure()));
    }
    else if(cardName==CARD_OPTIONS[6])
    {
        m_cards.push(std::unique_ptr<Well>(new Well()));
    }
    else if(cardName==CARD_OPTIONS[7])
    {
        m_cards.push(std::unique_ptr<Witch>(new Witch()));
    }
}

void Mtmchkin::playRound() {
    if(isGameOver())
    {
        printGameEndMessage();
    }
    else
    {
        m_numberOfRounds++;
        printRoundStartMessage(m_numberOfRounds);
        int currentRoundActivePlayers = m_numberOfActivePlayers;
        for(int i = 0; i<currentRoundActivePlayers; i++)
        {
            printTurnStartMessage(m_players.front()->getName());
            m_cards.front()->playCard(*m_players.front());
            if(m_players.front()->isKnockedOut())
            {
                m_losers.push_back(std::move(m_players.front()));
                m_players.pop_front();
                m_numberOfActivePlayers--;
            }
            else if(m_players.front()->getLevel()==Player::getMaxLevel())
            {
                m_winners.push_back(std::move(m_players.front()));
                m_players.pop_front();
                m_numberOfActivePlayers--;
            }
            else
            {
                m_players.push_back(std::move(m_players.front()));
                m_players.pop_front();
            }
            m_cards.push(std::move(m_cards.front()));
            m_cards.pop();
        }
        if(m_numberOfActivePlayers==0)
        {
            printGameEndMessage();
        }


    }



}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int counter = 1;
    for(int i = 0; i<static_cast<int>(m_winners.size()); i++)
    {
        printPlayerLeaderBoard(counter, *(m_winners[i].get()));
        counter++;
    }
    for(auto it = m_players.cbegin(); it!=m_players.cend(); it++)
    {
        printPlayerLeaderBoard(counter,*((*it).get()));
        counter++;
    }
    for(int i = m_losers.size(); i>0;i--)
    {
        printPlayerLeaderBoard(counter, *(m_losers[i-1].get()));
        counter++;
    }

}

bool Mtmchkin::isGameOver() const {
    return m_numberOfActivePlayers==0;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_numberOfRounds;
}

bool Mtmchkin::isntLetter(char &letter) {
    return !((letter>='a'&&letter<='z')||(letter>='A'&&letter<='Z'));
}
