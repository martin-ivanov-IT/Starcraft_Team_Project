#ifndef TerranAirship_H_
#define TerranAirship_H_

#include "Defines.h"
#include "Airship.h"
#include "Carrier.h"

typedef Airship TerranAirship;
void initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage, int index);
void terranDealDamageByCarrier(TerranAirship** lastOfTerran, Vector* terranFleet, int attacks, char* atackerName, int atackerID);

#endif
