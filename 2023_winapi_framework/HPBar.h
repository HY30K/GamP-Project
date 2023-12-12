#pragma once
#include "Object.h"
class Texture;
class HPBar :
    public Object
{
public:
    HPBar();
    HPBar(int maxhp, bool left);
    ~HPBar();

public:
    void Init();
    void Update();
    void Render(HDC _dc);
    void Release();

public:
    void SetHP(int hp) {
        m_nhp = hp;
    }
    const int GetHP() const {
        return m_nhp;
    }
private:
    int m_nHeight;
    int m_nWidth;
    int m_nMaxHp;
    int m_nhp;
    int m_fSize;
    
    bool m_isLeft;


    Texture* m_pTex; //»¡°£ Ã¼·ÂÄ­
    Texture* m_pbgTex; // ¹é±×¶ó¿îµå
};

