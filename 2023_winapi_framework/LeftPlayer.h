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
	//float coolTime; //���� ���ݱ����� �ð�

	Texture* m_pTex;
};

