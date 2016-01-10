#ifndef BEZAHLUNG_H_
#define BEZAHLUNG_H_

#include <odemx/odemx.h>
#include "WareUndRechnung.h"
using namespace std;
using namespace odemx::synchronization;

class Bezahlung
{
	shared_ptr<PortTailT<Rechnung>> zahlungsUebertragungKassiererKunde;
	shared_ptr<PortTailT<Rechnung>> zahlungsUebertragungKundeKassierer;
public:
	Bezahlung(Simulation& sim);
	~Bezahlung(){}
	void rechnungZeigen(Rechnung rechnung);
	Rechnung kundeWartetAufRechnung();
	void rechnungBezahlen(Rechnung rechnung);
	Rechnung kassiererWartetAufGeld();
};


#endif /* BEZAHLUNG_H_ */
