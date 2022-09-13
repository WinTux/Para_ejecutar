#include "Strecke.h"


bool Strecke::operator==(Strecke other)
{
	return (this->getStart() == other.getStart() && this->getZiel() == other.getZiel());
}

Strecke::Strecke(string st, string ub, string zi, double da)
{
	this->start = st;
	this->dauer = da;
	this->ueber = ub;
	this->ziel = zi;
}

string Strecke::getStart()
{
	return this->start;
}

string Strecke::getZiel()
{
	return this->ziel;
}

string Strecke::getUeber()
{
	return this->ueber;
}

double Strecke::getDauer()
{
	return this->dauer;
}

void Strecke::printStrecke()
{
	cout << "\nStart: " << this->start;
	cout << "\nUeber: " << this->ueber;
	cout << "\nZiel : " << this->ziel;
	cout << "\nDauer: " << this->dauer << "\n";
}

Strecke::~Strecke()
{
}
/*
bool operator ==(  Strecke strecke1,  Strecke strecke2) {

	return (strecke1.getStart() == strecke2.getStart() && strecke1.getZiel() == strecke2.getZiel());
*/