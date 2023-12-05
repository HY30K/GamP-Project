#pragma once
#include "Object.h"
class Texture;
class RightPlayer :
    public Object
{
public:
	RightPlayer();
	~RightPlayer();
public:
	void Update();
	void Render(HDC _dc);

public:
	void GetDamage(UINT damage);
private:
	//int health;

    Texture* m_pTex;

};

