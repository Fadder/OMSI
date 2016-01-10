/*
 * WareUndRechnung.cpp
 *
 *  Created on: 11.12.2015
 *      Author: work
 */

#include "WareUndRechnung.h"

#include <string>
#include <odemx/odemx.h>
using namespace odemx::synchronization;

/*----Implementation von "Ware"----*/
Ware::Ware(double preis, std::string besitzer, int id , bool istLetzteWare) : preis(preis),
					letzteWare(istLetzteWare), besitzer(besitzer), id(id)
{}

bool Ware::letzteWareDesKunden() { return letzteWare; }
double Ware::kosten() { return preis; }


/*----Implementation von "Rechnung"----*/
Rechnung::Rechnung(double betrag, double dauerDerBezahlug) { this->betrag = betrag; this->dauerDerBezahlung = dauerDerBezahlug; }

double Rechnung::getBetrag() { return betrag; }

//Dauer der gesamten Bezahlungsphase
double Rechnung::dauerDerGesamtenBezahlung() {
	return dauerDerBezahlung;
}


