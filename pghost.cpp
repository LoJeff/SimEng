#include "pghost.h"

PGhost::PGhost(const PHuman *human) : 
    Character(750, 340, "texture/ghost.jpg"),
    m_vel(0, 0),
    m_velCap(400, 400),
    m_acc(80, 80),
    m_dec(160, 160),
    m_dim(50, 70),
    m_tarRad(6),
    m_human(human) {
}

void PGhost::input(const Vector2i& locPos) {
    // Calculate distance from center of hitbox
    m_dir.x = locPos.x - cenX();
    m_dir.y = locPos.y - cenY();

    if ((m_dir.x*m_dir.x + m_dir.y*m_dir.y) > m_tarRad*m_tarRad) { // Normalize
        float norm = abs(m_dir.x) + abs(m_dir.y);
        m_dir.x /= norm;
        m_dir.y /= norm;
    } else { // Close enough no need to move ghost anymore
        m_dir.x = 0;
        m_dir.y = 0;
    }
}

float PGhost::updateVel(const float &dir, const float &vel, const float &acc,
    const float &dec, const float &velCap) {
    if (dir > (float) 0) {
        if (vel > (float) 0) {
            return min(vel + acc * dir, velCap);
        } else {
            return max(vel + dec * dir, (float) 0);
        }
    } else if (dir < (float) 0) {
        if (vel < (float) 0) {
            return max(vel + acc * dir, -velCap);
        } else {
            return min(vel + dec * dir, (float) 0);
        }
    } else {
        return (float) 0;
    }
}

void PGhost::update(float timeElapsed) {
    m_vel.x = updateVel(m_dir.x, m_vel.x, m_acc.x, m_dec.x, m_velCap.x);
    m_vel.y = updateVel(m_dir.y, m_vel.y, m_acc.y, m_dec.y, m_velCap.y);

    m_pos.x += timeElapsed * m_vel.x;
    m_pos.y += timeElapsed * m_vel.y;

    m_sprite.setPosition(m_pos);
}