/*
 * KundenGenerator.h
 *
 *  Created on: 13.12.2015
 *      Author: work
 */

#ifndef KUNDENGENERATOR_H_
#define KUNDENGENERATOR_H_

#include "Kunde.h"
#include <string>
#include <odemx/odemx.h>
using namespace odemx::random;
using odemx::base::Process;
using odemx::base::Simulation;
using namespace std;

class KundenGenerator : public Process {
	NegativeExponential kundenAnkunft;
public:
	KundenGenerator(Simulation& sim);
	virtual ~KundenGenerator();

	virtual int main();

	void erstelleKundenUndAktiviere(); //erstellt einen Kunden und aktiviert diesen nach einer zufaelligen Zeit(NegExp)
	void message(string aktion);
};

#endif /* KUNDENGENERATOR_H_ */
