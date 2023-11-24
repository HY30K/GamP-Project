#pragma once
#include "Scene.h"
class Texture;
class SelectCharScene:
	public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    Texture* m_pTex;
};

