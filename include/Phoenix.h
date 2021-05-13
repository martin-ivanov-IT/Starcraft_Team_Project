#ifndef Phoenix_H_
#define Phoenix_H_

#include "ProtossAirship.h"
#include"TerranAirship.h"

typedef ProtossAirship Phoenix;
void initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index);
int phoenixDealDamageToTerranAirship(Vector* terranFleet,TerranAirship** lastOfTerran, Phoenix* phoenix);
int phoenixRegenerate(ProtossAirship* protossAirship);

#endif