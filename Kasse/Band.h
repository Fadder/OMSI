/*
 * BandTest.h
 *
 *  Created on: 13.12.2015
 *      Author: work
 */

#ifndef BAND_H_
#define BAND_H_

#include "WareUndRechnung.h"
#include <odemx/odemx.h>
#include <string>
#include <iostream>
#include <memory>
using namespace odemx::synchronization;
using odemx::base::Simulation;
using namespace std;

class Band {
	Bin exclusiveNutznung;
	int bandkapazitaet;
	PortTail::Ptr ptrPT;
public:
	Band(Simulation& sim);
	virtual ~Band();

	void bandExclusivBenutzen();
	void bandFreigeben();
	void wareAufsBandLegen(Ware* ware);
	Ware wareEntnehmen();
};

#endif /* BAND_H_ */
