#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <thread>
#include <Windows.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Strecke
{
private:
	string start;
	string ziel;
	string ueber;
	double dauer;
public:
	Strecke(string s, string u, string z, double d);
	string getStart();
	string getZiel();
	string getUeber();
	double getDauer();
	void printStrecke();
	bool operator == (Strecke other);
	~Strecke();
};
