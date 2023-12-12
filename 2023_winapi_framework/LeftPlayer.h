#pragma once
#include "Object.h"
class HPBar;
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
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther)  override;
	virtual void StayCollision(Collider* _pOther)  override;
private:
	void CreateSlash();
public:
	void GetDamage(int damage);
	void SetHPBar();
private:
	//float coolTime; //���� ���ݱ����� �ð�
	HPBar* p_HPBar;
	Texture* m_pTex;
};

