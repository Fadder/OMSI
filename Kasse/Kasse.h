#ifndef KASSE_H_
#define KASSE_H_

#include "Band.h"
#include <odemx/base/Simulation.h>
#include <odemx/odemx.h>
#include "KundenGenerator.h"
#include "Kassierer.h"
#include "Ablage.h"
#include "Bezahlung.h"
using odemx::base::Simulation;

/* 1 Zeiteinheit entspricht 1 Sekunde*/

class Kasse : public Simulation {
	KundenGenerator kundenGen;
	Kassierer kassierer;

	//Variablen fuer die Statistik
	double umsatz;
	SimTime leerlauf;
	int kundenAnzahl;
	SimTime abfertigungsDauerGesamt;

public:
	Band band;
	Ablage ablage;
	Bezahlung bezahlung;

	Kasse();

	virtual void initSimulation();

	//Funktionen fuer die Sammlung von Information fuer die Statistik
	void kundenanzahlInkrementieren();
	void abfertigungsDauerErhoehen(SimTime time);
	void leerlaufErhoehen(SimTime time);
	void umsatzErhoehen(double betrag);

	//Auswertungsfunktionen der gesammelten Information
	double gesamtUmsatz();
	SimTime gesamtLeerlauf();
	SimTime durchschnittlicheAbfertigungsdauerProKunden();
};

#endif /* KASSE_H_ */
