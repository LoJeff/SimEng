#ifndef ENG_H
#define ENG_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "common.h"
#include "player.h"

using namespace sf;

class Engine {
private:
    RenderWindow m_window;
 
    Sprite m_bkgdSprite;
    Texture m_bkgdTexture;
    Vector2f m_locPos;

    bool m_success;
 
    Player m_player;

    void input();
    void update(float timeElapsed);
    void draw();

public:
    Engine();

    void start();
};

#endif // ENG_H