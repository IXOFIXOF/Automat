#pragma once

enum class Typ�akocia
{
	eJedzenie = 0,
	ePicie
};
class C�ako�
{
public:
	C�ako�();
	~C�ako�();
protected:
	virtual void UstalCene(int iCena) = 0;
	int m_iCena;
	Typ�akocia eTyp�akocia;
	
};

