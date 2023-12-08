#include "pch.h"
#include "HPBar.h"
#include "Texture.h"
#include "ResMgr.h"

HPBar::HPBar():
	m_nHeight(50),
	m_nWidth(500),
	m_fSize(0.9f),
	m_nMaxHp(100),
	m_nhp(100)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"HpBarImage", L"Texture\\HpbarImage.bmp");
	m_pbgTex = ResMgr::GetInst()->TexLoad(L"HpBarBackground", L"Texture\\HPbarbackground.bmp");
}

HPBar::~HPBar()
{
}

void HPBar::Init()
{
}

void HPBar::Update()
{

}

void HPBar::Render(HDC _dc)
{
	Vec2 pos = GetPos();
	int x = m_pTex->GetWidth(), y = m_pTex->GetHeight();
	BitBlt(_dc, pos.x, pos.y, pos.x + (m_nWidth * m_nMaxHp * m_fSize * 0.01f), pos.y + m_nHeight,
		m_pbgTex->GetDC(), 0, 0, SRCCOPY);
	StretchBlt(_dc, pos.x + 10, pos.y + 10, pos.x + (m_nWidth * m_nhp * m_fSize * 0.01f) - 10, pos.y + m_nHeight - 10,
		m_pTex->GetDC(), pos.x + 10, pos.y + 10,x, y, SRCCOPY);
}

void HPBar::Release()
{
}
