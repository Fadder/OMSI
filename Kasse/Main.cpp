#include <iostream>
#include "Kasse.h"


int main( int argc, char* argv[] )
{
	Kasse kasse;

	kasse.runUntil(57600); // sek = 16 stunden

	cout << endl;
	cout << "-----------------------------Ergebnisse der Simulation--------------------------" << endl;

	cout << "Tagesumsatz: " << kasse.gesamtUmsatz() << " Euro" << endl;
	cout << "Kassenleerlauf:" << kasse.gesamtLeerlauf() << " sek" << endl;
	cout << "Durchschnittliche Abfertigungsdauer pro Kunde: " << kasse.durchschnittlicheAbfertigungsdauerProKunden()
		 << " sek" << endl;

	cout << "--------------------------------------------------------------------------------" << endl;

	return 0;
}


