#include <odemx/odemx.h>
#include "WareUndRechnung.h"
#include "Ablage.h"
using namespace std;
using namespace odemx::synchronization;

Ablage::Ablage(Simulation& sim)
{
	ablageKapazitaet = 10000; //default
	warenUebertragung = PortTailT<Ware>::create(sim, "warenUebertragungAblage", PortMode::WAITING_MODE,
			ablageKapazitaet);
	exklusiveNutzung = new Bin(sim, "AblageExklusiveNutzung", 1);
}

Ware Ablage::wareEntnehmen()
{
	return(*warenUebertragung->getHead()->get());
}

void Ablage::wareLegen(Ware zuLegen)
{
	warenUebertragung->put(zuLegen);
}

void Ablage::kundeMoechteBenutzen()
{
	exklusiveNutzung->take(1);

}

void Ablage::furNaechstenKundenFreigeben()
{
	exklusiveNutzung->give(1);
}

void Ablage::ablageKapazitaetSetzenAuf(int anzWaren)
{
	ablageKapazitaet = anzWaren;
}
