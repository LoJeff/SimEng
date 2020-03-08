#include "phuman.h"

PHuman::PHuman() : 
    Character(500, 430, "texture/phuman.png"),
    m_vel(0, 0),
    m_velCap(400, 800),
    m_acc(50, 100),
    m_dim(110, 230) {
    m_left = false;
    m_right = false;
}

void PHuman::jump() {
    // Implement when stage creation is created
    cout << "BOING" << endl;
}

bool PHuman::onGround() {
    // Update when stage creation is created
    return true;
}

void PHuman::input() {
    // Left Control
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        moveLeft();
    } else {
        stopLeft();
    }
    // Right Control
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        moveRight();
    } else {
        stopRight();
    }
}

void PHuman::update(float timeElapsed) {
    m_prevPos = m_pos;

    // Moving in one direction
    if (m_right != m_left) { // Accelerate
        if (m_right) { // Right
            m_vel.x = min(m_vel.x + m_acc.x, m_velCap.x);
        } else { // Left
            m_vel.x = max(m_vel.x - m_acc.x, -m_velCap.x);
        }
    } else if (m_vel.x != 0) { // Decelerate
        if (m_vel.x > 0) { // Right
            m_vel.x = min(m_vel.x + m_dec.x, (float) 0);
        } else { // Left
            m_vel.x = max(m_vel.x - m_dec.x, (float) 0);
        }
    }

    m_pos.x += m_vel.x * timeElapsed;
    m_sprite.setPosition(m_pos);
}