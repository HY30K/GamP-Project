#pragma once
#include "Scene.h"
class ResultScene :
    public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
private:
    Vec2 restart;
    Vec2 GameQuit;
};

