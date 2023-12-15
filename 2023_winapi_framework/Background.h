#pragma once
#include "Object.h"
class Texture;
class Background :
	public Object
{
public:
	Background();
	~Background();
public:
	void Render(HDC _dc) override;
private:
	Texture* m_pTex;
};

