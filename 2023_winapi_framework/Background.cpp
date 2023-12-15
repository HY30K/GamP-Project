#include "pch.h"
#include "Background.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Core.h"

Background::Background()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Background", L"Texture\\gameBackground.bmp");
}

Background::~Background()
{
}

void Background::Render(HDC _dc)
{
}
