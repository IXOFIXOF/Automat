#pragma once
#include "Produkt.h"
class CWoda :
	public CProdukt
{
public:
	CWoda();
	virtual ~CWoda();
	void UstalSpecyficzneDane(void* Dane = nullptr);
	string DaneOProdukcie();
	int PobierzCene();
private:
	string Gazowana;
};

