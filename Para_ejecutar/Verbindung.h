#pragma once
#include "Strecke.h"

class Verbindung : public Strecke
{
private:
	string bahnFirma;
public:
	Verbindung(string s, string u, string z, double d, string firma);
	friend ostream& operator <<(ostream& o, Verbindung v);
	string getBahnFirma();
	~Verbindung();
};