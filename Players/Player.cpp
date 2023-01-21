//
// Created by Omer Bahat on 12/01/2023.
//

#include "Player.h"
#include "utilities.h"

static const std::string WITCH_NAME="Witch";
static const std::string GREMLIN_NAME="Gremlin";
static const std::string DRAGON_NAME="Dragon";
static const std::string HEALER_NAME="Healer";
static const std::string NINJA_NAME="Ninja";
static const std::string WARRIOR_NAME="Warrior";

Player::Player(const std::string &name, const std::string &type):
        m_name(name),
        m_maxHP(Player::DEFAULT_MAX_HP),
        m_force(Player::DEFAULT_FORCE),
        m_HP(Player::DEFAULT_MAX_HP),
        m_coins(Player::DEFAULT_COINS),
        m_level(Player::DEFAULT_LEVEL),
        m_type(type)
{
}

void Player::levelUp()
{
    if(m_level>=Player::MAX_LEVEL)
    {

    }
    else
    {
        m_level+=1;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int buffBy) {
    if(buffBy<=ZERO)
    {

    }
    else
    {
        m_force+=buffBy;
    }
}

void Player::heal(int healBy) {
    if(healBy<=ZERO)
    {

    }
    else
    {
        m_HP+=healBy;
        if(m_HP>m_maxHP)
        {
            m_HP=m_maxHP;
        }
    }
}

void Player::damage(int damageBy) {
    if(damageBy<=ZERO)
    {

    }
    else
    {
        if(damageBy>=m_HP)
        {
            m_HP=0;
        }
        else
        {
            m_HP-=damageBy;
        }
    }
}

bool Player::isKnockedOut() const {
    return m_HP==ZERO;
}

void Player::addCoins(int toAdd) {
    if(toAdd<=ZERO)
    {

    }
    else
    {
        m_coins+=toAdd;
    }
}

bool Player::pay(int price) {
    if(price<=ZERO)
    {
        return true;
    }
    else
    {
        if(price>m_coins)
        {
            return false;
        }
        else
        {
            m_coins-=price;
            return true;
        }
    }
}

int Player::getAttackStrength() {
    return m_level+m_force;
}


int Player::getMaxLevel() {
    return MAX_LEVEL;
}

void Player::useBarfightCard() {
    damage(BARFIGHT_DAMAGE);
}

void Player::useWellCard() {
    damage(WELL_DAMAGE);
}

std::string Player::getName() const{
    return this->m_name;
}

void Player::killPlayer() {
    m_HP = 0;
}

int Player::getCoins() const {
    return m_coins;
}

void Player::deBuff(int deBuffBy) {
    if(m_force-deBuffBy <0)
    {
        m_force = 0;
    }
    else
    {
        m_force-=deBuffBy;
    }
}

int Player::getForce() const {
    return m_force;
}

int Player::getHP() const {
    return m_HP;
}

std::string Player::getType() const {
    return m_type;
}

std::ostream &operator<<(std::ostream &os, const Player &player)
{
    printPlayerDetails(os, player.getName(), player.getType(), player.getLevel(), player.getForce(), player.getHP(), player.getCoins());
    return os;
}
