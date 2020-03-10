#include "pghost.h"

PGhost::PGhost(PHuman *human) : 
    Character(750, 340, "texture/ghost.jpg"),
    m_vel(0, 0),
    m_velCap(500, 500),
    m_acc(60, 60),
    m_dec(120, 120),
    m_dim(50, 70),
    m_tarRad(5),
    m_human(human) {
}

void PGhost::input(const Vector2f& locPos) {
    // Calculate distance from center of hitbox
    m_dir.x = locPos.x - m_cen.x;
    m_dir.y = locPos.y - m_cen.y;

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
        if (vel >= (float) 0) {
            return min(vel + acc * dir, velCap);
        } else {
            return vel + dec * dir;
        }
    } else if (dir < (float) 0) {
        if (vel <= (float) 0) {
            return max(vel + acc * dir, -velCap);
        } else {
            return vel + dec * dir;
        }
    } else {
        return (float) 0;
    }
}

void PGhost::update(float timeElapsed) {
    m_prevPos = m_pos;

    m_vel.x = updateVel(m_dir.x, m_vel.x, m_acc.x, m_dec.x, m_velCap.x);
    m_vel.y = updateVel(m_dir.y, m_vel.y, m_acc.y, m_dec.y, m_velCap.y);

    m_pos.x += timeElapsed * m_vel.x;
    m_pos.y += timeElapsed * m_vel.y;

    m_sprite.setPosition(m_pos);
    m_cen.x = m_pos.x + m_dim.x/2.f;
    m_cen.y = m_pos.y + m_dim.y/2.f;
}

void PGhost::updatePos(const Vector2f& pos) {
    m_pos = pos;
    m_vel.x = 0;
    m_vel.y = 0;
    m_sprite.setPosition(m_pos);
}