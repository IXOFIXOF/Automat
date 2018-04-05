#pragma once
#include "Produkt.h"


class CBaton : public CProdukt
{
public:

	CBaton();
	~CBaton();
	void UstalSpecyficzneDane( void* Dane = nullptr );
	string DaneOProdukcie();
	int PobierzCene();

private:
	string Smak;
};

