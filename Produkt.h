#pragma once
#include <string>

class CProdukt
{
public:
	
	CProdukt();
    virtual ~CProdukt();
    void UstalCene();
	void UstalNazwe();
	virtual void UstalSpecyficzneDane() = 0;
	virtual void DaneOProdukcie() = 0;
protected:
	int m_iCena;
	string m_sNazwa;
};

