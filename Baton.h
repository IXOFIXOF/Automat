#pragma once
#include "Produkt.h"


class CBaton : public CProdukt
{
public:

	CBaton();
	~CBaton();
	void UstalSpecyficzneDane();
	string DaneOProdukcie();
	int PobierzCene();

};

