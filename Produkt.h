#pragma once
#include <string>

class CProdukt
{
public:
	CProdukt();
	~CProdukt();
protected:
	virtual void UstalCene(int iCena) = 0;
	virtual void UstalNazwe(string sNazwa) = 0;
	int m_iCena;
	string m_Nazwa;
};

