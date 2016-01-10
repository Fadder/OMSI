#include <odemx/odemx.h>
#include "WareUndRechnung.h"
#include "Bezahlung.h"
using namespace std;
using namespace odemx::synchronization;

Bezahlung::Bezahlung(Simulation& sim)
{
	zahlungsUebertragungKassiererKunde = PortTailT<Rechnung>::create(sim, "zahlungsUebertragung_Kassierer->Kunde"
			, PortMode::WAITING_MODE, 1);
	zahlungsUebertragungKundeKassierer = PortTailT<Rechnung>::create(sim, "zahlungsUebertragung_Kunde->Kassierer"
				, PortMode::WAITING_MODE, 1);
}

void Bezahlung::rechnungZeigen(Rechnung rechnung)
{
	zahlungsUebertragungKassiererKunde->put(rechnung);
}

Rechnung Bezahlung::kundeWartetAufRechnung()
{
	return(*zahlungsUebertragungKassiererKunde->getHead()->get());
}


void Bezahlung::rechnungBezahlen(Rechnung rechnung)
{
	zahlungsUebertragungKundeKassierer->put(rechnung);
}

Rechnung Bezahlung::kassiererWartetAufGeld()
{
	return(*zahlungsUebertragungKundeKassierer->getHead()->get());
}

