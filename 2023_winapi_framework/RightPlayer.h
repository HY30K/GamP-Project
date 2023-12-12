#pragma once
#include "Object.h"
class HPBar;
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
private:
	void CreateSlash();
public:
	void GetDamage(UINT damage);
	void SetHPBar();
private:
	//int health;
	HPBar* p_HPBar;
    Texture* m_pTex;
};

