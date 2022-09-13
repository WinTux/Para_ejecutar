#include <iostream>

#include "Fahrplan.h"


void aufgabe3(Fahrplan& f)
{
	f.readVerbindungen();
	f.printVerbindungen();
}

void aufgabe4(Fahrplan& f)
{
	f.selectVerbindungen("DBahn");
}

void aufgabe5(Fahrplan& f)
{
	f.writeSelected();
}

void aufgabe2()
{
	Strecke a("a","b","c",12.1), b("a","b","c",12.1);
	if (a == b)
		cout << "Son iguales\n";
	else
		cout << "Son diferentes\n";
}

void aufgabe6(Fahrplan& f)
{
	//f.minDauer("Darmstadt","Ruesselsheim");

	//Threads (hilos)
	thread hilo(&Fahrplan::minDauer, f, "Darmstadt", "Ruesselsheim");
	hilo.join();
	//termina acá
}

int main()
{
	Fahrplan f;
	aufgabe2();
	aufgabe3(f);
	aufgabe4(f);
	aufgabe5(f);
	aufgabe6(f);

	cout << "\n\n";
	system("pause");
	return EXIT_SUCCESS;
}