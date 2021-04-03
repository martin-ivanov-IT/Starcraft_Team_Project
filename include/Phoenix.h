#ifndef Phoenix_H_
#define Phoenix_H_

#include "Defines.h"
#include "Airship.h"
#include "ProtossAirship.h"

typedef ProtossAirship Phoenix;
void initPhoenix(Phoenix* phoenix, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType);

#endif