#ifndef Phoenix_H_
#define Phoenix_H_

#include "Defines.h"
#include "Airship.h"
#include "ProtossAirship.h"
#include"TerranAirship.h"
#include <stdlib.h>

typedef ProtossAirship Phoenix;
int initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index);
int phoenixDealDamageToTerranAirship(Vector* terranFleet,TerranAirship** lastOfTerran, Phoenix* phoenix);
int phoenixRegenerate(ProtossAirship* protossAirship);

#endif