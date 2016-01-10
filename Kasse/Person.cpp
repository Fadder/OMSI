/*
 * Person.cpp
 *
 *  Created on: 12.12.2015
 *      Author: work
 */
#include <string>
#include <iostream>
#include "Person.h"
#include "WareUndRechnung.h"
#include <odemx/odemx.h>
using namespace odemx::random;
using odemx::base::Process;
using odemx::base::Simulation;
using namespace std;

Person::Person(Simulation& sim, const odemx::data::Label& label) :
		Process(sim, label),
		bewegungEinerWare(sim, "dauerDerBewegungEinerWare", 3, 2),
		bazahlZeit(sim, "bezahlDauer", 10, 5)

{ }

Person::~Person() {
	// TODO Auto-generated destructor stub
}

//berechnet nur positive Zeit fuer die Bewegung einer Ware
double Person::dauerEinerWarenbewegung() {
	double ret;

	while(true) {
		ret = bewegungEinerWare.sample();
		if(ret > 0) {
			break;
		}
	}

	return ret;
}

//berechnet nur positive Zeit fuer die Bezahlung
double Person::dauerEinerBezahlung() {
	double ret;

	while(true) {
		ret = bazahlZeit.sample();
		if(ret > 0) {
			break;
		}
	}

	return ret;
}

void Person::message( std::string aktion, Ware ware ) {
		if(ware.id == 0) {
			cout << "[Zeit: " << this->getSimulation().getTime() << " sek] " << "<" <<getLabel() << ">"
				 << ": \"" << aktion << "\""  << endl;
		}
		else {
			cout << "[Zeit: " << this->getSimulation().getTime() << " sek] " << "<" <<getLabel() << ">"
				 << ": \"" << aktion << "\""  << ", {-->Ware<-- Besitzer: " << ware.besitzer
				 << ", Id: " << ware.id << ", letztWareDesBesitzers?: " << ware.letzteWareDesKunden()
				 << " }" << endl;
		}
}

