#include "Fahrplan.h"

Fahrplan::Fahrplan()
{
}

void Fahrplan::readVerbindungen()
{
	fstream verbind;
	verbind.open(this->file, ios::in);
	std::string firma = "";
	std::string s = "", u = "", z = "";
	double distancia;

	if (verbind.is_open())
	{
		cout << "\nFile found.\n";
		//iteración
		//leer linea a linea
		int count = 0, limite = 5;
		while (!verbind.eof()) {
			verbind >> firma;
			verbind >> s;
			verbind >> z;
			verbind >> u;
			verbind >> distancia;
			Verbindung ver(s, u, z, distancia, firma);
			verbindungen.push_back(ver);//agregar elemento al vector


		}

	}
	else
	{
		cout << "\nFile NOT found.\n";
	}
	verbind.close();
}

void Fahrplan::selectVerbindungen(string firma)
{
	// Poblar el map con todos  los Verbindung que pertenezcan a la firma proporcionada.
	//mapa es selected; vector verbindungen
	int count = 0;
	for (Verbindung& i : verbindungen) {
		if (i.getBahnFirma() == firma)
			selected.insert(pair<int, Verbindung>(count++, i));
	}

}

void Fahrplan::writeSelected()
{
	//crear un archivo con todos los verbindung del map
	//crear un archivo de salida
	fstream salida;
	salida.open("salida.dat", ios::out);
	//iterar sobre el map
	map<int, Verbindung>::iterator it;
	for (it = selected.begin(); it != selected.end(); it++) {
		//escribir en el archivo
		salida << it->second.getBahnFirma() << "\n";
		salida << it->second.getStart() << "\n";
		salida << it->second.getZiel() << "\n";
		salida << it->second.getUeber() << "\n";
		salida << it->second.getDauer() << "\n";

	}
	salida.close();

}

void Fahrplan::minDauer(string start, string ziel)
{
	double tiempoMinimo = 200;
	string inicio = "", destino="", medio = "";

	// iterar en el map

	
	map<int, Verbindung>::iterator it;
	for (it = selected.begin(); it != selected.end(); it++) {
		//si start y ziel coinciden ->
		if (it->second.getStart() == start && it->second.getZiel() == ziel && it->second.getDauer() < tiempoMinimo) {
			//verificamos si dauer < tiempoMinimo -> si es así entonces tiempoMinimo = dauer
			
				// rescatamos inicio, destino, medio y duración 
				tiempoMinimo = it->second.getDauer();
				inicio = it->second.getStart();
				destino = it->second.getZiel();
				medio = it->second.getUeber();
			
			
		}
	}

	cout << "Inicio: " << inicio << ", medio: " << medio << ", final: " << destino << ": " << tiempoMinimo << "\n";

}


void Fahrplan::printVerbindungen()
{
	for (Verbindung v : this->verbindungen)
	{
		cout << v;
	}
	cout << "\nEs wurden >> " << this->verbindungen.size() << " << Verbindungen eingelesen:\n";
}

Fahrplan::~Fahrplan()
{
}