#ifndef CHAR_H
#define CHAR_H

#include <SFML/Graphics.hpp>
#include "common.h"

using namespace sf;

class Character {
protected:
    Vector2f m_pos;
    Sprite m_sprite;
    Texture m_texture;

public:
    Character(float x, float y,
        string textureFile = "texture/default.png");
    Sprite getSprite();
    const Vector2f& pos() { return m_pos; };
    virtual void update(float elapsedTime) = 0;
};

#endif // CHAR_H