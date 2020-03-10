#ifndef ENG_H
#define ENG_H

#include "common.h"
#include "player.h"
#include "stage.h"

class Engine {
private:
    RenderWindow m_window;
 
    Sprite m_bkgdSprite;
    Texture m_bkgdTexture;
    Vector2f m_locPos;
    Stage m_stage;

    bool m_success;
 
    Player m_player;

    void loadStage();
    void input();
    void update(float timeElapsed);
    void draw();

public:
    Engine();

    void start();
};

#endif // ENG_H