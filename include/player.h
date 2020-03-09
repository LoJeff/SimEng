#ifndef PLAYER_H
#define PLAYER_H

#include "pghost.h"
#include "phuman.h"

class Player {
private:
    PHuman m_human;
    PGhost m_ghost;
    float m_chainLen;

    bool m_chain;
public:
    Player();

    void input(const Vector2f& locPos);
    void update(float timeElapsed);
    void draw(RenderWindow &window);
};

#endif // PLAYER_H