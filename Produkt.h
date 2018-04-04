#pragma once
#include <string>

class CProdukt
{
public:
	
	CProdukt();
    virtual ~CProdukt();
    void UstalCene( int Cena = 0);
	void UstalNazwe( string Nazwa = "");
	virtual void UstalSpecyficzneDane() = 0;
	virtual string DaneOProdukcie() = 0;
	virtual int PobierzCene() = 0;
protected:
	int m_iCena;
	string m_sNazwa;
};

