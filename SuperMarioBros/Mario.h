#ifndef MARIO_H
#define MARIO_H

class Mario{
    public:
        Mario(); // default constructor
        ~Mario(); // default destructor
        void setNumLives(int lives); // set lives given input from file
        int getPowerLevel(); // return power level
        void increasePowerLevel(); // add 1 to power level
        void decreasePowerLevel(); // subtract 1 from power level
        void addCoin(); // add 1 to number of coins
        void resetCoins(); // set number of coins to 0
        int getNumCoins(); // return number of coins
        void takeAwayLife(); // subtract 1 from number of lives
        void addLife(); // add 1 to number of lives
        int getLives(); // return number of lives
        bool returnHasWon(); // return boolean that is false if Mario has not won the game and true if he has
        bool returnIsDead(); // return boolean that is false if Mario has not died and true if he has
        void setHasWonToTrue(); // set boolean to true representing that Mario has won the game
        void setIsDeadToTrue(); // set boolean to true representing that Mario has died
        void addToWinCount(); // add 1 to number of enemies defeated
        int getWinCount(); // return number of enemies defeated
    private:
        int lives;
        int coins;
        int power;
        int enemyCount;
        bool died;
        bool won;
        void resetWinCount(); // set number of enemies defeated to 0
};

#endif