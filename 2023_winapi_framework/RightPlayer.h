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
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther)  override;
	virtual void StayCollision(Collider* _pOther)  override;
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

