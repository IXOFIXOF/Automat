#pragma once
#include "Produkt.h"
class CPrzekaska :
	public CProdukt
{
public:
	CPrzekaska();
	virtual ~CPrzekaska();
	void UstalSpecyficzneDane(void* Dane = nullptr);
	string DaneOProdukcie();
	int PobierzCene();
};

