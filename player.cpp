
#include "player.h"

Player::Player() : 
    Character(500, 430, 400, "texture/player.png") {
    m_left = false;
    m_right = false;
}

void Player::moveLeft() {
    m_left = true;
}

void Player::moveRight() {
    m_right = true;
}

void Player::stopLeft() {
    m_left = false;
}

void Player::stopRight() {
    m_right = false;
}

void Player::update(float timeElapsed) {
    if (m_right) {
        m_pos.x += m_spd * timeElapsed;
    }

    if (m_left) {
        m_pos.x -= m_spd * timeElapsed;
    }

    m_sprite.setPosition(m_pos);
}