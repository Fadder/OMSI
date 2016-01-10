/*
 * Kassierer.h
 *
 *  Created on: 12.12.2015
 *      Author: work
 */

#ifndef KASSIERER_H_
#define KASSIERER_H_
#include "Person.h"
#include "WareUndRechnung.h"
#include <odemx/odemx.h>
#include <memory>
using namespace odemx::random;
using odemx::base::Process;
using odemx::base::Simulation;
using namespace std;

class Kassierer : public Person {

	Ware aktuelleWare;
	//Rechnung rechnung;
public:
	Kassierer(Simulation& sim);
	virtual ~Kassierer();

	virtual int main();
};

#endif /* KASSIERER_H_ */
