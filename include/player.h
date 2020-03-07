#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "char.h"

class Player : public Character {
private:
    bool m_left;
    bool m_right;
public:
    Player();

    void moveLeft();
    void moveRight();

    void stopLeft();
    void stopRight();

    void update(float timeElapsed);
};

#endif // PLAYER_H