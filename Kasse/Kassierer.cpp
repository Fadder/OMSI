

#include <string>
#include <iostream>
#include "Kassierer.h"
#include "Kasse.h"
#include "Person.h"
#include "Bezahlung.h"
#include <odemx/base/Process.h>
using namespace odemx::random;
using odemx::base::Process;
using odemx::base::Simulation;
using namespace std;

Kassierer::Kassierer(Simulation& sim) : Person(sim, "Kassierer"), aktuelleWare(0,"Null", 0, false) {
	// TODO Auto-generated constructor stub

}

Kassierer::~Kassierer() {
	// TODO Auto-generated destructor stub
}

int Kassierer::main() {
	Band& band = static_cast<Kasse&>( this->getSimulation() ).band;
	Ablage& ablage = static_cast<Kasse&>( this->getSimulation() ).ablage;
	Bezahlung& bezahlung = static_cast<Kasse&>( this->getSimulation() ).bezahlung;
	Kasse& kasse = static_cast<Kasse&>( this->getSimulation() );

	//In der Rechnung ist die Dauer der gesamten Bezahlphase zwischen Kunden und Kassierer gespeichert
	//"rechnungAnsagenAnteil" und "geldInDieKasseLegen" geben den Anteil der Bezahlzeit an, die der Kassierer verbraucht
	double rechnungAnsagenAnteil = 0.1;
	double geldInDieKasseLegen = 0.3;

	//fuer die Bestimmung des Kassenleerlaufs
	SimTime leerlaufDerKasseStart = 0;
	SimTime leerlaufDerKasseEnde = 0;
	SimTime leerlaufDerKasseProZyklus;

	//fuer die Bestimmung von Kundenabfertigungsdauer
	SimTime kundenAbfertigungStart = 0;
	SimTime kundenAbfertigungEnde = 0;
	SimTime kundenAbfertigungsDauer = 0;

	while(true) {

		//fuer Kassenleerlauf
		leerlaufDerKasseStart = kasse.getTime();

		//Kassierer wartet auf den naechsten Kunden
		//und kassiert alle Waren des Kunden
		message("wartet auf naechsten Kunden");
		aktuelleWare = band.wareEntnehmen();

		//Fuer Kassenleerlauf
		leerlaufDerKasseEnde = kasse.getTime();
		leerlaufDerKasseProZyklus = leerlaufDerKasseEnde - leerlaufDerKasseStart;//Leerlauf pro Zyklus
		kasse.leerlaufErhoehen(leerlaufDerKasseProZyklus);

		kundenAbfertigungStart = kasse.getTime();//Fuer die Berechnung der Kundenabfertigungsdauer

		message("faengt an eine Ware aus dem Band zu entnehmen");
		holdFor( this->dauerEinerWarenbewegung() );
		message("hat dem Band eine Ware entnohmen", aktuelleWare);


		kasse.kundenanzahlInkrementieren();//neuer Kunde wird abgefertigt
		kasse.umsatzErhoehen( aktuelleWare.kosten() ); //Umsatz der Kasse um den Preis der Ware erhoehen

		message("faengt an die Ware in die Ablage zu legen", aktuelleWare);
		holdFor( this->dauerEinerWarenbewegung() );
		ablage.wareLegen(aktuelleWare);
		message("hat die Ware in die Ablage gelegt", aktuelleWare);


		while( !(aktuelleWare.letzteWareDesKunden()) ) {
			aktuelleWare = band.wareEntnehmen();
			message("faengt an eine Ware aus dem Band zu entnehmen");
			holdFor( this->dauerEinerWarenbewegung() );
			message("hat dem Band eine Ware entnohmen", aktuelleWare);


			kasse.umsatzErhoehen( aktuelleWare.kosten() ); //Umsatz der Kasse um den Preis der Ware erhoehen

			message("faengt an die Ware in die Ablage zu legen", aktuelleWare);
			holdFor( this->dauerEinerWarenbewegung() );
			ablage.wareLegen(aktuelleWare);
			message("hat die Ware in die Ablage gelegt", aktuelleWare);

		}

		//alle Waren des Kunden sind kassiert, jetzt generiert der Kunde die Rechnung und uebergibt dem Kunden diese
		//in der Rechnung ist die Bezahlzeit der gesamten Bezahlphase zwischen Kunden und Kassierer gespeichert
		Rechnung rechnung{0, this->dauerEinerBezahlung()}; //Betrag der Rechnung kann ignoriert werden, deswegen Null

		message("faengt an die Rechnung dem Kunden zu uebergeben");
		holdFor( rechnung.dauerDerGesamtenBezahlung() * rechnungAnsagenAnteil );
		bezahlung.rechnungZeigen(rechnung);
		message("hat die Rechnung dem Kunden uebergeben und waret auf das Geld");


		//Kassierer wartet auf das Geld
		rechnung = bezahlung.kassiererWartetAufGeld();
		holdFor( rechnung.dauerDerGesamtenBezahlung() * geldInDieKasseLegen );
		message("Geld bekommen und in die Kasse gelegt");


		message("hat einen Kunden volltaendig abgearbeitet");
		message("------------------------KASSIERER-ZYKLUS-ENDE---------------------------");

		kundenAbfertigungEnde = kasse.getTime();//Fuer die Berechnung der Kundenabfertigungsdauer
		kundenAbfertigungsDauer = kundenAbfertigungEnde - kundenAbfertigungStart;
		kasse.abfertigungsDauerErhoehen(kundenAbfertigungsDauer);


	}

	return 0;

}
