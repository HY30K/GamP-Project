#pragma once
#include "Object.h"
class Texture;
class Title:
	public Object
{
public:
	Title();
	~Title();
public:
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
};

