//
// Created by Omer Bahat on 14/01/2023.
//
#include "Mtmchkin.h"

void Mtmchkin::initializePlayers() {
    printEnterTeamSizeMessage();
    int teamSize;
    while((!std::cin>>teamSize) || teamSize>6 || teamSize<2)
    {
        printInvalidTeamSize();
    }
    std::string newPlayerName, newPlayerType;
    for(int i = 0; i<teamSize; i++)
    {
        newPlayer();
    }


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
            continue;
        }
        int locationOfSpace = inputString.find(" ");
        if(locationOfSpace=-1)
        {
            printInvalidName();
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
                    completelyValidInput= false;
                    break;
                }
            }
            if(completelyValidInput)
            {
                //check class
                if(playerClass==Player::WARRIOR_NAME || playerClass==Player::HEALER_NAME || playerClass==Player::NINJA_NAME)
                {}
                else
                {
                    printInvalidClass();
                    completelyValidInput= false;
                }
            }
        }
    }
    const std::string playerNameConst = playerName;
    std::shared_ptr<Player> playerToAdd(nullptr);
    //
    if(playerClass==Player::NINJA_NAME)
    {
        playerToAdd= std::shared_ptr<Player>(new Ninja(playerName));
    }
    else if(playerClass==Player::HEALER_NAME)
    {
        players.push(std::shared_ptr<Player>(new Healer(playerName)));
    }
    else if (playerClass==Player::WARRIOR_NAME)
    {
        players.push(std::shared_ptr<Player>(new Warrior(playerName)));
    }
}


Mtmchkin::Mtmchkin(const std::string &fileName) {
    initializePlayers();
}

void Mtmchkin::playRound() {

}

void Mtmchkin::printLeaderBoard() const {

}

bool Mtmchkin::isGameOver() const {
    return false;
}

int Mtmchkin::getNumberOfRounds() const {
    return 0;
}

bool Mtmchkin::isntLetter(char &letter) {
    return !((letter>='a'&&letter<='z')||(letter>='A'&&letter<='Z'));
}
