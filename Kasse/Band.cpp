/*
 * BandTest.cpp
 *
 *  Created on: 13.12.2015
 *      Author: work
 */

#include "Band.h"
#include "WareUndRechnung.h"
#include <odemx/odemx.h>
#include <string>
#include <iostream>
#include <memory>
using namespace odemx::synchronization;
using odemx::base::Simulation;
using namespace std;

Band::Band(Simulation& sim) : exclusiveNutznung(sim, "BandLock", 1), bandkapazitaet(20) {
	ptrPT = PortTail::create( sim, "warenUebertragungBand", WAITING_MODE, bandkapazitaet );
}

Band::~Band() {
	// TODO Auto-generated destructor stub
}

void Band::bandExclusivBenutzen() {
	exclusiveNutznung.take(1);
}

void Band::bandFreigeben() {
	exclusiveNutznung.give(1);
}

void Band::wareAufsBandLegen(Ware* ware) {
	ptrPT->put(ware);
}

Ware Band::wareEntnehmen() {
	std::auto_ptr< PortData* > data = ptrPT->getHead()->get();
	Ware* ware = static_cast<Ware*>(*data);

	return *ware;
}
