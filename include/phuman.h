#ifndef PHUMAN_H
#define PHUMAN_H

#include <SFML/Graphics.hpp>
#include "char.h"

class PHuman : public Character {
private:
    bool m_left;
    bool m_right;
    bool m_stop;

    Vector2f m_vel;
    Vector2f m_velCap;
    Vector2f m_acc;
    Vector2f m_dec;

    Vector2f m_cen;
    Vector2f m_dim;
    Vector2f m_prevPos;
public:
    PHuman();

    void moveLeft() { m_left = true; };
    void moveRight() { m_right = true; };
    void stop() { m_stop = true; };
    void jump();

    void stopLeft() { m_left = false; };
    void stopRight() { m_right = false; };
    void free() { m_stop = false; };
    bool onGround();

    const Vector2f& cen() { return m_cen; };

    void input();
    void update(float timeElapsed);
    void revertPos();
};

#endif // PHUMAN_H