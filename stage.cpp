#include "stage.h"

Stage::Stage() :
    m_loaded(false) {
}

void Stage::init(string name, string bkgdFile) {
    m_loaded = false;
    m_name = name;
    m_bkgdTexture.loadFromFile(bkgdFile);
    m_bkgdSprite.setTexture(m_bkgdTexture);

    Vector2u bkgdSize = m_bkgdTexture.getSize();
    m_view.reset(FloatRect(0.f, 0.f, bkgdSize.x, bkgdSize.y));
}