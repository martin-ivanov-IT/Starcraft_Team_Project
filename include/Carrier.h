#ifndef Carrier_H_
#define Carrier_H_

#include "ProtossAirship.h"


typedef ProtossAirship Carrier;
 
void initCarrier(Carrier* carrier, const char *inputName, int inputHealth, int inputDamage,
            int inputShield, int inputShieldRegenerateRate, enum AirShipType airShipType, int index);

int getCarrierAtacks(Carrier* carrier);
int carrierRegenerate(ProtossAirship* protossAirship);
#endif
