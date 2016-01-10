/*
 * Kunde.h
 *
 *  Created on: 12.12.2015
 *      Author: work
 */

#ifndef KUNDE_H_
#define KUNDE_H_

#include <vector>
#include "Person.h"
#include "WareUndRechnung.h"
#include <odemx/odemx.h>
using namespace odemx::random;
using odemx::base::Process;
using odemx::base::Simulation;
using namespace std;

class Kunde : public Person {
	vector<Ware> einkaufskorb;
	Normal anzahlDerWaren;
	NegativeExponential kostenProProdukt;
	Poisson warenAnzahlPois;

public:
	Kunde(Simulation& sim);
	virtual ~Kunde();
	virtual int main();

private:
	int zufaelligeWarenAnzahl();
	int zufaelligeWarenAnzahlPoisson();
	double zufaelligerPreisEinerWare();
	void einkaufskorbFuellen();
};

#endif /* KUNDE_H_ */
