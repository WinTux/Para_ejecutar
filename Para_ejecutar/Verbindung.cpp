#include "Verbindung.h"

Verbindung::Verbindung(string s, string u, string z, double d, string firma) : Strecke(s, u, z, d)
{
	this->bahnFirma = firma;
}

ostream& operator<<(ostream& o, Verbindung v)
{
	v.printStrecke();
	return o << "Firma: " << v.bahnFirma << "\n";
}

string Verbindung::getBahnFirma()
{
	return this->bahnFirma;
}

Verbindung::~Verbindung()
{
}