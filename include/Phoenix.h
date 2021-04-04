#ifndef Phoenix_H_
#define Phoenix_H_

#include "Defines.h"
#include "Airship.h"
#include "ProtossAirship.h"
#include"TerranAirship.h"

typedef ProtossAirship Phoenix;
void initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index);
void phoenixDealDamageToTerranAirship(Vector* terranFleet,TerranAirship** lastOfTerran, Phoenix* phoenix);
void phoenixRegenerate(ProtossAirship* protossAirship);

#endif