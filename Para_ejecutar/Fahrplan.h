#pragma once
#include "Verbindung.h"

class Fahrplan
{
private:
	vector<Verbindung> verbindungen;
	map<int, Verbindung> selected;
	string file = "verbindungen.dat";
public:
	Fahrplan();
	void readVerbindungen();
	void selectVerbindungen(string firma);
	void writeSelected();
	void minDauer(string start, string ziel);
	void printVerbindungen();
	~Fahrplan();
};