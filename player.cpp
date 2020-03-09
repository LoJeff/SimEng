#include "player.h"

Player::Player() :
    m_human(),
    m_ghost(&m_human),
    m_chainLen(500),
    m_chain(true) {
}

void Player::input(const Vector2i& locPos) {
    m_human.input();
    m_ghost.input(locPos);
}

void Player::update(float timeElapsed) {
    m_human.update(timeElapsed);
    m_ghost.update(timeElapsed);
    
    float distX = m_ghost.cen().x - m_human.cen().x;
    float distY = m_ghost.cen().y - m_human.cen().y;
    float distSqr = distX*distX + distY*distY;

    if (m_chain) {
        if (distSqr >= m_chainLen*m_chainLen) {
            float ratio = m_chainLen / sqrtf(distSqr);
            Vector2f newPos;
            newPos.x = m_human.cen().x + distX*ratio - m_ghost.dim().x/2;
            newPos.y = m_human.cen().y + distY*ratio - m_ghost.dim().y/2;
            m_ghost.updatePos(newPos);
        }
    }
}

void Player::draw(RenderWindow &window) {
    window.draw(m_ghost.getSprite());
    window.draw(m_human.getSprite());
}