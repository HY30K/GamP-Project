#include "pch.h"
#include "Background.h"
#include "ResMgr.h"
#include "Texture.h"
#include "Core.h"

Background::Background()
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Background", L"Texture\\background1.bmp");
}

Background::~Background()
{
}

void Background::Render(HDC _dc)
{
	POINT point = Core::GetInst()->GetResolution();

	StretchBlt(_dc
		, 0
		, 0
		, point.x, point.y, m_pTex->GetDC()
		, 0, 0, point.x - 800, point.y - 480, SRCCOPY);

	Component_Render(_dc);
}
