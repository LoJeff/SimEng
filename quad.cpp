
#include "quad.h"

Quad::Quad(Vector2f tL, Vector2f bR) {
    m_tL = tL;
    m_bR = bR;
    state = 0;
    m_tLQuad = nullptr;
    m_tRQuad = nullptr;
    m_bLQuad = nullptr;
    m_bRQuad = nullptr;
}

Quad::Quad() {
    m_tL = Vector2f(0, 0);
    m_bR = Vector2f(0, 0);
    state = 0;
    m_tLQuad = nullptr;
    m_tRQuad = nullptr;
    m_bLQuad = nullptr;
    m_bRQuad = nullptr;
}

void Quad::insert(Rect rec) {
    insert(rec.tL, rec.bR);
}

void Quad::insert(Vector2f tL, Vector2f bR) {
    // Check if given coordinates cover the current bounding box
    if (tL.x <= m_tL.x && tL.y <= m_tL.y && bR.x >= m_bR.x && bR.y >= m_bR.y) {
        state = true;
        return;
    }

    float xMid = (m_tL.x + m_bR.x)/2;
    float yMid = (m_tL.y + m_bR.y)/2;
    if (xMid > tL.x) { //Left
        if (yMid > tL.y) { //Top
            if (m_tLQuad == nullptr) m_tLQuad = new Quad(m_tL, Vector2f(xMid, yMid));
            if (!m_bLQuad->filled()) {
                Vector2f subTL(max(tL.x, m_tL.x), max(tL.y, m_tL.y));
                Vector2f subBR(min(bR.x, xMid), min(bR.y, yMid)); 
                m_tLQuad->insert(subTL, subBR);
            }
        }
        if (yMid <= bR.y) { //Bottom
            if (m_bLQuad == nullptr) m_bLQuad = new Quad(Vector2f(m_tL.x, yMid), Vector2f(xMid, m_bR.y));
            if (!m_bLQuad->filled()) {
                Vector2f subTL(max(tL.x, m_tL.x), max(tL.y, yMid));
                Vector2f subBR(min(bR.x, xMid), min(bR.y, m_bR.y));
                m_bLQuad->insert(subTL, subBR);
            }
        }
    }

    if (xMid <= bR.x) { //Right
        if (yMid > tL.y) { //Top
            if (m_tRQuad == nullptr) m_tLQuad = new Quad(Vector2f(xMid, m_tL.y), Vector2f(m_bR.x, yMid));
            if (!m_tRQuad->filled()) {
                Vector2f subTL(max(tL.x, xMid), max(tL.y, yMid));
                Vector2f subBR(min(bR.x, m_bR.x), min(bR.y, m_bR.y));
                m_tRQuad->insert(subTL, subBR);
            }
        }
        if (yMid <= bR.y) { //Bottom
            if (m_bRQuad == nullptr) m_tLQuad = new Quad(Vector2f(xMid, yMid), m_bR);
            if (!m_bRQuad->filled()) {
                Vector2f subTL(max(tL.x, xMid), max(tL.y, m_tL.y));
                Vector2f subBR(min(bR.x, m_bR.x), min(bR.y, yMid));
                m_bRQuad->insert(subTL, subBR);
            }
        }
    }
}