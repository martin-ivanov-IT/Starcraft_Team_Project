#ifndef TerranAirship_H_
#define TerranAirship_H_

#include "Defines.h"
#include "Airship.h"

typedef Airship TerranAirship;
void initTerranAirship(TerranAirship* terranAirship, enum AirShipType airShipType, const char *inputName, int inputHealth, int inputDamage);

#endif
