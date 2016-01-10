/*
 * Person.h
 *
 *  Created on: 12.12.2015
 *      Author: work
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <odemx/odemx.h>
#include "WareUndRechnung.h"
using namespace odemx::random;
using odemx::base::Process;
using odemx::base::Simulation;

class Person : public Process {
public:
	Normal bewegungEinerWare;
	Normal bazahlZeit;

	Person(Simulation& sim, const odemx::data::Label& label);
	virtual ~Person();

	double dauerEinerWarenbewegung();
	double dauerEinerBezahlung();
	void message(std::string aktion, Ware ware=Ware(0,"Null", 0, false));
	//virtual int main() { return 0;};
};

#endif /* PERSON_H_ */
