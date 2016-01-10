#ifndef ABLAGE_H_
#define ABLAGE_H_

#include <odemx/odemx.h>
#include "WareUndRechnung.h"
using namespace std;
using namespace odemx::synchronization;

class Ablage
{
	Bin* exklusiveNutzung;
	shared_ptr<PortTailT<Ware>> warenUebertragung;
	int ablageKapazitaet;
public:
	Ablage(Simulation& sim);
	~Ablage(){}
	Ware wareEntnehmen();
	void wareLegen(Ware zuLegen);
	void kundeMoechteBenutzen();
	void furNaechstenKundenFreigeben();
	void ablageKapazitaetSetzenAuf(int anzWaren);
};

#endif /* ABLAGE_H_ */

