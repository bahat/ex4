//
// Created by Omer Bahat on 12/01/2023.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H
#include <string>

class Player {
public:
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_LEVEL = 1;
    static const int DEFAULT_COINS = 0;
    static const int MAX_LEVEL = 10;
    static const int ZERO = 0;
    static const int BARFIGHT_DAMAGE = 10;
    static const int WELL_DAMAGE = 10;
    static const std::string WITCH_NAME;
    static const std::string GREMLIN_NAME;
    static const std::string DRAGON_NAME;
    static const std::string HEALER_NAME;
    static const std::string NINJA_NAME;
    static const std::string WARRIOR_NAME;
    Player(const std::string &name);

protected:
    std::string m_name;
    int m_maxHP;
    int m_force;
    int m_HP;
    int m_coins;
    int m_level;
public:
    virtual std::string getType() const = 0;
    /// @brief Increases level by 1, if level is maximal, does nothing
    void levelUp();
    /// @brief Gets current level of Player
    /// @return Returns Player's current level
    int getLevel() const;
    /// @brief Increments force
    /// @param buffBy- Determines by how much player force shall be increased
    void buff(int buffBy);
    /// @brief Increases HP (until reaching maximal HP)
    /// @param healBy- Determines by how much player hp will be increased
    virtual void heal(int healBy);
    /// @brief Decreases HP until reaches 0
    /// @param damageBy - Determines by how much player hp will be decreased
    void damage(int damageBy);
    /// @brief Checks if HP is 0 <=> player is knocked out
    /// @return true if knocked out, false else
    bool isKnockedOut() const;
    /// @brief Adds coins to player
    /// @param toAdd Determines how many coins should be added do player
    virtual void addCoins(int toAdd);
    /// @brief Reduces coins from player in order to pay. If coins aren't sufficient payment fails.
    /// @param price - Value of current payment
    /// @return true if transaction uas successful, false else
    bool pay(int price);
    /// @brief Gets current player strength
    /// @return strength of player which is defined as level+force
    virtual int getAttackStrength();
    ///@brief Gets level needed to win
    ///@return const max level
    static int getMaxLevel();
    virtual void useManaCard() {};
    virtual void useBarfightCard();
    virtual void useWellCard();
    std::string getName() const;
    void killPlayer();
    void deBuff(int deBuffBy);
    int getCoins() const;
};
std::ostream& operator<<(std::ostream& os, const Player &player);
#endif //EX4_PLAYER_H
