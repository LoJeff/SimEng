#ifndef PHUMAN_H
#define PHUMAN_H

#include <SFML/Graphics.hpp>
#include "char.h"

class PHuman : public Character {
private:
    bool m_left;
    bool m_right;

    Vector2f m_vel;
    Vector2f m_velCap;
    Vector2f m_acc;
    Vector2f m_dec;

    Vector2f m_dim;
    Vector2f m_prevPos;
public:
    PHuman();

    void moveLeft() { m_left = true; };
    void moveRight() { m_right = true; };
    void jump();

    void stopLeft() { m_left = false; };
    void stopRight() { m_right = false; };
    bool onGround();

    float cenX() { return m_pos.x + m_dim.x/2; };
    float cenY() { return m_pos.y + m_dim.y/2; };

    void input();
    void update(float timeElapsed);
    void revertPos() { m_pos = m_prevPos; };
};

#endif // PHUMAN_H