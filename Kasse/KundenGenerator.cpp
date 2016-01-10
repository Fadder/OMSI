/*
 * KundenGenerator.cpp
 *
 *  Created on: 13.12.2015
 *      Author: work
 */

#include "KundenGenerator.h"
#include "Kunde.h"
#include <odemx/odemx.h>
#include <string>
#include <iostream>
using namespace odemx::random;
using odemx::base::Process;
using odemx::base::Simulation;
using namespace std;

KundenGenerator::KundenGenerator(Simulation& sim) : Process(sim, "KundenGenerator"),
													kundenAnkunft(sim, "KundenankunftZeit", (1.0/30.0) )
{
	// TODO Auto-generated constructor stub

}

KundenGenerator::~KundenGenerator() {
	// TODO Auto-generated destructor stub
}

void KundenGenerator::erstelleKundenUndAktiviere() {
	holdFor( kundenAnkunft.sample() );
	Kunde* kunde = new Kunde( this->getSimulation() );

	kunde->hold();

	message("neuer Kunde hat sich angestellt");
}

void KundenGenerator::message(std::string aktion) {
	cout << "[Zeit: " << this->getSimulation().getTime() << " sek] " << "<" <<getLabel() << ">"
		 << ": \"" << aktion << "\""  << endl;
}

int KundenGenerator::main() {
	while(true) {
		erstelleKundenUndAktiviere();
	}

	return 0;
}

