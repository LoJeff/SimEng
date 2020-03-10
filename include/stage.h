#ifndef STAGE_H
#define STAGE_H

#include "common.h"

class Stage {
private:
    string m_name;
    bool m_loaded;
    Texture m_bkgdTexture;
    Sprite m_bkgdSprite;
    View m_view;

public:
    Stage();
    void init(string name, string bkgdFile);
    View getView() { return m_view; };
    Sprite getSprite() { return m_bkgdSprite; };

    bool loaded() { return m_loaded; };
    bool setLoaded() { return m_loaded = true; };
};

#endif // STAGE_H