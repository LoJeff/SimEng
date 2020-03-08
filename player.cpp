#include "player.h"

Player::Player() :
    m_human(),
    m_ghost(&m_human),
    m_chainLen(1000) {
}

void Player::input(const Vector2i& locPos) {
    m_human.input();
    m_ghost.input(locPos);
}

void Player::update(float timeElapsed) {
    m_human.update(timeElapsed);
    m_ghost.update(timeElapsed);
}

void Player::draw(RenderWindow &window) {
    window.draw(m_ghost.getSprite());
    window.draw(m_human.getSprite());
}