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

    // Initialize with starting stage
    m_stage.init("Level 1", "texture/background.jpg");

    while (m_window.isOpen())
    {
        // Restart clock and get elapsed time
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        loadStage();
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

void Engine::update(float timeElapsed) {
    m_locPos = m_window.mapPixelToCoords(Mouse::getPosition(m_window));
    if (Keyboard::isKeyPressed(Keyboard::P))
    cout << m_locPos.x << " , " << m_locPos.y << endl;

    m_player.update(timeElapsed);
}

void Engine::draw() {
    m_window.clear(Color::White);

    // Draw everything
    m_window.draw(m_stage.getSprite());
    m_player.draw(m_window);

    m_window.display();
}

void Engine::loadStage() {
    if (!m_stage.loaded()) {
        m_window.setView(m_stage.getView());
    }
}