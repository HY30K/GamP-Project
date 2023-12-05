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
        this->hp = hp;
    }
private:
    int Height;
    int Width;
    int size;
    int hp;

    Texture* m_pTex;
};

