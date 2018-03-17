#pragma once
#include <string>

class CProdukt
{
public:
	
	CProdukt();
   virtual ~CProdukt();
	virtual void UstalCene() = 0;
	virtual void UstalNazwe() = 0;
	virtual void DodajSpecyficzneDane() = 0;
	virtual void PodajStan() = 0;
protected:
	int m_iCena;
	string m_Nazwa;
};

