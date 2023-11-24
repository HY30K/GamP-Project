#pragma once
#include"Object.h"
class Texture;
class Characters :
	public Object
{
public:
	Characters();
	~Characters();
public:
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
};

