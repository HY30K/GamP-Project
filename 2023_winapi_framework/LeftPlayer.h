#pragma once
#include "Object.h"
#include "HPBar.h"
class Texture;
class LeftPlayer
	: public Object
{
public:
	LeftPlayer();
	~LeftPlayer();

public:
	void Update();
	void Render(HDC _dc);
private:
	void CreateSlash();
public:
	void GetDamage(int damage);
	void SetHPBar();
private:
	int health;
	//float coolTime; //다음 공격까지의 시간
	HPBar* p_HPBar;
	Texture* m_pTex;
};

