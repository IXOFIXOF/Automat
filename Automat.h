#pragma once
#include <vector>
#include "Produkt.h"
#include "stdafx.h"
class CAutomat
{

public:
	CAutomat();
	void Init();
	~CAutomat();
private:
	vector< CProdukt* > ListaProduktow;
	vector< CProdukt*> ::iterator it;
	void DodajProdukt();
	void StanAutomatu();
	void UsunProdukt();
	void EdytujDane();

};

