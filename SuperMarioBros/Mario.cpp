#include "Mario.h"

int powerLevel;
int numLives;
int numCoins;
int winCount;
bool isDead;
bool hasWon;

Mario::Mario() // default constructor initializes member variables
{
    powerLevel = 0;
    numLives = 0;
    numCoins = 0;
    winCount = 0;
    isDead = false;
    hasWon = false;

}

Mario::~Mario() // default destructor
{

}

void Mario::setNumLives(int lives)
{
    numLives = lives;
}

int Mario::getPowerLevel()
{
    return powerLevel;
}

void Mario::increasePowerLevel()
{
    powerLevel += 1;
}

void Mario::decreasePowerLevel()
{
    powerLevel -= 1;
}

void Mario::addCoin()
{
    numCoins += 1;
}

void Mario::resetCoins()
{
    numCoins = 0;
}

int Mario::getNumCoins()
{
    return numCoins;
}

void Mario::takeAwayLife()
{
    numLives -= 1;
    Mario::resetWinCount(); // current life changes, so number of enemies defeated is reset
}

void Mario::addLife()
{
    numLives += 1;
    Mario::resetWinCount(); // current life changes, so number of enemies defeated is reset
}

int Mario::getLives()
{
    return numLives;
}

bool Mario::returnHasWon()
{
    return hasWon;
}

bool Mario::returnIsDead()
{
    return isDead;
}

void Mario::setHasWonToTrue()
{
    hasWon = true;
}

void Mario::setIsDeadToTrue()
{
    isDead = true;
}

void Mario::addToWinCount()
{
    winCount += 1;
}
void Mario::resetWinCount()
{
    winCount = 0;
}

int Mario::getWinCount()
{
    return winCount;
}
