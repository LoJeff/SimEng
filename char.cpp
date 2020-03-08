#include "char.h"

Character::Character(float x, float y, string textureFile) {
    m_pos.x = x;
    m_pos.y = y;
    m_texture.loadFromFile(textureFile);
    m_sprite.setTexture(m_texture);
}

Sprite Character::getSprite() {
    return m_sprite;
}