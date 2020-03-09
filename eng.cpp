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
    Vector2u bkgdSize = m_bkgdTexture.getSize();
    View view1(FloatRect(0.f, 0.f, bkgdSize.x, bkgdSize.y));
    m_window.setView(view1);
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

    m_player.input(m_locPos);
}

void Engine::update(float timeElapsed)
{
    m_locPos = m_window.mapPixelToCoords(Mouse::getPosition(m_window));
    if (Keyboard::isKeyPressed(Keyboard::P))
    cout << m_locPos.x << " , " << m_locPos.y << endl;

    m_player.update(timeElapsed);
}

void Engine::draw()
{
    m_window.clear(Color::White);
 
    // Draw everything
    m_window.draw(m_bkgdSprite);
    m_player.draw(m_window);

    m_window.display();
}