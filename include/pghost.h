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

    Vector2f m_cen;
    Vector2f m_dim;
    float m_tarRad;

    PHuman *m_human;
    Vector2f m_prevPos;

    float updateVel(const float &dir, const float &vel, const float &acc,
        const float &dec, const float &velCap);
public:
    PGhost(PHuman *human);

    const Vector2f& dim() { return m_dim; };
    const Vector2f& cen() { return m_cen; };

    void input(const Vector2i& locPos);
    void update(float timeElapsed);
    void updatePos(const Vector2f& pos);
};

#endif // PGHOST_H