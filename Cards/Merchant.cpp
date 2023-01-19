//
// Created by Omer Bahat on 12/01/2023.
//

#include "Merchant.h"
#include <assert.h>
void Merchant::playCard(Player &player) {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::string inputString;
    bool inputInFormat = false;
    int inputInt;
    while(!inputInFormat)
    {
        try 
        {
            getline(std::cin, inputString);
            inputInt = std::stoi(inputString);
        }
        catch (std::exception&)
        {
            printInvalidInput();
            continue;
        }
        if(inputInt!=BUY_HP && inputInt!=BUY_NOTHING && inputInt!= BUY_FORCE)
        {
            printInvalidInput();
        }
        else
        {
            inputInFormat = true;
        }
    }
    assert(inputInt==BUY_HP||inputInt==BUY_NOTHING||inputInt==BUY_FORCE);
    int priceToBuy;
    switch (inputInt) {
        case BUY_HP:
            priceToBuy = HP_PRICE;
            break;
        case BUY_FORCE:
            priceToBuy = FORCE_PRICE;
            break;
        default:
            priceToBuy = NO_PURCHASE_PRICE;
    }
    if(!player.pay(priceToBuy))
    {
        printMerchantInsufficientCoins(std::cout);
    }
    else
    {
        switch (inputInt) {
            case BUY_HP:
                player.heal(HEAL_AMOUNT);
                break;
            case BUY_FORCE:
                player.buff(BUFF_AMOUNT);
                break;
        }
        printMerchantSummary(std::cout, player.getName(), inputInt, priceToBuy);
    }



}

Merchant::Merchant() : Card("Merchant") {}
