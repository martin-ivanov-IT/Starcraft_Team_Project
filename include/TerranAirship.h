#ifndef TerranAirship_H_
#define TerranAirship_H_

#include "Airship.h"

typedef Airship TerranAirship;
int initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index);
int terranDealDamageByCarrier(TerranAirship** lastOfTerran, Vector* terranFleet, int attacks, char* atackerName, int atackerID);

#endif
