#pragma once
#include "Object.h"
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

public:
	void GetDamage(UINT damage);

private:
	//UINT health;
	//float coolTime; //다음 공격까지의 시간

	Texture* m_pTex;
};

