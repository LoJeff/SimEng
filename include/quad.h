#ifndef QUAD_H
#define QUAD_H

#include "common.h"

class Quad {
public:
    struct Rect {
        Vector2f tL;
        Vector2f bR;
        
        Rect(Vector2f _tL, Vector2f _bR) {
            tL = _tL;
            bR = _bR;
        }

        Rect() {
            tL = Vector2f(0, 0);
            bR = Vector2f(0, 0);
        }
    };
private:
    Vector2f m_tL;
    Vector2f m_bR;

    Quad *m_tLQuad;
    Quad *m_tRQuad;
    Quad *m_bLQuad;
    Quad *m_bRQuad;

    uint state;

public:
    Quad(Vector2f tL, Vector2f bR);
    Quad();

    bool filled() { return state != 0; };

    void insert(Vector2f tL, Vector2f bR);
    void insert(Rect rec);
}; 
#endif // QUAD_H