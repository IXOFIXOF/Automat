#pragma once
#include "Produkt.h"
class CNapoj :
	public CProdukt
{
public:
	CNapoj();
	virtual ~CNapoj();
	void UstalSpecyficzneDane(void* Dane = nullptr);
	string DaneOProdukcie();
	int PobierzCene();
private:
	int pojemnosc;
};

