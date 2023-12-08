#pragma once
#include "Object.h"
class Texture;
class HPBar :
    public Object
{
public:
    HPBar();
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
    void GiveDamage(int a) {
        m_nhp -= a;
    }
private:
    int m_nHeight;
    int m_nWidth;
    int m_nMaxHp;
    int m_nhp;
    
    float m_fSize;

    Texture* m_pTex; //���� ü��ĭ
    Texture* m_pbgTex; // ��׶���
};

