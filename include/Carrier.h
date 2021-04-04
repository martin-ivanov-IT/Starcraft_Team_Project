#ifndef Carrier_H_
#define Carrier_H_

#include "Defines.h"
#include "Airship.h"
#include "ProtossAirship.h"
#include"TerranAirship.h"

typedef ProtossAirship Carrier;
 
void initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index);

int getCarrierAtacks(Carrier* carrier);
void carrierRegenerate(ProtossAirship* protossAirship);
#endif
