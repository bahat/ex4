//
// Created by Omer Bahat on 14/01/2023.
//
#include "Mtmchkin.h"


void Mtmchkin::initializePlayers() {
    printEnterTeamSizeMessage();
    int teamSize;
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
        while((!std::cin>>teamSize))
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
        if(!(std::cin >> inputString))
        {
            printInvalidName();
            printInsertPlayerMessage();
            continue;
        }
        int locationOfSpace = inputString.find(" ");
        if(locationOfSpace==-1)
        {
            printInvalidName();
            printInsertPlayerMessage();
            continue;
        }
        else
        {
            playerName = inputString.substr(0, locationOfSpace);
            playerClass = inputString.substr(locationOfSpace + 1);
            for (int i = 0; i < playerName.size(); i++)
            {
                //check name
                completelyValidInput=true;
                if (isntLetter(playerName[i]))
                {
                    printInvalidName();
                    printInsertPlayerMessage();
                    completelyValidInput= false;
                    break;
                }
            }
            if(completelyValidInput)
            {
                //check class
                if(playerClass==Player::NINJA_NAME)
                {
                    m_players.push(std::dynamic_pointer_cast<Player>(std::make_shared<Ninja>(Ninja(playerName))));
                }
                else if(playerClass==Player::HEALER_NAME)
                {
                    m_players.push(std::dynamic_pointer_cast<Player>(std::make_shared<Healer>(Healer(playerName))));
                }
                else if (playerClass==Player::WARRIOR_NAME)
                {
                    m_players.push(std::dynamic_pointer_cast<Player>(std::make_shared<Warrior>(Warrior(playerName))));
                }
                else
                {
                    printInvalidClass();
                    printInsertPlayerMessage();
                    completelyValidInput= false;
                }
            }
        }
    }

}


Mtmchkin::Mtmchkin(const std::string &fileName) {
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
    return std::find(CARD_OPTIONS.begin(), CARD_OPTIONS.end(), cardName)!=CARD_OPTIONS.end();
}

void Mtmchkin::createAndPushNewCard(const std::string cardName) {
    if(cardName==CARD_OPTIONS[0])
    {

        m_cards.push(std::make_shared<Barfight>(Barfight()));
    }
    else if(cardName==CARD_OPTIONS[1])
    {
        m_cards.push(std::make_shared<Dragon>(Dragon()));
    }
    else if(cardName==CARD_OPTIONS[2])
    {
        m_cards.push(std::make_shared<Gremlin>(Gremlin()));
    }
    else if(cardName==CARD_OPTIONS[3])
    {
        m_cards.push(std::make_shared<Mana>(Mana()));
    }
    else if(cardName==CARD_OPTIONS[4])
    {
        m_cards.push(std::make_shared<Merchant>(Merchant()));
    }
    else if(cardName==CARD_OPTIONS[5])
    {
        m_cards.push(std::make_shared<Treasure>(Treasure()));
    }
    else if(cardName==CARD_OPTIONS[6])
    {
        m_cards.push(std::make_shared<Well>(Well()));
    }
    else if(cardName==CARD_OPTIONS[7])
    {
        m_cards.push(std::make_shared<Witch>(Witch()));
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
            m_cards.front()->playCard(m_players.front());
            if(m_players.front()->isKnockedOut())
            {
                m_losers.push_back(m_players.front());
                m_players.pop();
                m_numberOfActivePlayers--;
            }
            else if(m_players.front()->getLevel()==Player::getMaxLevel())
            {
                m_winners.push_back(m_players.front());
                m_players.pop();
                m_numberOfActivePlayers--;
            }
            else
            {
                m_players.push(m_players.front());
                m_players.pop();
            }
            m_cards.push(m_cards.front());
            m_cards.pop();
        }


    }



}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int counter = 1;
    for(int i = 0; i<m_winners.size(); i++)
    {
        printPlayerLeaderBoard(counter, m_winners[i].operator*());
        counter++;
    }
    std::queue<std::shared_ptr<Player>> tempQueue = m_players;
    for(int i = 0; i<m_numberOfActivePlayers; i++)
    {
        printPlayerLeaderBoard(counter, tempQueue.front().operator*());
        tempQueue.push(tempQueue.front());
        tempQueue.pop();
        counter++;
    }
    for(int i = m_losers.size(); i>0;i--)
    {
        printPlayerLeaderBoard(counter, m_losers[i-1].operator*());
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
