#include "Kasse.h"
#include "KundenGenerator.h"
#include <iostream>
#include <string>
#include <odemx/base/Simulation.h>
using odemx::base::Simulation;

Kasse::Kasse() : kundenGen(*this), kassierer(*this), umsatz(0),leerlauf(0), kundenAnzahl(0), abfertigungsDauerGesamt(0),
				 band(*this), ablage(*this), bezahlung(*this)
{/*erzeuge Ablage, Bezahlung, Band, Kassierer, KundenGenerator*/ }

void Kasse::initSimulation() { /* aktiviere Kassierer und KundenGenerator*/
	kassierer.hold();
	kundenGen.hold();
}

/*Funktionen fuer die Sammlung von Information fuer die Statistik*/
void Kasse::kundenanzahlInkrementieren() {
	kundenAnzahl++;
}

void Kasse::abfertigungsDauerErhoehen(SimTime time) {
	abfertigungsDauerGesamt = abfertigungsDauerGesamt + time;
}

void Kasse::leerlaufErhoehen(SimTime time) {
	leerlauf = leerlauf + time;
}

void Kasse::umsatzErhoehen(double betrag) {
	umsatz = umsatz + betrag;
}

/*Funktionen fuer die Auswertung der gesammelten Information*/
double Kasse::gesamtUmsatz() {
	return umsatz;
}

SimTime Kasse::gesamtLeerlauf() {
	return leerlauf;
}

SimTime Kasse::durchschnittlicheAbfertigungsdauerProKunden() {
	return (double)abfertigungsDauerGesamt / (double)kundenAnzahl;
}
