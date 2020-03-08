#ifndef PGHOST_H
#define PGHOST_H

#include <SFML/Graphics.hpp>
#include "char.h"
#include "phuman.h"

class PGhost : public Character {
private:
    Vector2f m_vel;
    Vector2f m_velCap;
    Vector2f m_acc;
    Vector2f m_dec;
    Vector2f m_dir;

    Vector2f m_dim;
    float m_tarRad;
    const PHuman *m_human;

    float updateVel(const float &dir, const float &vel, const float &acc,
        const float &dec, const float &velCap);
public:
    PGhost(const PHuman *human);

    float cenX() { return m_pos.x + m_dim.x/2; };
    float cenY() { return m_pos.y + m_dim.y/2; };

    void input(const Vector2i& locPos);
    void update(float timeElapsed);
};

#endif // PGHOST_H