#include "eng.h"

Engine::Engine() {
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
 
    m_window.create(VideoMode(resolution.x, resolution.y),
        "SimEng",
        Style::Default);
 
    m_bkgdTexture.loadFromFile("texture/background.jpg");
    m_bkgdSprite.setTexture(m_bkgdTexture);
 
}

void Engine::start() {
    Clock clock;

    while (m_window.isOpen())
    {
        // Restart clock and get elapsed time
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
 
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input() {
    // Player Quit
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        m_window.close();
    }
 
    // Player Movement
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        m_player.moveLeft();
    } else {
        m_player.stopLeft();
    }
 
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        m_player.moveRight();
    } else {
        m_player.stopRight();
    }
}

void Engine::update(float timeElapsed)
{
    m_player.update(timeElapsed);
}

void Engine::draw()
{
    m_window.clear(Color::White);
 
    // Draw everything
    m_window.draw(m_bkgdSprite);
    m_window.draw(m_player.getSprite());

    m_window.display();
}